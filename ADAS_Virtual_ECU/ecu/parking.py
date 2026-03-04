"""
Autonomous Parking Controller
Supports parallel, perpendicular, and angled-bay parking manoeuvres.

State machine:
  IDLE → SCANNING → SLOT_DETECTED → ALIGNING → MANOEUVRING → PARKED

The controller fuses USS and rear-camera data to plan and execute a
multi-arc parking path.
"""

from __future__ import annotations

import math
from dataclasses import dataclass, field
from enum import Enum, auto
from typing import List, Optional, Tuple


class ParkingType(Enum):
    PARALLEL = "parallel"
    PERPENDICULAR = "perpendicular"
    ANGLED = "angled"


class ParkingState(Enum):
    IDLE = auto()
    SCANNING = auto()
    SLOT_DETECTED = auto()
    ALIGNING = auto()
    MANOEUVRING = auto()
    PARKED = auto()
    ABORTED = auto()


@dataclass
class ParkingSlot:
    """Describes a detected parking slot."""
    slot_type: ParkingType
    centre_x_m: float          # relative to vehicle at detection time
    centre_y_m: float
    width_m: float
    length_m: float
    heading_deg: float         # slot orientation (0 = same as vehicle)
    confidence: float          # 0 – 1


@dataclass
class PathPoint:
    """One waypoint in the parking path."""
    x_m: float
    y_m: float
    heading_deg: float
    speed_mps: float           # negative = reverse
    steer_deg: float           # steering wheel angle


@dataclass
class ParkingStatus:
    state: ParkingState
    slot: Optional[ParkingSlot]
    path: List[PathPoint]
    current_waypoint_idx: int
    progress_pct: float        # 0–100
    guidance_text: str
    front_clearance_m: float
    rear_clearance_m: float


# Vehicle geometry (sedan-class defaults)
_VEHICLE_LENGTH_M = 4.6
_VEHICLE_WIDTH_M = 1.9
_TURNING_RADIUS_M = 5.5        # minimum
_MIN_SLOT_PARALLEL_M = _VEHICLE_LENGTH_M + 0.8
_MIN_SLOT_PERP_M = _VEHICLE_WIDTH_M + 0.6


