import base64
import hashlib
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[1]
DEPLOYABLES_DIR = PROJECT_ROOT / "deployables"


BUNDLES = {
    "node_agent_standalone.py": {
        "bundle_dirname": ".softwaretest_node_agent_bundle",
        "entrypoint": "node_agent.py",
        "files": [
            "runtime_bootstrap.py",
            "node_agent.py",
            "monitor_server/report_parser.py",
            "examples/node_agent_config.json",
        ],
        "write_once_files": ["examples/node_agent_config.json"],
        "default_args": [
            (
                "config",
                "node_agent_config.json",
                "examples/node_agent_config.json",
                "Path(__file__).resolve().parent / 'node_agent_config.json'",
            ),
        ],
    },
    "server_standalone.py": {
        "bundle_dirname": ".softwaretest_server_bundle",
        "entrypoint": "server.py",
        "files": [
            "runtime_bootstrap.py",
            "server.py",
            "monitor_server/__init__.py",
            "monitor_server/state.py",
            "monitor_server/report_parser.py",
            "monitor_server/templates/index.html",
            "monitor_server/static/styles.css",
            "monitor_server/static/dashboard.js",
        ],
        "write_once_files": [],
        "default_args": [
            (
                "data-file",
                "server_state.json",
                None,
                "Path(__file__).resolve().parent / 'server_data' / 'state.json'",
            ),
        ],
    },
}


def encode_file(path: Path) -> str:
    return base64.b64encode(path.read_bytes()).decode("ascii")


def build_default_args_block(default_args):
    lines = []
    for option, output_name, embedded_source, path_expr in default_args:
        option_literal = repr(f"--{option}")
        if embedded_source:
            lines.append(f"    if {option_literal} not in args:")
            lines.append(f"        target_path = {path_expr}")
            lines.append("        target_path.parent.mkdir(parents=True, exist_ok=True)")
            lines.append(f"        embedded_bytes = base64.b64decode(EMBEDDED_FILES[{repr(embedded_source)}])")
            lines.append("        if not target_path.exists():")
            lines.append("            target_path.write_bytes(embedded_bytes)")
            lines.append("        args = [*args, " + option_literal + ", str(target_path)]")
        else:
            lines.append(f"    if {option_literal} not in args:")
            lines.append(f"        target_path = {path_expr}")
            lines.append("        target_path.parent.mkdir(parents=True, exist_ok=True)")
            lines.append("        args = [*args, " + option_literal + ", str(target_path)]")
    return "\n".join(lines)


def build_script(output_name: str, bundle_config: dict) -> str:
    embedded_files = {
        relative_path: encode_file(PROJECT_ROOT / relative_path)
        for relative_path in bundle_config["files"]
    }
    version_hash = hashlib.sha256(
        "".join(embedded_files.values()).encode("utf-8")
    ).hexdigest()[:12]
    default_args_block = build_default_args_block(bundle_config["default_args"])
    script_lines = [
        "import base64",
        "import subprocess",
        "import sys",
        "from pathlib import Path",
        "",
        f"BUNDLE_VERSION = {version_hash!r}",
        f"BUNDLE_DIRNAME = {bundle_config['bundle_dirname']!r}",
        f"ENTRYPOINT = {bundle_config['entrypoint']!r}",
        f"WRITE_ONCE_FILES = {bundle_config['write_once_files']!r}",
        f"EMBEDDED_FILES = {embedded_files!r}",
        "",
        "",
        "def write_bundle(bundle_root: Path) -> None:",
        "    bundle_root.mkdir(parents=True, exist_ok=True)",
        "    version_file = bundle_root / '.bundle_version'",
        "    current_version = version_file.read_text(encoding='utf-8') if version_file.exists() else ''",
        "    force_update = current_version != BUNDLE_VERSION",
        "",
        "    for relative_path, encoded in EMBEDDED_FILES.items():",
        "        target_path = bundle_root / relative_path",
        "        target_path.parent.mkdir(parents=True, exist_ok=True)",
        "        if relative_path in WRITE_ONCE_FILES and target_path.exists():",
        "            continue",
        "        payload = base64.b64decode(encoded)",
        "        if force_update or not target_path.exists() or target_path.read_bytes() != payload:",
        "            target_path.write_bytes(payload)",
        "",
        "    version_file.write_text(BUNDLE_VERSION, encoding='utf-8')",
        "",
        "",
        "def main() -> int:",
        "    script_dir = Path(__file__).resolve().parent",
        "    bundle_root = script_dir / BUNDLE_DIRNAME",
        "    write_bundle(bundle_root)",
        "",
        "    args = list(sys.argv[1:])",
    ]
    if default_args_block:
        script_lines.extend(default_args_block.splitlines())
    else:
        script_lines.append("    pass")
    script_lines.extend(
        [
            "",
            "    entrypoint = bundle_root / ENTRYPOINT",
            "    return subprocess.call([sys.executable, str(entrypoint), *args], cwd=str(bundle_root))",
            "",
            "",
            "if __name__ == '__main__':",
            "    raise SystemExit(main())",
            "",
        ]
    )
    return "\n".join(script_lines)


def main() -> None:
    DEPLOYABLES_DIR.mkdir(parents=True, exist_ok=True)
    for output_name, bundle_config in BUNDLES.items():
        content = build_script(output_name, bundle_config)
        output_path = DEPLOYABLES_DIR / output_name
        output_path.write_text(content, encoding="utf-8")
        print(f"Generated {{output_path}}")


if __name__ == "__main__":
    main()
