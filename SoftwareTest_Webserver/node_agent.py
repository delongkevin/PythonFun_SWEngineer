import argparse
import logging
import re
import socket
import sys
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict, Iterable, List

import json

from monitor_server.report_parser import scan_report_roots
from runtime_bootstrap import ensure_runtime_dependencies

PROJECT_DIR = Path(__file__).resolve().parent
BOOTSTRAP_VENV_DIR = PROJECT_DIR / ".node_agent_venv"
BOOTSTRAP_ENV_VAR = "SOFTWARETEST_NODE_AGENT_BOOTSTRAPPED"
RUNTIME_DEPENDENCIES = {
    "psutil": "psutil>=5.9,<8.0",
    "requests": "requests>=2.31,<3.0",
    "serial": "pyserial>=3.5,<4.0",
}


ensure_runtime_dependencies(
    runtime_dependencies=RUNTIME_DEPENDENCIES,
    bootstrap_env_var=BOOTSTRAP_ENV_VAR,
    bootstrap_venv_dir=BOOTSTRAP_VENV_DIR,
    entry_script=Path(__file__).resolve(),
)

import psutil
import requests
from serial.tools import list_ports

DEFAULT_APPLICATIONS: List[Dict[str, Any]] = [
    {
        "name": "Vector CANoe",
        "process_names": ["CANoe64.exe"],
    },
    {
        "name": "Tera Term",
        "process_names": ["ttermpro.exe"],
    },
    {
        "name": "Lauterbach Trace32",
        "process_names": ["t32marm.exe", "t32marm64.exe"],
    },
]

DEFAULT_NODE_AGENT_CONFIG: Dict[str, Any] = {
    "server_url": "http://127.0.0.1:5050",
    "node_id": "bench-pc-01",
    "display_name": "Bench PC 01",
    "rdp_host": "192.168.1.25",
    "description": "Powertrain nightly regression node",
    "heartbeat_interval": 20,
    "tags": ["Powertrain", "Nightly", "Regression"],
    "report_roots": [
        "C:/TestReports/Nightly",
        "D:/Shared/Bench01/Results",
    ],
    "applications": DEFAULT_APPLICATIONS,
}


def is_frozen_app() -> bool:
    return bool(getattr(sys, "frozen", False))


def default_config_path() -> Path:
    if is_frozen_app():
        return Path(sys.executable).resolve().parent / "node_agent_config.json"
    return PROJECT_DIR / "examples" / "node_agent_config.json"


def ensure_config_exists(config_path: Path) -> None:
    if config_path.exists():
        return
    config_path.parent.mkdir(parents=True, exist_ok=True)
    config_path.write_text(json.dumps(DEFAULT_NODE_AGENT_CONFIG, indent=2), encoding="utf-8")


def configure_logging(verbose: bool) -> None:
    logging.basicConfig(
        level=logging.DEBUG if verbose else logging.INFO,
        format="%(asctime)s %(levelname)s %(message)s",
        datefmt="%Y-%m-%d %H:%M:%S",
    )


def load_config(config_path: Path) -> Dict[str, Any]:
    with config_path.open("r", encoding="utf-8") as handle:
        config = json.load(handle)
    config.setdefault("heartbeat_interval", 20)
    config.setdefault("applications", DEFAULT_APPLICATIONS)
    config.setdefault("report_roots", [])
    return config


def iso_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def get_primary_ip() -> str:
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as probe:
            probe.connect(("8.8.8.8", 80))
            return probe.getsockname()[0]
    except OSError:
        return "127.0.0.1"


def normalize_process_name(value: str) -> str:
    return value.strip().lower()


def collect_processes() -> List[Dict[str, Any]]:
    processes: List[Dict[str, Any]] = []
    for process in psutil.process_iter(["pid", "name", "cmdline", "create_time"]):
        try:
            info = process.info
            cmdline = info.get("cmdline") or []
            processes.append(
                {
                    "pid": info.get("pid"),
                    "name": info.get("name") or "unknown",
                    "name_normalized": normalize_process_name(info.get("name") or "unknown"),
                    "cmdline": [str(part) for part in cmdline],
                    "create_time": info.get("create_time"),
                }
            )
        except (psutil.NoSuchProcess, psutil.AccessDenied):
            continue
    return processes


