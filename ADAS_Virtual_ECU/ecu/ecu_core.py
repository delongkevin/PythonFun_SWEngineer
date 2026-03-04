"""
ADAS ECU Core Controller

Top-level controller that integrates:
  - 4 virtual cameras (Front, Rear, Left, Right)
  - 12 USS sensors (4 front, 4 rear, 2 front-flank, 2 rear-flank)
  - Autonomous Parking Controller
  - Trailer Hitch Assist
  - Trailer Steering Guidance

The ECU runs at a configurable tick rate and exposes a single
``step()`` method that advances all subsystems by one cycle.
"""

from __future__ import annotations

import time
from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional

from .camera import CameraPosition, VirtualCamera
from .parking import AutonomousParkingController, ParkingState, ParkingType
from .trailer_hitch import TrailerHitchAssist, THAState
from .trailer_steering import TrailerSteeringGuidance, TSGState
from .uss import SENSOR_IDS, SensorZone, USSArray, USSReading


@dataclass
class ECUInputs:
    """
    All external inputs to the ECU for one processing cycle.

    scene_objects : list[dict]
        Each dict: ``{"type": str, "distance_m": float, "azimuth_deg": float}``
        Objects visible to any camera.

    uss_distances : dict[str, float]
        True distances for each of the 12 USS sensors.
        Missing entries default to open space (> 5 m).

    vehicle_speed_mps : float
        Signed vehicle speed (negative = reversing).

    steering_angle_deg : float
        Current steering wheel angle (positive = right).

    trailer_hitch_offset_px : tuple | None
        Pixel offset (dx, dy) of hitch coupler from image centre.
        ``None`` if no trailer is attached.

    trailer_articulation_deg : float
        Current trailer articulation (hitch) angle.

    lane_offset_m : float
        Lateral offset from lane centre (front camera signal).
    """
    scene_objects: List[Dict[str, Any]] = field(default_factory=list)
    uss_distances: Dict[str, float] = field(default_factory=dict)
    vehicle_speed_mps: float = 0.0
    steering_angle_deg: float = 0.0
    trailer_hitch_offset_px: Optional[tuple] = None
    trailer_articulation_deg: float = 0.0
    lane_offset_m: float = 0.0


@dataclass
class ECUOutputs:
    """All outputs from the ECU for one processing cycle."""
    camera_frames: Dict[str, Any] = field(default_factory=dict)
    uss_readings: List[USSReading] = field(default_factory=list)
    parking_status: Optional[Any] = None
    tha_status: Optional[Any] = None
    tsg_status: Optional[Any] = None
    system_health: str = "OK"
    active_features: List[str] = field(default_factory=list)
    timestamp_ms: float = 0.0


