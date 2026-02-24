"""
build.py – Build helper for Trace32 Test Framework
====================================================

Usage (from the Trace32_Test_Framework/ directory):

    python build.py              # install deps + build release exe
    python build.py --clean      # remove previous build artifacts first
    python build.py --no-install # skip pip install step

The finished executable is placed in:
    Trace32_Test_Framework/dist/Trace32Executor/Trace32Executor.exe  (Windows)
"""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------
SCRIPT_DIR = Path(__file__).resolve().parent   # Trace32_Test_Framework/
SPEC_FILE = SCRIPT_DIR / "trace32_executor.spec"
DIST_DIR = SCRIPT_DIR / "dist"
BUILD_DIR = SCRIPT_DIR / "build"

# ---------------------------------------------------------------------------
# Minimum required packages
# ---------------------------------------------------------------------------
BUILD_DEPS = [
    "pyinstaller>=6.0",
]


def run(cmd: list[str], **kwargs) -> int:
    """Run a subprocess command and return the exit code."""
    print(f"\n>>> {' '.join(str(c) for c in cmd)}")
    result = subprocess.run(cmd, **kwargs)
    return result.returncode


def install_deps() -> None:
    """Install build dependencies via pip."""
    print("\n[build.py] Installing build dependencies …")
    rc = run([sys.executable, "-m", "pip", "install", "--upgrade"] + BUILD_DEPS)
    if rc != 0:
        print("[build.py] ERROR: pip install failed.")
        sys.exit(rc)
    print("[build.py] Dependencies installed successfully.")


def clean_artifacts() -> None:
    """Remove previous dist/ and build/ directories."""
    for directory in (DIST_DIR, BUILD_DIR):
        if directory.exists():
            print(f"[build.py] Removing {directory} …")
            shutil.rmtree(directory)


def build_exe() -> None:
    """Run PyInstaller to produce the executable."""
    print("\n[build.py] Starting PyInstaller build …")

    cmd: list[str] = [
        sys.executable, "-m", "PyInstaller",
        "--noconfirm",
        str(SPEC_FILE),
    ]

    rc = run(cmd, cwd=str(SCRIPT_DIR))
    if rc != 0:
        print("[build.py] ERROR: PyInstaller build failed.")
        sys.exit(rc)


def print_summary() -> None:
    """Print a summary of the built artefacts."""
    exe_name = "Trace32Executor.exe" if sys.platform == "win32" else "Trace32Executor"
    exe_path = DIST_DIR / "Trace32Executor" / exe_name
    dist_dir = DIST_DIR / "Trace32Executor"

    print("\n" + "=" * 60)
    if exe_path.exists():
        size_mb = exe_path.stat().st_size / (1024 * 1024)
        print("[build.py] Build SUCCESSFUL")
        print(f"  Output dir : {dist_dir}")
        print(f"  Executable : {exe_path}")
        print(f"  Launcher   : {size_mb:.1f} MB  (dependencies in _internal/)")
    else:
        print(f"[build.py] WARNING: expected output not found at {exe_path}")
    print("=" * 60)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Build Trace32 Test Framework as a standalone executable."
    )
    parser.add_argument(
        "--clean",
        action="store_true",
        help="Remove previous build artefacts before building.",
    )
    parser.add_argument(
        "--no-install",
        action="store_true",
        dest="no_install",
        help="Skip the 'pip install' step (assumes deps are already present).",
    )
    args = parser.parse_args()

    os.chdir(SCRIPT_DIR)

    print(f"[build.py] Working directory : {SCRIPT_DIR}")
    print(f"[build.py] Python executable : {sys.executable}")
    print(f"[build.py] Platform          : {sys.platform}")

    if args.clean:
        clean_artifacts()

    if not args.no_install:
        install_deps()

    build_exe()
    print_summary()


if __name__ == "__main__":
    main()
