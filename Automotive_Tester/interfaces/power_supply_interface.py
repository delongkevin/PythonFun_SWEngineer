"""
BK Precision 1687b Power Supply interface via SCPI-like serial commands.

The 1687b communicates over RS-232/USB-serial at 9600 baud using a text
protocol where commands are terminated with \\r\\n and responses end with \\r\\n.
"""
from __future__ import annotations

import logging
import time
from typing import Optional, Tuple

try:
    import serial  # pyserial
    _SERIAL_AVAILABLE = True
except ImportError:
    serial = None  # type: ignore[assignment]
    _SERIAL_AVAILABLE = False

logger = logging.getLogger(__name__)

if not _SERIAL_AVAILABLE:
    logger.warning("pyserial not available – power supply serial features disabled.")

# Command strings ─────────────────────────────────────────────────────────────
_CMD_IDN = b"*IDN?\r\n"
_CMD_OUTPUT_ON = b"OUTPUT ON\r\n"
_CMD_OUTPUT_OFF = b"OUTPUT OFF\r\n"
_CMD_STATUS = b"STATUS?\r\n"
_CMD_VOLTAGE_FMT = "VSET1:{:.3f}\r\n"
_CMD_CURRENT_FMT = "ISET1:{:.3f}\r\n"
_CMD_VOLTAGE_READ = b"VOUT1?\r\n"
_CMD_CURRENT_READ = b"IOUT1?\r\n"
_RESPONSE_TIMEOUT = 2.0   # seconds to wait for a response line


