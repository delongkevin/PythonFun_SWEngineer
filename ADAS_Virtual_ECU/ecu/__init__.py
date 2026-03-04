"""
Virtual ADAS ECU - Advanced Driver Assistance System Electronic Control Unit
Supports 4 virtual cameras, 12 ultrasonic sensors (USS),
autonomous parking, Trailer Hitch Assist, and Trailer Steering Guidance.
"""
from .camera import VirtualCamera, CameraPosition
from .uss import UltrasonicSensor, USSArray
from .ecu_core import ADASECUCore
from .parking import AutonomousParkingController
from .trailer_hitch import TrailerHitchAssist
from .trailer_steering import TrailerSteeringGuidance

__all__ = [
    "VirtualCamera",
    "CameraPosition",
    "UltrasonicSensor",
    "USSArray",
    "ADASECUCore",
    "AutonomousParkingController",
    "TrailerHitchAssist",
    "TrailerSteeringGuidance",
]

__version__ = "1.0.0"
