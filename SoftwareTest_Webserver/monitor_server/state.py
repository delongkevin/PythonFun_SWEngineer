import json
import re
import threading
from copy import deepcopy
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, List


def iso_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def sanitize_node_id(value: str) -> str:
    sanitized = re.sub(r"[^a-zA-Z0-9_-]+", "-", value.strip().lower()).strip("-")
    return sanitized or "node"


def parse_iso(value: str | None) -> datetime | None:
    if not value:
        return None
    try:
        return datetime.fromisoformat(value)
    except ValueError:
        return None


def default_report_summary() -> Dict[str, Any]:
    return {
        "total": 0,
        "pass": 0,
        "fail": 0,
        "not_executed": 0,
        "unknown": 0,
        "pass_rate": 0.0,
        "paths_scanned": 0,
    }


class StateStore:
    def __init__(self, state_file: Path, stale_after_seconds: int = 180) -> None:
        self.state_file = state_file
        self.stale_after_seconds = stale_after_seconds
        self._lock = threading.Lock()
        self._state: Dict[str, Any] = {"nodes": {}}
        self.state_file.parent.mkdir(parents=True, exist_ok=True)
        self._load()

    def _load(self) -> None:
        if not self.state_file.exists():
            return
        with self.state_file.open("r", encoding="utf-8") as handle:
            self._state = json.load(handle)
        self._state.setdefault("nodes", {})

    def _save(self) -> None:
        temp_file = self.state_file.with_suffix(".tmp")
        with temp_file.open("w", encoding="utf-8") as handle:
            json.dump(self._state, handle, indent=2, sort_keys=True)
        temp_file.replace(self.state_file)

    def _resolve_status(self, last_seen: str | None) -> str:
        seen_at = parse_iso(last_seen)
        if seen_at is None:
            return "offline"
        age_seconds = (datetime.now(timezone.utc) - seen_at).total_seconds()
        if age_seconds <= self.stale_after_seconds:
            return "online"
        if age_seconds <= self.stale_after_seconds * 3:
            return "stale"
        return "offline"

    def _decorate(self, node: Dict[str, Any]) -> Dict[str, Any]:
        hydrated = deepcopy(node)
        summary = deepcopy(hydrated.get("report_summary") or default_report_summary())
        hydrated["report_summary"] = summary
        hydrated["status"] = self._resolve_status(hydrated.get("last_seen"))
        return hydrated

    def _merge_registration(self, existing: Dict[str, Any], payload: Dict[str, Any]) -> Dict[str, Any]:
        now = iso_now()
        return {
            "node_id": payload["node_id"],
            "display_name": payload.get("display_name") or existing.get("display_name") or payload["node_id"],
            "rdp_host": payload.get("rdp_host") or existing.get("rdp_host") or "",
            "description": payload.get("description") or existing.get("description") or "",
            "tags": payload.get("tags") or existing.get("tags") or [],
            "host": payload.get("host") or existing.get("host") or {},
            "agent_version": payload.get("agent_version") or existing.get("agent_version"),
            "report_roots": payload.get("report_roots") or existing.get("report_roots") or [],
            "report_summary": existing.get("report_summary") or default_report_summary(),
            "report_details": existing.get("report_details") or [],
            "applications": existing.get("applications") or [],
            "serial_ports": existing.get("serial_ports") or [],
            "created_at": existing.get("created_at") or now,
            "updated_at": now,
            "last_seen": existing.get("last_seen"),
            "last_heartbeat": existing.get("last_heartbeat"),
        }

    def register_node(self, payload: Dict[str, Any]) -> Dict[str, Any]:
        with self._lock:
            requested_id = payload.get("node_id") or payload.get("display_name") or "node"
            node_id = sanitize_node_id(requested_id)
            payload = {**payload, "node_id": node_id}
            existing = self._state["nodes"].get(node_id, {})
            self._state["nodes"][node_id] = self._merge_registration(existing, payload)
            self._save()
            return self._decorate(self._state["nodes"][node_id])

    def update_heartbeat(self, node_id: str, payload: Dict[str, Any]) -> Dict[str, Any]:
        with self._lock:
            node_id = sanitize_node_id(node_id)
            existing = self._state["nodes"].get(node_id)
            if existing is None:
                existing = self._merge_registration({}, {"node_id": node_id, "display_name": node_id})

            now = iso_now()
            existing.update(
                {
                    "host": payload.get("host") or existing.get("host") or {},
                    "rdp_host": payload.get("rdp_host") or existing.get("rdp_host") or "",
                    "agent_version": payload.get("agent_version") or existing.get("agent_version"),
                    "applications": payload.get("applications") or [],
                    "serial_ports": payload.get("serial_ports") or [],
                    "report_roots": payload.get("report_roots") or existing.get("report_roots") or [],
                    "report_summary": payload.get("report_summary") or default_report_summary(),
                    "report_details": payload.get("report_details") or [],
                    "updated_at": now,
                    "last_seen": payload.get("captured_at") or now,
                    "last_heartbeat": now,
                }
            )
            self._state["nodes"][node_id] = existing
            self._save()
            return self._decorate(existing)

    def get_node(self, node_id: str) -> Dict[str, Any] | None:
        with self._lock:
            node = self._state["nodes"].get(sanitize_node_id(node_id))
            return self._decorate(node) if node else None

    def list_nodes(self) -> List[Dict[str, Any]]:
        with self._lock:
            nodes = [self._decorate(node) for node in self._state["nodes"].values()]
        return sorted(nodes, key=lambda item: item.get("display_name", item["node_id"]).lower())

    def summary(self) -> Dict[str, Any]:
        nodes = self.list_nodes()
        totals = {
            "total_nodes": len(nodes),
            "online_nodes": 0,
            "stale_nodes": 0,
            "offline_nodes": 0,
            "applications_running": 0,
            "applications_total": 0,
            "connected_serial_ports": 0,
            "report_totals": default_report_summary(),
        }
        for node in nodes:
            status = node.get("status", "offline")
            if status == "online":
                totals["online_nodes"] += 1
            elif status == "stale":
                totals["stale_nodes"] += 1
            else:
                totals["offline_nodes"] += 1

            applications = node.get("applications") or []
            totals["applications_total"] += len(applications)
            totals["applications_running"] += sum(1 for app in applications if app.get("running"))
            totals["connected_serial_ports"] += len(node.get("serial_ports") or [])

            report_summary = node.get("report_summary") or {}
            for key in ("total", "pass", "fail", "not_executed", "unknown", "paths_scanned"):
                totals["report_totals"][key] += int(report_summary.get(key, 0) or 0)

        executed = totals["report_totals"]["pass"] + totals["report_totals"]["fail"]
        totals["report_totals"]["pass_rate"] = round(
            (totals["report_totals"]["pass"] / executed) * 100, 1
        ) if executed else 0.0
        return totals
