from pathlib import Path

import pytest

import node_agent
import runtime_bootstrap
import server


def test_find_missing_runtime_packages_returns_missing_specs(monkeypatch):
    def fake_find_spec(name):
        return None if name in {"psutil", "serial"} else object()

    monkeypatch.setattr(runtime_bootstrap.importlib.util, "find_spec", fake_find_spec)

    missing = runtime_bootstrap.find_missing_runtime_packages(
        {
            "psutil": "psutil>=5.9,<8.0",
            "requests": "requests>=2.31,<3.0",
            "serial": "pyserial>=3.5,<4.0",
        }
    )

    assert "psutil>=5.9,<8.0" in missing
    assert "pyserial>=3.5,<4.0" in missing
    assert "requests>=2.31,<3.0" not in missing


def test_bootstrap_virtualenv_uses_expected_python_path(monkeypatch, tmp_path):
    recorded = {}

    class FakeBuilder:
        def __init__(self, with_pip):
            recorded["with_pip"] = with_pip

        def create(self, destination):
            recorded["destination"] = destination

    def fake_run_pip_install(python_executable, packages):
        recorded["python_executable"] = python_executable
        recorded["packages"] = packages

    monkeypatch.setattr(runtime_bootstrap.venv, "EnvBuilder", FakeBuilder)
    monkeypatch.setattr(runtime_bootstrap, "run_pip_install", fake_run_pip_install)

    venv_dir = tmp_path / "agent-venv"
    python_executable = runtime_bootstrap.bootstrap_virtualenv(venv_dir, ["requests>=2.31,<3.0"])

    assert recorded["with_pip"] is True
    assert recorded["destination"] == str(venv_dir)
    expected_dir = "Scripts" if runtime_bootstrap.os.name == "nt" else "bin"
    assert Path(python_executable) == venv_dir / expected_dir / ("python.exe" if runtime_bootstrap.os.name == "nt" else "python")
    assert recorded["packages"] == ["requests>=2.31,<3.0"]


def test_ensure_runtime_dependencies_installs_missing_packages_in_place(monkeypatch):
    missing_packages = ["requests>=2.31,<3.0"]
    state = {"calls": 0}
    installed = []

    def fake_find_missing_runtime_packages(_runtime_dependencies):
        state["calls"] += 1
        return missing_packages if state["calls"] == 1 else []

    def fake_run_pip_install(python_executable, packages):
        installed.append((python_executable, packages))

    monkeypatch.setattr(runtime_bootstrap, "find_missing_runtime_packages", fake_find_missing_runtime_packages)
    monkeypatch.setattr(runtime_bootstrap, "run_pip_install", fake_run_pip_install)
    monkeypatch.delenv("TEST_BOOTSTRAP_ENV", raising=False)

    runtime_bootstrap.ensure_runtime_dependencies(
        runtime_dependencies={"requests": "requests>=2.31,<3.0"},
        bootstrap_env_var="TEST_BOOTSTRAP_ENV",
        bootstrap_venv_dir=Path("/tmp/unused-venv"),
        entry_script=Path("bootstrap_entry.py"),
    )

    assert installed == [(runtime_bootstrap.sys.executable, missing_packages)]


