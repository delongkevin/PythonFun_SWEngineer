"""
USB camera interface using OpenCV.

Gracefully degrades when cv2 is not installed.
"""
from __future__ import annotations

import logging
import os
import threading
import time
from pathlib import Path
from typing import TYPE_CHECKING, Callable, Optional, Union

if TYPE_CHECKING:
    import cv2 as _cv2_type

logger = logging.getLogger(__name__)

try:
    import cv2 as _cv2
    _CV2_AVAILABLE = True
except ImportError:
    _cv2 = None  # type: ignore[assignment]
    _CV2_AVAILABLE = False
    logger.warning("cv2 (opencv-python) not available – camera features disabled.")

try:
    from PIL import Image as _PILImage, ImageTk as _PILImageTk
    _PIL_AVAILABLE = True
except ImportError:
    _PILImage = None    # type: ignore[assignment]
    _PILImageTk = None  # type: ignore[assignment]
    _PIL_AVAILABLE = False


# Type alias for a raw OpenCV frame (numpy ndarray)
Frame = "object"


class CameraInterface:
    """Manages a USB camera via OpenCV.

    Usage::

        cam = CameraInterface()
        cam.connect(index=0)
        frame = cam.capture_frame()
        cam.save_frame("snapshot.png", frame)
        cam.start_stream(callback=my_fn)
        cam.stop_stream()
        cam.disconnect()
    """

    def __init__(self, snapshot_dir: "Optional[Union[str, Path]]" = None) -> None:
        self._cap: "Optional[_cv2_type.VideoCapture]" = None
        self._index: int = 0
        self._connected: bool = False
        self._streaming: bool = False
        self._stream_thread: Optional[threading.Thread] = None
        self._stop_event = threading.Event()
        self._snapshot_dir = snapshot_dir

    # ------------------------------------------------------------------
    # device_index property
    # ------------------------------------------------------------------

    @property
    def device_index(self) -> int:
        """Camera device index used by :meth:`connect`."""
        return self._index

    @device_index.setter
    def device_index(self, value: int) -> None:
        self._index = int(value)

    # ------------------------------------------------------------------
    # Connection lifecycle
    # ------------------------------------------------------------------

    def connect(self, index: "Optional[int]" = None) -> bool:
        """Open the camera at the given device index.

        Args:
            index: OpenCV camera index (0 = default camera).  When *None*
                the value of :attr:`device_index` is used.

        Returns:
            True on success, False if cv2 is unavailable or camera not found.
        """
        if not _CV2_AVAILABLE:
            logger.error("Cannot connect camera: cv2 is not installed.")
            return False
        if index is None:
            index = self._index
        try:
            cap = _cv2.VideoCapture(index)
            if not cap.isOpened():
                logger.error("Camera index %d could not be opened.", index)
                return False
            self._cap = cap
            self._index = index
            self._connected = True
            logger.info("Camera connected at index %d.", index)
            return True
        except Exception as exc:
            logger.error("Camera connect exception: %s", exc)
            return False

    def disconnect(self) -> None:
        """Release the camera resource."""
        self.stop_stream()
        if self._cap is not None and _CV2_AVAILABLE:
            try:
                self._cap.release()  # type: ignore[attr-defined]
            except Exception as exc:
                logger.warning("Camera disconnect warning: %s", exc)
            finally:
                self._cap = None
                self._connected = False
                logger.info("Camera disconnected.")

    # ------------------------------------------------------------------
    # Frame capture
    # ------------------------------------------------------------------

    def capture_frame(self) -> Optional[Frame]:
        """Grab a single frame from the camera.

        Returns:
            An OpenCV frame (numpy ndarray), or None on failure.
        """
        if not self._connected or self._cap is None:
            logger.error("capture_frame called but camera is not connected.")
            return None
        try:
            ret, frame = self._cap.read()  # type: ignore[attr-defined]
            if not ret:
                logger.warning("Camera failed to read a frame.")
                return None
            return frame
        except Exception as exc:
            logger.error("capture_frame exception: %s", exc)
            return None

    def save_frame(self, path: str, frame: Optional[Frame] = None) -> bool:
        """Save a frame to disk as an image file.

        Args:
            path:  Destination file path (extension determines format).
            frame: Frame to save; if None, a new frame is captured.

        Returns:
            True on success.
        """
        if not _CV2_AVAILABLE:
            logger.error("Cannot save frame: cv2 is not installed.")
            return False
        if frame is None:
            frame = self.capture_frame()
        if frame is None:
            logger.error("save_frame: no frame available.")
            return False
        try:
            os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
            _cv2.imwrite(path, frame)  # type: ignore[attr-defined]
            logger.info("Frame saved to %s.", path)
            return True
        except Exception as exc:
            logger.error("save_frame exception: %s", exc)
            return False

    def snapshot(self, label: str = "snap") -> "Optional[str]":
        """Capture a single frame and save it to :attr:`_snapshot_dir`.

        Args:
            label: Short label included in the file name.

        Returns:
            Saved file path on success, ``None`` on failure.
        """
        frame = self.capture_frame()
        if frame is None:
            logger.error("snapshot: no frame captured.")
            return None
        ts = time.strftime("%Y%m%d_%H%M%S")
        snap_dir = self._snapshot_dir if self._snapshot_dir is not None else "snapshots"
        path = os.path.join(str(snap_dir), f"{label}_{ts}.png")
        if self.save_frame(path, frame):
            return path
        return None

    # ------------------------------------------------------------------
    # Streaming (background thread, push frames via callback)
    # ------------------------------------------------------------------

    def start_stream(self, callback: Optional[Callable[[Frame], None]] = None) -> bool:
        """Start reading frames in a background thread.

        Args:
            callback: Optional callable invoked with each new frame.

        Returns:
            True if streaming was started.
        """
        if not self._connected:
            logger.error("start_stream called but camera is not connected.")
            return False
        if self._streaming:
            logger.warning("Stream already running.")
            return True
        self._stop_event.clear()
        self._streaming = True
        self._stream_thread = threading.Thread(
            target=self._stream_loop,
            args=(callback,),
            daemon=True,
            name="CameraStream",
        )
        self._stream_thread.start()
        logger.info("Camera stream started.")
        return True

    def stop_stream(self) -> None:
        """Signal the streaming thread to stop and wait for it to exit."""
        if self._streaming:
            self._stop_event.set()
            if self._stream_thread is not None:
                self._stream_thread.join(timeout=2.0)
            self._streaming = False
            logger.info("Camera stream stopped.")

    def _stream_loop(self, callback: Optional[Callable[[Frame], None]]) -> None:
        """Internal frame-grab loop executed in a daemon thread."""
        while not self._stop_event.is_set():
            frame = self.capture_frame()
            if frame is not None and callback is not None:
                try:
                    callback(frame)
                except Exception as exc:
                    logger.warning("Camera stream callback raised: %s", exc)

    # ------------------------------------------------------------------
    # PIL / tkinter helper
    # ------------------------------------------------------------------

    @staticmethod
    def frame_to_photoimage(
        frame: Frame,
        width: int = 0,
        height: int = 0,
    ) -> Optional[object]:
        """Convert an OpenCV BGR frame to a tkinter-compatible PhotoImage.

        Args:
            frame:  OpenCV ndarray (BGR).
            width:  Target width in pixels.  When both *width* and *height*
                    are non-zero the image is resized to fit that rectangle
                    before conversion.
            height: Target height in pixels.

        Returns:
            A PIL.ImageTk.PhotoImage object, or None if PIL is unavailable.
        """
        if not _PIL_AVAILABLE or not _CV2_AVAILABLE:
            return None
        try:
            rgb = _cv2.cvtColor(frame, _cv2.COLOR_BGR2RGB)  # type: ignore[attr-defined]
            img = _PILImage.fromarray(rgb)  # type: ignore[attr-defined]
            if width > 0 and height > 0:
                img = img.resize((width, height), _PILImage.LANCZOS)  # type: ignore[attr-defined]
            return _PILImageTk.PhotoImage(img)  # type: ignore[attr-defined]
        except Exception as exc:
            logger.warning("frame_to_photoimage failed: %s", exc)
            return None

    @property
    def is_connected(self) -> bool:
        """True if camera device is open."""
        return self._connected

    @property
    def is_streaming(self) -> bool:
        """True if background streaming is active."""
        return self._streaming
