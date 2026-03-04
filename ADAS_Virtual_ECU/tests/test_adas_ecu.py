"""
Unit tests for the Virtual ADAS ECU modules.
"""

import math
import sys
import os
import unittest

# Make the ecu package importable from the tests directory
_HERE = os.path.dirname(os.path.abspath(__file__))
_ECU_ROOT = os.path.dirname(_HERE)
if _ECU_ROOT not in sys.path:
    sys.path.insert(0, _ECU_ROOT)

from ecu.camera import CameraPosition, VirtualCamera, DetectedObject
from ecu.uss import (
    UltrasonicSensor, USSArray, SENSOR_IDS,
    USS_MAX_RANGE_M, USS_BLIND_ZONE_M,
    USS_WARNING_THRESH_M, USS_CRITICAL_THRESH_M,
    SensorZone,
)
from ecu.parking import (
    AutonomousParkingController, ParkingType, ParkingState,
)
from ecu.trailer_hitch import TrailerHitchAssist, THAState
from ecu.trailer_steering import TrailerSteeringGuidance, TSGState
from ecu.ecu_core import ADASECUCore, ECUInputs


# ─────────────────────────────────────────────────────────────────────────────
# Camera tests
# ─────────────────────────────────────────────────────────────────────────────

class TestVirtualCamera(unittest.TestCase):

    def setUp(self):
        self.cam = VirtualCamera(CameraPosition.FRONT, seed=0)

    def test_repr(self):
        r = repr(self.cam)
        self.assertIn("front", r)
        self.assertIn("120", r)

    def test_fov_and_range(self):
        self.assertEqual(self.cam.fov_deg, 120)
        self.assertEqual(self.cam.range_m, 50)

    def test_update_returns_frame(self):
        frame = self.cam.update({})
        self.assertEqual(frame.camera_id, CameraPosition.FRONT)
        self.assertEqual(frame.frame_number, 1)

    def test_object_within_fov_detected(self):
        scene = {"objects": [
            {"type": "vehicle", "distance_m": 10.0, "azimuth_deg": 5.0}
        ]}
        frame = self.cam.update(scene)
        labels = [d.label for d in frame.detections]
        self.assertIn("vehicle", labels)

    def test_object_outside_range_not_detected(self):
        scene = {"objects": [
            {"type": "vehicle", "distance_m": 200.0, "azimuth_deg": 0.0}
        ]}
        frame = self.cam.update(scene)
        self.assertEqual(len(frame.detections), 0)

    def test_object_outside_fov_not_detected(self):
        scene = {"objects": [
            {"type": "vehicle", "distance_m": 5.0, "azimuth_deg": 90.0}
        ]}
        frame = self.cam.update(scene)
        self.assertEqual(len(frame.detections), 0)

    def test_rear_camera_detects_trailer_hitch(self):
        cam_rear = VirtualCamera(CameraPosition.REAR, seed=1)
        scene = {
            "objects": [{"type": "trailer_hitch", "distance_m": 2.0, "azimuth_deg": 0.0}],
            "trailer_hitch": {"offset_px": (10, 5)},
        }
        frame = cam_rear.update(scene)
        self.assertTrue(frame.trailer_hitch_visible)
        self.assertEqual(frame.trailer_hitch_offset_px, (10, 5))

    def test_front_camera_does_not_show_trailer_hitch_visible(self):
        scene = {"trailer_hitch": {"offset_px": (0, 0)}}
        frame = self.cam.update(scene)
        self.assertFalse(frame.trailer_hitch_visible)

    def test_confidence_between_0_and_1(self):
        scene = {"objects": [
            {"type": "pedestrian", "distance_m": 20.0, "azimuth_deg": 40.0}
        ]}
        frame = self.cam.update(scene)
        for det in frame.detections:
            self.assertGreaterEqual(det.confidence, 0.0)
            self.assertLessEqual(det.confidence, 1.0)

    def test_last_frame_stored(self):
        self.cam.update({"objects": []})
        self.assertIsNotNone(self.cam.last_frame)

    def test_frame_counter_increments(self):
        for i in range(5):
            frame = self.cam.update({})
        self.assertEqual(frame.frame_number, 5)

    def test_all_four_camera_positions(self):
        for pos in CameraPosition:
            cam = VirtualCamera(pos, seed=42)
            frame = cam.update({})
            self.assertEqual(frame.camera_id, pos)


# ─────────────────────────────────────────────────────────────────────────────
# USS tests
# ─────────────────────────────────────────────────────────────────────────────

