"""
Trailer Hitch Assist (THA) Module

Uses the rear camera + rear USS sensors to guide the driver to align the
vehicle's tow-ball precisely with the trailer hitch coupler.

State machine:
  IDLE → SEARCHING → HITCH_FOUND → GUIDING → ALIGNED → COUPLED

Key outputs:
  - Longitudinal distance to couple (m)
  - Lateral offset from target (cm)
  - Steering guidance angle (°)
  - Alert level
"""

from __future__ import annotations

import math
from dataclasses import dataclass
from enum import Enum, auto
from typing import Optional, Tuple


class THAState(Enum):
    IDLE = auto()
    SEARCHING = auto()
    HITCH_FOUND = auto()
    GUIDING = auto()
    ALIGNED = auto()
    COUPLED = auto()
    FAULT = auto()


@dataclass
class HitchTarget:
    """Detected trailer hitch coupler position."""
    distance_m: float          # distance from tow-ball to coupler
    lateral_offset_cm: float   # positive = coupler to left of tow-ball
    vertical_offset_cm: float  # positive = coupler above tow-ball plane
    image_offset_px: Tuple[int, int]  # (dx, dy) from image centre
    confidence: float


@dataclass
class THAStatus:
    state: THAState
    hitch: Optional[HitchTarget]
    steering_correction_deg: float  # positive = steer right
    longitudinal_speed_mps: float   # recommended reverse speed
    guidance_text: str
    alert_level: str                # "clear" | "warning" | "critical" | "aligned"


# Alignment thresholds
_LATERAL_OK_CM = 3.0          # ≤ 3 cm lateral offset → aligned
_DIST_COUPLE_M = 0.05         # ≤ 5 cm distance → coupled
_DIST_SLOW_M = 0.5            # ≤ 0.5 m → reduce speed
_MAX_STEER_DEG = 30.0
_COUPLED_USS_DIST_M = 0.15    # rear USS reads ≤ 15 cm → trailer contacted


