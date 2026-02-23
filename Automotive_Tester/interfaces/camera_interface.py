"""
USB Camera Interface
Captures frames from USB camera for visual inspection / test evidence.
Uses OpenCV (cv2). Falls back to PIL/Pillow for basic capture if cv2 unavailable.

Install: pip install opencv-python pillow
"""

import logging
import time
import threading
from pathlib import Path
from datetime import datetime
from typing import Optional, Tuple

try:
    import cv2
    import numpy as np
    _HAS_CV2 = True
except ImportError:
    _HAS_CV2 = False

try:
    from PIL import Image, ImageGrab
    _HAS_PIL = True
except ImportError:
    _HAS_PIL = False


class CameraInterface:
    """
    USB Camera capture interface.
    
    Features:
      - Live preview thread
      - Snapshot to file (timestamped)
      - Record video clips (optional)
      - Frame callback for UI integration
    """

    def __init__(self, device_index: int = 0, resolution: Tuple[int, int] = (1280, 720),
                 snapshot_dir: Optional[Path] = None):
        self.device_index = device_index
        self.resolution = resolution
        self.snapshot_dir = snapshot_dir or Path("logs/camera")
        self.snapshot_dir.mkdir(parents=True, exist_ok=True)
        self.logger = logging.getLogger("tester.camera")
        self._cap = None
        self._connected = False
        self._preview_active = False
        self._stop = threading.Event()
        self._frame_callbacks = []
        self._latest_frame = None
        self._lock = threading.Lock()
        self._video_writer = None

    @staticmethod
    def list_cameras() -> list[int]:
        """Return indices of available cameras."""
        available = []
        if _HAS_CV2:
            for i in range(8):
                cap = cv2.VideoCapture(i)
                if cap.isOpened():
                    available.append(i)
                    cap.release()
        return available

    def connect(self) -> bool:
        if not _HAS_CV2:
            self.logger.warning("OpenCV not installed; camera unavailable.")
            return False
        try:
            self._cap = cv2.VideoCapture(self.device_index)
            if not self._cap.isOpened():
                self.logger.error(f"Camera device {self.device_index} not found.")
                return False
            self._cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.resolution[0])
            self._cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.resolution[1])
            self._connected = True
            self.logger.info(f"Camera connected: device {self.device_index} @ {self.resolution}")
            # Start capture thread
            self._stop.clear()
            threading.Thread(target=self._capture_loop, daemon=True).start()
            return True
        except Exception as e:
            self.logger.error(f"Camera connect error: {e}")
            return False

    def disconnect(self):
        self._stop.set()
        if self._video_writer:
            self._video_writer.release()
            self._video_writer = None
        if self._cap:
            self._cap.release()
        self._connected = False
        self.logger.info("Camera disconnected.")

    @property
    def is_connected(self) -> bool:
        return self._connected

    def snapshot(self, label: str = "") -> Optional[Path]:
        """Capture a single frame and save to disk."""
        with self._lock:
            frame = self._latest_frame
        if frame is None:
            self.logger.warning("No frame available for snapshot.")
            return None
        ts = datetime.now().strftime("%Y%m%d_%H%M%S_%f")
        name = f"{ts}_{label}.jpg" if label else f"{ts}.jpg"
        path = self.snapshot_dir / name
        cv2.imwrite(str(path), frame)
        self.logger.info(f"Snapshot saved: {path}")
        return path

    def start_recording(self, filename: Optional[str] = None, fps: int = 15):
        if not self._connected:
            return
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        fname = filename or f"video_{ts}.avi"
        path = self.snapshot_dir / fname
        fourcc = cv2.VideoWriter_fourcc(*"XVID")
        w, h = self.resolution
        self._video_writer = cv2.VideoWriter(str(path), fourcc, fps, (w, h))
        self.logger.info(f"Recording started: {path}")

    def stop_recording(self):
        if self._video_writer:
            self._video_writer.release()
            self._video_writer = None
            self.logger.info("Recording stopped.")

    def add_frame_callback(self, cb):
        """cb(frame: np.ndarray) called on each captured frame."""
        self._frame_callbacks.append(cb)

    def get_latest_frame(self):
        with self._lock:
            return self._latest_frame

    def _capture_loop(self):
        while not self._stop.is_set():
            if self._cap and self._cap.isOpened():
                ret, frame = self._cap.read()
                if ret:
                    with self._lock:
                        self._latest_frame = frame
                    if self._video_writer:
                        self._video_writer.write(frame)
                    for cb in self._frame_callbacks:
                        try:
                            cb(frame)
                        except Exception:
                            pass
            time.sleep(0.033)  # ~30 fps