def test_ensure_runtime_dependencies_falls_back_to_virtualenv(monkeypatch):
    created = {}

    def fake_find_missing_runtime_packages(_runtime_dependencies):
        return ["pyserial>=3.5,<4.0"]

    def fake_run_pip_install(_python_executable, _packages):
        raise runtime_bootstrap.subprocess.CalledProcessError(returncode=1, cmd=["pip"])

    def fake_bootstrap_virtualenv(venv_dir, packages):
        created["venv_dir"] = venv_dir
        created["packages"] = packages
        return "C:/fake-venv/python.exe"

    def fake_check_call(command, env=None):
        created["command"] = command
        created["env"] = env
        return 0

    monkeypatch.setattr(runtime_bootstrap, "find_missing_runtime_packages", fake_find_missing_runtime_packages)
    monkeypatch.setattr(runtime_bootstrap, "run_pip_install", fake_run_pip_install)
    monkeypatch.setattr(runtime_bootstrap, "bootstrap_virtualenv", fake_bootstrap_virtualenv)
    monkeypatch.setattr(runtime_bootstrap.subprocess, "check_call", fake_check_call)
    monkeypatch.delenv("TEST_BOOTSTRAP_ENV", raising=False)

    with pytest.raises(SystemExit) as exc_info:
        runtime_bootstrap.ensure_runtime_dependencies(
            runtime_dependencies={"serial": "pyserial>=3.5,<4.0"},
            bootstrap_env_var="TEST_BOOTSTRAP_ENV",
            bootstrap_venv_dir=Path("/tmp/node-agent-venv"),
            entry_script=Path("boot.py"),
            argv=["--once"],
        )

    assert exc_info.value.code == 0
    assert created["venv_dir"] == Path("/tmp/node-agent-venv")
    assert created["packages"] == ["pyserial>=3.5,<4.0"]
    assert created["command"][0] == "C:/fake-venv/python.exe"
    assert created["command"][1] == "boot.py"
    assert created["command"][2:] == ["--once"]
    assert created["env"]["TEST_BOOTSTRAP_ENV"] == "1"


def test_ensure_runtime_dependencies_raises_after_failed_bootstrap(monkeypatch):
    monkeypatch.setattr(
        runtime_bootstrap,
        "find_missing_runtime_packages",
        lambda _runtime_dependencies: ["Flask>=3.0,<4.0"],
    )
    monkeypatch.setenv("TEST_BOOTSTRAP_ENV", "1")

    with pytest.raises(RuntimeError, match="dependencies are still missing"):
        runtime_bootstrap.ensure_runtime_dependencies(
            runtime_dependencies={"flask": "Flask>=3.0,<4.0"},
            bootstrap_env_var="TEST_BOOTSTRAP_ENV",
            bootstrap_venv_dir=Path("unused"),
            entry_script=Path("server.py"),
        )


def test_bootstrap_is_skipped_for_frozen_apps(monkeypatch):
    monkeypatch.setattr(runtime_bootstrap.sys, "frozen", True, raising=False)
    called = {"pip": False}

    def fake_run_pip_install(_python_executable, _packages):
        called["pip"] = True

    monkeypatch.setattr(runtime_bootstrap, "run_pip_install", fake_run_pip_install)

    runtime_bootstrap.ensure_runtime_dependencies(
        runtime_dependencies={"flask": "Flask>=3.0,<4.0"},
        bootstrap_env_var="TEST_BOOTSTRAP_ENV",
        bootstrap_venv_dir=Path("unused"),
        entry_script=Path("server.py"),
    )

    assert called["pip"] is False


def test_node_agent_default_config_path_uses_executable_directory_when_frozen(monkeypatch):
    monkeypatch.setattr(node_agent.sys, "frozen", True, raising=False)
    monkeypatch.setattr(node_agent.sys, "executable", "/tmp/NodeAgent.exe", raising=False)

    config_path = node_agent.default_config_path()

    expected_path = Path(node_agent.sys.executable).resolve().parent / "node_agent_config.json"

    assert config_path == expected_path


def test_node_agent_creates_default_config_when_missing(tmp_path):
    config_path = tmp_path / "node_agent_config.json"

    node_agent.ensure_config_exists(config_path)

    assert config_path.exists()
    payload = node_agent.json.loads(config_path.read_text(encoding="utf-8"))
    assert payload["applications"][0]["process_names"] == ["CANoe64.exe"]


def test_server_default_state_file_uses_executable_directory_when_frozen(monkeypatch):
    monkeypatch.setattr(server.sys, "frozen", True, raising=False)
    monkeypatch.setattr(server.sys, "executable", "/tmp/SoftwareTestServer.exe", raising=False)

    state_path = server.default_state_file()

    expected_path = Path(server.sys.executable).resolve().parent / "server_data" / "state.json"

    assert state_path == expected_path
