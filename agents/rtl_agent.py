"""Generate, validate, and version SystemVerilog RTL."""

from __future__ import annotations

import json
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Protocol, Sequence

from agents.requirement_agent import OpenAICompatibleClient, Requirements
from agents.trace import append_trace


class RtlAgentError(RuntimeError):
    """Raised when RTL generation cannot continue."""


class TextClient(Protocol):
    def complete(self, prompt: str) -> str:
        ...


@dataclass(frozen=True)
class RtlGenerationResult:
    iteration: int
    rtl_path: Path
    validation_log: Path
    valid: bool
    compiler_returncode: int
    compiler_stdout: str
    compiler_stderr: str


class RtlAgent:
    """Generate RTL using a configured LLM or the deterministic FIFO template."""

    def __init__(self, llm_client: TextClient | None = None) -> None:
        self.llm_client = llm_client
        self.prompt_template = self._load_prompt()

    @classmethod
    def from_environment(cls) -> "RtlAgent":
        from agents.requirement_agent import RequirementAgent

        requirement_agent = RequirementAgent.from_environment()
        return cls(requirement_agent.llm_client)

    def generate(
        self,
        requirements: Requirements,
        output_root: str | Path,
        *,
        iteration: int = 1,
        use_llm: bool = False,
        fault: str | Sequence[str] | None = None,
        feedback: dict[str, str] | None = None,
        trace_path: str | Path | None = None,
    ) -> RtlGenerationResult:
        if iteration < 1:
            raise RtlAgentError("iteration must be at least 1")
        if use_llm and self.llm_client is None:
            raise RtlAgentError("LLM is not configured")

        iteration_directory = Path(output_root).resolve() / f"iteration_{iteration:03d}"
        if iteration_directory.exists():
            raise RtlAgentError(f"Refusing to overwrite existing iteration: {iteration_directory}")
        rtl_directory = iteration_directory / "rtl"
        rtl_directory.mkdir(parents=True)

        if use_llm:
            debug_feedback = (
                json.dumps(feedback, indent=2)
                if feedback
                else "No previous simulation feedback; generate an initial candidate."
            )
            prompt = self.prompt_template.replace(
                "{{REQUIREMENTS}}",
                requirements.model_dump_json(indent=2),
            ).replace("{{DEBUG_FEEDBACK}}", debug_feedback)
            try:
                raw_rtl = self.llm_client.complete(prompt)
            except Exception as exc:
                append_trace(trace_path, "rtl_agent", "generation_failed", iteration=iteration, prompt=prompt, error=str(exc))
                raise
            source = self._extract_rtl(raw_rtl)
        else:
            prompt = None
            source = self._fifo_template(requirements, fault=fault)
        faults = [fault] if isinstance(fault, str) else list(fault or ())
        for fault_name in faults:
            source = self._apply_fault(source, fault_name)

        append_trace(
            trace_path,
            "rtl_agent",
            "generation_completed",
            iteration=iteration,
            mode="llm" if use_llm else "offline_template",
            prompt=prompt,
            response=raw_rtl if use_llm else source,
            feedback=feedback,
            injected_faults=faults,
        )

        rtl_path = rtl_directory / f"{requirements.module_name}.sv"
        rtl_path.write_text(source, encoding="utf-8")
        interface_error = self._validate_interface(source, requirements)
        if interface_error:
            validation_log = rtl_directory / "validation.log"
            validation_log.write_text("INTERFACE ERROR: " + interface_error + "\n", encoding="utf-8")
            validation = (False, 1, "", interface_error)
        else:
            validation = self._validate(rtl_path, rtl_directory / "validation.log")
        append_trace(
            trace_path,
            "rtl_agent",
            "rtl_validation_completed",
            iteration=iteration,
            valid=validation[0],
            compiler_returncode=validation[1],
            compiler_stdout=validation[2],
            compiler_stderr=validation[3],
        )

        metadata = {
            "iteration": iteration,
            "module_name": requirements.module_name,
            "injected_faults": faults,
            "rtl_path": str(rtl_path),
            "valid": validation[0],
            "compiler_returncode": validation[1],
        }
        (iteration_directory / "metadata.json").write_text(
            json.dumps(metadata, indent=2) + "\n",
            encoding="utf-8",
        )
        return RtlGenerationResult(
            iteration=iteration,
            rtl_path=rtl_path,
            validation_log=rtl_directory / "validation.log",
            valid=validation[0],
            compiler_returncode=validation[1],
            compiler_stdout=validation[2],
            compiler_stderr=validation[3],
        )

    @staticmethod
    def _load_prompt() -> str:
        prompt_path = Path(__file__).resolve().parents[1] / "prompts" / "rtl_prompt.txt"
        try:
            return prompt_path.read_text(encoding="utf-8")
        except OSError as exc:
            raise RtlAgentError(f"Unable to load RTL prompt: {prompt_path}") from exc

    @staticmethod
    def _extract_rtl(raw_rtl: str) -> str:
        candidate = raw_rtl.strip()
        fenced = re.search(r"```(?:systemverilog|verilog)?\s*(.*?)```", candidate, re.DOTALL | re.IGNORECASE)
        if fenced:
            candidate = fenced.group(1).strip()
        if not re.search(r"\bmodule\b", candidate) or not re.search(r"\bendmodule\b", candidate):
            raise RtlAgentError("LLM response does not contain a complete SystemVerilog module")
        return candidate + "\n"

    @staticmethod
    def _validate(rtl_path: Path, validation_log: Path) -> tuple[bool, int, str, str]:
        command = ["iverilog", "-g2012", "-Wall", "-t", "null", str(rtl_path)]
        try:
            process = subprocess.run(
                command,
                cwd=rtl_path.parent,
                capture_output=True,
                text=True,
                timeout=30,
                check=False,
            )
        except FileNotFoundError as exc:
            raise RtlAgentError("iverilog was not found on PATH") from exc
        except subprocess.TimeoutExpired as exc:
            stdout = RtlAgent._decode(exc.stdout)
            stderr = RtlAgent._decode(exc.stderr)
            validation_log.write_text(
                "COMMAND: " + " ".join(command) + "\nSTATUS: TIMEOUT\n" + stdout + stderr,
                encoding="utf-8",
            )
            return False, -1, stdout, stderr

        validation_log.write_text(
            "COMMAND: " + " ".join(command)
            + f"\nRETURN CODE: {process.returncode}\n\nSTDOUT:\n{process.stdout}\nSTDERR:\n{process.stderr}",
            encoding="utf-8",
        )
        return process.returncode == 0, process.returncode, process.stdout, process.stderr

    @staticmethod
    def _decode(output: str | bytes | None) -> str:
        if output is None:
            return ""
        return output.decode(errors="replace") if isinstance(output, bytes) else output

    @staticmethod
    def _validate_interface(source: str, requirements: Requirements) -> str | None:
        module_match = re.search(r"\bmodule\s+([A-Za-z_][A-Za-z0-9_]*)", source)
        if not module_match:
            return "generated RTL has no named module"
        if module_match.group(1) != requirements.module_name:
            return f"module name {module_match.group(1)} does not match {requirements.module_name}"
        required_names = {port.name for port in (*requirements.inputs, *requirements.outputs)}
        missing = sorted(name for name in required_names if not re.search(rf"\b{re.escape(name)}\b", source))
        if missing:
            return "missing required interface symbol(s): " + ", ".join(missing)
        return None

    @staticmethod
    def _apply_fault(source: str, fault: str) -> str:
        if fault == "broken_full_flag":
            updated = source.replace("assign full = (count == DEPTH);", "assign full = (count == DEPTH - 1);")
            if updated == source:
                raise RtlAgentError("Requested fault could not be applied to generated RTL")
            return updated
        if fault == "invert_first_comparison":
            updated, count = re.subn(r"==", "!=", source, count=1)
            if count != 1:
                raise RtlAgentError("Requested comparison fault could not be applied to generated RTL")
            return updated
        raise RtlAgentError(f"Unsupported fault: {fault}")

    @staticmethod
    def _fifo_template(requirements: Requirements, *, fault: str | None = None) -> str:
        if requirements.module_name != "fifo":
            raise RtlAgentError("Offline RTL generation currently supports the FIFO target only")
        data_width = int(requirements.parameters.get("DATA_WIDTH", 8))
        depth = int(requirements.parameters.get("DEPTH", 4))
        return f'''module fifo #(\n    parameter int DATA_WIDTH = {data_width},\n    parameter int DEPTH = {depth}\n) (\n    input logic clk,\n    input logic rst,\n    input logic wr_en,\n    input logic rd_en,\n    input logic [DATA_WIDTH-1:0] data_in,\n    output logic [DATA_WIDTH-1:0] data_out,\n    output logic full,\n    output logic empty\n);\n\n    localparam int PTR_WIDTH = (DEPTH <= 1) ? 1 : $clog2(DEPTH);\n    localparam int COUNT_WIDTH = $clog2(DEPTH + 1);\n    logic [DATA_WIDTH-1:0] memory [0:DEPTH-1];\n    logic [PTR_WIDTH-1:0] read_pointer, write_pointer;\n    logic [COUNT_WIDTH-1:0] count;\n    wire write_accept = wr_en && !full;\n    wire read_accept = rd_en && !empty;\n\n    assign full = (count == DEPTH);\n    assign empty = (count == 0);\n\n    always_ff @(posedge clk) begin\n        if (rst) begin\n            read_pointer <= '0;\n            write_pointer <= '0;\n            count <= '0;\n            data_out <= '0;\n        end else begin\n            if (write_accept) begin\n                memory[write_pointer] <= data_in;\n                write_pointer <= (write_pointer == DEPTH - 1) ? '0 : write_pointer + 1'b1;\n            end\n            if (read_accept) begin\n                data_out <= memory[read_pointer];\n                read_pointer <= (read_pointer == DEPTH - 1) ? '0 : read_pointer + 1'b1;\n            end\n            case ({{write_accept, read_accept}})\n                2'b10: count <= count + 1'b1;\n                2'b01: count <= count - 1'b1;\n                default: count <= count;\n            endcase\n        end\n    end\nendmodule\n'''
