import tempfile
import unittest
from pathlib import Path

from agents.requirement_agent import RequirementAgent
from agents.test_agent import TestAgent, TestAgentError


class FakeTestClient:
    def __init__(self, response: str) -> None:
        self.response = response

    def complete(self, prompt: str) -> str:
        self.prompt = prompt
        return self.response


class TestAgentTests(unittest.TestCase):
    def setUp(self) -> None:
        self.requirements = RequirementAgent().extract(
            "An 8-bit FIFO with depth 4, synchronous reset, read/write enables, full and empty flags."
        )

    def test_fifo_testbench_is_saved(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = TestAgent().generate(self.requirements, temporary_directory)
            source = result.testbench_path.read_text(encoding="utf-8")
            self.assertTrue(result.valid_source)
            self.assertIn("PASS:", source)
            self.assertIn("$dumpfile", source)
            self.assertTrue(result.testbench_path.is_file())

    def test_testbench_uses_variable_fifo_depth(self) -> None:
        requirements = RequirementAgent().extract("Build a 16-bit FIFO with depth 8.")

        with tempfile.TemporaryDirectory() as temporary_directory:
            result = TestAgent().generate(requirements, temporary_directory)
            source = result.testbench_path.read_text(encoding="utf-8")
            self.assertIn("logic [15:0] data_in, data_out;", source)
            self.assertIn("expected_queue.size() == 8", source)
            self.assertIn("write_item(8'h28);", source)

    def test_existing_testbench_is_not_overwritten(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            agent = TestAgent()
            agent.generate(self.requirements, temporary_directory)
            with self.assertRaises(TestAgentError):
                agent.generate(self.requirements, temporary_directory)

    def test_malformed_llm_testbench_is_rejected(self) -> None:
        agent = TestAgent(FakeTestClient("not a testbench"))
        with tempfile.TemporaryDirectory() as temporary_directory:
            with self.assertRaises(TestAgentError):
                agent.generate(self.requirements, temporary_directory, use_llm=True)

    def test_top_module_is_discovered_from_generated_source(self) -> None:
        self.assertEqual(TestAgent._extract_top_module("module tb_counter; endmodule"), "tb_counter")

    def test_vcd_dump_is_added_when_llm_testbench_omits_it(self) -> None:
        source = "module tb_counter; initial begin $display(\"PASS\"); $finish; end endmodule"
        instrumented = TestAgent._ensure_vcd_dump(source, "tb_counter")

        self.assertIn('$dumpfile("waveform.vcd")', instrumented)
        self.assertIn("$dumpvars(0, tb_counter)", instrumented)

    def test_existing_vcd_dump_is_preserved(self) -> None:
        source = 'module tb_counter; initial begin $dumpfile("custom.vcd"); $dumpvars(0, tb_counter); end endmodule'
        self.assertEqual(TestAgent._ensure_vcd_dump(source, "tb_counter"), source)

    def test_llm_testbench_contract_requires_prompt_markers(self) -> None:
        requirements = RequirementAgent().extract("An 8-bit FIFO with depth 4.")
        source = """
module tb_fifo;
    // SCENARIO: empty_underflow
    // SCENARIO: single_write_read
    // SCENARIO: full_and_overflow
    // SCENARIO: drain_to_empty
    // SCENARIO: simultaneous_read_write
    // SCENARIO: reset_during_operation
    // ASSERTION: full_and_empty_are_mutually_exclusive
    // ASSERTION: read_does_not_change_empty_fifo
    // ASSERTION: write_does_not_change_full_fifo
    fifo dut();
    initial begin $display("PASS"); $display("FAIL"); $finish; end
endmodule
"""
        TestAgent._validate_testbench(source, requirements, require_markers=True)

    def test_testbench_fatal_is_accepted_as_failure_path(self) -> None:
        requirements = RequirementAgent().extract("An 8-bit FIFO with depth 4.")
        source = "module tb_fifo; fifo dut(); initial begin if (1) $fatal(1, \"FAIL\"); $display(\"PASS\"); $finish; end endmodule"
        TestAgent._validate_testbench(source, requirements, require_markers=False)

    def test_testbench_assertion_is_accepted_as_failure_path(self) -> None:
        requirements = RequirementAgent().extract("An 8-bit FIFO with depth 4.")
        source = "module tb_fifo; fifo dut(); initial begin assert (dut.empty); $display(\"PASS\"); $finish; end endmodule"
        TestAgent._validate_testbench(source, requirements, require_markers=False)


if __name__ == "__main__":
    unittest.main()
