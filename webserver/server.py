"""
Local Web Server Dashboard
--------------------------
Serves a professional HTML dashboard for all applications in this repository.

Features:
  - Dashboard landing page with app cards
  - Real-time git-update monitoring via Server-Sent Events (SSE)
  - Background thread polls git every 30 s and auto-pulls latest changes
  - JSON API endpoints for programmatic access
  - Thread-safe design suitable for multiple concurrent users

Usage:
    pip install -r requirements.txt
    python server.py [--host 0.0.0.0] [--port 5000] [--no-auto-pull]
"""

import argparse
import json
import logging
import os
import queue
import subprocess
import sys
import threading
import time
from datetime import datetime, timezone
from typing import Any, Dict, Generator, List

from flask import Flask, Response, jsonify, render_template, stream_with_context

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

# ---------------------------------------------------------------------------
# Application registry
# Each entry describes one application in the repository.
# ---------------------------------------------------------------------------
APPS: List[Dict[str, Any]] = [
    {
        "id": "automotive_tester",
        "name": "Automotive ECU Tester",
        "icon": "bi-cpu",
        "badge": "Core",
        "badge_class": "bg-primary",
        "description": (
            "Comprehensive test-automation platform for automotive ECU validation. "
            "Integrates Lauterbach TRACE32, Vector CANoe, BK Precision power supply, "
            "USB camera, and up to four serial terminals in a unified Tkinter GUI."
        ),
        "path": "Automotive_Tester",
        "entry": "main.py",
        "readme": "Automotive_Tester/README.md",
        "tags": ["ECU", "TRACE32", "CANoe", "Power Supply", "Serial"],
        "requirements": "Automotive_Tester/requirements.txt",
    },
    {
        "id": "automotive_can_tester",
        "name": "Automotive CAN / CAN-FD Tester",
        "icon": "bi-diagram-3",
        "badge": "Core",
        "badge_class": "bg-primary",
        "description": (
            "Vector CAN / CAN-FD test-automation and sequencer GUI. "
            "Supports DBC file loading, UDS flow-control, command bank/script "
            "separation, and real-time message logging."
        ),
        "path": "Automotive_CAN_Tester",
        "entry": "Automotive_Diag_Tester.py",
        "readme": None,
        "tags": ["CAN", "CAN-FD", "UDS", "Vector", "DBC"],
        "requirements": None,
    },
    {
        "id": "cpu_load_monitor",
        "name": "CPU Load Monitor",
        "icon": "bi-bar-chart-line",
        "badge": "Utility",
        "badge_class": "bg-success",
        "description": (
            "Automotive CPU-load analyser with real-time graphing and "
            "Excel/CSV export. Parses serial/log output, queues command "
            "sequences, and renders live Matplotlib charts in Tkinter."
        ),
        "path": "CPU_Load_Monitor",
        "entry": "Automotive_CPU_Load_withGraphParser.py",
        "readme": None,
        "tags": ["CPU", "Graphs", "Serial", "Export"],
        "requirements": None,
    },
    {
        "id": "trace32_framework",
        "name": "TRACE32 Test Framework",
        "icon": "bi-terminal",
        "badge": "Utility",
        "badge_class": "bg-success",
        "description": (
            "Lightweight Lauterbach TRACE32 script executor with Tkinter GUI. "
            "Auto-detects T32 installation on Windows, queues .cmm scripts, "
            "and streams execution output in real time."
        ),
        "path": "Trace32_Test_Framework",
        "entry": "Trace32_Executor.py",
        "readme": None,
        "tags": ["TRACE32", "CMM", "Lauterbach"],
        "requirements": None,
    },
]

# ---------------------------------------------------------------------------
# Flask app
# ---------------------------------------------------------------------------
app = Flask(__name__, template_folder="templates")

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s  %(levelname)-8s  %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
)
log = logging.getLogger("dashboard")

# ---------------------------------------------------------------------------
# Git helper
# ---------------------------------------------------------------------------

def _run_git(args: List[str], cwd: str = BASE_DIR) -> subprocess.CompletedProcess:
    """Run a git command, returning CompletedProcess (stdout/stderr captured)."""
    return subprocess.run(
        ["git"] + args,
        cwd=cwd,
        capture_output=True,
        text=True,
        timeout=30,
    )


