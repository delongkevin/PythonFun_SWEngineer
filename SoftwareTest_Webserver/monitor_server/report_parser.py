import json
import re
import xml.etree.ElementTree as ET
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, Iterator, List

STATUS_MAP = {
    "pass": "pass",
    "passed": "pass",
    "success": "pass",
    "ok": "pass",
    "completed": "pass",
    "fail": "fail",
    "failed": "fail",
    "failure": "fail",
    "error": "fail",
    "aborted": "fail",
    "not executed": "not_executed",
    "not_executed": "not_executed",
    "not run": "not_executed",
    "notrun": "not_executed",
    "skipped": "not_executed",
    "skip": "not_executed",
}
SUPPORTED_SUFFIXES = {".json", ".xml", ".txt", ".log", ".csv"}


def _iso_from_timestamp(value: float) -> str:
    return datetime.fromtimestamp(value, tz=timezone.utc).isoformat()


def normalize_status(value: str | None) -> str | None:
    if value is None:
        return None
    normalized = re.sub(r"\s+", " ", value.strip().lower())
    return STATUS_MAP.get(normalized)


def iter_scalar_strings(value: Any) -> Iterator[str]:
    if isinstance(value, dict):
        for key, nested in value.items():
            yield str(key)
            yield from iter_scalar_strings(nested)
    elif isinstance(value, list):
        for item in value:
            yield from iter_scalar_strings(item)
    elif isinstance(value, (str, int, float, bool)):
        yield str(value)


def status_from_text(text: str) -> str | None:
    lowered = text.lower()
    patterns = [
        (r"\b(fail|failed|failure|error|aborted)\b", "fail"),
        (r"\b(not executed|not run|notrun|skipped|skip)\b", "not_executed"),
        (r"\b(pass|passed|success|ok|completed)\b", "pass"),
    ]
    for pattern, status in patterns:
        if re.search(pattern, lowered):
            return status
    return None


def status_from_json(path: Path) -> str | None:
    with path.open("r", encoding="utf-8", errors="ignore") as handle:
        data = json.load(handle)

    priority: List[str] = []
    for scalar in iter_scalar_strings(data):
        status = normalize_status(scalar)
        if status:
            priority.append(status)
            continue
        status = status_from_text(scalar)
        if status:
            priority.append(status)

    if "fail" in priority:
        return "fail"
    if "not_executed" in priority:
        return "not_executed"
    if "pass" in priority:
        return "pass"
    return None


def status_from_xml(path: Path) -> str | None:
    tree = ET.parse(path)
    root = tree.getroot()
    candidates = [root.tag]
    candidates.extend(root.attrib.values())
    candidates.extend(root.itertext())
    for candidate in candidates:
        normalized = normalize_status(str(candidate))
        if normalized:
            return normalized
        inferred = status_from_text(str(candidate))
        if inferred:
            return inferred
    return None


def status_from_plaintext(path: Path) -> str | None:
    with path.open("r", encoding="utf-8", errors="ignore") as handle:
        text = handle.read(32768)
    return status_from_text(text)


def analyze_report_file(path: Path, source_root: Path) -> Dict[str, Any] | None:
    if path.suffix.lower() not in SUPPORTED_SUFFIXES:
        return None

    status = status_from_text(path.name)
    if status is None:
        try:
            if path.suffix.lower() == ".json":
                status = status_from_json(path)
            elif path.suffix.lower() == ".xml":
                status = status_from_xml(path)
            else:
                status = status_from_plaintext(path)
        except (OSError, json.JSONDecodeError, ET.ParseError, UnicodeDecodeError):
            status = None

    return {
        "name": path.name,
        "path": str(path),
        "source_root": str(source_root),
        "status": status or "unknown",
        "modified_at": _iso_from_timestamp(path.stat().st_mtime),
    }


def scan_report_roots(report_roots: Iterable[str | Path], limit: int = 20) -> Dict[str, Any]:
    reports: List[Dict[str, Any]] = []
    roots_scanned = 0
    for raw_root in report_roots:
        root = Path(raw_root).expanduser()
        if not root.exists() or not root.is_dir():
            continue
        roots_scanned += 1
        for path in root.rglob("*"):
            if not path.is_file():
                continue
            report = analyze_report_file(path, root)
            if report is not None:
                reports.append(report)

    reports.sort(key=lambda item: item["modified_at"], reverse=True)
    summary = {
        "total": len(reports),
        "pass": sum(1 for report in reports if report["status"] == "pass"),
        "fail": sum(1 for report in reports if report["status"] == "fail"),
        "not_executed": sum(1 for report in reports if report["status"] == "not_executed"),
        "unknown": sum(1 for report in reports if report["status"] == "unknown"),
        "paths_scanned": roots_scanned,
    }
    executed = summary["pass"] + summary["fail"]
    summary["pass_rate"] = round((summary["pass"] / executed) * 100, 1) if executed else 0.0
    return {"summary": summary, "reports": reports[:limit]}
