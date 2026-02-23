"""
Example Python test script for Automotive Tester.

Every Python test script must expose a ``run(**params)`` function.
Return a truthy value on success (dict with telemetry is ideal),
or raise AssertionError / return None/False on failure.
"""
from __future__ import annotations

import logging
import time
from typing import Any, Dict

logger = logging.getLogger(__name__)


def run(**params: Any) -> Dict[str, Any]:
    """Demonstrate a minimal passing test.

    This test simulates a voltage check:
      - Reads a target voltage from params (default 12.0 V).
      - Sleeps briefly to mimic real measurement time.
      - Asserts the simulated reading is within ±0.5 V.

    Args:
        **params: Keyword parameters injected by the test runner.
                  Recognised keys:
                  - ``target_voltage`` (float): Expected voltage (default 12.0).

    Returns:
        Dictionary with telemetry that will be recorded in the run log.

    Raises:
        AssertionError: If the simulated voltage is out of tolerance.
    """
    target: float = float(params.get("target_voltage", 12.0))
    tolerance: float = 0.5

    logger.info("example_test.py: checking voltage – target=%.2f V ±%.2f V", target, tolerance)

    # Simulate measurement (replace with real hardware read in production)
    time.sleep(0.1)
    simulated_voltage = target + 0.05   # slight positive offset – within tolerance

    assert abs(simulated_voltage - target) <= tolerance, (
        f"Voltage out of range: got {simulated_voltage:.3f} V, "
        f"expected {target:.3f} ± {tolerance:.3f} V"
    )

    result = {
        "target_voltage_V": target,
        "measured_voltage_V": simulated_voltage,
        "delta_V": round(simulated_voltage - target, 4),
    }
    logger.info("example_test.py PASSED – %s", result)
    return result
