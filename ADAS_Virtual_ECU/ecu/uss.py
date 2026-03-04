"""
Ultrasonic Sensor (USS) Module - Simulates 12 USS sensors for the ADAS ECU.

Sensor layout (SAE J1169-style):
  Front bumper  : USS_F1 (L corner), USS_F2 (L-centre), USS_F3 (R-centre), USS_F4 (R corner)
  Rear  bumper  : USS_R1 (L corner), USS_R2 (L-centre), USS_R3 (R-centre), USS_R4 (R corner)
  Front flanks  : USS_FL (left side, near front),  USS_FR (right side, near front)
  Rear  flanks  : USS_RL (left side, near rear),   USS_RR (right side, near rear)

All sensors operate at 40–48 kHz; max range 5.0 m, blind zone 0.10 m.
"""

from __future__ import annotations

import math
import random
from dataclasses import dataclass
from enum import Enum
from typing import Dict, List, Optional, Tuple


class SensorZone(Enum):
    FRONT = "front"
    REAR = "rear"
    SIDE_FRONT = "side_front"
    SIDE_REAR = "side_rear"


# ── Sensor IDs ────────────────────────────────────────────────────────────────
SENSOR_IDS = [
    "USS_F1", "USS_F2", "USS_F3", "USS_F4",   # front bumper
    "USS_R1", "USS_R2", "USS_R3", "USS_R4",   # rear  bumper
    "USS_FL", "USS_FR",                         # front flanks
    "USS_RL", "USS_RR",                         # rear  flanks
]

# Physical mounting position (x, y) relative to vehicle centre [metres]
# x=forward, y=left positive
_MOUNT_POSITIONS: Dict[str, Tuple[float, float]] = {
    "USS_F1": (2.3,  0.85),  # front-left  corner
    "USS_F2": (2.3,  0.28),  # front-left  centre
    "USS_F3": (2.3, -0.28),  # front-right centre
    "USS_F4": (2.3, -0.85),  # front-right corner
    "USS_R1": (-2.3,  0.85), # rear-left   corner
    "USS_R2": (-2.3,  0.28), # rear-left   centre
    "USS_R3": (-2.3, -0.28), # rear-right  centre
    "USS_R4": (-2.3, -0.85), # rear-right  corner
    "USS_FL": (1.2,   1.0),  # left  front flank
    "USS_FR": (1.2,  -1.0),  # right front flank
    "USS_RL": (-1.2,  1.0),  # left  rear  flank
    "USS_RR": (-1.2, -1.0),  # right rear  flank
}

# Boresight angle (degrees from vehicle forward) for each sensor
_BORESIGHT: Dict[str, float] = {
    "USS_F1": 35.0, "USS_F2": 12.0, "USS_F3": -12.0, "USS_F4": -35.0,
    "USS_R1": 145.0, "USS_R2": 168.0, "USS_R3": -168.0, "USS_R4": -145.0,
    "USS_FL": 90.0,  "USS_FR": -90.0,
    "USS_RL": 90.0,  "USS_RR": -90.0,
}

_ZONE_MAP: Dict[str, SensorZone] = {
    "USS_F1": SensorZone.FRONT, "USS_F2": SensorZone.FRONT,
    "USS_F3": SensorZone.FRONT, "USS_F4": SensorZone.FRONT,
    "USS_R1": SensorZone.REAR,  "USS_R2": SensorZone.REAR,
    "USS_R3": SensorZone.REAR,  "USS_R4": SensorZone.REAR,
    "USS_FL": SensorZone.SIDE_FRONT, "USS_FR": SensorZone.SIDE_FRONT,
    "USS_RL": SensorZone.SIDE_REAR,  "USS_RR": SensorZone.SIDE_REAR,
}

USS_MAX_RANGE_M = 5.0
USS_BLIND_ZONE_M = 0.10
USS_WARNING_THRESH_M = 1.5   # yellow warning
USS_CRITICAL_THRESH_M = 0.4  # red critical / stop request