class ADASECUCore:
    """
    Main ADAS ECU controller.

    Instantiate once and call ``step(inputs)`` every processing cycle
    (typically 10–100 ms).
    """

    # Feature flags
    FEATURE_PARKING = "autonomous_parking"
    FEATURE_THA = "trailer_hitch_assist"
    FEATURE_TSG = "trailer_steering_guidance"

    def __init__(self, seed: Optional[int] = 42) -> None:
        # 4 cameras
        self.cameras: Dict[CameraPosition, VirtualCamera] = {
            pos: VirtualCamera(pos, seed=(seed + i) if seed else None)
            for i, pos in enumerate(CameraPosition)
        }
        # 12 USS sensors
        self.uss_array = USSArray(seed=seed)

        # Feature subsystems
        self.parking = AutonomousParkingController()
        self.tha = TrailerHitchAssist()
        self.tsg = TrailerSteeringGuidance()

        self._active_features: List[str] = []
        self._tick = 0

    # ------------------------------------------------------------------
    # Feature activation / deactivation
    # ------------------------------------------------------------------

    def activate_parking(self, parking_type: ParkingType = ParkingType.PERPENDICULAR) -> None:
        self.parking.request_parking(parking_type)
        if self.FEATURE_PARKING not in self._active_features:
            self._active_features.append(self.FEATURE_PARKING)

    def deactivate_parking(self) -> None:
        self.parking.abort()
        self._active_features = [f for f in self._active_features if f != self.FEATURE_PARKING]

    def activate_tha(self) -> None:
        self.tha.activate()
        if self.FEATURE_THA not in self._active_features:
            self._active_features.append(self.FEATURE_THA)

    def deactivate_tha(self) -> None:
        self.tha.deactivate()
        self._active_features = [f for f in self._active_features if f != self.FEATURE_THA]

    def activate_tsg(self) -> None:
        self.tsg.activate()
        if self.FEATURE_TSG not in self._active_features:
            self._active_features.append(self.FEATURE_TSG)

    def deactivate_tsg(self) -> None:
        self.tsg.deactivate()
        self._active_features = [f for f in self._active_features if f != self.FEATURE_TSG]

    # ------------------------------------------------------------------
    # Main processing loop
    # ------------------------------------------------------------------

    def step(self, inputs: ECUInputs) -> ECUOutputs:
        """Run one ECU processing cycle and return all outputs."""
        self._tick += 1
        t_ms = time.monotonic() * 1000

        # ── Build camera scene context ────────────────────────────────
        hitch_ctx = None
        if inputs.trailer_hitch_offset_px is not None:
            hitch_ctx = {"offset_px": inputs.trailer_hitch_offset_px}

        camera_scene = {
            "objects": inputs.scene_objects,
            "lane_offset_m": inputs.lane_offset_m,
            "trailer_hitch": hitch_ctx,
        }

        # ── Process all 4 cameras ──────────────────────────────────────
        frames = {
            pos: cam.update(camera_scene)
            for pos, cam in self.cameras.items()
        }

        # ── Process all 12 USS sensors ────────────────────────────────
        uss_readings = self.uss_array.scan(inputs.uss_distances)
        uss_map = {r.sensor_id: r.distance_m for r in uss_readings}
        rear_uss_min = self.uss_array.get_zone_min(SensorZone.REAR, uss_readings)

        # ── Autonomous Parking ────────────────────────────────────────
        parking_status = None
        if self.FEATURE_PARKING in self._active_features:
            rear_cam_detections = frames[CameraPosition.REAR].detections
            parking_status = self.parking.update(
                uss_readings=uss_map,
                camera_detections=rear_cam_detections,
                vehicle_speed_mps=inputs.vehicle_speed_mps,
            )
            # Auto-remove feature on completion / abort
            if parking_status.state in (ParkingState.PARKED, ParkingState.ABORTED):
                self._active_features = [
                    f for f in self._active_features if f != self.FEATURE_PARKING
                ]

        # ── Trailer Hitch Assist ──────────────────────────────────────
        tha_status = None
        if self.FEATURE_THA in self._active_features:
            rear_frame = frames[CameraPosition.REAR]
            tha_status = self.tha.update(
                camera_frame=rear_frame,
                rear_uss_min_m=rear_uss_min,
            )
            if tha_status.state == THAState.COUPLED:
                self._active_features = [
                    f for f in self._active_features if f != self.FEATURE_THA
                ]

        # ── Trailer Steering Guidance ─────────────────────────────────
        tsg_status = None
        if self.FEATURE_TSG in self._active_features:
            tsg_status = self.tsg.update(
                articulation_angle_deg=inputs.trailer_articulation_deg,
                vehicle_steer_deg=inputs.steering_angle_deg,
                vehicle_speed_mps=inputs.vehicle_speed_mps,
            )

        # ── Health check ──────────────────────────────────────────────
        health = self._health_check(uss_readings)

        return ECUOutputs(
            camera_frames={pos.value: f for pos, f in frames.items()},
            uss_readings=uss_readings,
            parking_status=parking_status,
            tha_status=tha_status,
            tsg_status=tsg_status,
            system_health=health,
            active_features=list(self._active_features),
            timestamp_ms=t_ms,
        )

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    @staticmethod
    def _health_check(uss_readings: List[USSReading]) -> str:
        """Simple health check: warn if critical obstacle detected."""
        critical = [r for r in uss_readings if r.alert_level == "critical"]
        if critical:
            ids = ", ".join(r.sensor_id for r in critical)
            return f"CRITICAL OBSTACLE — {ids}"
        return "OK"

    @property
    def tick(self) -> int:
        return self._tick