def get_git_info() -> Dict[str, Any]:
    """Return a dict with current git metadata."""
    info: Dict[str, Any] = {
        "branch": "unknown",
        "commit_hash": "unknown",
        "commit_message": "unknown",
        "commit_author": "unknown",
        "commit_date": "unknown",
        "last_checked": datetime.now(timezone.utc).isoformat(),
        "remote_ahead": False,
        "error": None,
    }
    try:
        branch = _run_git(["rev-parse", "--abbrev-ref", "HEAD"])
        info["branch"] = branch.stdout.strip() if branch.returncode == 0 else "unknown"

        log_line = _run_git(
            ["log", "-1", "--pretty=format:%H|%s|%an|%ai"]
        )
        if log_line.returncode == 0 and log_line.stdout.strip():
            parts = log_line.stdout.strip().split("|", 3)
            if len(parts) == 4:
                info["commit_hash"] = parts[0][:8]
                info["commit_message"] = parts[1]
                info["commit_author"] = parts[2]
                info["commit_date"] = parts[3]

        # Check if remote has new commits (non-blocking – we already fetched)
        rev = _run_git(
            ["rev-list", "--count", "HEAD..@{u}"],
        )
        if rev.returncode == 0:
            ahead = int(rev.stdout.strip() or "0")
            info["remote_ahead"] = ahead > 0
    except Exception as exc:  # pragma: no cover
        info["error"] = str(exc)

    return info


def git_fetch_and_pull(auto_pull: bool = True) -> Dict[str, Any]:
    """Fetch from remote, optionally pull, and return result dict."""
    result: Dict[str, Any] = {
        "fetched": False,
        "pulled": False,
        "pull_output": "",
        "error": None,
        "timestamp": datetime.now(timezone.utc).isoformat(),
    }
    try:
        fetch = _run_git(["fetch", "--quiet"])
        result["fetched"] = fetch.returncode == 0
        if not result["fetched"]:
            result["error"] = fetch.stderr.strip()
            return result

        if auto_pull:
            pull = _run_git(["pull", "--ff-only"])
            result["pulled"] = pull.returncode == 0
            result["pull_output"] = (pull.stdout + pull.stderr).strip()
            if not result["pulled"]:
                result["error"] = pull.stderr.strip()
    except Exception as exc:  # pragma: no cover
        result["error"] = str(exc)
    return result


# ---------------------------------------------------------------------------
# Background git-monitor thread + SSE broadcast
# ---------------------------------------------------------------------------
_sse_listeners: List[queue.Queue] = []
_sse_lock = threading.Lock()
_git_state: Dict[str, Any] = {}
_git_state_lock = threading.Lock()


def _broadcast(event: str, data: Any) -> None:
    """Push an SSE message to every connected client."""
    payload = f"event: {event}\ndata: {json.dumps(data)}\n\n"
    with _sse_lock:
        dead: List[queue.Queue] = []
        for q in _sse_listeners:
            try:
                q.put_nowait(payload)
            except queue.Full:
                dead.append(q)
        for q in dead:
            _sse_listeners.remove(q)


def _git_monitor(interval: int = 30, auto_pull: bool = True) -> None:
    """Background thread: fetch/pull every *interval* seconds."""
    log.info("Git monitor started (interval=%ds, auto_pull=%s)", interval, auto_pull)
    while True:
        try:
            pull_result = git_fetch_and_pull(auto_pull=auto_pull)
            git_info = get_git_info()
            with _git_state_lock:
                _git_state.update({**git_info, "last_pull": pull_result})
            _broadcast("git_update", _git_state)
            if pull_result.get("pulled") and "Already up to date" not in pull_result.get("pull_output", ""):
                log.info("Pulled latest changes: %s", pull_result["pull_output"])
                _broadcast("notification", {"type": "success", "message": "Repository updated – latest changes pulled."})
        except Exception as exc:  # pragma: no cover
            log.warning("Git monitor error: %s", exc)
        time.sleep(interval)


