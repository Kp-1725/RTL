import tempfile
import unittest
from pathlib import Path

from agents.requirement_agent import RequirementAgent
from agents.test_agent import TestAgent


class CliAndTargetedTests(unittest.TestCase):
    def test_targeted_testbench_is_separate_and_versioned(self) -> None:
        requirements = RequirementAgent().extract("An 8-bit FIFO with depth 4.")
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = TestAgent().generate_targeted(
                requirements,
                temporary_directory,
                ["full_and_overflow"],
            )
            source = result.testbench_path.read_text(encoding="utf-8")
            self.assertTrue(result.testbench_path.is_file())
            self.assertIn("Targeted scenarios: full_and_overflow", source)
            self.assertIn("module tb_fifo_targeted", source)
            self.assertTrue(Path(temporary_directory, "targeted_tests").is_dir())


if __name__ == "__main__":
    unittest.main()
