import json
import tempfile
import unittest
from pathlib import Path

from agents.requirement_agent import RequirementAgent
from agents.rtl_agent import RtlAgent, RtlAgentError


class FakeRtlClient:
    def __init__(self, response: str) -> None:
        self.response = response

    def complete(self, prompt: str) -> str:
        self.prompt = prompt
        return self.response


class RtlAgentTests(unittest.TestCase):
    def setUp(self) -> None:
        self.requirements = RequirementAgent().extract(
            "An 8-bit FIFO with depth 4, synchronous reset, read/write enables, full and empty flags."
        )

    def test_deterministic_fifo_rtl_is_valid_and_versioned(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = RtlAgent().generate(self.requirements, temporary_directory, iteration=1)

            self.assertTrue(result.valid)
            self.assertEqual(result.compiler_returncode, 0)
            self.assertTrue(result.rtl_path.is_file())
            self.assertTrue(result.validation_log.is_file())
            self.assertTrue(Path(temporary_directory, "iteration_001", "metadata.json").is_file())

    def test_existing_iteration_is_never_overwritten(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            agent = RtlAgent()
            agent.generate(self.requirements, temporary_directory, iteration=1)
            with self.assertRaises(RtlAgentError):
                agent.generate(self.requirements, temporary_directory, iteration=1)

    def test_malformed_llm_rtl_is_rejected_before_validation(self) -> None:
        agent = RtlAgent(FakeRtlClient("This is not RTL"))
        with tempfile.TemporaryDirectory() as temporary_directory:
            with self.assertRaises(RtlAgentError):
                agent.generate(self.requirements, temporary_directory, use_llm=True)

    def test_debug_feedback_is_included_in_rtl_generation_prompt(self) -> None:
        source = RtlAgent._fifo_template(self.requirements)
        client = FakeRtlClient(source)
        agent = RtlAgent(client)
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = agent.generate(
                self.requirements,
                temporary_directory,
                use_llm=True,
                feedback={
                    "root_cause": "full asserted before DEPTH accepted writes",
                    "simulator_evidence": "FAIL: full mismatch",
                },
            )

        self.assertTrue(result.valid)
        self.assertIn("full asserted before DEPTH accepted writes", client.prompt)
        self.assertIn("FAIL: full mismatch", client.prompt)

    def test_generic_fault_injection_inverts_a_comparison(self) -> None:
        source = "module counter(input logic clk, output logic done); assign done = (clk == 1'b1); endmodule"
        mutated = RtlAgent._apply_fault(source, "invert_first_comparison")
        self.assertIn("clk != 1'b1", mutated)

    def test_multiple_faults_are_injected_and_recorded(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = RtlAgent().generate(
                self.requirements,
                temporary_directory,
                fault=["broken_full_flag", "invert_first_comparison"],
            )
            source = result.rtl_path.read_text(encoding="utf-8")
            metadata = json.loads(
                Path(temporary_directory, "iteration_001", "metadata.json").read_text(encoding="utf-8")
            )
            self.assertIn("assign full = (count != DEPTH - 1);", source)
            self.assertEqual(metadata["injected_faults"], ["broken_full_flag", "invert_first_comparison"])

    def test_interface_validation_rejects_wrong_module(self) -> None:
        source = "module other(input logic clk); endmodule"
        self.assertIn("module name", RtlAgent._validate_interface(source, self.requirements))


if __name__ == "__main__":
    unittest.main()
