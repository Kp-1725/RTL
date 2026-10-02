"""Append auditable, timestamped agent events to a local JSONL trace."""

from __future__ import annotations

import json
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


def append_trace(path: str | Path | None, agent: str, event: str, **details: Any) -> None:
    """Persist visible prompts, outputs, evidence, and decisions; never credentials."""
    if path is None:
        return
    trace_path = Path(path)
    trace_path.parent.mkdir(parents=True, exist_ok=True)
    record = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "agent": agent,
        "event": event,
        **details,
    }
    with trace_path.open("a", encoding="utf-8") as trace_file:
        trace_file.write(json.dumps(record, ensure_ascii=False, default=str) + "\n")