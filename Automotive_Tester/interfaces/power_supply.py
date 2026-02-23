"""
BK Precision 1687B Power Supply Interface
Protocol: RS-232 serial, 9600 baud, 8N1
Command set: SCPI-compatible subset per BK 1687B manual.

Wiring: USB-to-Serial adapter → BK 1687B RS-232 port
"""

import serial
import time
import threading
import logging
from typing import Optional


class BKPrecision1687B:
    """
    Controls the BK Precision 1687B programmable DC power supply.

    Key capabilities:
      - Set/get voltage and current limits
      - Enable/disable output
      - Read measured voltage and current
      - Over-voltage / over-current protection settings
      - Remote/local mode control
    """

    DEFAULT_BAUD = 9600
    TERMINATOR = "\r\n"
    READ_TIMEOUT = 2.0

    def __init__(self, port: str, baud: int = DEFAULT_BAUD):
        self.port = port
        self.baud = baud
        self.logger = logging.getLogger("tester.power_supply")
        self._serial: Optional[serial.Serial] = None
        self._lock = threading.Lock()
        self._connected = False

    # ── Connection ─────────────────────────────────────────────────────────

    def connect(self) -> bool:
        try:
            self._serial = serial.Serial(
                port=self.port,
                baudrate=self.baud,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=self.READ_TIMEOUT,
                xonxoff=False,
                rtscts=False,
            )
            self._connected = True
            self.logger.info(f"BK1687B connected on {self.port} @ {self.baud}")
            # Identify
            idn = self.identify()
            if idn:
                self.logger.info(f"PSU IDN: {idn}")
            return True
        except serial.SerialException as e:
            self.logger.error(f"BK1687B connect failed: {e}")
            return False

    def disconnect(self):
        if self._serial and self._serial.is_open:
            self.output_off()
            self._serial.close()
        self._connected = False
        self.logger.info("BK1687B disconnected.")

    @property
    def is_connected(self) -> bool:
        return self._connected and self._serial is not None and self._serial.is_open

    # ── Low-level I/O ───────────────────────────────────────────────────────

    def _send(self, cmd: str) -> Optional[str]:
        if not self.is_connected:
            self.logger.warning(f"PSU not connected, simulating: {cmd}")
            return "OK"
        with self._lock:
            try:
                raw = (cmd + self.TERMINATOR).encode("ascii")
                self._serial.reset_input_buffer()
                self._serial.write(raw)
                time.sleep(0.05)
                if "?" in cmd or cmd.upper().startswith("MEAS"):
                    response = self._serial.readline().decode("ascii", errors="ignore").strip()
                    return response
                return None
            except serial.SerialException as e:
                self.logger.error(f"PSU serial error: {e}")
                return None

    # ── SCPI Commands ────────────────────────────────────────────────────────

    def identify(self) -> Optional[str]:
        return self._send("*IDN?")

    def reset(self):
        self._send("*RST")
        time.sleep(1)

    def set_voltage(self, volts: float):
        """Set output voltage limit (CV mode)."""
        cmd = f"VOLT {volts:.3f}"
        self._send(cmd)
        self.logger.info(f"PSU voltage set: {volts:.3f} V")

    def set_current(self, amps: float):
        """Set output current limit (CC mode)."""
        cmd = f"CURR {amps:.3f}"
        self._send(cmd)
        self.logger.info(f"PSU current limit set: {amps:.3f} A")

    def set_ovp(self, volts: float):
        """Set over-voltage protection threshold."""
        self._send(f"VOLT:PROT {volts:.3f}")

    def set_ocp(self, amps: float):
        """Set over-current protection threshold."""
        self._send(f"CURR:PROT {amps:.3f}")

    def output_on(self):
        self._send("OUTP ON")
        self.logger.info("PSU output ON")

    def output_off(self):
        self._send("OUTP OFF")
        self.logger.info("PSU output OFF")

    def measure_voltage(self) -> Optional[float]:
        resp = self._send("MEAS:VOLT?")
        try:
            return float(resp) if resp else None
        except ValueError:
            return None

    def measure_current(self) -> Optional[float]:
        resp = self._send("MEAS:CURR?")
        try:
            return float(resp) if resp else None
        except ValueError:
            return None

    def measure_power(self) -> Optional[float]:
        v = self.measure_voltage()
        i = self.measure_current()
        if v is not None and i is not None:
            return round(v * i, 4)
        return None

    def read_status(self) -> dict:
        return {
            "voltage_set": self._send("VOLT?"),
            "current_set": self._send("CURR?"),
            "voltage_meas": self.measure_voltage(),
            "current_meas": self.measure_current(),
        }

    # ── Helper: Power Cycle ECU ──────────────────────────────────────────────

    def power_cycle(self, off_time: float = 2.0):
        """Turn output off, wait, then back on. Useful for ECU resets."""
        self.output_off()
        time.sleep(off_time)
        self.output_on()
        self.logger.info(f"Power cycled (off for {off_time}s)")

    def ramp_voltage(self, target: float, step: float = 0.5, delay: float = 0.2):
        """Slowly ramp voltage to target from current level."""
        current = self.measure_voltage() or 0.0
        direction = 1 if target >= current else -1
        v = current
        while (direction == 1 and v < target) or (direction == -1 and v > target):
            v = round(v + direction * step, 3)
            if (direction == 1 and v > target) or (direction == -1 and v < target):
                v = target
            self.set_voltage(v)
            time.sleep(delay)
        self.logger.info(f"Ramp complete: {target} V")
