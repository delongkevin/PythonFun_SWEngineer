"""
Trailer Steering Guidance (TSG) Module

Monitors trailer articulation angle and provides real-time steering
corrections to stabilise the trailer during reversing/low-speed manoeuvres.

Key algorithms:
  - Trailer angle estimation from rear camera + virtual trailer model
  - Anti-jackknife detection
  - Predictive steering guidance based on desired trailer heading

State machine:
  IDLE → TRAILER_DETECTED → TRACKING → REVERSING_ACTIVE → JACKKNIFE_RISK → STABLE
"""

from __future__ import annotations

import math
from dataclasses import dataclass
from enum import Enum, auto
from typing import Optional


class TSGState(Enum):
    IDLE = auto()
    TRAILER_DETECTED = auto()
    TRACKING = auto()
    REVERSING_ACTIVE = auto()
    JACKKNIFE_RISK = auto()
    STABLE = auto()


@dataclass
class TrailerState:
    """Estimated state of the articulated trailer."""
    articulation_angle_deg: float  # hitch angle, positive = trailer jack-left
    trailer_heading_deg: float     # absolute heading (vehicle=0)
    effective_wheelbase_m: float   # tow-vehicle wheelbase estimate
    trailer_length_m: float        # estimated trailer length
    angular_velocity_dps: float    # rate of articulation change (°/s)


@dataclass
class TSGStatus:
    state: TSGState
    trailer: Optional[TrailerState]
    recommended_steer_deg: float   # positive = right
    target_trailer_heading_deg: float
    jackknife_risk: float          # 0.0 – 1.0
    guidance_text: str
    alert_level: str               # "clear" | "warning" | "critical"


# Physical limits
_JACKKNIFE_ANGLE_DEG = 55.0    # articulation angle beyond which jackknife is imminent
_WARN_ANGLE_DEG = 35.0         # warning threshold
_TOW_WHEELBASE_M = 2.7         # typical tow-vehicle wheelbase
_TRAILER_LENGTH_M = 6.0        # semi-default trailer length

# Controller gains
_KP_TRAILER = 0.8              # proportional gain for trailer heading error
_MAX_STEER_DEG = 30.0