@dataclass
class USSReading:
    """Single reading from one ultrasonic sensor."""
    sensor_id: str
    distance_m: float            # NaN or > MAX_RANGE means no echo detected
    zone: SensorZone
    mount_xy: Tuple[float, float]
    boresight_deg: float

    @property
    def is_valid(self) -> bool:
        return USS_BLIND_ZONE_M <= self.distance_m <= USS_MAX_RANGE_M

    @property
    def alert_level(self) -> str:
        if not self.is_valid:
            return "none"
        if self.distance_m <= USS_CRITICAL_THRESH_M:
            return "critical"
        if self.distance_m <= USS_WARNING_THRESH_M:
            return "warning"
        return "clear"


class UltrasonicSensor:
    """Simulates one USS transducer."""

    def __init__(self, sensor_id: str, seed: Optional[int] = None) -> None:
        if sensor_id not in SENSOR_IDS:
            raise ValueError(f"Unknown sensor id: {sensor_id}")
        self.sensor_id = sensor_id
        self.zone = _ZONE_MAP[sensor_id]
        self.mount_xy = _MOUNT_POSITIONS[sensor_id]
        self.boresight_deg = _BORESIGHT[sensor_id]
        self._rng = random.Random(seed)
        self._last_reading: Optional[USSReading] = None

    def measure(self, true_distance_m: float) -> USSReading:
        """
        Return a simulated reading given the ground-truth obstacle distance.

        Parameters
        ----------
        true_distance_m : float
            Ground-truth distance to the nearest obstacle in the sensor's
            field of view.  Pass ``float('inf')`` for open space.
        """
        if true_distance_m > USS_MAX_RANGE_M:
            measured = USS_MAX_RANGE_M + 0.1   # no echo
        elif true_distance_m < USS_BLIND_ZONE_M:
            measured = USS_BLIND_ZONE_M - 0.01  # in blind zone
        else:
            noise = self._rng.gauss(0, 0.02)   # ±2 cm noise (1-σ)
            measured = max(USS_BLIND_ZONE_M, true_distance_m + noise)

        reading = USSReading(
            sensor_id=self.sensor_id,
            distance_m=round(measured, 3),
            zone=self.zone,
            mount_xy=self.mount_xy,
            boresight_deg=self.boresight_deg,
        )
        self._last_reading = reading
        return reading

    @property
    def last_reading(self) -> Optional[USSReading]:
        return self._last_reading

    def __repr__(self) -> str:
        return (
            f"UltrasonicSensor(id={self.sensor_id}, "
            f"zone={self.zone.value}, "
            f"boresight={self.boresight_deg}°)"
        )


class USSArray:
    """
    Manages all 12 USS sensors as a unit.

    The array accepts a ``scene_distances`` dict keyed by sensor_id to
    override individual readings; all unspecified sensors get open-space
    (> MAX_RANGE) readings.
    """

    def __init__(self, seed: Optional[int] = None) -> None:
        base_seed = seed if seed is not None else 42
        self._sensors: Dict[str, UltrasonicSensor] = {
            sid: UltrasonicSensor(sid, seed=base_seed + i)
            for i, sid in enumerate(SENSOR_IDS)
        }

    def scan(self, scene_distances: Optional[Dict[str, float]] = None) -> List[USSReading]:
        """
        Trigger all 12 sensors and return their readings.

        Parameters
        ----------
        scene_distances : dict, optional
            ``{sensor_id: true_distance_m}``.  Missing entries → open space.
        """
        dist_map = scene_distances or {}
        readings: List[USSReading] = []
        for sid, sensor in self._sensors.items():
            true_dist = dist_map.get(sid, float("inf"))
            readings.append(sensor.measure(true_dist))
        return readings

    def get_zone_min(self, zone: SensorZone, readings: List[USSReading]) -> float:
        """Return the minimum valid distance for a given zone."""
        vals = [r.distance_m for r in readings if r.zone == zone and r.is_valid]
        return min(vals) if vals else USS_MAX_RANGE_M

    def closest_obstacle(self, readings: List[USSReading]) -> Optional[USSReading]:
        """Return the reading with the smallest valid distance across all sensors."""
        valid = [r for r in readings if r.is_valid]
        return min(valid, key=lambda r: r.distance_m) if valid else None

    @property
    def sensor_ids(self) -> List[str]:
        return list(self._sensors.keys())
