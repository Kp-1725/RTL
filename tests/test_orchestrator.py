import json
import tempfile
import unittest
from pathlib import Path

from orchestrator.orchestrator import Orchestrator


class OrchestratorTests(unittest.TestCase):
    def test_baseline_workflow_runs_and_writes_report(self) -> None:
        specification = (
            "An 8-bit FIFO with depth 4. It must have synchronous reset, write enable, "
            "read enable, data input, data output, full and empty flags. Prevent overflow "
            "and underflow, handle simultaneous read/write, and test reset during operation."
        )
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = Orchestrator().run(specification, temporary_directory)

            self.assertEqual(result.iteration, 1)
            self.assertEqual(result.simulation.status, "PASS")
            self.assertTrue(result.rtl_path.is_file())
            self.assertTrue(result.testbench_path.is_file())
            self.assertTrue(result.report_path.is_file())
            self.assertIn("coverage", result.stopping_reason.lower())
            self.assertTrue(Path(temporary_directory, "iteration_001", "simulation", "result.json").is_file())
            self.assertGreaterEqual(result.duration_seconds, 0)
            self.assertTrue(result.started_at.endswith("+00:00"))
            self.assertTrue(result.history[0].completed_at.endswith("+00:00"))
            report = json.loads(result.report_path.read_text(encoding="utf-8"))
            self.assertIn("duration_seconds", report)
            self.assertIn("started_at", report["iterations"][0])
            trace_path = Path(temporary_directory, "agent_trace.jsonl")
            self.assertTrue(trace_path.is_file())
            events = [json.loads(line) for line in trace_path.read_text(encoding="utf-8").splitlines()]
            agents = {event["agent"] for event in events}
            self.assertTrue({"orchestrator", "requirement_agent", "rtl_agent", "test_agent", "simulator"}.issubset(agents))
            self.assertEqual(report["agent_trace_path"], str(trace_path))

    def test_workflow_report_includes_panel_ready_summary(self) -> None:
        specification = (
            "An 8-bit FIFO with depth 4. It must have synchronous reset, write enable, "
            "read enable, data input, data output, full and empty flags. Prevent overflow "
            "and underflow, handle simultaneous read/write, and test reset during operation."
        )
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = Orchestrator().run(specification, temporary_directory)
            self.assertTrue(result.story_summary)
            self.assertIn("agentic", result.story_summary.lower())
            report_payload = json.loads(result.report_path.read_text(encoding="utf-8"))
            self.assertIn("panel_summary", report_payload)
            self.assertIn("demo_highlights", report_payload)

    def test_workflow_tracks_explicit_agentic_state(self) -> None:
        specification = (
            "An 8-bit FIFO with depth 4. It must have synchronous reset, write enable, "
            "read enable, data input, data output, full and empty flags. Prevent overflow "
            "and underflow, handle simultaneous read/write, and test reset during operation."
        )
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = Orchestrator().run(specification, temporary_directory)
            self.assertTrue(result.agent_state.plan)
            self.assertIn("generate_rtl", " ".join(result.agent_state.plan))
            self.assertIn("summarize", result.agent_state.phase)
            self.assertTrue(result.agent_state.next_action)


if __name__ == "__main__":
    unittest.main()
