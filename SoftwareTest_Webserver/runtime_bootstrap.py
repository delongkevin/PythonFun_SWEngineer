import importlib.util
import os
import subprocess
import sys
import venv
from pathlib import Path
from typing import Dict, List, Sequence


def is_frozen_app() -> bool:
    return bool(getattr(sys, "frozen", False))


def find_missing_runtime_packages(runtime_dependencies: Dict[str, str]) -> List[str]:
    missing_packages: List[str] = []
    for module_name, package_spec in runtime_dependencies.items():
        if importlib.util.find_spec(module_name) is None:
            missing_packages.append(package_spec)
    return missing_packages


def run_pip_install(python_executable: str, packages: List[str]) -> None:
    subprocess.check_call(
        [
            python_executable,
            "-m",
            "pip",
            "install",
            "--disable-pip-version-check",
            *packages,
        ]
    )


def bootstrap_virtualenv(venv_dir: Path, packages: List[str]) -> str:
    builder = venv.EnvBuilder(with_pip=True)
    builder.create(str(venv_dir))
    if os.name == "nt":
        python_executable = venv_dir / "Scripts" / "python.exe"
    else:
        python_executable = venv_dir / "bin" / "python"
    run_pip_install(str(python_executable), packages)
    return str(python_executable)


def ensure_runtime_dependencies(
    runtime_dependencies: Dict[str, str],
    bootstrap_env_var: str,
    bootstrap_venv_dir: Path,
    entry_script: Path,
    argv: Sequence[str] | None = None,
) -> None:
    if is_frozen_app():
        return

    missing_packages = find_missing_runtime_packages(runtime_dependencies)
    if not missing_packages:
        return

    if os.environ.get(bootstrap_env_var) == "1":
        missing_list = ", ".join(missing_packages)
        raise RuntimeError(
            "Bootstrap already ran, but dependencies are still missing: "
            f"{missing_list}"
        )

    print(
        "[bootstrap] Missing runtime dependencies detected. "
        "Attempting automatic installation...",
        file=sys.stderr,
    )

    try:
        run_pip_install(sys.executable, missing_packages)
        importlib.invalidate_caches()
        if not find_missing_runtime_packages(runtime_dependencies):
            return
    except subprocess.CalledProcessError:
        pass

    print(
        "[bootstrap] Direct installation failed or did not satisfy imports. "
        "Creating a dedicated virtual environment...",
        file=sys.stderr,
    )
    python_executable = bootstrap_virtualenv(bootstrap_venv_dir, missing_packages)
    environment = os.environ.copy()
    environment[bootstrap_env_var] = "1"
    subprocess.check_call(
        [python_executable, str(entry_script), *(list(argv) if argv is not None else sys.argv[1:])],
        env=environment,
    )
    raise SystemExit(0)
