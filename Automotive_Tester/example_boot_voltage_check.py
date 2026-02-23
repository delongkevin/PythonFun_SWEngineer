"""
Example Python test script for the Automotive ECU Tester.

Every Python test script must define a run(params) function.
The context (hardware handles) is injected into the module namespace before run() is called.

Available in namespace:
  - power_supply   : BKPrecision1687B instance
  - trace32        : Trace32Interface instance
  - serial_manager : SerialManager instance
  - camera         : CameraInterface instance
  - canoe          : CANoeInterface instance
  - logger         : TesterLogger instance
"""

import time


def run(params: dict):
    """
    Test: ECU Boot Voltage Check
    Verifies ECU receives correct supply voltage at startup.

    params:
      min_voltage: minimum acceptable voltage (default 11.5)
      max_voltage: maximum acceptable voltage (default 14.5)
    """
    min_v = float(params.get("min_voltage", 11.5))
    max_v = float(params.get("max_voltage", 14.5))

    # Set supply voltage
    power_supply.set_voltage(12.0)  # noqa: F821
    power_supply.set_current(5.0)  # noqa: F821
    power_supply.output_on()  # noqa: F821
    time.sleep(1.0)  # Allow ECU to boot

    # Measure actual voltage
    v = power_supply.measure_voltage()  # noqa: F821
    if v is None:
        raise RuntimeError("Could not read PSU voltage.")

    # Capture visual evidence
    camera.snapshot(label="boot_voltage_check")  # noqa: F821

    # Check serial terminal for ECU boot message
    term = serial_manager.get("Serial-1")  # noqa: F821
    if term:
        response = term.wait_for("BOOT OK", timeout=10.0)
        if not response:
            raise RuntimeError("ECU did not send 'BOOT OK' within 10s")

    # Validate voltage
    assert min_v <= v <= max_v, \
        f"Voltage {v:.3f}V outside range [{min_v}, {max_v}]"

    return f"PASS — Voltage: {v:.3f}V (within [{min_v}, {max_v}])"
