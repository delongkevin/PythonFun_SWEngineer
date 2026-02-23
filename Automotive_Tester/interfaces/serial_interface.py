"""
Serial port interface – manages up to 4 USB serial ports for terminal logging.

Each port runs a background thread that continuously reads data and writes it
to a timestamped log file, mimicking the behaviour of TeraTerm / PuTTY.
"""
from __future__ import annotations

import logging
import os
import threading
import time
from typing import Callable, Dict, List, Optional

import serial  # pyserial
import serial.tools.list_ports
from typing import IO

logger = logging.getLogger(__name__)

MAX_PORTS = 4
_READ_INTERVAL = 0.05   # seconds between read attempts when no data
_READ_CHUNK = 4096       # bytes per read attempt


class SerialPort:
    """Represents a single managed serial port with background logging."""

    def __init__(self, name: str) -> None:
        self.name = name
        self._serial: Optional[serial.Serial] = None
        self._port: str = ""
        self._baud: int = 115200
        self._connected: bool = False
        self._logging_active: bool = False
        self._log_thread: Optional[threading.Thread] = None
        self._stop_event = threading.Event()
        self._log_file: Optional[IO[str]] = None   # open file handle
        self._data_callback: Optional[Callable[[str, str], None]] = None

    # ------------------------------------------------------------------
    # Connection lifecycle
    # ------------------------------------------------------------------

    def connect(self, port: str, baud: int = 115200, timeout: float = 0.1) -> bool:
        """Open the serial port.

        Args:
            port:    Port name, e.g. 'COM4' or '/dev/ttyUSB0'.
            baud:    Baud rate.
            timeout: Read timeout in seconds (kept short so the thread stays responsive).

        Returns:
            True on success.
        """
        try:
            self._serial = serial.Serial(
                port=port,
                baudrate=baud,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=timeout,
            )
            self._port = port
            self._baud = baud
            self._connected = True
            logger.info("[%s] Connected to %s @ %d baud.", self.name, port, baud)
            return True
        except Exception as exc:
            logger.error("[%s] Connect failed on %s: %s", self.name, port, exc)
            return False

    def disconnect(self) -> None:
        """Stop logging and close the serial port."""
        self.stop_logging()
        if self._serial and self._serial.is_open:
            try:
                self._serial.close()
            except serial.SerialException as exc:
                logger.warning("[%s] Disconnect warning: %s", self.name, exc)
            finally:
                self._connected = False
                logger.info("[%s] Disconnected from %s.", self.name, self._port)

    # ------------------------------------------------------------------
    # Logging
    # ------------------------------------------------------------------

    def start_logging(
        self,
        logfile: str,
        data_callback: Optional[Callable[[str, str], None]] = None,
    ) -> bool:
        """Begin capturing port data to a log file.

        Args:
            logfile:       Path to the output log file (created / appended).
            data_callback: Optional callable(port_name, text) called for each chunk.

        Returns:
            True if logging started successfully.
        """
        if not self._connected or self._serial is None:
            logger.error("[%s] Cannot start logging: not connected.", self.name)
            return False
        if self._logging_active:
            logger.warning("[%s] Logging already active.", self.name)
            return True
        try:
            os.makedirs(os.path.dirname(os.path.abspath(logfile)), exist_ok=True)
            self._log_file = open(logfile, "a", encoding="utf-8", errors="replace")  # noqa: WPS515
        except OSError as exc:
            logger.error("[%s] Cannot open log file %s: %s", self.name, logfile, exc)
            return False
        self._data_callback = data_callback
        self._stop_event.clear()
        self._logging_active = True
        self._log_thread = threading.Thread(
            target=self._read_loop,
            daemon=True,
            name=f"SerialLog-{self.name}",
        )
        self._log_thread.start()
        logger.info("[%s] Logging started → %s", self.name, logfile)
        return True

    def stop_logging(self) -> None:
        """Stop the logging thread and flush/close the log file."""
        if self._logging_active:
            self._stop_event.set()
            if self._log_thread is not None:
                self._log_thread.join(timeout=2.0)
            self._logging_active = False
        if self._log_file is not None:
            try:
                self._log_file.flush()
                self._log_file.close()
            except OSError as exc:
                logger.warning("[%s] Log file close warning: %s", self.name, exc)
            finally:
                self._log_file = None
        logger.info("[%s] Logging stopped.", self.name)

    # ------------------------------------------------------------------
    # Internal
    # ------------------------------------------------------------------

    def _read_loop(self) -> None:
        """Background thread: drain the serial port and write to the log file."""
        while not self._stop_event.is_set():
            if self._serial is None or not self._serial.is_open:
                break
            try:
                waiting = self._serial.in_waiting
            except serial.SerialException as exc:
                logger.error("[%s] Serial read error: %s", self.name, exc)
                break
            if waiting:
                try:
                    raw = self._serial.read(min(waiting, _READ_CHUNK))
                    text = raw.decode(errors="replace")
                    timestamp = time.strftime("%H:%M:%S")
                    if self._log_file is not None:
                        self._log_file.write(f"[{timestamp}] {text}")
                        self._log_file.flush()
                    if self._data_callback is not None:
                        self._data_callback(self.name, text)
                except Exception as exc:
                    logger.error("[%s] Read loop exception: %s", self.name, exc)
            else:
                time.sleep(_READ_INTERVAL)

    @property
    def is_connected(self) -> bool:
        """True if the serial port is open."""
        return self._connected and self._serial is not None and self._serial.is_open

    @property
    def is_logging(self) -> bool:
        """True if background logging is active."""
        return self._logging_active