class TrailerSteeringGuidance:
    """
    Computes steering guidance to direct the trailer to a target heading
    while preventing jackknife.

    The articulation angle is estimated from the rear camera's trailer
    coupler landmark positions.
    """

    def __init__(
        self,
        tow_wheelbase_m: float = _TOW_WHEELBASE_M,
        trailer_length_m: float = _TRAILER_LENGTH_M,
    ) -> None:
        self._state = TSGState.IDLE
        self._trailer: Optional[TrailerState] = None
        self._tow_wb = tow_wheelbase_m
        self._trailer_len = trailer_length_m
        self._prev_angle: Optional[float] = None
        self._target_heading_deg = 0.0    # desired trailer heading (0 = straight)

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    def activate(self) -> None:
        if self._state == TSGState.IDLE:
            self._state = TSGState.TRAILER_DETECTED

    def deactivate(self) -> None:
        self._state = TSGState.IDLE
        self._trailer = None
        self._prev_angle = None

    def set_target_heading(self, heading_deg: float) -> None:
        """Set the desired trailer heading for guided manoeuvres."""
        self._target_heading_deg = heading_deg

    def update(
        self,
        articulation_angle_deg: float,  # measured hitch angle (+left / -right)
        vehicle_steer_deg: float,        # current steering wheel angle
        vehicle_speed_mps: float,        # signed (negative = reversing)
        dt_s: float = 0.1,              # time step
    ) -> TSGStatus:
        """
        Update trailer state and compute steering guidance.

        Parameters
        ----------
        articulation_angle_deg : float
            Current articulation (hitch) angle in degrees.
        vehicle_steer_deg : float
            Current steering wheel angle (positive = right).
        vehicle_speed_mps : float
            Signed vehicle speed.
        dt_s : float
            Time step since last call.
        """
        # ── Angular velocity ──────────────────────────────────────────
        ang_vel = 0.0
        if self._prev_angle is not None and dt_s > 0:
            ang_vel = (articulation_angle_deg - self._prev_angle) / dt_s
        self._prev_angle = articulation_angle_deg

        # ── Update trailer state ──────────────────────────────────────
        self._trailer = TrailerState(
            articulation_angle_deg=articulation_angle_deg,
            trailer_heading_deg=articulation_angle_deg,  # relative to vehicle
            effective_wheelbase_m=self._tow_wb,
            trailer_length_m=self._trailer_len,
            angular_velocity_dps=round(ang_vel, 2),
        )

        # ── State transitions ─────────────────────────────────────────
        abs_angle = abs(articulation_angle_deg)

        if self._state == TSGState.IDLE:
            pass

        elif self._state == TSGState.TRAILER_DETECTED:
            self._state = TSGState.TRACKING

        elif self._state == TSGState.TRACKING:
            if vehicle_speed_mps < -0.1:
                self._state = TSGState.REVERSING_ACTIVE
            if abs_angle >= _JACKKNIFE_ANGLE_DEG:
                self._state = TSGState.JACKKNIFE_RISK

        elif self._state == TSGState.REVERSING_ACTIVE:
            if abs_angle >= _JACKKNIFE_ANGLE_DEG:
                self._state = TSGState.JACKKNIFE_RISK
            elif vehicle_speed_mps >= 0:
                self._state = TSGState.TRACKING

        elif self._state == TSGState.JACKKNIFE_RISK:
            if abs_angle < _WARN_ANGLE_DEG:
                self._state = TSGState.REVERSING_ACTIVE

        # ── Compute steering guidance ──────────────────────────────────
        steer = self._compute_steer(articulation_angle_deg, vehicle_speed_mps)
        risk = self._jackknife_risk(articulation_angle_deg)

        return TSGStatus(
            state=self._state,
            trailer=self._trailer,
            recommended_steer_deg=round(steer, 1),
            target_trailer_heading_deg=self._target_heading_deg,
            jackknife_risk=round(risk, 3),
            guidance_text=self._guidance_text(steer, risk),
            alert_level=self._alert(risk, abs_angle),
        )

    @property
    def state(self) -> TSGState:
        return self._state

    # ------------------------------------------------------------------
    # Private helpers
    # ------------------------------------------------------------------

    def _compute_steer(self, angle_deg: float, speed_mps: float) -> float:
        """
        Compute recommended steering angle to bring trailer to target heading.

        Uses the inverse kinematic formula for a tow-trailer system:
            δ = arctan( L_tow / L_trailer * tan(γ) ) + Kp * (θ_target - γ)
        where γ is the articulation angle, L_tow the tow-vehicle wheelbase,
        L_trailer the trailer length.
        """
        if self._state not in (TSGState.REVERSING_ACTIVE, TSGState.JACKKNIFE_RISK):
            return 0.0

        heading_error = self._target_heading_deg - angle_deg

        # Kinematic feed-forward term for reversing
        ff_rad = math.atan2(self._tow_wb, self._trailer_len) * math.sin(math.radians(angle_deg))
        ff_deg = math.degrees(ff_rad)

        steer = ff_deg - _KP_TRAILER * heading_error

        # Anti-jackknife override: force counter-steer
        if abs(angle_deg) >= _JACKKNIFE_ANGLE_DEG:
            steer = -math.copysign(_MAX_STEER_DEG, angle_deg)

        return max(-_MAX_STEER_DEG, min(_MAX_STEER_DEG, steer))

    @staticmethod
    def _jackknife_risk(angle_deg: float) -> float:
        """Risk score 0–1 based on articulation angle."""
        ratio = abs(angle_deg) / _JACKKNIFE_ANGLE_DEG
        return min(1.0, ratio ** 1.5)

    @staticmethod
    def _alert(risk: float, angle_deg: float) -> str:
        if angle_deg >= _JACKKNIFE_ANGLE_DEG:
            return "critical"
        if angle_deg >= _WARN_ANGLE_DEG:
            return "warning"
        return "clear"

    def _guidance_text(self, steer_deg: float, risk: float) -> str:
        s = self._state
        if s == TSGState.IDLE:
            return "Trailer Steering Guidance inactive"
        if s == TSGState.TRAILER_DETECTED:
            return "Trailer detected — activate reversing to begin guidance"
        if s == TSGState.TRACKING:
            angle = self._trailer.articulation_angle_deg if self._trailer else 0
            return f"Monitoring trailer — articulation {angle:+.1f}°"
        if s == TSGState.REVERSING_ACTIVE:
            if steer_deg == 0:
                return "Trailer straight — maintain current steering"
            side = "right" if steer_deg > 0 else "left"
            return f"Steer {side} {abs(steer_deg):.0f}° to guide trailer  (risk {risk:.0%})"
        if s == TSGState.JACKKNIFE_RISK:
            side = "right" if steer_deg > 0 else "left"
            return (
                f"⚠ JACKKNIFE RISK — Steer hard {side} {abs(steer_deg):.0f}°  "
                f"(risk {risk:.0%})"
            )
        return ""