class PowerSupplyInterface:
    """Driver for BK Precision 1687b bench power supply.

    Usage::

        ps = PowerSupplyInterface()
        ps.connect("COM3", baud=9600)
        ps.set_voltage(12.0)
        ps.set_current(1.5)
        ps.output_on()
        v, i = ps.read_status()
        ps.output_off()
        ps.disconnect()
    """

    def __init__(self) -> None:
        self._serial: Optional[serial.Serial] = None
        self._port: str = ""
        self._baud: int = 9600
        self._connected: bool = False

    # ------------------------------------------------------------------
    # Port / baud properties
    # ------------------------------------------------------------------

    @property
    def port(self) -> str:
        """Serial port name (e.g. 'COM3')."""
        return self._port

    @port.setter
    def port(self, value: str) -> None:
        self._port = value

    @property
    def baud(self) -> int:
        """Baud rate for the serial connection."""
        return self._baud

    @baud.setter
    def baud(self, value: int) -> None:
        self._baud = int(value)

    # ------------------------------------------------------------------
    # Connection lifecycle
    # ------------------------------------------------------------------

    def connect(self, port: str = "", baud: Optional[int] = None, timeout: float = 2.0) -> bool:
        """Open a serial connection to the power supply.

        If *port* is omitted (or empty), the last-stored :attr:`port` value is
        used.  If *baud* is ``None``, the last-stored :attr:`baud` value is used.

        Args:
            port:    Serial port name, e.g. 'COM3' or '/dev/ttyUSB0'.
            baud:    Baud rate (default 9600 for 1687b).  Pass ``None`` to reuse
                     the previously configured baud rate.
            timeout: Read timeout in seconds.

        Returns:
            True on success, False on failure.
        """
        if not _SERIAL_AVAILABLE:
            logger.error("pyserial is not installed – cannot connect to power supply.")
            return False
        conn_port = port or self._port
        conn_baud = baud if baud is not None else self._baud
        if not conn_port:
            logger.error("Power supply connect: no port specified.")
            return False
        try:
            self._serial = serial.Serial(
                port=conn_port,
                baudrate=conn_baud,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=timeout,
            )
            self._port = conn_port
            self._baud = conn_baud
            self._connected = True
            logger.info("Power supply connected on %s @ %d baud.", conn_port, conn_baud)
            return True
        except Exception as exc:
            logger.error("Power supply connect failed on %s: %s", conn_port, exc)
            self._connected = False
            return False

    def disconnect(self) -> None:
        """Close the serial connection."""
        if self._serial and self._serial.is_open:
            try:
                self._serial.close()
            except serial.SerialException as exc:
                logger.warning("Power supply disconnect warning: %s", exc)
            finally:
                self._connected = False
                logger.info("Power supply disconnected from %s.", self._port)

    # ------------------------------------------------------------------
    # Control commands
    # ------------------------------------------------------------------

    def set_voltage(self, volts: float) -> bool:
        """Set the output voltage set-point.

        Args:
            volts: Desired voltage in volts (0 – 30 V for channel 1).

        Returns:
            True if command was sent successfully.
        """
        cmd = _CMD_VOLTAGE_FMT.format(volts).encode()
        return self._send(cmd)

    def set_current(self, amps: float) -> bool:
        """Set the current limit.

        Args:
            amps: Desired current limit in amperes (0 – 5 A for channel 1).

        Returns:
            True if command was sent successfully.
        """
        cmd = _CMD_CURRENT_FMT.format(amps).encode()
        return self._send(cmd)

    def output_on(self) -> bool:
        """Enable the power supply output.

        Returns:
            True if command was sent successfully.
        """
        return self._send(_CMD_OUTPUT_ON)

    def output_off(self) -> bool:
        """Disable the power supply output.

        Returns:
            True if command was sent successfully.
        """
        return self._send(_CMD_OUTPUT_OFF)

    # ------------------------------------------------------------------
    # Status / telemetry
    # ------------------------------------------------------------------

    def read_status(self) -> Tuple[Optional[float], Optional[float]]:
        """Read actual output voltage and current.

        Returns:
            Tuple of (voltage_V, current_A), with None entries on failure.
        """
        voltage = self._query_float(_CMD_VOLTAGE_READ)
        current = self._query_float(_CMD_CURRENT_READ)
        return voltage, current

    def identify(self) -> str:
        """Send *IDN? and return the instrument identification string."""
        return self._query_str(_CMD_IDN)

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _send(self, cmd: bytes) -> bool:
        """Write a command to the serial port, no response expected."""
        if not self._connected or self._serial is None:
            logger.error("Power supply not connected – cannot send command.")
            return False
        try:
            self._serial.write(cmd)
            self._serial.flush()
            logger.debug("Power supply TX: %s", cmd.strip())
            return True
        except serial.SerialException as exc:
            logger.error("Power supply write error: %s", exc)
            return False

    def _query_str(self, cmd: bytes) -> str:
        """Send a command and return the response as a stripped string."""
        if not self._connected or self._serial is None:
            logger.error("Power supply not connected – cannot query.")
            return ""
        try:
            self._serial.reset_input_buffer()
            self._serial.write(cmd)
            self._serial.flush()
            deadline = time.monotonic() + _RESPONSE_TIMEOUT
            while time.monotonic() < deadline:
                if self._serial.in_waiting:
                    raw = self._serial.readline()
                    return raw.decode(errors="replace").strip()
                time.sleep(0.01)
            logger.warning("Power supply query timed out for: %s", cmd.strip())
            return ""
        except serial.SerialException as exc:
            logger.error("Power supply query error: %s", exc)
            return ""

    def _query_float(self, cmd: bytes) -> Optional[float]:
        """Send a command and parse the response as a float."""
        raw = self._query_str(cmd)
        if not raw:
            return None
        try:
            return float(raw)
        except ValueError:
            logger.warning("Could not parse float from response: '%s'", raw)
            return None

    @property
    def is_connected(self) -> bool:
        """True if the serial port is currently open."""
        return self._connected and self._serial is not None and self._serial.is_open

    # ------------------------------------------------------------------
    # Convenience wrappers
    # ------------------------------------------------------------------

    def measure_voltage(self) -> Optional[float]:
        """Read actual output voltage in volts."""
        return self._query_float(_CMD_VOLTAGE_READ)

    def measure_current(self) -> Optional[float]:
        """Read actual output current in amperes."""
        return self._query_float(_CMD_CURRENT_READ)

    def power_cycle(self, off_time: float = 2.0) -> None:
        """Turn output off, wait *off_time* seconds, then turn it back on.

        Args:
            off_time: Duration in seconds to keep the output off.
        """
        self.output_off()
        time.sleep(off_time)
        self.output_on()
        logger.info("Power cycled (off for %.1f s).", off_time)

    def refresh_connection(self) -> bool:
        """Disconnect then reconnect to release and re-acquire the serial port.

        Useful when another process was holding the port, or after a USB
        cable re-seat.  The previously configured :attr:`port` and
        :attr:`baud` are reused.

        Returns:
            True if the reconnection succeeded, False otherwise.
        """
        if self._connected:
            self.disconnect()
        time.sleep(0.5)
        if not self._port:
            logger.warning("refresh_connection: no port configured.")
            return False
        return self.connect(self._port, baud=self._baud)
