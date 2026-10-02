import tempfile
import unittest
from pathlib import Path

from agents.coverage_agent import CoverageAgent
from agents.debug_agent import DebugAgent
from agents.requirement_agent import RequirementAgent
from agents.requirement_agent import Requirements
from simulator.simulator import SimulationResult


class AnalysisAgentTests(unittest.TestCase):
    def setUp(self) -> None:
        self.requirements = RequirementAgent().extract("An 8-bit FIFO with depth 4.")

    def test_coverage_is_labeled_as_derived(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            testbench = Path(temporary_directory, "tb.sv")
            testbench.write_text("read_item(); 8'h11 8'h21 8'h24 8'hff rst = 1'b1; wr_en = 1'b1; rd_en = 1'b1", encoding="utf-8")
            result = CoverageAgent().analyze(self.requirements, testbench, Path(temporary_directory, "coverage.json"))
            self.assertEqual(result.measurement_type, "derived_test_scenario")
            self.assertLess(result.percentage, 100)
            self.assertTrue(result.coverage_path.is_file())

    def test_coverage_reports_all_3_coverage_types(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            testbench = Path(temporary_directory, "tb.sv")
            testbench.write_text(
                "read_item(); 8'h11 8'h21 8'h24 8'hff rst = 1'b1; wr_en = 1'b1; rd_en = 1'b1",
                encoding="utf-8",
            )
            result = CoverageAgent().analyze(self.requirements, testbench, Path(temporary_directory, "coverage.json"))
            self.assertEqual(set(result.coverage_breakdown.keys()), {"functional", "code", "assertion"})
            self.assertEqual(result.coverage_breakdown["functional"]["status"], "measured")
            self.assertEqual(result.coverage_breakdown["code"]["status"], "not_measured")
            self.assertEqual(result.coverage_breakdown["assertion"]["status"], "not_measured")

    def test_coverage_merges_verilator_code_and_assertion_measurements(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            testbench = Path(temporary_directory, "tb.sv")
            testbench.write_text("read_item(); 8'h11", encoding="utf-8")
            result = CoverageAgent().analyze(
                self.requirements,
                testbench,
                Path(temporary_directory, "coverage.json"),
                code_coverage={
                    "status": "measured",
                    "tool": "verilator",
                    "percentage": 88.0,
                    "metrics": {
                        "line": {"percentage": 90.0},
                        "branch": {"percentage": 80.0},
                        "assertion": {"percentage": 100.0},
                    },
                },
            )
            self.assertEqual(result.coverage_breakdown["code"]["status"], "measured")
            self.assertEqual(result.coverage_breakdown["assertion"]["status"], "measured")
            self.assertEqual(result.coverage_breakdown["assertion"]["percentage"], 100.0)

    def test_debug_agent_preserves_compiler_evidence(self) -> None:
        simulation = SimulationResult(1, None, "", "syntax error", "", "", ("iverilog",), ("vvp",), Path("logs"), Path("sim.vvp"), "FAIL")
            
        analysis = DebugAgent().analyze("rtl.sv", "tb.sv", simulation)
        self.assertEqual(analysis.failure_type, "compilation")
        self.assertIn("syntax error", analysis.evidence)

    def test_generic_functional_coverage_uses_prompt_scenario_markers(self) -> None:
        requirements = Requirements(
            module_name="counter",
            scenarios=["reset", "overflow"],
            assertions=["bounded_count"],
        )
        with tempfile.TemporaryDirectory() as temporary_directory:
            testbench = Path(temporary_directory, "tb_counter.sv")
            testbench.write_text(
                "// SCENARIO: reset\n// SCENARIO: overflow\n// ASSERTION: bounded_count\n",
                encoding="utf-8",
            )
            result = CoverageAgent().analyze(requirements, testbench, Path(temporary_directory, "coverage.json"))
            self.assertEqual(result.coverage_breakdown["functional"]["status"], "measured")
            self.assertEqual(result.coverage_breakdown["functional"]["percentage"], 100.0)


if __name__ == "__main__":
    unittest.main()
