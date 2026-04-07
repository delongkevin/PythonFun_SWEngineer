import argparse
from pathlib import Path
import sys

from runtime_bootstrap import ensure_runtime_dependencies

PROJECT_DIR = Path(__file__).resolve().parent
BOOTSTRAP_VENV_DIR = PROJECT_DIR / ".server_venv"
BOOTSTRAP_ENV_VAR = "SOFTWARETEST_SERVER_BOOTSTRAPPED"
RUNTIME_DEPENDENCIES = {
    "flask": "Flask>=3.0,<4.0",
    "waitress": "waitress>=3.0,<4.0",
}

ensure_runtime_dependencies(
    runtime_dependencies=RUNTIME_DEPENDENCIES,
    bootstrap_env_var=BOOTSTRAP_ENV_VAR,
    bootstrap_venv_dir=BOOTSTRAP_VENV_DIR,
    entry_script=Path(__file__).resolve(),
)

from monitor_server import create_app


def is_frozen_app() -> bool:
    return bool(getattr(sys, "frozen", False))


def default_state_file() -> Path:
    if is_frozen_app():
        return Path(sys.executable).resolve().parent / "server_data" / "state.json"
    return PROJECT_DIR / "data" / "state.json"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Software test network dashboard server"
    )
    parser.add_argument("--host", default="0.0.0.0", help="Bind host")
    parser.add_argument("--port", type=int, default=5050, help="Bind port")
    parser.add_argument(
        "--data-file",
        default=str(default_state_file()),
        help="Path to persisted node state JSON file",
    )
    parser.add_argument(
        "--stale-after",
        type=int,
        default=180,
        help="Seconds before a node is considered stale",
    )
    parser.add_argument(
        "--debug",
        action="store_true",
        help="Enable Flask debug mode",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    app = create_app(
        data_file=Path(args.data_file),
        stale_after_seconds=args.stale_after,
    )
    app.run(host=args.host, port=args.port, debug=args.debug)


if __name__ == "__main__":
    main()