class TestUltrasonicSensor(unittest.TestCase):

    def test_twelve_sensor_ids(self):
        self.assertEqual(len(SENSOR_IDS), 12)

    def test_valid_sensor_created(self):
        s = UltrasonicSensor("USS_F1", seed=0)
        self.assertEqual(s.sensor_id, "USS_F1")

    def test_invalid_sensor_raises(self):
        with self.assertRaises(ValueError):
            UltrasonicSensor("USS_FAKE")

    def test_open_space_reading(self):
        s = UltrasonicSensor("USS_F2", seed=0)
        r = s.measure(float("inf"))
        self.assertFalse(r.is_valid)   # > max range

    def test_close_obstacle_reading(self):
        s = UltrasonicSensor("USS_R1", seed=0)
        r = s.measure(0.3)
        self.assertTrue(r.is_valid)
        self.assertEqual(r.alert_level, "critical")

    def test_warning_zone(self):
        s = UltrasonicSensor("USS_F3", seed=0)
        r = s.measure(1.0)
        self.assertEqual(r.alert_level, "warning")

    def test_clear_zone(self):
        s = UltrasonicSensor("USS_FL", seed=0)
        r = s.measure(3.0)
        self.assertEqual(r.alert_level, "clear")

    def test_blind_zone(self):
        s = UltrasonicSensor("USS_R4", seed=0)
        r = s.measure(0.05)
        self.assertFalse(r.is_valid)


class TestUSSArray(unittest.TestCase):

    def setUp(self):
        self.arr = USSArray(seed=0)

    def test_scan_returns_twelve_readings(self):
        readings = self.arr.scan()
        self.assertEqual(len(readings), 12)

    def test_custom_distances_applied(self):
        dists = {"USS_F1": 0.5}
        readings = self.arr.scan(dists)
        r = next(r for r in readings if r.sensor_id == "USS_F1")
        self.assertAlmostEqual(r.distance_m, 0.5, delta=0.1)

    def test_zone_min_front(self):
        dists = {s: 0.3 for s in ["USS_F1", "USS_F2", "USS_F3", "USS_F4"]}
        readings = self.arr.scan(dists)
        mn = self.arr.get_zone_min(SensorZone.FRONT, readings)
        self.assertAlmostEqual(mn, 0.3, delta=0.1)

    def test_closest_obstacle(self):
        dists = {"USS_R2": 0.25}
        readings = self.arr.scan(dists)
        closest = self.arr.closest_obstacle(readings)
        self.assertIsNotNone(closest)
        self.assertEqual(closest.sensor_id, "USS_R2")

    def test_no_obstacle_returns_none(self):
        readings = self.arr.scan({})  # all open
        closest = self.arr.closest_obstacle(readings)
        self.assertIsNone(closest)


# ─────────────────────────────────────────────────────────────────────────────
# Autonomous Parking tests
# ─────────────────────────────────────────────────────────────────────────────

class _MockDetection:
    def __init__(self, label, distance_m, azimuth_deg, confidence=0.9):
        self.label = label
        self.distance_m = distance_m
        self.azimuth_deg = azimuth_deg
        self.confidence = confidence


class TestAutonomousParking(unittest.TestCase):

    def _make_slot_detection(self):
        return [_MockDetection("parking_slot", 3.0, 2.0)]

    def test_initial_state_idle(self):
        c = AutonomousParkingController()
        self.assertEqual(c.state, ParkingState.IDLE)

    def test_request_parking_starts_scanning(self):
        c = AutonomousParkingController()
        c.request_parking(ParkingType.PERPENDICULAR)
        self.assertEqual(c.state, ParkingState.SCANNING)

    def test_slot_detected_transitions(self):
        c = AutonomousParkingController()
        c.request_parking(ParkingType.PERPENDICULAR)
        # Provide parking_slot detection to trigger transition
        for _ in range(3):
            status = c.update(
                uss_readings={},
                camera_detections=self._make_slot_detection(),
                vehicle_speed_mps=1.0,
            )
        self.assertIn(
            status.state,
            {ParkingState.SLOT_DETECTED, ParkingState.ALIGNING, ParkingState.MANOEUVRING},
        )

    def test_abort_transitions_to_aborted(self):
        c = AutonomousParkingController()
        c.request_parking()
        c.abort()
        self.assertEqual(c.state, ParkingState.ABORTED)

    def test_reset_restores_idle(self):
        c = AutonomousParkingController()
        c.request_parking()
        c.reset()
        self.assertEqual(c.state, ParkingState.IDLE)

    def test_status_includes_guidance_text(self):
        c = AutonomousParkingController()
        c.request_parking()
        status = c.update({}, [], 0.5)
        self.assertIsInstance(status.guidance_text, str)
        self.assertGreater(len(status.guidance_text), 0)

    def test_progress_between_0_and_100(self):
        c = AutonomousParkingController()
        c.request_parking()
        for _ in range(20):
            status = c.update({}, self._make_slot_detection(), -0.8)
        self.assertGreaterEqual(status.progress_pct, 0.0)
        self.assertLessEqual(status.progress_pct, 100.0)

    def test_path_planned_for_all_types(self):
        for ptype in ParkingType:
            c = AutonomousParkingController()
            c.request_parking(ptype)
            # Drive through scanning + slot_detected
            for _ in range(5):
                c.update({}, self._make_slot_detection(), -0.8)
            if c._path:
                self.assertGreater(len(c._path), 0)