class AutonomousParkingController:
    """
    Fuses rear-camera slot detections and USS readings to plan and
    execute an autonomous parking manoeuvre.
    """

    def __init__(self) -> None:
        self._reset_state()

    def _reset_state(self) -> None:
        """Initialise / reinitialise all mutable state."""
        self._state = ParkingState.IDLE
        self._slot: Optional[ParkingSlot] = None
        self._path: List[PathPoint] = []
        self._waypoint_idx = 0
        self._scan_ticks = 0
        self._manoeuvre_ticks = 0

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def request_parking(self, parking_type: ParkingType = ParkingType.PERPENDICULAR) -> None:
        """Activate the parking controller."""
        if self._state == ParkingState.IDLE:
            self._state = ParkingState.SCANNING
            self._parking_type = parking_type
            self._scan_ticks = 0

    def abort(self) -> None:
        self._state = ParkingState.ABORTED
        self._path = []

    def reset(self) -> None:
        self._reset_state()

    def update(
        self,
        uss_readings: dict,
        camera_detections: list,
        vehicle_speed_mps: float,
    ) -> ParkingStatus:
        """
        Step the parking state machine.

        Parameters
        ----------
        uss_readings : dict
            ``{sensor_id: distance_m}`` for all 12 sensors.
        camera_detections : list[DetectedObject]
            Rear camera detections (label, distance_m, azimuth_deg).
        vehicle_speed_mps : float
            Current vehicle speed (≥ 0, m/s).
        """
        front_clear = self._min_zone(uss_readings, front=True)
        rear_clear = self._min_zone(uss_readings, front=False)

        if self._state == ParkingState.IDLE:
            pass

        elif self._state == ParkingState.SCANNING:
            self._scan_ticks += 1
            slot = self._detect_slot(camera_detections, uss_readings)
            if slot:
                self._slot = slot
                self._state = ParkingState.SLOT_DETECTED

        elif self._state == ParkingState.SLOT_DETECTED:
            self._path = self._plan_path(self._slot)
            self._waypoint_idx = 0
            self._state = ParkingState.ALIGNING

        elif self._state == ParkingState.ALIGNING:
            # Move to first waypoint (approach alignment)
            if self._waypoint_idx < len(self._path) // 3:
                self._waypoint_idx += 1
            else:
                self._state = ParkingState.MANOEUVRING
                self._manoeuvre_ticks = 0

        elif self._state == ParkingState.MANOEUVRING:
            self._manoeuvre_ticks += 1
            if self._waypoint_idx < len(self._path) - 1:
                self._waypoint_idx += 1
            # Stop if rear obstacle is critical
            if rear_clear <= 0.30:
                self._waypoint_idx = len(self._path) - 1
            if self._waypoint_idx >= len(self._path) - 1:
                self._state = ParkingState.PARKED

        progress = (
            self._waypoint_idx / max(1, len(self._path) - 1) * 100
            if self._path else 0.0
        )

        return ParkingStatus(
            state=self._state,
            slot=self._slot,
            path=self._path,
            current_waypoint_idx=self._waypoint_idx,
            progress_pct=round(progress, 1),
            guidance_text=self._guidance_text(rear_clear, front_clear),
            front_clearance_m=round(front_clear, 2),
            rear_clearance_m=round(rear_clear, 2),
        )

    @property
    def state(self) -> ParkingState:
        return self._state

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    @staticmethod
    def _min_zone(uss: dict, front: bool) -> float:
        if front:
            keys = ["USS_F1", "USS_F2", "USS_F3", "USS_F4"]
        else:
            keys = ["USS_R1", "USS_R2", "USS_R3", "USS_R4"]
        vals = [v for k, v in uss.items() if k in keys]
        return min(vals) if vals else 5.0

    def _detect_slot(self, detections: list, uss: dict) -> Optional[ParkingSlot]:
        """Find a valid parking slot from camera detections."""
        for det in detections:
            label = det.label if hasattr(det, "label") else det.get("label", "")
            if label != "parking_slot":
                continue
            dist = det.distance_m if hasattr(det, "distance_m") else det.get("distance_m", 5.0)
            az = det.azimuth_deg if hasattr(det, "azimuth_deg") else det.get("azimuth_deg", 0.0)
            conf = det.confidence if hasattr(det, "confidence") else det.get("confidence", 0.8)
            cx = dist * math.sin(math.radians(az))
            cy = -dist * math.cos(math.radians(az))
            ptype = getattr(self, "_parking_type", ParkingType.PERPENDICULAR)
            width = 2.5 if ptype == ParkingType.PERPENDICULAR else 6.0
            length = 5.0 if ptype == ParkingType.PERPENDICULAR else 2.4
            return ParkingSlot(
                slot_type=ptype,
                centre_x_m=round(cx, 2),
                centre_y_m=round(cy, 2),
                width_m=width,
                length_m=length,
                heading_deg=0.0,
                confidence=conf,
            )
        return None

    def _plan_path(self, slot: ParkingSlot) -> List[PathPoint]:
        """Generate a simplified multi-arc parking path."""
        path: List[PathPoint] = []
        ptype = slot.slot_type

        if ptype == ParkingType.PERPENDICULAR:
            # Phase 1: approach (3 waypoints)
            for i in range(3):
                t = i / 2.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m * t * 0.5, 2),
                    y_m=round(slot.centre_y_m * 0.3, 2),
                    heading_deg=0.0,
                    speed_mps=2.0,
                    steer_deg=0.0,
                ))
            # Phase 2: turn-in (4 waypoints)
            for i in range(4):
                t = i / 3.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m * 0.5, 2),
                    y_m=round(slot.centre_y_m * t, 2),
                    heading_deg=round(-30 * t, 1),
                    speed_mps=-1.5,
                    steer_deg=round(-35 * t, 1),
                ))
            # Phase 3: reverse into slot (5 waypoints)
            for i in range(5):
                t = i / 4.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m, 2),
                    y_m=round(slot.centre_y_m - 1.5 * t, 2),
                    heading_deg=round(-30 + 30 * t, 1),
                    speed_mps=-0.8,
                    steer_deg=round(20 * t, 1),
                ))

        elif ptype == ParkingType.PARALLEL:
            # Phase 1: pass slot
            for i in range(3):
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m + 1.5 - i * 0.5, 2),
                    y_m=round(slot.centre_y_m + 0.5, 2),
                    heading_deg=0.0,
                    speed_mps=2.0,
                    steer_deg=0.0,
                ))
            # Phase 2: first arc (reverse-right)
            for i in range(4):
                t = i / 3.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m + 1.0 - 1.5 * t, 2),
                    y_m=round(slot.centre_y_m + 0.5 - 0.8 * t, 2),
                    heading_deg=round(-20 * t, 1),
                    speed_mps=-1.0,
                    steer_deg=round(-30 * t, 1),
                ))
            # Phase 3: second arc (reverse-left)
            for i in range(5):
                t = i / 4.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m - 0.5 - 1.0 * t, 2),
                    y_m=round(slot.centre_y_m - 0.3 - 0.5 * t, 2),
                    heading_deg=round(-20 + 20 * t, 1),
                    speed_mps=-0.8,
                    steer_deg=round(25 * t, 1),
                ))

        else:  # ANGLED
            for i in range(8):
                t = i / 7.0
                path.append(PathPoint(
                    x_m=round(slot.centre_x_m * t, 2),
                    y_m=round(slot.centre_y_m * t, 2),
                    heading_deg=round(slot.heading_deg * t, 1),
                    speed_mps=-1.0,
                    steer_deg=round(-20 * (1 - t), 1),
                ))

        return path

    def _guidance_text(self, rear_m: float, front_m: float) -> str:
        s = self._state
        if s == ParkingState.IDLE:
            return "Press 'Park' to start parking assistance"
        if s == ParkingState.SCANNING:
            return "Scanning for parking slot — drive slowly past parking area"
        if s == ParkingState.SLOT_DETECTED:
            return f"Slot detected ({self._slot.slot_type.value}) — preparing manoeuvre"
        if s == ParkingState.ALIGNING:
            return "Aligning to entry position — maintain low speed"
        if s == ParkingState.MANOEUVRING:
            if rear_m <= 0.5:
                return f"STOP — obstacle {rear_m:.2f} m behind"
            return f"Reversing into slot — rear {rear_m:.2f} m  front {front_m:.2f} m"
        if s == ParkingState.PARKED:
            return "✓ Vehicle parked successfully"
        if s == ParkingState.ABORTED:
            return "⚠ Parking aborted"
        return ""