def match_applications(rules: Iterable[Dict[str, Any]], processes: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    app_statuses: List[Dict[str, Any]] = []
    for rule in rules:
        aliases = {normalize_process_name(name) for name in rule.get("process_names", [])}
        matches = []
        for process in processes:
            name = process["name_normalized"]
            cmdline_text = " ".join(process["cmdline"]).lower()
            if name in aliases or any(alias in cmdline_text for alias in aliases):
                matches.append(process)

        app_statuses.append(
            {
                "name": rule.get("name", "Unnamed Application"),
                "running": bool(matches),
                "instances": len(matches),
                "process_names": sorted(aliases),
                "processes": [
                    {
                        "pid": proc["pid"],
                        "name": proc["name"],
                        "cmdline": proc["cmdline"],
                        "create_time": proc["create_time"],
                    }
                    for proc in matches
                ],
            }
        )
    return app_statuses


def detect_teraterm_ports(processes: List[Dict[str, Any]]) -> set[str]:
    ports: set[str] = set()
    for process in processes:
        if process["name_normalized"] not in {"ttermpro.exe", "teraterm.exe"}:
            continue
        cmdline = " ".join(process["cmdline"])
        for match in re.findall(r"COM\d+", cmdline, re.IGNORECASE):
            ports.add(match.upper())
    return ports


def collect_serial_ports(processes: List[Dict[str, Any]]) -> List[Dict[str, Any]]:
    teraterm_ports = detect_teraterm_ports(processes)
    ports = []
    for port in list_ports.comports():
        device_name = (port.device or "").upper()
        ports.append(
            {
                "device": port.device,
                "description": port.description,
                "manufacturer": port.manufacturer,
                "hwid": port.hwid,
                "serial_number": port.serial_number,
                "connected": True,
                "in_use_by_teraterm": device_name in teraterm_ports,
            }
        )
    return ports


def build_registration_payload(config: Dict[str, Any]) -> Dict[str, Any]:
    hostname = socket.gethostname()
    return {
        "node_id": config.get("node_id") or hostname.lower(),
        "display_name": config.get("display_name") or hostname,
        "rdp_host": config.get("rdp_host") or get_primary_ip(),
        "description": config.get("description", ""),
        "tags": config.get("tags", []),
        "report_roots": config.get("report_roots", []),
        "agent_version": "1.0.0",
        "host": {
            "hostname": hostname,
            "ip_address": get_primary_ip(),
            "platform": config.get("platform") or psutil.WINDOWS and "windows" or "unknown",
            "username": psutil.Process().username() if hasattr(psutil.Process(), "username") else None,
        },
    }


def build_heartbeat_payload(config: Dict[str, Any]) -> Dict[str, Any]:
    processes = collect_processes()
    report_stats = scan_report_roots(config.get("report_roots", []), limit=20)
    return {
        "captured_at": iso_now(),
        "host": {
            "hostname": socket.gethostname(),
            "ip_address": get_primary_ip(),
            "platform": config.get("platform") or psutil.WINDOWS and "windows" or "unknown",
            "username": psutil.Process().username() if hasattr(psutil.Process(), "username") else None,
        },
        "rdp_host": config.get("rdp_host") or get_primary_ip(),
        "applications": match_applications(config.get("applications", DEFAULT_APPLICATIONS), processes),
        "serial_ports": collect_serial_ports(processes),
        "report_roots": config.get("report_roots", []),
        "report_summary": report_stats["summary"],
        "report_details": report_stats["reports"],
        "agent_version": "1.0.0",
    }


def post_json(session: requests.Session, url: str, payload: Dict[str, Any]) -> requests.Response:
    response = session.post(url, json=payload, timeout=15)
    response.raise_for_status()
    return response


def run_agent(config: Dict[str, Any], run_once: bool = False) -> None:
    node_id = config.get("node_id") or socket.gethostname().lower()
    base_url = config["server_url"].rstrip("/")
    interval = int(config.get("heartbeat_interval", 20))
    register_payload = build_registration_payload(config)

    with requests.Session() as session:
        registered = False
        while True:
            try:
                if not registered:
                    post_json(session, f"{base_url}/api/nodes/register", register_payload)
                    registered = True
                    logging.info("Registered node %s", node_id)

                heartbeat_payload = build_heartbeat_payload(config)
                post_json(
                    session,
                    f"{base_url}/api/nodes/{node_id}/heartbeat",
                    heartbeat_payload,
                )
                logging.info("Published heartbeat for %s", node_id)
            except requests.RequestException as exc:
                registered = False
                logging.error("Unable to publish node state: %s", exc)

            if run_once:
                return
            time.sleep(interval)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Software test node monitoring agent")
    parser.add_argument(
        "--config",
        default=str(default_config_path()),
        help="Path to the node agent configuration JSON file",
    )
    parser.add_argument("--once", action="store_true", help="Send a single heartbeat")
    parser.add_argument("--verbose", action="store_true", help="Enable debug logging")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    configure_logging(args.verbose)
    config_path = Path(args.config)
    ensure_config_exists(config_path)
    config = load_config(config_path)
    run_agent(config, run_once=args.once)


if __name__ == "__main__":
    main()
