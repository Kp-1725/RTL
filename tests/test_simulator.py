import tempfile
import unittest
from pathlib import Path

from simulator.simulator import IcarusSimulator, SimulatorError
from simulator.verilator import VerilatorSimulator


REPOSITORY_ROOT = Path(__file__).resolve().parents[1]
REFERENCE_DIR = REPOSITORY_ROOT / "designs" / "fifo" / "reference"
RTL_PATH = REFERENCE_DIR / "fifo.sv"
TESTBENCH_PATH = REFERENCE_DIR / "tb_fifo.sv"


class IcarusSimulatorTests(unittest.TestCase):
    def test_reference_fifo_passes_and_writes_logs(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            result = IcarusSimulator(timeout_seconds=30).run(
                [RTL_PATH],
                [TESTBENCH_PATH],
                temporary_directory,
            )

            self.assertTrue(result.passed)
            self.assertEqual(result.compile_returncode, 0)
            self.assertEqual(result.simulation_returncode, 0)
            self.assertIn("PASS: FIFO reference tests completed", result.output)
            self.assertTrue(Path(temporary_directory, "compile.log").is_file())
            self.assertTrue(Path(temporary_directory, "simulation.log").is_file())
            self.assertTrue(Path(temporary_directory, "result.json").is_file())

    def test_missing_source_is_rejected(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            with self.assertRaises(SimulatorError):
                IcarusSimulator().run(
                    [Path(temporary_directory, "missing.sv")],
                    [TESTBENCH_PATH],
                    temporary_directory,
                )

    def test_compile_failure_is_returned_and_logged(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            invalid_rtl = Path(temporary_directory, "invalid.sv")
            invalid_rtl.write_text("module invalid( ;\n", encoding="utf-8")

            result = IcarusSimulator().run(
                [invalid_rtl],
                [TESTBENCH_PATH],
                temporary_directory,
            )

            self.assertTrue(result.failed)
            self.assertNotEqual(result.compile_returncode, 0)
            self.assertIsNone(result.simulation_returncode)
            self.assertTrue(Path(temporary_directory, "compile.log").is_file())
            self.assertTrue(Path(temporary_directory, "result.json").is_file())


class VerilatorCoverageTests(unittest.TestCase):
    def test_verilator_database_parser_reports_real_code_metrics(self) -> None:
        with tempfile.TemporaryDirectory() as temporary_directory:
            coverage_path = Path(temporary_directory, "coverage.dat")
            coverage_path.write_bytes(
                b"# SystemC::Coverage-3\n"
                b"C 'x page\x02v_line/fifo' 4\n"
                b"C 'x page\x02v_line/fifo' 0\n"
                b"C 'x page\x02v_branch/fifo' 2\n"
                b"C 'x page\x02v_toggle/fifo' 0\n"
                b"C 'x page\x02v_assert/fifo' 1\n"
            )

            result = VerilatorSimulator.parse_coverage_database(coverage_path)

            self.assertEqual(result["status"], "measured")
            self.assertEqual(result["tool"], "verilator")
            self.assertEqual(result["metrics"]["line"]["percentage"], 50.0)
            self.assertEqual(result["metrics"]["branch"]["percentage"], 100.0)
            self.assertEqual(result["metrics"]["toggle"]["percentage"], 0.0)
            self.assertEqual(result["metrics"]["assert"]["percentage"], 100.0)
            self.assertEqual(result["metrics"]["assertion"]["percentage"], 100.0)

if __name__ == "__main__":
    unittest.main()
