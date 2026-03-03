# ADAS Virtual ECU – Virtual Test Environment (Software-only)

This package provides a **software-only Virtual ECU** and **virtual test harness** for:
- **2 CAN-FD channels** (in-memory virtual bus; no hardware)
- **4 cameras** (simulated health + frame counters)
- **12 ultrasonic sensors (USS)** (simulated distance targets)
- **Unit → Integration → Qualification** test ladder
- **Windows-first**, with **Docker backup** runner

## Quick start (Windows)

```powershell
cd ADAS_Virtual_ECU\virtual_test_env
py -m venv .venv
.venv\Scripts\activate
pip install -U pip
pip install -e ".[dev]"
pytest -q
```

## Run a scenario (CLI)

```powershell
python -m virtual_ecu_test_env.cli run scenarios\example_basic.yaml
```

You will see:
- generated CAN traffic on channel `can0` and `can1`
- basic UDS responses (stub)
- sensor simulation updates

## Docker backup

```bash
docker build -t adas-virtual-ecu .
docker run --rm adas-virtual-ecu
```

## Notes

- This is **protocol-level** virtualization. It does not compile/run the embedded `sw_app` C/C++ code.
- If you later provide concrete DBC files for the ADAS ECU, the harness can decode/encode signals via `cantools`
  (optional dependency) and validate message-level requirements.