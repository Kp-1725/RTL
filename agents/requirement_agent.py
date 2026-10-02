"""Requirement extraction with validated output and optional LLM support."""

from __future__ import annotations

import json
import os
import re
from pathlib import Path
from typing import Any
from urllib import error, request

from dotenv import load_dotenv
from pydantic import BaseModel, ConfigDict, Field, ValidationError

from agents.trace import append_trace


class Port(BaseModel):
    model_config = ConfigDict(extra="forbid")

    name: str
    direction: str
    width: str = "1"
    description: str = ""


class Requirements(BaseModel):
    model_config = ConfigDict(extra="forbid")

    module_name: str
    inputs: list[Port] = Field(default_factory=list)
    outputs: list[Port] = Field(default_factory=list)
    parameters: dict[str, int | str] = Field(default_factory=dict)
    functional_requirements: list[str] = Field(default_factory=list)
    corner_cases: list[str] = Field(default_factory=list)
    verification_requirements: list[str] = Field(default_factory=list)
    scenarios: list[str] = Field(default_factory=list)
    assertions: list[str] = Field(default_factory=list)
    coverage_targets: dict[str, int | float | str] = Field(default_factory=dict)


class RequirementAgentError(RuntimeError):
    """Raised when requirement extraction or LLM communication fails."""


class OpenAICompatibleClient:
    """Small dependency-free client for OpenAI-compatible chat endpoints."""

    def __init__(
        self,
        api_key: str,
        model_name: str,
        base_url: str,
        timeout_seconds: float = 300.0,
    ) -> None:
        if timeout_seconds <= 0:
            raise ValueError("timeout_seconds must be greater than zero")
        self.api_key = api_key
        self.model_name = model_name
        self.base_url = base_url.rstrip("/")
        self.timeout_seconds = timeout_seconds

    def complete(self, prompt: str) -> str:
        payload = json.dumps(
            {
                "model": self.model_name,
                "messages": [
                    {"role": "system", "content": "Return only valid JSON."},
                    {"role": "user", "content": prompt},
                ],
                "temperature": 0,
            }
        ).encode("utf-8")
        endpoint = f"{self.base_url}/chat/completions"
        http_request = request.Request(
            endpoint,
            data=payload,
            headers={
                "Authorization": f"Bearer {self.api_key}",
                "Content-Type": "application/json",
            },
            method="POST",
        )
        try:
            with request.urlopen(http_request, timeout=self.timeout_seconds) as response:
                response_data = json.loads(response.read().decode("utf-8"))
        except error.HTTPError as exc:
            try:
                detail = exc.read().decode("utf-8", errors="replace")
            except OSError:
                detail = ""
            raise RequirementAgentError(
                f"LLM request failed with HTTP {exc.code} for model {self.model_name}: {detail or exc.reason}"
            ) from exc
        except (error.URLError, TimeoutError, json.JSONDecodeError) as exc:
            raise RequirementAgentError(f"LLM request failed: {exc}") from exc

        try:
            return response_data["choices"][0]["message"]["content"]
        except (KeyError, IndexError, TypeError) as exc:
            raise RequirementAgentError("LLM response did not contain chat content") from exc


