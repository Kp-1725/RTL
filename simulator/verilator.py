"""Run Verilator with real coverage collection through WSL2 on Windows."""

from __future__ import annotations

import json
import os
import re
import shlex
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Sequence


@dataclass(frozen=True)
class VerilatorResult:
    status: str
    returncode: int
    output: str
    log_directory: Path
    coverage_database: Path
    build_directory: str
    code_coverage: dict[str, object]

    @property
    def passed(self) -> bool:
        return self.status == "PASS"

    @property
    def failed(self) -> bool:
        return self.status == "FAIL"

    @property
    def compile_returncode(self) -> int:
        return 0 if "Verilator: Built" in self.output else self.returncode

    @property
    def simulation_returncode(self) -> int:
        return self.returncode

    @property
    def timed_out(self) -> bool:
        return False

    @property
    def compile_stdout(self) -> str:
        return self.output

    @property
    def compile_stderr(self) -> str:
        return ""

    @property
    def simulation_stdout(self) -> str:
        return self.output

    @property
    def simulation_stderr(self) -> str:
        return ""

class VerilatorError(RuntimeError):
    """Raised when the WSL Verilator runner cannot be started."""


class VerilatorSimulator:
    """Compile and run SystemVerilog with Verilator coverage enabled."""

    def __init__(self, wsl_executable: str = "wsl.exe", distribution: str = "Ubuntu", timeout_seconds: float = 300.0) -> None:
        self.wsl_executable = wsl_executable
        self.distribution = distribution
        self.timeout_seconds = timeout_seconds

    def run(
        self,
        rtl_paths: Sequence[str | Path],
        testbench_paths: Sequence[str | Path],
        log_directory: str | Path,
        *,
        top_module: str = "tb_fifo",
    ) -> VerilatorResult:
        if not rtl_paths or not testbench_paths:
            raise VerilatorError("RTL and testbench sources are required")
        sources = [Path(path).resolve() for path in (*rtl_paths, *testbench_paths)]
        missing = [str(path) for path in sources if not path.is_file()]
        if missing:
            raise VerilatorError(f"Missing source file(s): {', '.join(missing)}")

        log_dir = Path(log_directory).resolve()
        log_dir.mkdir(parents=True, exist_ok=True)
        coverage_database = log_dir / "coverage.dat"
        harness = log_dir / "verilator_main.cpp"
        wsl_coverage = self._wsl_path(coverage_database)
        harness.write_text(self._harness_source(wsl_coverage, top_module), encoding="utf-8")

        build_directory = f"/tmp/agentic-rtl-verilator-{os.getpid()}"
        wsl_log_directory = self._wsl_path(log_dir)
        wsl_sources = [self._wsl_path(path) for path in sources]
        wsl_harness_source = self._wsl_path(harness)
        wsl_harness = f"{build_directory}/verilator_main.cpp"
        wsl_executable = f"{build_directory}/sim_{top_module}"
        command = (
            f"cd {shlex.quote(wsl_log_directory)} && "
            f"rm -rf {shlex.quote(build_directory)} && "
            f"mkdir -p {shlex.quote(build_directory)} && "
            f"cp {shlex.quote(wsl_harness_source)} {shlex.quote(wsl_harness)} && "
            f"verilator --cc --coverage --assert --timing --trace --Wno-fatal -DVERILATOR_COVERAGE "
            f"--top-module {shlex.quote(top_module)} "
            f"--Mdir {shlex.quote(build_directory)} "
            f"--exe {shlex.quote(wsl_harness)} --build -o {shlex.quote(wsl_executable)} "
            + " ".join(shlex.quote(path) for path in wsl_sources)
            + " && "
            + shlex.quote(wsl_executable)
        )
        try:
            process = subprocess.run(
                [self.wsl_executable, "-d", self.distribution, "--", "bash", "-lc", command],
                capture_output=True,
                text=True,
                timeout=self.timeout_seconds,
                check=False,
            )
        except FileNotFoundError as error:
            raise VerilatorError(f"WSL executable was not found: {self.wsl_executable}") from error
        except subprocess.TimeoutExpired as error:
            raise VerilatorError("Verilator simulation timed out") from error

        output = "\n".join(part for part in (process.stdout, process.stderr) if part)
        status = "PASS" if process.returncode == 0 and "PASS" in output.upper() else "FAIL"
        code_coverage = self.parse_coverage_database(coverage_database)
        code_coverage = self._merge_runtime_assertion_coverage(code_coverage, output)
        (log_dir / "verilator.log").write_text(
            "COMMAND:\n" + command + f"\n\nRETURN CODE: {process.returncode}\n\n" + output,
            encoding="utf-8",
        )
        (log_dir / "result.json").write_text(
            json.dumps(
                {
                    "status": status,
                    "returncode": process.returncode,
                    "coverage_database": str(coverage_database),
                    "build_directory": build_directory,
                    "code_coverage": code_coverage,
                },
                indent=2,
            )
            + "\n",
            encoding="utf-8",
        )
        return VerilatorResult(status, process.returncode, output, log_dir, coverage_database, build_directory, code_coverage)

    @staticmethod
    def _merge_runtime_assertion_coverage(
        code_coverage: dict[str, object],
        output: str,
    ) -> dict[str, object]:
        match = re.search(r"ASSERTION_COVERAGE checks=(\d+) passes=(\d+)", output)
        if not match:
            return code_coverage
        checks = int(match.group(1))
        passes = int(match.group(2))
        metrics = dict(code_coverage.get("metrics", {}))
        metrics["assertion"] = {
            "covered": passes,
            "total": checks,
            "percentage": round(100 * passes / checks, 2) if checks else 0.0,
            "measurement": "runtime_assertion_monitor",
        }
        return {**code_coverage, "metrics": metrics}

    @staticmethod
    def parse_coverage_database(path: str | Path) -> dict[str, object]:
        """Parse Verilator's textual coverage database without inventing metrics."""
        coverage_path = Path(path)
        if not coverage_path.is_file():
            return {
                "status": "not_available",
                "tool": "verilator",
                "database": str(coverage_path),
                "metrics": {},
            }

        data = coverage_path.read_bytes()
        records = re.findall(rb"page\x02v_(line|branch|toggle|assert|cover).*?' (\d+)", data)
        metrics: dict[str, dict[str, int | float]] = {}
        for raw_name, raw_count in records:
            name = raw_name.decode("ascii")
            metric = metrics.setdefault(name, {"covered": 0, "total": 0, "percentage": 0.0})
            metric["total"] = int(metric["total"]) + 1
            if int(raw_count) > 0:
                metric["covered"] = int(metric["covered"]) + 1
        for metric in metrics.values():
            total = int(metric["total"])
            metric["percentage"] = round(100 * int(metric["covered"]) / total, 2) if total else 0.0

        assertion_metrics = [metrics[name] for name in ("assert", "cover") if name in metrics]
        if assertion_metrics:
            assertion_total = sum(int(metric["total"]) for metric in assertion_metrics)
            assertion_covered = sum(int(metric["covered"]) for metric in assertion_metrics)
            metrics["assertion"] = {
                "covered": assertion_covered,
                "total": assertion_total,
                "percentage": round(100 * assertion_covered / assertion_total, 2) if assertion_total else 0.0,
            }

        code_metrics = [metrics[name] for name in ("line", "branch", "toggle") if name in metrics]
        total = sum(int(metric["total"]) for metric in code_metrics)
        covered = sum(int(metric["covered"]) for metric in code_metrics)
        return {
            "status": "measured",
            "tool": "verilator",
            "database": str(coverage_path),
            "metrics": metrics,
            "percentage": round(100 * covered / total, 2) if total else 0.0,
        }

    @staticmethod
    def _wsl_path(path: Path) -> str:
        drive = path.drive.rstrip(":").lower()
        if len(drive) != 1:
            raise VerilatorError(f"Expected a Windows drive path, got: {path}")
        return f"/mnt/{drive}{path.as_posix()[2:]}"

    @staticmethod
    def _harness_source(coverage_database: str, top_module: str) -> str:
        return f'''#include "V{top_module}.h"
#include "verilated.h"
#include "verilated_cov.h"

int main(int argc, char** argv) {{
    VerilatedContext context;
    context.commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    V{top_module} top{{&context}};
    while (!context.gotFinish() && context.time() < 100000) {{
        top.eval();
        context.timeInc(1);
    }}
    top.final();
    VerilatedCov::write("{coverage_database}");
    return context.gotFinish() ? 0 : 1;
}}
'''