class TrailerHitchAssist:
    """
    Guides reverse manoeuvre to align tow-ball with trailer coupler.

    The rear camera tracks the hitch coupler; rear USS provides
    proximity stop safety.
    """

    def __init__(self) -> None:
        self._state = THAState.IDLE
        self._hitch: Optional[HitchTarget] = None
        self._search_ticks = 0

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def activate(self) -> None:
        if self._state == THAState.IDLE:
            self._state = THAState.SEARCHING
            self._search_ticks = 0

    def deactivate(self) -> None:
        self._state = THAState.IDLE
        self._hitch = None

    def update(
        self,
        camera_frame,           # CameraFrame from rear camera
        rear_uss_min_m: float,  # minimum rear USS reading
    ) -> THAStatus:
        """
        Step the THA state machine.

        Parameters
        ----------
        camera_frame : CameraFrame
            Latest frame from the REAR virtual camera.
        rear_uss_min_m : float
            Minimum distance reading from the rear USS cluster.
        """
        # ── Extract hitch detection from camera frame ──────────────────
        detected_hitch: Optional[HitchTarget] = None
        if camera_frame is not None and camera_frame.trailer_hitch_visible:
            dx, dy = camera_frame.trailer_hitch_offset_px
            # Convert pixel offset to physical offset (calibrated pinhole approx.)
            # Assume 8 px/cm at typical backing distance
            lateral_cm = -dx / 8.0     # negative dx = hitch to the right
            vertical_cm = -dy / 8.0
            # Estimate distance from USS or use a model
            dist = max(_DIST_COUPLE_M, rear_uss_min_m - 0.05)
            detected_hitch = HitchTarget(
                distance_m=round(dist, 3),
                lateral_offset_cm=round(lateral_cm, 1),
                vertical_offset_cm=round(vertical_cm, 1),
                image_offset_px=(dx, dy),
                confidence=0.92,
            )

        # ── State transitions ─────────────────────────────────────────
        if self._state == THAState.IDLE:
            pass

        elif self._state == THAState.SEARCHING:
            self._search_ticks += 1
            if detected_hitch is not None:
                self._hitch = detected_hitch
                self._state = THAState.HITCH_FOUND
            elif self._search_ticks > 30:
                self._state = THAState.FAULT   # timeout

        elif self._state in (THAState.HITCH_FOUND, THAState.GUIDING):
            if detected_hitch:
                self._hitch = detected_hitch
                self._state = THAState.GUIDING
                if abs(detected_hitch.lateral_offset_cm) <= _LATERAL_OK_CM:
                    if detected_hitch.distance_m <= _DIST_COUPLE_M * 3:
                        self._state = THAState.ALIGNED
            else:
                self._state = THAState.HITCH_FOUND  # lost tracking

        elif self._state == THAState.ALIGNED:
            if rear_uss_min_m <= _COUPLED_USS_DIST_M:
                self._state = THAState.COUPLED
            elif detected_hitch and abs(detected_hitch.lateral_offset_cm) > _LATERAL_OK_CM * 2:
                self._state = THAState.GUIDING   # drifted

        elif self._state == THAState.COUPLED:
            pass  # terminal state until deactivated

        # ── Compute guidance outputs ──────────────────────────────────
        steer = self._compute_steering()
        speed = self._compute_speed(rear_uss_min_m)
        alert = self._alert_level(rear_uss_min_m)

        return THAStatus(
            state=self._state,
            hitch=self._hitch,
            steering_correction_deg=round(steer, 1),
            longitudinal_speed_mps=round(speed, 2),
            guidance_text=self._guidance_text(rear_uss_min_m),
            alert_level=alert,
        )

    @property
    def state(self) -> THAState:
        return self._state

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    def _compute_steering(self) -> float:
        """Proportional steering correction from lateral offset."""
        if self._hitch is None or self._state not in (
            THAState.GUIDING, THAState.HITCH_FOUND, THAState.ALIGNED
        ):
            return 0.0
        # P-gain: 1° of steering per cm of lateral offset
        gain = 1.0
        steer = -self._hitch.lateral_offset_cm * gain
        return max(-_MAX_STEER_DEG, min(_MAX_STEER_DEG, steer))

    def _compute_speed(self, rear_uss_min_m: float) -> float:
        """Recommended reverse speed (m/s, negative = reverse)."""
        if self._state not in (THAState.GUIDING, THAState.HITCH_FOUND, THAState.ALIGNED):
            return 0.0
        if rear_uss_min_m <= 0.20:
            return 0.0  # stop
        if rear_uss_min_m <= _DIST_SLOW_M:
            return -0.3  # creep
        return -0.8  # normal backing speed

    @staticmethod
    def _alert_level(rear_uss_min_m: float) -> str:
        if rear_uss_min_m <= 0.20:
            return "critical"
        if rear_uss_min_m <= 0.60:
            return "warning"
        return "clear"

    def _guidance_text(self, rear_uss_min_m: float) -> str:
        s = self._state
        if s == THAState.IDLE:
            return "Trailer Hitch Assist inactive"
        if s == THAState.SEARCHING:
            return "Searching for trailer hitch coupler — reverse slowly"
        if s == THAState.HITCH_FOUND:
            h = self._hitch
            return (
                f"Hitch found — {h.distance_m:.2f} m, "
                f"offset {h.lateral_offset_cm:+.1f} cm lateral"
            )
        if s == THAState.GUIDING:
            h = self._hitch
            steer = self._compute_steering()
            side = "right" if steer > 0 else "left"
            return (
                f"Guiding — steer {side} {abs(steer):.0f}°  "
                f"distance {h.distance_m:.2f} m"
            )
        if s == THAState.ALIGNED:
            return f"✓ Aligned — continue reversing  {rear_uss_min_m:.2f} m"
        if s == THAState.COUPLED:
            return "✓ Coupled — engage trailer brake & safety chain"
        if s == THAState.FAULT:
            return "⚠ Hitch not found — reposition vehicle"
        return ""
