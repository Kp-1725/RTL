"""Analyze compiler and simulation failures without modifying RTL automatically."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

from simulator.simulator import SimulationResult


@dataclass(frozen=True)
class DebugAnalysis:
    failure_type: str
    likely_owner: str
    summary: str
    root_cause: str
    proposed_action: str
    evidence: str


class DebugAgent:
    """Produce traceable failure analysis from actual runner output."""

    def analyze(
        self,
        rtl_path: str | Path,
        testbench_path: str | Path,
        simulation: SimulationResult,
    ) -> DebugAnalysis:
        compiler_output = "\n".join((simulation.compile_stdout, simulation.compile_stderr)).strip()
        simulation_output = simulation.output.strip()
        if simulation.compile_returncode != 0:
            return DebugAnalysis(
                failure_type="compilation",
                likely_owner="rtl_or_testbench",
                summary="Icarus rejected the source files before simulation started.",
                root_cause="The compiler returned a non-zero status.",
                proposed_action="Inspect compile.log and create a new RTL or testbench iteration; do not overwrite the failed files.",
                evidence=compiler_output,
            )
        if simulation.timed_out:
            return DebugAnalysis(
                failure_type="simulation_timeout",
                likely_owner="rtl_or_testbench",
                summary="The simulator exceeded its configured timeout.",
                root_cause="The testbench did not terminate within the allowed time.",
                proposed_action="Inspect simulation.log for the last activity and add a bounded test or correct the RTL control flow.",
                evidence=simulation_output,
            )
        return DebugAnalysis(
            failure_type="simulation_assertion",
            likely_owner="rtl_or_testbench",
            summary="The simulation ran but reported a failure.",
            root_cause="A self-checking testbench assertion or fatal condition was triggered.",
            proposed_action="Compare expected and actual values in simulation.log, then generate a new corrective iteration.",
            evidence=simulation_output,
        )
