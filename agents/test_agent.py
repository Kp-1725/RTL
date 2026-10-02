"""Generate and version SystemVerilog verification testbenches."""

from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from typing import Protocol

from agents.requirement_agent import Requirements
from agents.trace import append_trace


class TestAgentError(RuntimeError):
    """Raised when testbench generation cannot continue."""


class TextClient(Protocol):
    def complete(self, prompt: str) -> str:
        ...


@dataclass(frozen=True)
class TestGenerationResult:
    testbench_path: Path
    valid_source: bool
    top_module: str


class TestAgent:
    """Generate a requirement-driven testbench for the supported FIFO target."""

    def __init__(self, llm_client: TextClient | None = None) -> None:
        self.llm_client = llm_client
        self.prompt_template = self._load_prompt()

    @classmethod
    def from_environment(cls) -> "TestAgent":
        from agents.requirement_agent import RequirementAgent

        return cls(RequirementAgent.from_environment().llm_client)

    def generate(
        self,
        requirements: Requirements,
        output_directory: str | Path,
        *,
        use_llm: bool = False,
        trace_path: str | Path | None = None,
    ) -> TestGenerationResult:
        output_path = Path(output_directory).resolve()
        test_directory = output_path / "tests"
        test_directory.mkdir(parents=True, exist_ok=True)
        testbench_path = test_directory / f"tb_{requirements.module_name}.sv"

        if testbench_path.exists():
            raise TestAgentError(f"Refusing to overwrite existing testbench: {testbench_path}")
        if use_llm:
            if self.llm_client is None:
                raise TestAgentError("LLM is not configured")
            prompt = self.prompt_template.replace(
                "{{REQUIREMENTS}}",
                requirements.model_dump_json(indent=2),
            )
            try:
                raw_response = self.llm_client.complete(prompt)
            except Exception as exc:
                append_trace(trace_path, "test_agent", "generation_failed", prompt=prompt, error=str(exc))
                raise
            (test_directory / "testbench_generation_attempt.txt").write_text(raw_response, encoding="utf-8")
            source = self._extract_testbench(raw_response)
        else:
            prompt = None
            raw_response = None
            source = self._fifo_template(requirements)

        append_trace(
            trace_path,
            "test_agent",
            "generation_completed",
            mode="llm" if use_llm else "offline_template",
            prompt=prompt,
            response=raw_response if use_llm else source,
        )
        top_module = self._extract_top_module(source)
        source = self._ensure_vcd_dump(source, top_module)
        try:
            self._validate_testbench(source, requirements, require_markers=use_llm)
        except TestAgentError as exc:
            append_trace(trace_path, "test_agent", "validation_failed", top_module=top_module, error=str(exc))
            raise
        testbench_path.write_text(source, encoding="utf-8")
        append_trace(trace_path, "test_agent", "validation_completed", top_module=top_module, valid=True)
        return TestGenerationResult(testbench_path=testbench_path, valid_source=True, top_module=top_module)

    def generate_targeted(
        self,
        requirements: Requirements,
        output_directory: str | Path,
        uncovered_scenarios: list[str],
    ) -> TestGenerationResult:
        """Create a separately named testbench for uncovered scenarios."""
        if not uncovered_scenarios:
            raise TestAgentError("At least one uncovered scenario is required")
        output_path = Path(output_directory).resolve()
        test_directory = output_path / "targeted_tests"
        test_directory.mkdir(parents=True, exist_ok=True)
        testbench_path = test_directory / f"tb_{requirements.module_name}_targeted.sv"
        if testbench_path.exists():
            raise TestAgentError(f"Refusing to overwrite targeted testbench: {testbench_path}")
        source = self._fifo_template(requirements)
        source = source.replace("module tb_fifo;", "module tb_fifo_targeted;")
        source = source.replace("$dumpvars(0, tb_fifo);", "$dumpvars(0, tb_fifo_targeted);")
        header = "// Targeted scenarios: " + ", ".join(uncovered_scenarios) + "\n"
        testbench_path.write_text(header + source, encoding="utf-8")
        return TestGenerationResult(testbench_path=testbench_path, valid_source=True, top_module="tb_fifo_targeted")

    @staticmethod
    def _load_prompt() -> str:
        prompt_path = Path(__file__).resolve().parents[1] / "prompts" / "test_prompt.txt"
        try:
            return prompt_path.read_text(encoding="utf-8")
        except OSError as exc:
            raise TestAgentError(f"Unable to load test prompt: {prompt_path}") from exc

    @staticmethod
    def _extract_testbench(raw_testbench: str) -> str:
        candidate = raw_testbench.strip()
        fenced = re.search(r"```(?:systemverilog|verilog)?\s*(.*?)```", candidate, re.DOTALL | re.IGNORECASE)
        if fenced:
            candidate = fenced.group(1).strip()
        if not re.search(r"\bmodule\b", candidate) or not re.search(r"\bendmodule\b", candidate):
            raise TestAgentError("LLM response does not contain a complete testbench")
        return candidate + "\n"

    @staticmethod
    def _extract_top_module(source: str) -> str:
        modules = re.findall(r"\bmodule\s+([A-Za-z_][A-Za-z0-9_]*)", source)
        if not modules:
            raise TestAgentError("Testbench does not contain a named module")
        return modules[0]

    @staticmethod
    def _ensure_vcd_dump(source: str, top_module: str) -> str:
        if "$dumpfile" in source and "$dumpvars" in source:
            return source
        module_end = re.search(r"\bendmodule\s*$", source)
        if not module_end:
            raise TestAgentError("Cannot add waveform dumping: testbench has no final endmodule")
        dump_block = (
            "\n    initial begin\n"
            '        $dumpfile("waveform.vcd");\n'
            f"        $dumpvars(0, {top_module});\n"
            "    end\n\n"
        )
        return source[:module_end.start()] + dump_block + source[module_end.start():]

    @staticmethod
    def _validate_testbench(source: str, requirements: Requirements, *, require_markers: bool) -> None:
        if not re.search(r"\bmodule\s+[A-Za-z_][A-Za-z0-9_]*", source):
            raise TestAgentError("Testbench does not contain a named module")
        if not re.search(rf"\b{re.escape(requirements.module_name)}\b", source):
            raise TestAgentError(f"Testbench does not instantiate module {requirements.module_name}")
        executable_source = re.sub(r"/\*.*?\*/|//[^\n]*", "", source, flags=re.DOTALL)
        has_pass_message = re.search(r"\bPASS\b", executable_source) is not None
        has_assertion = re.search(r"\bassert\s*(?:property\s*)?(?:\(|[A-Za-z_])", executable_source) is not None
        has_failure_path = (
            re.search(r"\bFAIL\b", executable_source) is not None
            or any(system_task in executable_source for system_task in ("$fatal", "$error"))
            or has_assertion
        )
        finish_count = executable_source.count("$finish")
        contract_errors = []
        if finish_count == 0:
            contract_errors.append("must terminate with $finish")
        elif finish_count > 1:
            contract_errors.append("must use one final $finish after all scenarios")
        if not has_pass_message:
            contract_errors.append("must print PASS only after all checks pass")
        if not has_failure_path:
            contract_errors.append("must have an executable assertion, $fatal/$error, or explicit FAIL path")
        if contract_errors:
            raise TestAgentError("Testbench " + "; ".join(contract_errors))
        if require_markers:
            scenarios = set(re.findall(r"^\s*//\s*SCENARIO:\s*([A-Za-z0-9_.-]+)", source, re.MULTILINE))
            assertions = set(re.findall(r"^\s*//\s*ASSERTION:\s*([A-Za-z0-9_.-]+)", source, re.MULTILINE))
            missing_scenarios = set(requirements.scenarios) - scenarios
            missing_assertions = set(requirements.assertions) - assertions
            if missing_scenarios:
                raise TestAgentError(f"Testbench is missing scenario markers: {sorted(missing_scenarios)}")
            if missing_assertions:
                raise TestAgentError(f"Testbench is missing assertion markers: {sorted(missing_assertions)}")

    @staticmethod
    def _fifo_template(requirements: Requirements) -> str:
        if requirements.module_name != "fifo":
            raise TestAgentError("Offline test generation currently supports the FIFO target only")
        data_width = int(requirements.parameters.get("DATA_WIDTH", 8))
        depth = int(requirements.parameters.get("DEPTH", 4))
        source = '''module tb_fifo;
    logic clk, rst, wr_en, rd_en;
    logic [7:0] data_in, data_out;
    logic full, empty;
    logic [7:0] expected_queue[$];
    integer checks;
    integer assertion_checks, assertion_passes;

    fifo dut (
        .clk(clk), .rst(rst), .wr_en(wr_en), .rd_en(rd_en),
        .data_in(data_in), .data_out(data_out), .full(full), .empty(empty)
    );

    always #5 clk = ~clk;

`ifdef VERILATOR_COVERAGE
    always @(posedge clk) begin
        if (!rst) begin
            assertion_checks = assertion_checks + 1;
            if (!(full && empty)) assertion_passes = assertion_passes + 1;
            else $fatal(1, "FAIL: full and empty asserted together");
        end
    end

    property p_flags_are_not_both_active;
        @(posedge clk) !(full && empty);
    endproperty
    assert property (p_flags_are_not_both_active);
    cover property (@(posedge clk) full);
    cover property (@(posedge clk) empty);
`endif

    task automatic check_flags;
        assert (empty === (expected_queue.size() == 0)) else $fatal(1, "FAIL: empty mismatch");
        assert (full === (expected_queue.size() == 4)) else $fatal(1, "FAIL: full mismatch");
        checks = checks + 1;
    endtask

    task automatic write_item(input logic [7:0] value);
        @(negedge clk);
        wr_en = 1'b1; rd_en = 1'b0; data_in = value;
        @(posedge clk); #1;
        if (expected_queue.size() < 4) expected_queue.push_back(value);
        check_flags();
    endtask

    task automatic read_item;
        logic [7:0] expected_value;
        logic had_read;
        @(negedge clk);
        wr_en = 1'b0; rd_en = 1'b1;
        had_read = expected_queue.size() > 0;
        if (had_read) expected_value = expected_queue.pop_front();
        @(posedge clk); #1;
        if (had_read && expected_value !== data_out) $fatal(1, "FAIL: data mismatch");
        check_flags();
    endtask

    initial begin
        $dumpfile("fifo_agent.vcd");
        $dumpvars(0, tb_fifo);
        clk = 0; rst = 1; wr_en = 0; rd_en = 0; data_in = 0; checks = 0;
        assertion_checks = 0; assertion_passes = 0;
        repeat (2) @(posedge clk); #1;
        expected_queue = {};
        check_flags();
        rst = 0;

        read_item();
        write_item(8'h11);
        read_item();
        write_item(8'h21);
        write_item(8'h22);
        write_item(8'h23);
        write_item(8'h24);
        write_item(8'hff);
        read_item();
        read_item();
        read_item();
        read_item();

        write_item(8'ha1);
        write_item(8'ha2);
        @(negedge clk);
        wr_en = 1'b1; rd_en = 1'b1; data_in = 8'ha3;
        expected_queue.push_back(8'ha3);
        expected_queue.pop_front();
        @(posedge clk); #1;
        if (data_out !== 8'ha1) $fatal(1, "FAIL: simultaneous data mismatch");
        check_flags();
        read_item();

        write_item(8'h55);
        @(negedge clk); rst = 1'b1; wr_en = 1'b1; rd_en = 1'b1;
        @(posedge clk); #1;
        expected_queue = {};
        if (data_out !== 8'h00) $fatal(1, "FAIL: reset output mismatch");
        check_flags();
        $display("PASS: generated FIFO testbench completed (%0d checks).", checks);
        $display("ASSERTION_COVERAGE checks=%0d passes=%0d", assertion_checks, assertion_passes);
        $finish;
    end
endmodule
'''
        additional_writes = "".join(
            f"        write_item(8'h{value:02x});\n"
            for value in range(0x25, 0x25 + max(0, depth - 4))
        )
        additional_reads = "".join("        read_item();\n" for _ in range(max(0, depth - 4)))
        return (
            source
            .replace("[7:0]", f"[{data_width - 1}:0]")
            .replace("== 4", f"== {depth}")
            .replace("< 4", f"< {depth}")
            .replace("        write_item(8'h24);\n", "        write_item(8'h24);\n" + additional_writes)
            .replace("        read_item();\n\n        write_item(8'ha1);", "        read_item();\n" + additional_reads + "\n        write_item(8'ha1);")
        )
