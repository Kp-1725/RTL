"""Command-line entry point for the agentic RTL prototype."""

from __future__ import annotations

import argparse
from pathlib import Path

from orchestrator.orchestrator import Orchestrator


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Run the agentic RTL design workflow")
    parser.add_argument("--spec", required=True, type=Path, help="Natural-language specification file")
    parser.add_argument("--output", required=True, type=Path, help="Directory for iteration artifacts")
    parser.add_argument("--max-iterations", type=int, default=3)
    parser.add_argument(
        "--inject-fault",
        nargs="+",
        choices=["invert_first_comparison", "broken_full_flag"],
        default=None,
        help="Inject one or more RTL mutations, e.g. --inject-fault broken_full_flag invert_first_comparison",
    )
    parser.add_argument(
        "--coverage-tool",
        choices=["icarus", "verilator"],
        default="icarus",
        help="Simulation backend; Verilator enables real line/branch/toggle coverage through WSL2",
    )
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--use-llm", action="store_true", help="Use the configured OpenAI-compatible agents (default)")
    mode.add_argument(
        "--offline-fifo",
        action="store_true",
        help="Use the legacy deterministic FIFO fallback; arbitrary modules require --use-llm",
    )
    return parser


def main() -> int:
    args = build_parser().parse_args()
    specification = args.spec.read_text(encoding="utf-8")
    result = Orchestrator().run(
        specification,
        args.output,
        max_iterations=args.max_iterations,
        use_llm=not args.offline_fifo,
        inject_fault=args.inject_fault,
        coverage_tool=args.coverage_tool,
    )
    print(f"Iterations: {len(result.history)}")
    print(f"Stopping reason: {result.stopping_reason}")
    if result.simulation:
        print(f"Final simulation: {result.simulation.status}")
    print(f"Started at (UTC): {result.started_at}")
    print(f"Completed at (UTC): {result.completed_at}")
    print(f"Total duration: {result.duration_seconds:.3f} seconds")
    for item in result.history:
        print(
            f"Iteration {item.iteration}: {item.started_at} -> {item.completed_at} "
            f"({item.duration_seconds:.3f} seconds)"
        )
    print(f"JSON report: {result.report_path}")
    print(f"HTML report: {result.report_path.with_suffix('.html')}")
    print(f"Agent trace: {result.report_path.parent / 'agent_trace.jsonl'}")
    return 0 if result.simulation and result.simulation.passed else 1


if __name__ == "__main__":
    raise SystemExit(main())