class SerialInterface:
    """Manages up to 4 named serial ports for multi-DUT terminal logging."""

    def __init__(self) -> None:
        self._ports: Dict[str, SerialPort] = {}

    # ------------------------------------------------------------------
    # Port management
    # ------------------------------------------------------------------

    def add_port(self, name: str) -> SerialPort:
        """Register a named port slot (does not open it yet).

        Args:
            name: Logical name, e.g. 'DUT1'.

        Returns:
            The :class:`SerialPort` instance.

        Raises:
            ValueError: If MAX_PORTS already registered.
        """
        if len(self._ports) >= MAX_PORTS:
            raise ValueError(f"Maximum of {MAX_PORTS} serial ports supported.")
        if name not in self._ports:
            self._ports[name] = SerialPort(name)
        return self._ports[name]

    def get_port(self, name: str) -> Optional[SerialPort]:
        """Retrieve a registered port by name."""
        return self._ports.get(name)

    def connect_port(self, name: str, port: str, baud: int = 115200) -> bool:
        """Connect a named port slot.

        Args:
            name: Logical name registered via :meth:`add_port`.
            port: OS port name.
            baud: Baud rate.
        """
        sp = self._ports.get(name)
        if sp is None:
            sp = self.add_port(name)
        return sp.connect(port, baud)

    def disconnect_all(self) -> None:
        """Disconnect all managed ports."""
        for sp in self._ports.values():
            sp.disconnect()

    def start_all_logging(self, log_dir: str) -> None:
        """Start logging on every connected port.

        Args:
            log_dir: Directory where log files will be created.
        """
        for sp in self._ports.values():
            if sp.is_connected:
                logfile = os.path.join(log_dir, f"{sp.name}_serial.log")
                sp.start_logging(logfile)

    def stop_all_logging(self) -> None:
        """Stop logging on all ports."""
        for sp in self._ports.values():
            sp.stop_logging()

    @property
    def ports(self) -> List[SerialPort]:
        """List of all registered SerialPort objects."""
        return list(self._ports.values())

    @staticmethod
    def list_available_ports() -> List[str]:
        """Return a list of available serial port names on this system."""
        return [p.device for p in serial.tools.list_ports.comports()]
