"""
Serial Terminal Manager
Manages up to 4 serial USB COM ports (like TeraTerm / PuTTY sessions).
Captures all incoming data to per-port log files.
Provides send/receive API for test scripts.
"""

import serial
import serial.tools.list_ports
import threading
import time
import logging
from typing import Optional, Callable
from pathlib import Path
from datetime import datetime


class SerialTerminal:
    """A single serial port with buffered reading and logging."""

    def __init__(self, name: str, port: str, baud: int = 115200,
                 log_dir: Optional[Path] = None):
        self.name = name
        self.port = port
        self.baud = baud
        self.log_dir = log_dir
        self.logger = logging.getLogger(f"tester.serial.{name}")
        self._serial: Optional[serial.Serial] = None
        self._connected = False
        self._rx_buffer: list[str] = []
        self._rx_callbacks: list[Callable] = []
        self._stop = threading.Event()
        self._reader_thread: Optional[threading.Thread] = None
        self._log_file = None

    def connect(self, bytesize=serial.EIGHTBITS, parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE, timeout=0.1) -> bool:
        try:
            self._serial = serial.Serial(
                port=self.port, baudrate=self.baud,
                bytesize=bytesize, parity=parity,
                stopbits=stopbits, timeout=timeout
            )
            self._connected = True
            # Open log file
            if self.log_dir:
                ts = datetime.now().strftime("%Y%m%d_%H%M%S")
                log_path = self.log_dir / f"{self.name}_{ts}.log"
                self._log_file = open(log_path, "w", buffering=1)
            # Start reader
            self._stop.clear()
            self._reader_thread = threading.Thread(target=self._read_loop, daemon=True)
            self._reader_thread.start()
            self.logger.info(f"Serial {self.name} connected: {self.port} @ {self.baud}")
            return True
        except serial.SerialException as e:
            self.logger.error(f"Serial {self.name} connect failed: {e}")
            return False

    def disconnect(self):
        self._stop.set()
        if self._serial and self._serial.is_open:
            self._serial.close()
        if self._log_file:
            self._log_file.close()
        self._connected = False
        self.logger.info(f"Serial {self.name} disconnected.")

    @property
    def is_connected(self) -> bool:
        return self._connected and self._serial is not None and self._serial.is_open

    def send(self, data: str, add_newline: bool = True):
        if not self.is_connected:
            self.logger.warning(f"[{self.name}] Not connected, cannot send.")
            return
        payload = (data + "\r\n") if add_newline else data
        self._serial.write(payload.encode("utf-8", errors="replace"))
        self.logger.debug(f"[{self.name}] TX: {data!r}")

    def send_bytes(self, data: bytes):
        if not self.is_connected:
            return
        self._serial.write(data)

    def read_buffer(self) -> list[str]:
        buf = list(self._rx_buffer)
        self._rx_buffer.clear()
        return buf

    def wait_for(self, pattern: str, timeout: float = 10.0) -> Optional[str]:
        """Block until pattern found in received data or timeout."""
        deadline = time.time() + timeout
        accumulated = ""
        while time.time() < deadline:
            lines = self.read_buffer()
            for line in lines:
                accumulated += line
                if pattern in accumulated:
                    return accumulated
            time.sleep(0.1)
        return None

    def add_rx_callback(self, cb: Callable[[str, str], None]):
        """cb(terminal_name, line)"""
        self._rx_callbacks.append(cb)

    def _read_loop(self):
        partial = b""
        while not self._stop.is_set():
            try:
                if self._serial and self._serial.in_waiting:
                    chunk = self._serial.read(self._serial.in_waiting)
                    partial += chunk
                    while b"\n" in partial:
                        line_bytes, partial = partial.split(b"\n", 1)
                        line = line_bytes.decode("utf-8", errors="replace").rstrip("\r")
                        self._rx_buffer.append(line)
                        if self._log_file:
                            ts = datetime.now().strftime("%H:%M:%S.%f")[:-3]
                            self._log_file.write(f"[{ts}] {line}\n")
                        for cb in self._rx_callbacks:
                            try:
                                cb(self.name, line)
                            except Exception:
                                pass
                else:
                    time.sleep(0.02)
            except serial.SerialException as e:
                self.logger.error(f"[{self.name}] Read error: {e}")
                self._connected = False
                break


class SerialManager:
    """
    Manages up to 4 named serial terminal connections.
    Provides a unified API and per-terminal logging.
    """

    MAX_PORTS = 4

    def __init__(self, log_dir: Optional[Path] = None):
        self.log_dir = log_dir
        self.logger = logging.getLogger("tester.serial_manager")
        self.terminals: dict[str, SerialTerminal] = {}

    @staticmethod
    def list_available_ports() -> list[dict]:
        ports = []
        for p in serial.tools.list_ports.comports():
            ports.append({
                "device": p.device,
                "description": p.description,
                "hwid": p.hwid,
            })
        return ports

    def add_terminal(self, name: str, port: str, baud: int = 115200,
                     autoconnect: bool = True) -> SerialTerminal:
        if len(self.terminals) >= self.MAX_PORTS:
            raise ValueError(f"Maximum {self.MAX_PORTS} serial ports supported.")
        term = SerialTerminal(name, port, baud, self.log_dir)
        self.terminals[name] = term
        if autoconnect:
            term.connect()
        return term

    def remove_terminal(self, name: str):
        if name in self.terminals:
            self.terminals[name].disconnect()
            del self.terminals[name]

    def get(self, name: str) -> Optional[SerialTerminal]:
        return self.terminals.get(name)

    def disconnect_all(self):
        for term in self.terminals.values():
            term.disconnect()

    def broadcast(self, data: str):
        """Send same string to all connected terminals."""
        for term in self.terminals.values():
            if term.is_connected:
                term.send(data)

    def status(self) -> dict:
        return {
            name: {
                "port": t.port,
                "baud": t.baud,
                "connected": t.is_connected,
            }
            for name, t in self.terminals.items()
        }