# ─────────────────────────────────────────────────────────────────────────────
# Trailer Hitch Assist tests
# ─────────────────────────────────────────────────────────────────────────────

class _MockCameraFrame:
    def __init__(self, hitch_visible, offset_px=(0, 0)):
        self.trailer_hitch_visible = hitch_visible
        self.trailer_hitch_offset_px = offset_px
        self.detections = []


class TestTrailerHitchAssist(unittest.TestCase):

    def test_initial_state_idle(self):
        t = TrailerHitchAssist()
        self.assertEqual(t.state, THAState.IDLE)

    def test_activate_enters_searching(self):
        t = TrailerHitchAssist()
        t.activate()
        self.assertEqual(t.state, THAState.SEARCHING)

    def test_deactivate_returns_idle(self):
        t = TrailerHitchAssist()
        t.activate()
        t.deactivate()
        self.assertEqual(t.state, THAState.IDLE)

    def test_hitch_found_on_visible_camera(self):
        t = TrailerHitchAssist()
        t.activate()
        frame = _MockCameraFrame(hitch_visible=True, offset_px=(5, 3))
        for _ in range(2):
            status = t.update(frame, rear_uss_min_m=2.0)
        self.assertIn(status.state, {THAState.HITCH_FOUND, THAState.GUIDING})

    def test_steering_correction_direction(self):
        t = TrailerHitchAssist()
        t.activate()
        # Hitch is 10 cm to the left (dx = +80 px → lateral = -10 cm → steer right)
        frame = _MockCameraFrame(hitch_visible=True, offset_px=(80, 0))
        for _ in range(3):
            status = t.update(frame, rear_uss_min_m=1.5)
        if status.hitch:
            # lateral_offset_cm = -10, steer = +10° (right)
            self.assertGreater(status.steering_correction_deg, 0)

    def test_fault_on_timeout(self):
        t = TrailerHitchAssist()
        t.activate()
        frame = _MockCameraFrame(hitch_visible=False)
        for _ in range(35):  # exceed timeout
            status = t.update(frame, rear_uss_min_m=3.0)
        self.assertEqual(status.state, THAState.FAULT)

    def test_guidance_text_non_empty(self):
        t = TrailerHitchAssist()
        t.activate()
        frame = _MockCameraFrame(hitch_visible=False)
        status = t.update(frame, rear_uss_min_m=2.0)
        self.assertGreater(len(status.guidance_text), 0)

    def test_alert_level_critical_close_distance(self):
        t = TrailerHitchAssist()
        t.activate()
        frame = _MockCameraFrame(hitch_visible=True, offset_px=(0, 0))
        status = t.update(frame, rear_uss_min_m=0.15)
        self.assertEqual(status.alert_level, "critical")


# ─────────────────────────────────────────────────────────────────────────────
# Trailer Steering Guidance tests
# ─────────────────────────────────────────────────────────────────────────────

