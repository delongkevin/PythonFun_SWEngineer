import argparse
from pathlib import Path

from monitor_server import create_app


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Software test network dashboard server"
    )
    parser.add_argument("--host", default="0.0.0.0", help="Bind host")
    parser.add_argument("--port", type=int, default=5050, help="Bind port")
    parser.add_argument(
        "--data-file",
        default=str(Path("data") / "state.json"),
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
