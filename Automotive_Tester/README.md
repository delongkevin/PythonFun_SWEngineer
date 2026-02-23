# 🚗 Automotive ECU Tester

A comprehensive Python-based test automation platform for automotive ECU validation.

---

## Architecture

```
automotive_tester/
├── main.py                          # Entry point
├── requirements.txt
├── core/
│   ├── logger.py                    # Session-based logging (auto timestamped)
│   ├── queue_manager.py             # Test queue engine (Python / CANoe / CMM)
│   └── debug_console.py             # Debug & diagnostics API
├── interfaces/
│   ├── trace32_interface.py         # Lauterbach TRACE32 via RCL or TCP socket
│   ├── power_supply.py              # BK Precision 1687B via RS-232/USB-Serial
│   ├── serial_manager.py            # Up to 4 serial terminals (TeraTerm/PuTTY style)
│   ├── camera_interface.py          # USB camera (OpenCV)
│   └── canoe_interface.py           # Vector CANoe via COM automation
├── ui/
│   └── app.py                       # Tkinter GUI (dark theme)
├── scripts/
│   ├── example_boot_voltage_check.py
│   └── example_ecu_flash_verify.cmm
└── logs/                            # Auto-created; one folder per session
    └── YYYYMMDD_HHMMSS/
        ├── main.log
        ├── test_results.csv
        ├── Serial-1_*.log
        ├── debug.log
        └── camera/
```

---

## Hardware Connections

| Device               | Connection             | Default Config        |
|----------------------|------------------------|-----------------------|
| BK Precision 1687B   | USB-to-Serial adapter  | COM3, 9600 baud       |
| Lauterbach TRACE32   | TCP (API port)         | localhost:20000       |
| Vector CANoe         | COM automation (Win)   | Configure .cfg path   |
| USB Camera           | USB                    | Device index 0        |
| Serial Terminal 1-4  | USB-Serial adapters    | COM4-COM7, 115200     |

---

## Quick Start

```bash
# 1. Install dependencies
pip install -r requirements.txt

# 2. Launch the application
python main.py
```

### UI Tabs

| Tab            | Purpose                                              |
|----------------|------------------------------------------------------|
| 🧪 Test Runner  | Add/order/run tests; live log streaming              |
| 🐛 Debug        | Test connections, inject commands, validate scripts  |
| ⚙ Config       | Set COM ports, IP addresses, file paths              |
| 📊 Results      | View pass/fail summary, open log folder              |

---

## Writing Test Scripts

### Python Test (`scripts/my_test.py`)

```python
def run(params: dict):
    # Hardware handles injected automatically:
    # power_supply, trace32, serial_manager, camera, canoe, logger

    power_supply.set_voltage(12.0)
    power_supply.output_on()

    term = serial_manager.get("Serial-1")
    response = term.wait_for("ECU READY", timeout=10.0)
    assert response, "ECU did not respond"

    camera.snapshot(label="test_evidence")
    return "PASS"
```

### CMM Script (`scripts/my_test.cmm`)

```
ENTRY &param1

SYStem.Up
Break.direct
; ... your PRACTICE commands ...
Go
ENDDO
```

### CANoe Test
Add a CANoe test module name as the script path. The runner will find it
in the open CANoe configuration and execute it.

---

## Logging

Every session creates a timestamped folder under `logs/`:
- `main.log` — all events
- `test_results.csv` — structured pass/fail with timestamps
- `Serial-N_*.log` — per-port terminal captures
- `camera/` — snapshots and video clips
- `debug.log` — debug console commands

---

## Dependencies

- **pyserial** — BK1687B + serial terminals
- **opencv-python** — USB camera
- **lauterbach-trace32-rcl** — TRACE32 control (optional, falls back to TCP check)
- **pywin32** — Vector CANoe COM automation (Windows only)
- **tkinter** — GUI (built into Python standard library)