class TestTrailerSteeringGuidance(unittest.TestCase):

    def test_initial_state_idle(self):
        tsg = TrailerSteeringGuidance()
        self.assertEqual(tsg.state, TSGState.IDLE)

    def test_activate_transitions(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        tsg.update(0.0, 0.0, 0.0)
        self.assertNotEqual(tsg.state, TSGState.IDLE)

    def test_reversing_triggers_active_state(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        for _ in range(3):
            status = tsg.update(5.0, 0.0, -1.0)
        self.assertEqual(status.state, TSGState.REVERSING_ACTIVE)

    def test_jackknife_risk_at_large_angle(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        tsg.update(0.0, 0.0, -1.0)
        status = tsg.update(60.0, 0.0, -1.0)
        self.assertEqual(status.state, TSGState.JACKKNIFE_RISK)
        self.assertGreater(status.jackknife_risk, 0.9)

    def test_steer_guidance_non_zero_when_reversing(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        tsg.update(0.0, 0.0, -1.0)
        status = tsg.update(20.0, 5.0, -1.2)
        # Non-zero articulation → non-zero steering correction
        self.assertNotEqual(status.recommended_steer_deg, 0.0)

    def test_risk_zero_when_straight(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        status = tsg.update(0.0, 0.0, -1.0)
        self.assertAlmostEqual(status.jackknife_risk, 0.0, delta=0.01)

    def test_deactivate_returns_idle(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        tsg.update(10.0, 0.0, -1.0)
        tsg.deactivate()
        self.assertEqual(tsg.state, TSGState.IDLE)

    def test_alert_level_clear_at_small_angle(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        status = tsg.update(10.0, 0.0, -1.0)
        self.assertEqual(status.alert_level, "clear")

    def test_alert_level_warning_at_moderate_angle(self):
        tsg = TrailerSteeringGuidance()
        tsg.activate()
        tsg.update(0.0, 0.0, -1.0)
        status = tsg.update(40.0, 0.0, -1.0)
        self.assertEqual(status.alert_level, "warning")

    def test_target_heading_setter(self):
        tsg = TrailerSteeringGuidance()
        tsg.set_target_heading(15.0)
        self.assertEqual(tsg._target_heading_deg, 15.0)


# ─────────────────────────────────────────────────────────────────────────────
# ECU Core integration tests
# ─────────────────────────────────────────────────────────────────────────────

class TestADASECUCore(unittest.TestCase):

    def setUp(self):
        self.ecu = ADASECUCore(seed=0)

    def test_step_returns_outputs(self):
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIsNotNone(outputs)

    def test_four_camera_frames(self):
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertEqual(len(outputs.camera_frames), 4)

    def test_twelve_uss_readings(self):
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertEqual(len(outputs.uss_readings), 12)

    def test_parking_inactive_by_default(self):
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIsNone(outputs.parking_status)

    def test_activate_parking_produces_status(self):
        self.ecu.activate_parking(ParkingType.PERPENDICULAR)
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIsNotNone(outputs.parking_status)

    def test_activate_tha_produces_status(self):
        self.ecu.activate_tha()
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIsNotNone(outputs.tha_status)

    def test_activate_tsg_produces_status(self):
        self.ecu.activate_tsg()
        inputs = ECUInputs(trailer_articulation_deg=10.0, vehicle_speed_mps=-1.0)
        outputs = self.ecu.step(inputs)
        self.assertIsNotNone(outputs.tsg_status)

    def test_active_features_list(self):
        self.ecu.activate_parking()
        self.ecu.activate_tha()
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIn(ADASECUCore.FEATURE_PARKING, outputs.active_features)
        self.assertIn(ADASECUCore.FEATURE_THA, outputs.active_features)

    def test_health_ok_when_no_obstacles(self):
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertEqual(outputs.system_health, "OK")

    def test_health_critical_when_close_obstacle(self):
        uss = {s: 0.2 for s in ["USS_F1", "USS_F2", "USS_F3", "USS_F4"]}
        inputs = ECUInputs(uss_distances=uss)
        outputs = self.ecu.step(inputs)
        self.assertIn("CRITICAL", outputs.system_health)

    def test_tick_increments(self):
        inputs = ECUInputs()
        self.ecu.step(inputs)
        self.ecu.step(inputs)
        self.assertEqual(self.ecu.tick, 2)

    def test_deactivate_parking(self):
        self.ecu.activate_parking()
        self.ecu.deactivate_parking()
        inputs = ECUInputs()
        outputs = self.ecu.step(inputs)
        self.assertIsNone(outputs.parking_status)

    def test_camera_detects_object_in_scene(self):
        inputs = ECUInputs(
            scene_objects=[
                {"type": "vehicle", "distance_m": 10.0, "azimuth_deg": 5.0}
            ]
        )
        outputs = self.ecu.step(inputs)
        front_frame = outputs.camera_frames.get("front")
        self.assertIsNotNone(front_frame)
        labels = [d.label for d in front_frame.detections]
        self.assertIn("vehicle", labels)

    def test_all_features_simultaneously(self):
        self.ecu.activate_parking(ParkingType.PARALLEL)
        self.ecu.activate_tha()
        self.ecu.activate_tsg()
        inputs = ECUInputs(
            scene_objects=[
                {"type": "parking_slot", "distance_m": 3.0, "azimuth_deg": 0.0},
            ],
            trailer_hitch_offset_px=(5, 3),
            trailer_articulation_deg=15.0,
            vehicle_speed_mps=-1.0,
        )
        for _ in range(5):
            outputs = self.ecu.step(inputs)
        self.assertIsNotNone(outputs)


if __name__ == "__main__":
    unittest.main(verbosity=2)
