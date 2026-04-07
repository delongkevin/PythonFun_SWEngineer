from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path


SCRIPT_DIR = Path(__file__).resolve().parent
DIST_DIR = SCRIPT_DIR / "dist"
BUILD_DIR = SCRIPT_DIR / "build"
BUILD_VENV_DIR = SCRIPT_DIR / ".build_venv"
SPEC_FILES = [
    SCRIPT_DIR / "software_test_node_agent.spec",
    SCRIPT_DIR / "software_test_server.spec",
]
BUILD_DEPS = [
    "pyinstaller>=6.0",
    "Flask>=3.0,<4.0",
    "waitress>=3.0,<4.0",
    "requests>=2.31,<3.0",
    "psutil>=5.9,<8.0",
    "pyserial>=3.5,<4.0",
]


def python_has_shared_library(python_executable: str) -> bool:
    result = subprocess.run(
        [python_executable, "-c", "import sysconfig; print(sysconfig.get_config_var('Py_ENABLE_SHARED') or 0)"],
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        return False
    return result.stdout.strip() == "1"


def select_build_python() -> str:
    candidates = [sys.executable]
    for candidate in (shutil.which("python3"), shutil.which("python"), "/usr/bin/python3"):
        if candidate and candidate not in candidates:
            candidates.append(candidate)

    for candidate in candidates:
        if python_has_shared_library(candidate):
            return candidate

    print("[build.py] ERROR: no Python interpreter with shared-library support was found.")
    sys.exit(1)


BUILD_PYTHON = select_build_python()
PYINSTALLER_PYTHON = BUILD_PYTHON


def build_venv_python() -> str:
    if sys.platform == "win32":
        return str(BUILD_VENV_DIR / "Scripts" / "python.exe")
    return str(BUILD_VENV_DIR / "bin" / "python")


def ensure_build_venv() -> bool:
    global PYINSTALLER_PYTHON

    existing_venv_python = Path(build_venv_python())
    if BUILD_VENV_DIR.exists() and existing_venv_python.exists():
        PYINSTALLER_PYTHON = str(existing_venv_python)
        return True
    if BUILD_VENV_DIR.exists() and not existing_venv_python.exists():
        shutil.rmtree(BUILD_VENV_DIR, ignore_errors=True)

    print(f"[build.py] Creating build virtual environment at {BUILD_VENV_DIR} ...")
    rc = run([BUILD_PYTHON, "-m", "venv", str(BUILD_VENV_DIR)])
    if rc != 0:
        print("[build.py] WARNING: failed to create build virtual environment; falling back to direct install.")
        shutil.rmtree(BUILD_VENV_DIR, ignore_errors=True)
        PYINSTALLER_PYTHON = BUILD_PYTHON
        return False

    PYINSTALLER_PYTHON = build_venv_python()
    return True


def run(cmd: list[str], **kwargs) -> int:
    print(f"\n>>> {' '.join(str(c) for c in cmd)}")
    result = subprocess.run(cmd, **kwargs)
    return result.returncode


def install_deps() -> None:
    using_venv = ensure_build_venv()
    print("\n[build.py] Installing build dependencies ...")
    cmd = [PYINSTALLER_PYTHON, "-m", "pip", "install", "--upgrade"]
    if not using_venv:
        cmd += ["--user", "--break-system-packages"]
    cmd += BUILD_DEPS
    rc = run(cmd)
    if rc != 0:
        print("[build.py] ERROR: pip install failed.")
        sys.exit(rc)


def clean_artifacts() -> None:
    for directory in (DIST_DIR, BUILD_DIR, BUILD_VENV_DIR):
        if directory.exists():
            print(f"[build.py] Removing {directory} ...")
            shutil.rmtree(directory)


def build_specs() -> None:
    ensure_build_venv()
    for spec_file in SPEC_FILES:
        print(f"\n[build.py] Building {spec_file.name} ...")
        rc = run([PYINSTALLER_PYTHON, "-m", "PyInstaller", "--noconfirm", str(spec_file)], cwd=str(SCRIPT_DIR))
        if rc != 0:
            print(f"[build.py] ERROR: PyInstaller build failed for {spec_file.name}.")
            sys.exit(rc)


def print_summary() -> None:
    outputs = [
        DIST_DIR / ("SoftwareTestNodeAgent.exe" if sys.platform == "win32" else "SoftwareTestNodeAgent"),
        DIST_DIR / ("SoftwareTestServer.exe" if sys.platform == "win32" else "SoftwareTestServer"),
    ]
    print("\n" + "=" * 60)
    for output_path in outputs:
        if output_path.exists():
            size_mb = output_path.stat().st_size / (1024 * 1024)
            print(f"[build.py] Built: {output_path} ({size_mb:.1f} MB)")
        else:
            print(f"[build.py] WARNING: expected output not found at {output_path}")
    print("=" * 60)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Build SoftwareTest Webserver server and node agent as single-file executables."
    )
    parser.add_argument("--clean", action="store_true", help="Remove previous build artifacts first.")
    parser.add_argument(
        "--no-install",
        action="store_true",
        dest="no_install",
        help="Skip dependency installation.",
    )
    args = parser.parse_args()

    os.chdir(SCRIPT_DIR)
    print(f"[build.py] Working directory : {SCRIPT_DIR}")
    print(f"[build.py] Python executable : {sys.executable}")
    print(f"[build.py] Build Python      : {BUILD_PYTHON}")
    print(f"[build.py] PyInstaller venv  : {BUILD_VENV_DIR}")
    print(f"[build.py] Platform          : {sys.platform}")

    if args.clean:
        clean_artifacts()

    if not args.no_install:
        install_deps()

    build_specs()
    print_summary()


if __name__ == "__main__":
    main()