def _start_git_monitor(interval: int = 30, auto_pull: bool = True) -> None:
    t = threading.Thread(
        target=_git_monitor,
        kwargs={"interval": interval, "auto_pull": auto_pull},
        daemon=True,
        name="git-monitor",
    )
    t.start()


# ---------------------------------------------------------------------------
# Routes
# ---------------------------------------------------------------------------

@app.route("/")
def index():
    with _git_state_lock:
        git_info = dict(_git_state)
    return render_template("index.html", apps=APPS, git_info=git_info)


@app.route("/api/apps")
def api_apps():
    """Return JSON list of all registered applications."""
    safe = []
    for a in APPS:
        entry = {k: v for k, v in a.items()}
        # Enrich with file existence check
        entry["entry_exists"] = os.path.isfile(
            os.path.join(BASE_DIR, a["path"], a["entry"])
        )
        req_path = a.get("requirements")
        entry["requirements_exists"] = (
            os.path.isfile(os.path.join(BASE_DIR, req_path)) if req_path else False
        )
        safe.append(entry)
    return jsonify(safe)


@app.route("/api/git")
def api_git():
    """Return current git state."""
    with _git_state_lock:
        info = dict(_git_state)
    if not info:
        info = get_git_info()
    return jsonify(info)


@app.route("/api/git/refresh", methods=["POST"])
def api_git_refresh():
    """Manually trigger a git fetch/pull."""
    result = git_fetch_and_pull(auto_pull=True)
    git_info = get_git_info()
    with _git_state_lock:
        _git_state.update({**git_info, "last_pull": result})
    _broadcast("git_update", _git_state)
    return jsonify({"status": "ok", **result})


@app.route("/api/health")
def api_health():
    """Simple health-check endpoint."""
    return jsonify({
        "status": "healthy",
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "apps": len(APPS),
    })


@app.route("/stream")
def stream():
    """Server-Sent Events endpoint – streams git_update and notification events."""
    client_q: queue.Queue = queue.Queue(maxsize=50)
    with _sse_lock:
        _sse_listeners.append(client_q)

    # Send initial state immediately
    with _git_state_lock:
        initial = dict(_git_state)
    if initial:
        client_q.put_nowait(f"event: git_update\ndata: {json.dumps(initial)}\n\n")

    @stream_with_context
    def generate() -> Generator[str, None, None]:
        try:
            while True:
                try:
                    msg = client_q.get(timeout=25)
                    yield msg
                except queue.Empty:
                    yield ": keepalive\n\n"  # SSE comment to keep connection alive
        finally:
            with _sse_lock:
                if client_q in _sse_listeners:
                    _sse_listeners.remove(client_q)

    return Response(
        generate(),
        mimetype="text/event-stream",
        headers={
            "Cache-Control": "no-cache",
            "X-Accel-Buffering": "no",
        },
    )


# ---------------------------------------------------------------------------
# CLI entry point
# ---------------------------------------------------------------------------

def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="PythonFun Engineering Dashboard")
    parser.add_argument("--host", default="0.0.0.0", help="Bind host (default: 0.0.0.0)")
    parser.add_argument("--port", type=int, default=5000, help="Bind port (default: 5000)")
    parser.add_argument(
        "--no-auto-pull",
        action="store_true",
        help="Disable automatic git pull (still fetches to detect remote changes)",
    )
    parser.add_argument(
        "--poll-interval",
        type=int,
        default=30,
        help="Git poll interval in seconds (default: 30)",
    )
    parser.add_argument("--debug", action="store_true", help="Enable Flask debug mode")
    return parser.parse_args()


if __name__ == "__main__":
    args = _parse_args()

    # Seed git state synchronously so the first page-load has data
    try:
        initial_info = get_git_info()
        with _git_state_lock:
            _git_state.update(initial_info)
    except Exception:  # pragma: no cover
        pass

    _start_git_monitor(interval=args.poll_interval, auto_pull=not args.no_auto_pull)

    log.info("Starting dashboard on http://%s:%d", args.host, args.port)
    app.run(
        host=args.host,
        port=args.port,
        debug=args.debug,
        threaded=True,
        use_reloader=False,  # Reloader conflicts with daemon threads
    )
