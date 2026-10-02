"""Compile and simulate SystemVerilog sources with Icarus Verilog."""

from __future__ import annotations

import re
import subprocess
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Sequence


@dataclass(frozen=True)
class SimulationResult:
    """Structured result from one compile and simulation attempt."""

    compile_returncode: int | None
    simulation_returncode: int | None
    compile_stdout: str
    compile_stderr: str
    simulation_stdout: str
    simulation_stderr: str
    compile_command: tuple[str, ...]
    simulation_command: tuple[str, ...]
    log_directory: Path
    executable_path: Path
    status: str
    timed_out: bool = False

    @property
    def passed(self) -> bool:
        return self.status == "PASS"

    @property
    def failed(self) -> bool:
        return self.status == "FAIL"

    @property
    def output(self) -> str:
        """Return combined simulator output for failure analysis."""
        return "\n".join(
            part
            for part in (self.simulation_stdout, self.simulation_stderr)
            if part
        )


class SimulatorError(RuntimeError):
    """Raised when the simulator cannot be started or its inputs are invalid."""


class IcarusSimulator:
    """Run Icarus compilation and vvp simulation without hard-coded project paths."""

    def __init__(
        self,
        iverilog_executable: str = "iverilog",
        vvp_executable: str = "vvp",
        timeout_seconds: float = 60.0,
    ) -> None:
        if timeout_seconds <= 0:
            raise ValueError("timeout_seconds must be greater than zero")
        self.iverilog_executable = iverilog_executable
        self.vvp_executable = vvp_executable
        self.timeout_seconds = timeout_seconds

    def run(
        self,
        rtl_paths: Sequence[str | Path],
        testbench_paths: Sequence[str | Path],
        log_directory: str | Path,
        *,
        top_module: str | None = None,
    ) -> SimulationResult:
        """Compile RTL and testbench files, then run the compiled simulation.

        All paths are supplied by the caller. Logs and the compiled executable are
        written to ``log_directory`` so each run remains inspectable.
        """
        rtl = self._validate_sources(rtl_paths, "RTL")
        testbench = self._validate_sources(testbench_paths, "testbench")
        sources = [*rtl, *testbench]

        log_dir = Path(log_directory).resolve()
        log_dir.mkdir(parents=True, exist_ok=True)
        executable = log_dir / "simulation.vvp"

        compile_command = [self.iverilog_executable, "-g2012", "-Wall"]
        if top_module:
            compile_command.extend(["-s", top_module])
        compile_command.extend(["-o", str(executable), *(str(path) for path in sources)])
        simulation_command = [self.vvp_executable, str(executable)]

        compile_process = self._run_process(compile_command, log_dir)
        self._write_process_log(
            log_dir / "compile.log",
            compile_command,
            compile_process,
        )

        if compile_process.returncode != 0:
            result = SimulationResult(
                compile_returncode=compile_process.returncode,
                simulation_returncode=None,
                compile_stdout=compile_process.stdout,
                compile_stderr=compile_process.stderr,
                simulation_stdout="",
                simulation_stderr="",
                compile_command=tuple(compile_command),
                simulation_command=tuple(simulation_command),
                log_directory=log_dir,
                executable_path=executable,
                status="FAIL",
            )
            self._write_summary(log_dir / "result.json", result)
            return result

        try:
            simulation_process = self._run_process(simulation_command, log_dir)
        except subprocess.TimeoutExpired as error:
            stdout = self._decode_output(error.stdout)
            stderr = self._decode_output(error.stderr)
            self._write_timeout_log(log_dir / "simulation.log", simulation_command, stdout, stderr)
            result = SimulationResult(
                compile_returncode=compile_process.returncode,
                simulation_returncode=None,
                compile_stdout=compile_process.stdout,
                compile_stderr=compile_process.stderr,
                simulation_stdout=stdout,
                simulation_stderr=stderr,
                compile_command=tuple(compile_command),
                simulation_command=tuple(simulation_command),
                log_directory=log_dir,
                executable_path=executable,
                status="FAIL",
                timed_out=True,
            )
            self._write_summary(log_dir / "result.json", result)
            return result

        self._write_process_log(
            log_dir / "simulation.log",
            simulation_command,
            simulation_process,
        )
        status = self._detect_status(simulation_process)
        result = SimulationResult(
            compile_returncode=compile_process.returncode,
            simulation_returncode=simulation_process.returncode,
            compile_stdout=compile_process.stdout,
            compile_stderr=compile_process.stderr,
            simulation_stdout=simulation_process.stdout,
            simulation_stderr=simulation_process.stderr,
            compile_command=tuple(compile_command),
            simulation_command=tuple(simulation_command),
            log_directory=log_dir,
            executable_path=executable,
            status=status,
        )
        self._write_summary(log_dir / "result.json", result)
        return result

    @staticmethod
    def _validate_sources(paths: Sequence[str | Path], label: str) -> list[Path]:
        if not paths:
            raise SimulatorError(f"At least one {label} source is required")
        resolved = [Path(path).resolve() for path in paths]
        missing = [str(path) for path in resolved if not path.is_file()]
        if missing:
            raise SimulatorError(f"Missing {label} source file(s): {', '.join(missing)}")
        return resolved

    def _run_process(
        self,
        command: Sequence[str],
        cwd: Path,
    ) -> subprocess.CompletedProcess[str]:
        try:
            return subprocess.run(
                list(command),
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=self.timeout_seconds,
                check=False,
            )
        except FileNotFoundError as error:
            raise SimulatorError(f"Required executable was not found: {command[0]}") from error
        except subprocess.TimeoutExpired:
            raise

    @staticmethod
    def _detect_status(process: subprocess.CompletedProcess[str]) -> str:
        output = f"{process.stdout}\n{process.stderr}"
        has_pass = re.search(r"\bPASS\b", output, re.IGNORECASE) is not None
        has_fail = re.search(r"\bFAIL\b", output, re.IGNORECASE) is not None
        if process.returncode == 0 and has_pass and not has_fail:
            return "PASS"
        if process.returncode != 0 or has_fail:
            return "FAIL"
        return "UNKNOWN"

    @staticmethod
    def _write_process_log(
        path: Path,
        command: Sequence[str],
        process: subprocess.CompletedProcess[str],
    ) -> None:
        path.write_text(
            "COMMAND:\n"
            + " ".join(command)
            + f"\n\nRETURN CODE: {process.returncode}\n\n"
            + "STDOUT:\n"
            + process.stdout
            + "\nSTDERR:\n"
            + process.stderr,
            encoding="utf-8",
        )

    @staticmethod
    def _write_timeout_log(
        path: Path,
        command: Sequence[str],
        stdout: str,
        stderr: str,
    ) -> None:
        path.write_text(
            "COMMAND:\n"
            + " ".join(command)
            + "\n\nSTATUS: TIMEOUT\n\nSTDOUT:\n"
            + stdout
            + "\nSTDERR:\n"
            + stderr,
            encoding="utf-8",
        )

    @staticmethod
    def _decode_output(output: str | bytes | None) -> str:
        if output is None:
            return ""
        if isinstance(output, bytes):
            return output.decode(errors="replace")
        return output

    @staticmethod
    def _write_summary(path: Path, result: SimulationResult) -> None:
        import json

        payload = {
            "compile_returncode": result.compile_returncode,
            "simulation_returncode": result.simulation_returncode,
            "status": result.status,
            "timed_out": result.timed_out,
            "compile_command": list(result.compile_command),
            "simulation_command": list(result.simulation_command),
            "log_directory": str(result.log_directory),
            "executable_path": str(result.executable_path),
            "created_at": datetime.now(timezone.utc).isoformat(),
        }
        path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
