import unittest

from agents.requirement_agent import (
    RequirementAgent,
    RequirementAgentError,
    Requirements,
)


FIFO_SPECIFICATION = """
An 8-bit FIFO with depth 4 must use synchronous reset, write enable, read enable,
data input, data output, full and empty flags. It must prevent overflow and
underflow, handle simultaneous read/write, and test reset during operation.
"""


class FakeLlmClient:
    def __init__(self, response: str) -> None:
        self.response = response

    def complete(self, prompt: str) -> str:
        self.prompt = prompt
        return self.response


class RequirementAgentTests(unittest.TestCase):
    def test_fifo_specification_extracts_required_contract(self) -> None:
        requirements = RequirementAgent().extract(FIFO_SPECIFICATION)

        self.assertIsInstance(requirements, Requirements)
        self.assertEqual(requirements.module_name, "fifo")
        self.assertEqual(requirements.parameters["DATA_WIDTH"], 8)
        self.assertEqual(requirements.parameters["DEPTH"], 4)
        self.assertEqual(
            {port.name for port in requirements.inputs},
            {"clk", "rst", "wr_en", "rd_en", "data_in"},
        )
        self.assertEqual(
            {port.name for port in requirements.outputs},
            {"data_out", "full", "empty"},
        )
        all_requirements = " ".join(requirements.functional_requirements).lower()
        self.assertIn("simultaneous", all_requirements)
        self.assertIn("not full", all_requirements)

    def test_16_bit_fifo_specification_preserves_data_width(self) -> None:
        requirements = RequirementAgent().extract("Build a 16-bit FIFO with depth 4.")

        self.assertEqual(requirements.parameters["DATA_WIDTH"], 16)
        self.assertEqual(next(port for port in requirements.inputs if port.name == "data_in").width, "16")
        self.assertEqual(next(port for port in requirements.outputs if port.name == "data_out").width, "16")

    def test_malformed_llm_json_is_rejected(self) -> None:
        agent = RequirementAgent(FakeLlmClient("not json"))

        with self.assertRaises(RequirementAgentError):
            agent.extract(FIFO_SPECIFICATION, use_llm=True)

    def test_valid_fenced_llm_json_is_validated(self) -> None:
        response = """```json
        {
          "module_name": "counter",
          "inputs": [],
          "outputs": [],
          "parameters": {},
          "functional_requirements": ["Count"],
          "corner_cases": [],
          "verification_requirements": [],
          "coverage_targets": {"functional_requirements": 100}
        }
        ```"""
        agent = RequirementAgent(FakeLlmClient(response))

        requirements = agent.extract("Build a counter.", use_llm=True)

        self.assertEqual(requirements.module_name, "counter")
        self.assertIn("Natural-language specification", agent.llm_client.prompt)

    def test_non_fifo_offline_specification_is_rejected(self) -> None:
        with self.assertRaises(RequirementAgentError):
            RequirementAgent().extract("Build an arithmetic unit.")


if __name__ == "__main__":
    unittest.main()
