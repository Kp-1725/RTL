"""Measure explicitly labeled derived scenario coverage for the prototype."""

from __future__ import annotations

import json
import re
from dataclasses import dataclass
from pathlib import Path

from agents.requirement_agent import Requirements


@dataclass(frozen=True)
class CoverageResult:
    measurement_type: str
    percentage: float
    covered: list[str]
    uncovered: list[str]
    coverage_path: Path
    coverage_breakdown: dict[str, dict[str, object]]


class CoverageAgent:
    """Map requirements to observable testbench scenarios.

    This is derived scenario coverage, not statement or branch coverage. Icarus
    alone does not produce those code-coverage measurements.
    """

    def analyze(
        self,
        requirements: Requirements,
        testbench_path: str | Path,
        output_path: str | Path,
        *,
        code_coverage: dict[str, object] | None = None,
    ) -> CoverageResult:
        source = Path(testbench_path).read_text(encoding="utf-8").lower()
        if requirements.module_name == "fifo":
            scenarios = {
                "empty_underflow": "read_item();" in source,
                "single_write_read": "8'h11" in source,
                "full_and_overflow": all(token in source for token in ("8'h21", "8'h24", "8'hff")),
                "drain_to_empty": source.count("read_item();") >= 5,
                "simultaneous_read_write": "wr_en = 1'b1; rd_en = 1'b1" in source,
                "reset_during_operation": "rst = 1'b1" in source,
            }
        else:
            scenarios = {
                scenario: bool(
                    re.search(
                        rf"^\s*//\s*scenario:\s*{re.escape(scenario.lower())}\b",
                        source,
                        re.MULTILINE,
                    )
                )
                for scenario in requirements.scenarios
            }
        covered = [name for name, present in scenarios.items() if present]
        uncovered = [name for name, present in scenarios.items() if not present]
        percentage = round(100 * len(covered) / len(scenarios), 2) if scenarios else 0.0
        coverage_path = Path(output_path).resolve()
        coverage_path.parent.mkdir(parents=True, exist_ok=True)
        measured_code_metrics = {
            name: metric
            for name, metric in (code_coverage.get("metrics", {}) if code_coverage else {}).items()
            if name in {"line", "branch", "toggle"}
        }
        coverage_breakdown = {
            "functional": {
                "status": "measured" if scenarios else "not_measured",
                "type": "derived_test_scenario" if scenarios else "prompt_defined_scenarios_required",
                "percentage": percentage,
                "covered": covered,
                "uncovered": uncovered,
                "note": "Generated from explicit FIFO scenario checks in the testbench." if scenarios else "Generic designs require prompt-defined scenario markers before functional coverage can be measured.",
            },
            "code": {
                "status": "measured" if code_coverage and code_coverage.get("status") == "measured" else "not_measured",
                "type": "statement_branch",
                "percentage": code_coverage.get("percentage") if code_coverage else None,
                "covered": [],
                "uncovered": [],
                "metrics": measured_code_metrics,
                "tool": code_coverage.get("tool") if code_coverage else None,
                "note": "Measured by Verilator line, branch, and toggle instrumentation." if code_coverage and code_coverage.get("status") == "measured" else "No HDL coverage tool is configured, so statement/branch coverage is not measured.",
            },
            "assertion": {
                "status": "measured" if code_coverage and "assertion" in code_coverage.get("metrics", {}) else "not_measured",
                "type": "property_assertion",
                "percentage": code_coverage.get("metrics", {}).get("assertion", {}).get("percentage") if code_coverage else None,
                "covered": [],
                "uncovered": [],
                "metrics": {"assertion": code_coverage.get("metrics", {}).get("assertion")} if code_coverage and "assertion" in code_coverage.get("metrics", {}) else {},
                "tool": code_coverage.get("tool") if code_coverage else None,
                "note": "Measured by executable runtime assertion-monitor evaluations; Verilator supplies the code-coverage database." if code_coverage and "assertion" in code_coverage.get("metrics", {}) else "Assertion/property coverage was not emitted by the selected simulator.",
            },
        }
        payload = {
            "measurement_type": "derived_test_scenario",
            "tool": None,
            "percentage": percentage,
            "covered": covered,
            "uncovered": uncovered,
            "coverage_breakdown": coverage_breakdown,
            "note": "Functional scenarios, Verilator RTL code metrics, and runtime assertion metrics are reported separately.",
            "requirements": requirements.model_dump(mode="json"),
        }
        coverage_path.write_text(json.dumps(payload, indent=2) + "\n", encoding="utf-8")
        return CoverageResult(
            measurement_type="derived_test_scenario",
            percentage=percentage,
            covered=covered,
            uncovered=uncovered,
            coverage_path=coverage_path,
            coverage_breakdown=coverage_breakdown,
        )
