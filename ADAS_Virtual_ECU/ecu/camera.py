"""
Virtual Camera Module - Simulates 4 surround-view cameras for the ADAS ECU.

Cameras:
  - FRONT  : Wide-angle (120°), 50 m range — obstacle/lane/sign detection
  - REAR   : Wide-angle (120°), 30 m range — parking / trailer hitch view
  - LEFT   : Fisheye  (180°), 10 m range — blind-spot / side-obstacle
  - RIGHT  : Fisheye  (180°), 10 m range — blind-spot / side-obstacle
"""

from __future__ import annotations

import math
import random
from dataclasses import dataclass, field
from enum import Enum
from typing import List, Optional, Tuple


class CameraPosition(Enum):
    FRONT = "front"
    REAR = "rear"
    LEFT = "left"
    RIGHT = "right"


@dataclass
class DetectedObject:
    """Represents an object detected by a virtual camera."""
    label: str                          # e.g. "vehicle", "pedestrian", "parking_slot"
    distance_m: float                   # metres from camera
    azimuth_deg: float                  # horizontal angle relative to camera boresight
    confidence: float                   # 0.0 – 1.0
    bbox: Tuple[int, int, int, int] = field(default_factory=lambda: (0, 0, 0, 0))
    # (x1, y1, x2, y2) in a 640×480 virtual image space


@dataclass
class CameraFrame:
    """One processed frame from a virtual camera."""
    camera_id: CameraPosition
    frame_number: int
    detections: List[DetectedObject] = field(default_factory=list)
    lane_offset_m: float = 0.0          # lateral offset from lane centre
    trailer_hitch_visible: bool = False
    trailer_hitch_offset_px: Tuple[int, int] = (0, 0)  # px offset from target centre


# Camera hardware specifications
_CAMERA_SPECS = {
    CameraPosition.FRONT: {
        "fov_deg": 120,
        "range_m": 50,
        "resolution": (1280, 720),
        "mount_height_m": 1.3,
    },
    CameraPosition.REAR: {
        "fov_deg": 120,
        "range_m": 30,
        "resolution": (1280, 720),
        "mount_height_m": 0.9,
    },
    CameraPosition.LEFT: {
        "fov_deg": 180,
        "range_m": 10,
        "resolution": (640, 480),
        "mount_height_m": 0.8,
    },
    CameraPosition.RIGHT: {
        "fov_deg": 180,
        "range_m": 10,
        "resolution": (640, 480),
        "mount_height_m": 0.8,
    },
}

# Object types that each camera can detect
_DETECTABLE_BY_CAMERA = {
    CameraPosition.FRONT: [
        "vehicle", "pedestrian", "cyclist", "sign", "traffic_light", "lane_marking",
    ],
    CameraPosition.REAR: [
        "vehicle", "pedestrian", "cyclist", "parking_slot", "trailer_hitch", "cone",
    ],
    CameraPosition.LEFT: [
        "vehicle", "pedestrian", "cyclist", "lane_marking", "curb",
    ],
    CameraPosition.RIGHT: [
        "vehicle", "pedestrian", "cyclist", "lane_marking", "curb",
    ],
}


class VirtualCamera:
    """
    Simulates a single surround-view camera on the ADAS ECU.

    The simulation generates plausible detections based on the current
    vehicle-scene context passed via ``update()``.
    """

    def __init__(self, position: CameraPosition, seed: Optional[int] = None) -> None:
        self.position = position
        self.specs = _CAMERA_SPECS[position]
        self._rng = random.Random(seed)
        self._frame_counter = 0
        self._last_frame: Optional[CameraFrame] = None

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def update(self, scene_context: dict) -> CameraFrame:
        """
        Generate a simulated camera frame for the given scene.

        Parameters
        ----------
        scene_context : dict
            Keys understood:
              - ``objects``        : list[dict] with ``type``, ``distance_m``, ``azimuth_deg``
              - ``lane_offset_m``  : float
              - ``trailer_hitch``  : dict | None — with ``offset_px`` tuple
        """
        self._frame_counter += 1
        detections: List[DetectedObject] = []

        for obj in scene_context.get("objects", []):
            obj_type = obj.get("type", "vehicle")
            if obj_type not in _DETECTABLE_BY_CAMERA[self.position]:
                continue
            dist = obj.get("distance_m", 10.0)
            azimuth = obj.get("azimuth_deg", 0.0)
            if dist > self.specs["range_m"]:
                continue
            half_fov = self.specs["fov_deg"] / 2
            if abs(azimuth) > half_fov:
                continue

            # Confidence degrades with distance and angle
            conf_dist = 1.0 - (dist / self.specs["range_m"]) * 0.5
            conf_az = 1.0 - (abs(azimuth) / half_fov) * 0.3
            confidence = max(0.1, min(1.0, conf_dist * conf_az + self._rng.uniform(-0.05, 0.05)))

            w, h = self.specs["resolution"]
            bbox = self._estimate_bbox(dist, azimuth, obj_type, w, h)
            detections.append(DetectedObject(
                label=obj_type,
                distance_m=round(dist + self._rng.uniform(-0.1, 0.1), 2),
                azimuth_deg=round(azimuth + self._rng.uniform(-0.5, 0.5), 2),
                confidence=round(confidence, 3),
                bbox=bbox,
            ))

        hitch_visible = False
        hitch_offset = (0, 0)
        if self.position == CameraPosition.REAR:
            th = scene_context.get("trailer_hitch")
            if th:
                hitch_visible = True
                hitch_offset = th.get("offset_px", (0, 0))

        frame = CameraFrame(
            camera_id=self.position,
            frame_number=self._frame_counter,
            detections=detections,
            lane_offset_m=scene_context.get("lane_offset_m", 0.0),
            trailer_hitch_visible=hitch_visible,
            trailer_hitch_offset_px=hitch_offset,
        )
        self._last_frame = frame
        return frame

    @property
    def last_frame(self) -> Optional[CameraFrame]:
        return self._last_frame

    @property
    def fov_deg(self) -> float:
        return self.specs["fov_deg"]

    @property
    def range_m(self) -> float:
        return self.specs["range_m"]

    def __repr__(self) -> str:
        return (
            f"VirtualCamera(pos={self.position.value}, "
            f"fov={self.fov_deg}°, range={self.range_m}m)"
        )

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    def _estimate_bbox(
        self,
        distance_m: float,
        azimuth_deg: float,
        obj_type: str,
        img_w: int,
        img_h: int,
    ) -> Tuple[int, int, int, int]:
        """Project object to image-space bounding box (simplified pin-hole model)."""
        half_fov = self.specs["fov_deg"] / 2
        # Normalised horizontal position
        nx = (azimuth_deg / half_fov + 1) / 2          # 0=left, 1=right
        cx = int(nx * img_w)
        cy = img_h // 2

        # Object apparent size shrinks with distance
        size_base = {"vehicle": 80, "pedestrian": 40, "cyclist": 50,
                     "parking_slot": 120, "trailer_hitch": 30, "sign": 35,
                     "traffic_light": 25, "lane_marking": 200, "curb": 150,
                     "cone": 20}.get(obj_type, 40)
        scale = max(5, int(size_base * (1 - distance_m / (self.range_m * 1.5))))
        x1 = max(0, cx - scale // 2)
        y1 = max(0, cy - scale // 2)
        x2 = min(img_w, cx + scale // 2)
        y2 = min(img_h, cy + scale // 2)
        return (x1, y1, x2, y2)