class RequirementAgent:
    """Extract requirements deterministically or through an optional LLM client."""

    def __init__(self, llm_client: OpenAICompatibleClient | None = None) -> None:
        self.llm_client = llm_client
        self.prompt_template = self._load_prompt()

    @classmethod
    def from_environment(cls) -> "RequirementAgent":
        load_dotenv()
        api_key = os.getenv("OPENAI_API_KEY", "").strip()
        model_name = os.getenv("MODEL_NAME", "").strip()
        base_url = os.getenv("OPENAI_BASE_URL", "https://api.openai.com/v1").strip()
        timeout_seconds = float(os.getenv("LLM_TIMEOUT_SECONDS", "300"))
        if api_key and model_name:
            return cls(OpenAICompatibleClient(api_key, model_name, base_url, timeout_seconds))
        return cls()

    def extract(
        self,
        specification: str,
        *,
        use_llm: bool = False,
        trace_path: str | Path | None = None,
    ) -> Requirements:
        if not specification.strip():
            raise RequirementAgentError("Specification must not be empty")

        if use_llm:
            if self.llm_client is None:
                raise RequirementAgentError("LLM is not configured")
            prompt = self.prompt_template.replace("{{SPECIFICATION}}", specification)
            try:
                raw_response = self.llm_client.complete(prompt)
                requirements = self._parse_llm_response(raw_response)
            except Exception as exc:
                append_trace(trace_path, "requirement_agent", "generation_failed", prompt=prompt, error=str(exc))
                raise
            append_trace(
                trace_path,
                "requirement_agent",
                "generation_completed",
                prompt=prompt,
                response=raw_response,
                validated_requirements=requirements.model_dump(mode="json"),
            )
            return requirements

        requirements = self._extract_fifo_requirements(specification)
        append_trace(
            trace_path,
            "requirement_agent",
            "offline_extraction_completed",
            specification=specification,
            validated_requirements=requirements.model_dump(mode="json"),
        )
        return requirements

    @staticmethod
    def _load_prompt() -> str:
        prompt_path = Path(__file__).resolve().parents[1] / "prompts" / "requirement_prompt.txt"
        try:
            return prompt_path.read_text(encoding="utf-8")
        except OSError as exc:
            raise RequirementAgentError(f"Unable to load requirement prompt: {prompt_path}") from exc

    @staticmethod
    def _parse_llm_response(raw_response: str) -> Requirements:
        candidate = raw_response.strip()
        fenced = re.search(r"```(?:json)?\s*(.*?)```", candidate, re.DOTALL | re.IGNORECASE)
        if fenced:
            candidate = fenced.group(1).strip()
        try:
            data: Any = json.loads(candidate)
            return Requirements.model_validate(data)
        except (json.JSONDecodeError, ValidationError) as exc:
            raise RequirementAgentError(f"LLM returned malformed requirements: {exc}") from exc

    @staticmethod
    def _extract_fifo_requirements(specification: str) -> Requirements:
        lowered = specification.lower()
        if "fifo" not in lowered:
            raise RequirementAgentError(
                "Offline extraction currently supports the FIFO target only; configure an LLM for other designs"
            )

        width_match = re.search(r"(\d+)\s*[- ]?bit", lowered)
        data_width = int(width_match.group(1)) if width_match else 8
        depth_match = re.search(r"depth\s*(?:=|of)?\s*(\d+)", lowered)
        depth = int(depth_match.group(1)) if depth_match else 4
        return Requirements(
            module_name="fifo",
            inputs=[
                Port(name="clk", direction="input", description="Synchronous clock"),
                Port(name="rst", direction="input", description="Synchronous active-high reset"),
                Port(name="wr_en", direction="input", description="Write enable"),
                Port(name="rd_en", direction="input", description="Read enable"),
                Port(name="data_in", direction="input", width=str(data_width), description="Input data"),
            ],
            outputs=[
                Port(name="data_out", direction="output", width=str(data_width), description="Output data"),
                Port(name="full", direction="output", description="FIFO full flag"),
                Port(name="empty", direction="output", description="FIFO empty flag"),
            ],
            parameters={"DATA_WIDTH": data_width, "DEPTH": depth},
            functional_requirements=[
                f"Store {data_width}-bit data values in FIFO order.",
                f"Support a configurable FIFO depth of {depth}.",
                "Apply a synchronous reset that clears FIFO state and output data.",
                "Accept writes only when the FIFO is not full.",
                "Accept reads only when the FIFO is not empty.",
                "Assert full when the FIFO contains its configured depth.",
                "Assert empty when the FIFO contains no entries.",
                "Support simultaneous accepted read and write operations.",
            ],
            corner_cases=[
                "Read from an empty FIFO without changing state.",
                "Write to a full FIFO without changing stored data.",
                "Fill the FIFO to capacity.",
                "Drain the FIFO to empty.",
                "Assert reset while the FIFO contains data.",
            ],
            verification_requirements=[
                "Verify FIFO ordering with multiple writes and reads.",
                "Verify full and empty flags at their boundaries.",
                "Verify overflow and underflow prevention.",
                "Verify simultaneous read/write behavior.",
                "Verify reset during active operation.",
            ],
            scenarios=[
                "empty_underflow",
                "single_write_read",
                "full_and_overflow",
                "drain_to_empty",
                "simultaneous_read_write",
                "reset_during_operation",
            ],
            assertions=[
                "full_and_empty_are_mutually_exclusive",
                "read_does_not_change_empty_fifo",
                "write_does_not_change_full_fifo",
            ],
            coverage_targets={
                "functional_requirements": 100,
                "corner_cases": 100,
                "statement_coverage": "tool-measured",
                "branch_coverage": "tool-measured",
            },
        )
