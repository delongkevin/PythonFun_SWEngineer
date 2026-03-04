"""
Virtual ADAS ECU — Interactive Demo
====================================
Run this script to launch the full-screen demo dashboard.

    python adas_demo.py [--mode {parking|hitch|tsg|all}] [--steps N]

The demo cycles through:
  1. Surround-View (4 cameras + 12 USS overlay)
  2. Autonomous Parking scenario
  3. Trailer Hitch Assist scenario
  4. Trailer Steering Guidance scenario

Dependencies: matplotlib, numpy (installed via requirements.txt)
"""

from __future__ import annotations

import argparse
import math
import sys
import os
import time
from typing import List

import matplotlib
matplotlib.use("Agg")   # non-interactive backend — works without a display
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import matplotlib.gridspec as gridspec
from matplotlib.patches import FancyArrowPatch, Arc, Circle, Rectangle, Wedge
from matplotlib.lines import Line2D
import numpy as np

# ── Locate the ECU package ───────────────────────────────────────────────────
_HERE = os.path.dirname(os.path.abspath(__file__))
_ECU_ROOT = os.path.dirname(_HERE)
if _ECU_ROOT not in sys.path:
    sys.path.insert(0, _ECU_ROOT)

from ecu import (
    ADASECUCore,
    AutonomousParkingController,
    CameraPosition,
    TrailerHitchAssist,
    TrailerSteeringGuidance,
)
from ecu.ecu_core import ECUInputs
from ecu.parking import ParkingState, ParkingType
from ecu.trailer_hitch import THAState
from ecu.trailer_steering import TSGState
from ecu.uss import SensorZone, SENSOR_IDS, _MOUNT_POSITIONS, _BORESIGHT, USS_MAX_RANGE_M

# ── Colour palette ────────────────────────────────────────────────────────────
C_BG = "#0a0e1a"
C_PANEL = "#111827"
C_ACCENT = "#00d4ff"
C_GREEN = "#22c55e"
C_YELLOW = "#facc15"
C_RED = "#ef4444"
C_ORANGE = "#f97316"
C_GREY = "#6b7280"
C_WHITE = "#f1f5f9"
C_VEHICLE = "#3b82f6"
C_TRAILER = "#8b5cf6"

# ── Vehicle geometry ──────────────────────────────────────────────────────────
VEH_L = 4.6    # m
VEH_W = 1.9    # m
TRAILER_L = 5.5
TRAILER_W = 2.1


# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║  Helper drawing functions                                                    ║
# ╚══════════════════════════════════════════════════════════════════════════════╝

def _setup_dark_axes(ax, title: str = "", xlim=(-8, 8), ylim=(-8, 8)) -> None:
    ax.set_facecolor(C_BG)
    ax.set_xlim(*xlim)
    ax.set_ylim(*ylim)
    ax.set_aspect("equal")
    ax.tick_params(colors=C_GREY, labelsize=7)
    for spine in ax.spines.values():
        spine.set_edgecolor(C_GREY)
        spine.set_linewidth(0.5)
    if title:
        ax.set_title(title, color=C_ACCENT, fontsize=9, pad=4, fontweight="bold")


def _draw_vehicle(ax, cx=0.0, cy=0.0, heading=0.0, color=C_VEHICLE,
                  label="EGO") -> None:
    """Draw a top-down vehicle rectangle."""
    rect = plt.Rectangle(
        (cx - VEH_W / 2, cy - VEH_L / 2),
        VEH_W, VEH_L,
        angle=heading,
        rotation_point="center",
        linewidth=1.5,
        edgecolor=color,
        facecolor=color + "33",
        zorder=3,
    )
    ax.add_patch(rect)
    # Direction arrow
    dx = math.sin(math.radians(heading)) * VEH_L * 0.35
    dy = math.cos(math.radians(heading)) * VEH_L * 0.35
    ax.annotate(
        "", xy=(cx + dx, cy + dy), xytext=(cx, cy),
        arrowprops=dict(arrowstyle="->", color=color, lw=1.5),
        zorder=4,
    )
    ax.text(cx, cy - VEH_L * 0.25, label, color=color,
            fontsize=7, ha="center", va="center", zorder=5)


def _draw_trailer(ax, veh_cx, veh_cy, articulation_deg, heading=0.0) -> None:
    """Draw trailer behind vehicle."""
    hitch_x = veh_cx - math.sin(math.radians(heading)) * (VEH_L / 2 + 0.3)
    hitch_y = veh_cy - math.cos(math.radians(heading)) * (VEH_L / 2 + 0.3)
    trailer_hdg = heading + articulation_deg
    tcx = hitch_x - math.sin(math.radians(trailer_hdg)) * (TRAILER_L / 2)
    tcy = hitch_y - math.cos(math.radians(trailer_hdg)) * (TRAILER_L / 2)
    rect = plt.Rectangle(
        (tcx - TRAILER_W / 2, tcy - TRAILER_L / 2),
        TRAILER_W, TRAILER_L,
        angle=trailer_hdg,
        rotation_point="center",
        linewidth=1.2,
        edgecolor=C_TRAILER,
        facecolor=C_TRAILER + "22",
        zorder=2,
    )
    ax.add_patch(rect)
    # Hitch link line
    ax.plot([veh_cx, hitch_x, tcx], [veh_cy, hitch_y, tcy],
            color=C_TRAILER, lw=1, linestyle="--", zorder=3)
    ax.text(tcx, tcy, "TRAILER", color=C_TRAILER,
            fontsize=6, ha="center", va="center", zorder=4)


def _uss_color(dist_m: float) -> str:
    if dist_m <= 0.4:
        return C_RED
    if dist_m <= 1.5:
        return C_YELLOW
    return C_GREEN


def _draw_uss_sensors(ax, uss_distances: dict) -> None:
    """Draw USS sensor arcs around the vehicle."""
    for sid in SENSOR_IDS:
        mx, my = _MOUNT_POSITIONS[sid]
        bore = _BORESIGHT[sid]
        dist = uss_distances.get(sid, USS_MAX_RANGE_M + 0.1)
        dist = min(dist, USS_MAX_RANGE_M)
        color = _uss_color(dist)
        # Draw wedge arc
        w = Wedge(
            (my, mx),   # note: x=lateral, y=longitudinal in plot
            dist * 0.6,  # visual scale
            bore - 25, bore + 25,
            alpha=0.25,
            color=color,
            zorder=2,
        )
        ax.add_patch(w)
        # Distance label
        rad = math.radians(bore)
        lx = my + math.sin(rad) * (dist * 0.3 + 0.3)
        ly = mx + math.cos(rad) * (dist * 0.3 + 0.3)
        ax.text(lx, ly, f"{dist:.1f}m", color=color,
                fontsize=5.5, ha="center", va="center", zorder=6)


def _draw_camera_fov(ax, pos: CameraPosition, color: str, alpha=0.12) -> None:
    """Draw camera field-of-view wedge."""
    fov_map = {
        CameraPosition.FRONT: (0, 2.3, 0, 120),
        CameraPosition.REAR:  (0, -2.3, 180, 120),
        CameraPosition.LEFT:  (-0.95, 0, 90, 180),
        CameraPosition.RIGHT: (0.95, 0, -90, 180),
    }
    mx, my, bore, fov = fov_map[pos]
    w = Wedge(
        (mx, my), 4.5,
        bore - fov / 2, bore + fov / 2,
        alpha=alpha,
        color=color,
        zorder=1,
    )
    ax.add_patch(w)
    # Camera label
    lx = mx + math.sin(math.radians(bore)) * 5.2
    ly = my + math.cos(math.radians(bore)) * 5.2
    ax.text(lx, ly, pos.value.upper(), color=color,
            fontsize=7, ha="center", va="center", fontweight="bold")


def _info_panel(ax, lines: list, title: str = "") -> None:
    """Render a text information panel."""
    ax.set_facecolor(C_PANEL)
    for spine in ax.spines.values():
        spine.set_edgecolor(C_ACCENT)
        spine.set_linewidth(0.8)
    ax.set_xticks([])
    ax.set_yticks([])
    if title:
        ax.set_title(title, color=C_ACCENT, fontsize=9, pad=4, fontweight="bold")
    y = 0.95
    for line in lines:
        color = line.get("color", C_WHITE)
        text = line.get("text", "")
        size = line.get("size", 8)
        ax.text(0.05, y, text, transform=ax.transAxes,
                color=color, fontsize=size, va="top", fontfamily="monospace")
        y -= 0.062 * (10 / max(size, 1))


def _bar_gauge(ax, value: float, vmin: float, vmax: float,
               label: str, unit: str = "", color: str = C_ACCENT) -> None:
    """Horizontal bar gauge."""
    ax.set_facecolor(C_PANEL)
    ax.set_xlim(vmin, vmax)
    ax.set_ylim(0, 1)
    ax.set_yticks([])
    ax.set_xticks([])
    for spine in ax.spines.values():
        spine.set_edgecolor(C_GREY)
        spine.set_linewidth(0.5)
    # Background
    ax.barh(0.4, vmax - vmin, left=vmin, height=0.3,
            color=C_GREY + "44", align="center")
    # Value bar
    ax.barh(0.4, value - vmin, left=vmin, height=0.3,
            color=color, align="center")
    # Labels
    ax.text(vmin + (vmax - vmin) * 0.02, 0.4, label,
            color=C_WHITE, fontsize=7, va="center")
    ax.text(vmax - (vmax - vmin) * 0.02, 0.4,
            f"{value:.1f}{unit}", color=color, fontsize=7, va="center", ha="right")


# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║  Scene generators                                                            ║
# ╚══════════════════════════════════════════════════════════════════════════════╝

def _parking_scene(tick: int) -> ECUInputs:
    """Generate a perpendicular parking scenario."""
    slot_dist = max(0.5, 4.0 - tick * 0.15)
    uss: dict = {}
    # Rear sensors close in as we reverse
    rear_dist = max(0.25, 4.0 - tick * 0.18)
    for k in ["USS_R1", "USS_R2", "USS_R3", "USS_R4"]:
        uss[k] = rear_dist
    for k in ["USS_F1", "USS_F2", "USS_F3", "USS_F4"]:
        uss[k] = max(0.8, 5.0 - tick * 0.05)
    for k in ["USS_FL", "USS_FR"]:
        uss[k] = 1.2
    for k in ["USS_RL", "USS_RR"]:
        uss[k] = 0.8
    return ECUInputs(
        scene_objects=[
            {"type": "parking_slot", "distance_m": slot_dist, "azimuth_deg": 2.0},
            {"type": "vehicle", "distance_m": max(1.0, slot_dist + 1.5), "azimuth_deg": -15.0},
        ],
        uss_distances=uss,
        vehicle_speed_mps=-0.8 if tick > 5 else 1.5,
        steering_angle_deg=-20.0 if 5 < tick < 15 else 15.0,
    )


def _hitch_scene(tick: int) -> ECUInputs:
    """Generate a trailer hitch alignment scenario."""
    dist = max(0.05, 2.5 - tick * 0.08)
    lateral_drift = max(-3.0, 8.0 - tick * 0.6)  # converging
    uss: dict = {}
    for k in ["USS_R1", "USS_R2", "USS_R3", "USS_R4"]:
        uss[k] = max(0.12, dist + 0.05)
    return ECUInputs(
        scene_objects=[
            {"type": "trailer_hitch", "distance_m": dist + 0.1, "azimuth_deg": 1.0},
        ],
        uss_distances=uss,
        vehicle_speed_mps=-0.4,
        steering_angle_deg=lateral_drift * 0.8,
        trailer_hitch_offset_px=(int(lateral_drift * 8), int(dist * 5)),
    )


def _tsg_scene(tick: int) -> ECUInputs:
    """Generate a trailer steering scenario with articulation sweep."""
    # Articulation oscillates to show jackknife prevention
    angle = 25.0 * math.sin(tick * 0.18)
    return ECUInputs(
        scene_objects=[],
        uss_distances={},
        vehicle_speed_mps=-1.2,
        steering_angle_deg=angle * 0.7,
        trailer_articulation_deg=angle,
    )


def _surround_scene(tick: int) -> ECUInputs:
    """Generic surround-view scene."""
    t = tick * 0.1
    return ECUInputs(
        scene_objects=[
            {"type": "vehicle", "distance_m": max(2.0, 12.0 - t * 2), "azimuth_deg": 5.0},
            {"type": "pedestrian", "distance_m": max(1.5, 8.0 - t), "azimuth_deg": -20.0},
            {"type": "cyclist", "distance_m": max(2.5, 10.0 - t * 1.5), "azimuth_deg": 30.0},
        ],
        uss_distances={
            "USS_F1": max(0.3, 4.0 - t * 0.4),
            "USS_F2": max(0.3, 5.0 - t * 0.3),
            "USS_F3": max(0.3, 5.0 - t * 0.3),
            "USS_F4": max(0.3, 4.0 - t * 0.4),
            "USS_FL": max(0.3, 3.0 - t * 0.2),
            "USS_FR": max(0.3, 2.5 - t * 0.2),
        },
        vehicle_speed_mps=5.0,
        lane_offset_m=math.sin(t) * 0.3,
    )


# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║  Plot builders                                                               ║
# ╚══════════════════════════════════════════════════════════════════════════════╝

def _build_surround_view(fig, gs_row, outputs, inputs, tick):
    """Row 0: Surround-view with all 4 cameras and USS overlay."""
    # Main surround view
    ax_sv = fig.add_subplot(gs_row[0, :3])
    _setup_dark_axes(ax_sv, "SURROUND VIEW  — All Cameras + 12 USS",
                     xlim=(-8, 8), ylim=(-8, 8))
    # Camera FOVs
    colors_cam = {
        CameraPosition.FRONT: C_ACCENT,
        CameraPosition.REAR:  C_GREEN,
        CameraPosition.LEFT:  C_YELLOW,
        CameraPosition.RIGHT: C_ORANGE,
    }
    for pos, col in colors_cam.items():
        _draw_camera_fov(ax_sv, pos, col)
    _draw_vehicle(ax_sv)
    # USS sensors
    _draw_uss_sensors(ax_sv, inputs.uss_distances)
    # Detected objects from all cameras
    for cam_name, frame in outputs.camera_frames.items():
        for det in frame.detections:
            rad = math.radians(det.azimuth_deg)
            ox = math.sin(rad) * det.distance_m
            oy = math.cos(rad) * det.distance_m
            ax_sv.plot(ox, oy, "o", markersize=5, color=C_RED, zorder=5)
            ax_sv.text(ox + 0.15, oy + 0.15, det.label[:4].upper(),
                       color=C_RED, fontsize=5, zorder=6)
    # Camera legend
    legend_handles = [
        mpatches.Patch(color=c, label=p.value.capitalize(), alpha=0.6)
        for p, c in colors_cam.items()
    ]
    ax_sv.legend(handles=legend_handles, loc="upper left",
                 fontsize=6, facecolor=C_PANEL, edgecolor=C_GREY,
                 labelcolor=C_WHITE)

    # Camera frames (simplified as colour-coded panels)
    cam_names = list(outputs.camera_frames.keys())
    cam_colors = [C_ACCENT, C_GREEN, C_YELLOW, C_ORANGE]
    for i in range(4):
        ax_c = fig.add_subplot(gs_row[0, 3 + i])
        cam_name = cam_names[i] if i < len(cam_names) else ""
        frame = outputs.camera_frames.get(cam_name)
        det_count = len(frame.detections) if frame else 0
        col = cam_colors[i]
        ax_c.set_facecolor(C_BG)
        ax_c.set_xlim(0, 10)
        ax_c.set_ylim(0, 7.5)
        for spine in ax_c.spines.values():
            spine.set_edgecolor(col)
            spine.set_linewidth(1.5)
        ax_c.set_xticks([])
        ax_c.set_yticks([])
        # Simulate camera image with bounding boxes
        ax_c.set_title(f"CAM_{cam_name.upper()}", color=col, fontsize=7, pad=2)
        # Road horizon
        ax_c.fill_between([0, 10], 0, 3.5, color="#1a2540", alpha=0.8)
        ax_c.fill_between([0, 10], 3.5, 7.5, color="#0d1625", alpha=0.8)
        # Lane markings (front/rear cams only)
        if cam_name in ("front", "rear"):
            for lx in [3.5, 6.5]:
                ax_c.plot([lx, lx * 0.98], [0, 3.5], color=C_YELLOW, lw=1.5, alpha=0.7)
        # Bounding boxes from detections
        if frame:
            bbox_colors = {"vehicle": C_ACCENT, "pedestrian": C_GREEN,
                           "cyclist": C_YELLOW, "parking_slot": C_ORANGE,
                           "trailer_hitch": C_ACCENT}
            for j, det in enumerate(frame.detections[:3]):
                bx = 2 + j * 2.5
                by = 0.5 + det.distance_m * 0.3
                bw = max(0.5, 1.5 - det.distance_m * 0.1)
                bh = bw * 1.8
                bc = bbox_colors.get(det.label, C_WHITE)
                ax_c.add_patch(Rectangle((bx, by), bw, bh,
                                         linewidth=1.2, edgecolor=bc,
                                         facecolor="none"))
                ax_c.text(bx, by + bh + 0.1, det.label[:4].upper(),
                          color=bc, fontsize=5.5)
        ax_c.text(0.5, 0.06, f"{det_count} obj",
                  transform=ax_c.transAxes, color=col, fontsize=6,
                  ha="center")

    # USS bar chart
    ax_uss = fig.add_subplot(gs_row[0, 7])
    ax_uss.set_facecolor(C_PANEL)
    ax_uss.set_title("USS (12)", color=C_ACCENT, fontsize=8, pad=3, fontweight="bold")
    sensor_short = [s.replace("USS_", "") for s in SENSOR_IDS]
    dists = [min(inputs.uss_distances.get(s, 5.1), 5.0) for s in SENSOR_IDS]
    colors_bar = [_uss_color(d) for d in dists]
    ax_uss.barh(sensor_short, dists, color=colors_bar, height=0.6)
    ax_uss.set_xlim(0, 5.2)
    ax_uss.tick_params(axis="y", colors=C_WHITE, labelsize=6)
    ax_uss.tick_params(axis="x", colors=C_GREY, labelsize=6)
    ax_uss.set_xlabel("dist (m)", color=C_GREY, fontsize=6)
    for spine in ax_uss.spines.values():
        spine.set_edgecolor(C_GREY)
        spine.set_linewidth(0.5)


def _build_parking_panel(fig, gs_row, outputs, inputs, tick):
    """Row 1: Autonomous Parking visualisation."""
    p = outputs.parking_status
    if p is None:
        return

    # Top-down parking view
    ax_pk = fig.add_subplot(gs_row[1, :4])
    _setup_dark_axes(ax_pk, "AUTONOMOUS PARKING", xlim=(-6, 6), ylim=(-5, 7))

    # Parking slot
    if p.slot:
        sx, sy = p.slot.centre_y_m, p.slot.centre_x_m
        slot_rect = Rectangle(
            (sx - p.slot.width_m / 2, sy - p.slot.length_m / 2),
            p.slot.width_m, p.slot.length_m,
            linewidth=1.5, edgecolor=C_GREEN, facecolor=C_GREEN + "18",
            linestyle="--",
        )
        ax_pk.add_patch(slot_rect)
        ax_pk.text(sx, sy, f"SLOT\n({p.slot.slot_type.value[:4].upper()})",
                   color=C_GREEN, fontsize=7, ha="center", va="center")

    # Planned path
    if p.path:
        px_list = [wp.y_m for wp in p.path]
        py_list = [wp.x_m for wp in p.path]
        ax_pk.plot(px_list, py_list, ":", color=C_ACCENT, lw=1.2, alpha=0.6)
        # Current waypoint marker
        if p.current_waypoint_idx < len(p.path):
            cwp = p.path[p.current_waypoint_idx]
            ax_pk.plot(cwp.y_m, cwp.x_m, "D",
                       markersize=7, color=C_ACCENT, zorder=5)

    _draw_vehicle(ax_pk, cx=0, cy=0)

    # Clearance annotations
    ax_pk.annotate(
        f"F: {p.front_clearance_m:.2f}m",
        xy=(0, VEH_L / 2 + 0.2), xytext=(0, VEH_L / 2 + 1.2),
        color=_uss_color(p.front_clearance_m), fontsize=7,
        ha="center", arrowprops=dict(arrowstyle="-", color=C_GREY, lw=0.8),
    )
    ax_pk.annotate(
        f"R: {p.rear_clearance_m:.2f}m",
        xy=(0, -VEH_L / 2 - 0.2), xytext=(0, -VEH_L / 2 - 1.2),
        color=_uss_color(p.rear_clearance_m), fontsize=7,
        ha="center", arrowprops=dict(arrowstyle="-", color=C_GREY, lw=0.8),
    )

    # Info panel
    ax_pi = fig.add_subplot(gs_row[1, 4:6])
    state_color = {
        ParkingState.IDLE: C_GREY,
        ParkingState.SCANNING: C_YELLOW,
        ParkingState.SLOT_DETECTED: C_ACCENT,
        ParkingState.ALIGNING: C_ACCENT,
        ParkingState.MANOEUVRING: C_ORANGE,
        ParkingState.PARKED: C_GREEN,
        ParkingState.ABORTED: C_RED,
    }.get(p.state, C_WHITE)
    lines = [
        {"text": f"STATE:  {p.state.name}", "color": state_color, "size": 8},
        {"text": "", "size": 7},
        {"text": f"Progress: {p.progress_pct:.0f}%", "color": C_WHITE, "size": 7},
        {"text": f"Front: {p.front_clearance_m:.2f} m", "color": _uss_color(p.front_clearance_m), "size": 7},
        {"text": f"Rear:  {p.rear_clearance_m:.2f} m", "color": _uss_color(p.rear_clearance_m), "size": 7},
        {"text": "", "size": 7},
        {"text": p.guidance_text[:45], "color": C_ACCENT, "size": 7},
        {"text": p.guidance_text[45:90], "color": C_ACCENT, "size": 7},
    ]
    if p.slot:
        lines += [
            {"text": "", "size": 7},
            {"text": f"Slot type:  {p.slot.slot_type.value}", "color": C_GREEN, "size": 7},
            {"text": f"Confidence: {p.slot.confidence:.0%}", "color": C_GREEN, "size": 7},
        ]
    _info_panel(ax_pi, lines, "PARKING STATUS")

    # Progress bar
    ax_prog = fig.add_subplot(gs_row[1, 6:])
    ax_prog.set_facecolor(C_PANEL)
    ax_prog.set_xlim(0, 100)
    ax_prog.set_ylim(0, 1)
    ax_prog.set_xticks([0, 25, 50, 75, 100])
    ax_prog.set_yticks([])
    ax_prog.tick_params(axis="x", colors=C_GREY, labelsize=6)
    for spine in ax_prog.spines.values():
        spine.set_edgecolor(C_GREY)
        spine.set_linewidth(0.4)
    ax_prog.set_title("Manoeuvre Progress", color=C_ACCENT, fontsize=8, pad=3, fontweight="bold")
    ax_prog.barh(0.4, p.progress_pct, height=0.35,
                 color=C_GREEN if p.state == ParkingState.PARKED else C_ACCENT)
    ax_prog.text(min(99, p.progress_pct + 1), 0.4,
                 f"{p.progress_pct:.0f}%", color=C_WHITE, fontsize=8, va="center")


def _build_hitch_panel(fig, gs_row, outputs, inputs, tick):
    """Row 2: Trailer Hitch Assist visualisation."""
    tha = outputs.tha_status
    if tha is None:
        return

    # Rear-view alignment display
    ax_rv = fig.add_subplot(gs_row[2, :4])
    _setup_dark_axes(ax_rv, "TRAILER HITCH ASSIST  — Rear Camera View",
                     xlim=(-4, 4), ylim=(-1, 6))

    # Vehicle rear bumper
    ax_rv.fill_between([-VEH_W / 2, VEH_W / 2], -0.15, 0.0,
                        color=C_VEHICLE, alpha=0.6)
    ax_rv.text(0, -0.3, "TOW BALL ●", color=C_WHITE, fontsize=7, ha="center")

    # Tow-ball marker
    ax_rv.plot(0, 0, "o", markersize=10, color=C_WHITE, zorder=5)

    if tha.hitch:
        h = tha.hitch
        lat = h.lateral_offset_cm / 100.0  # cm → m
        dist = h.distance_m
        # Hitch coupler
        ax_rv.plot(lat, dist, "^", markersize=12,
                   color=C_GREEN if tha.state == THAState.ALIGNED else C_YELLOW,
                   zorder=6)
        ax_rv.text(lat, dist + 0.3, "COUPLER", color=C_ORANGE, fontsize=7, ha="center")
        # Lateral offset line
        ax_rv.annotate(
            f"{h.lateral_offset_cm:+.1f} cm",
            xy=(lat, 0.1), xytext=(lat + 0.4, 0.8),
            color=C_YELLOW, fontsize=7,
            arrowprops=dict(arrowstyle="->", color=C_YELLOW, lw=0.8),
        )
        # Distance circles
        for r in [0.5, 1.0, 1.5, 2.0]:
            circ = Circle((0, 0), r, fill=False,
                           edgecolor=C_GREY, linewidth=0.5, linestyle=":", alpha=0.5)
            ax_rv.add_patch(circ)
            ax_rv.text(0.05, r, f"{r:.1f}m", color=C_GREY, fontsize=5)
        # Guidance arrow
        if tha.steering_correction_deg != 0:
            sx = 1.5 * math.sin(math.radians(tha.steering_correction_deg))
            ax_rv.annotate(
                "", xy=(sx, 2.5), xytext=(0, 2.5),
                arrowprops=dict(arrowstyle="->", color=C_ACCENT, lw=2),
            )
            ax_rv.text(sx / 2, 2.7, f"STEER {abs(tha.steering_correction_deg):.0f}°",
                       color=C_ACCENT, fontsize=7, ha="center")

    # Alignment centre line
    ax_rv.axvline(0, color=C_GREEN, linewidth=0.8, linestyle="--", alpha=0.5)

    # Info panel
    ax_hi = fig.add_subplot(gs_row[2, 4:6])
    state_color = {
        THAState.IDLE: C_GREY,
        THAState.SEARCHING: C_YELLOW,
        THAState.HITCH_FOUND: C_ACCENT,
        THAState.GUIDING: C_ACCENT,
        THAState.ALIGNED: C_GREEN,
        THAState.COUPLED: C_GREEN,
        THAState.FAULT: C_RED,
    }.get(tha.state, C_WHITE)
    lines = [
        {"text": f"STATE:  {tha.state.name}", "color": state_color, "size": 8},
        {"text": "", "size": 7},
    ]
    if tha.hitch:
        h = tha.hitch
        lines += [
            {"text": f"Distance:  {h.distance_m:.3f} m", "color": C_WHITE, "size": 7},
            {"text": f"Lat offset: {h.lateral_offset_cm:+.1f} cm", "color": C_YELLOW, "size": 7},
            {"text": f"Confidence: {h.confidence:.0%}", "color": C_GREEN, "size": 7},
            {"text": "", "size": 7},
            {"text": f"Steer corr: {tha.steering_correction_deg:+.1f}°", "color": C_ACCENT, "size": 7},
            {"text": f"Rev speed:  {tha.longitudinal_speed_mps:.2f} m/s", "color": C_WHITE, "size": 7},
            {"text": f"Alert:      {tha.alert_level.upper()}", "color": state_color, "size": 7},
        ]
    lines += [
        {"text": "", "size": 7},
        {"text": tha.guidance_text[:45], "color": C_ACCENT, "size": 7},
        {"text": tha.guidance_text[45:90], "color": C_ACCENT, "size": 7},
    ]
    _info_panel(ax_hi, lines, "HITCH STATUS")

    # Lateral offset gauge
    ax_lat = fig.add_subplot(gs_row[2, 6:])
    lat_val = tha.hitch.lateral_offset_cm if tha.hitch else 0.0
    _bar_gauge(ax_lat, lat_val, -20, 20, "Lateral offset", " cm",
               color=C_GREEN if abs(lat_val) <= 3 else C_YELLOW)
    ax_lat.set_title("Alignment Gauge", color=C_ACCENT, fontsize=8, pad=3)


def _build_tsg_panel(fig, gs_row, outputs, inputs, tick):
    """Row 3: Trailer Steering Guidance visualisation."""
    tsg = outputs.tsg_status
    if tsg is None:
        return

    # Top-down trailer view
    ax_tg = fig.add_subplot(gs_row[3, :4])
    _setup_dark_axes(ax_tg, "TRAILER STEERING GUIDANCE", xlim=(-7, 7), ylim=(-9, 4))
    _draw_vehicle(ax_tg, cx=0, cy=0)
    angle = tsg.trailer.articulation_angle_deg if tsg.trailer else 0.0
    _draw_trailer(ax_tg, 0, 0, angle)

    # Jackknife danger zone arc
    danger_arc = Arc(
        (0, -VEH_L / 2 - 0.3), 10, 10,
        theta1=180 - 55, theta2=180 + 55,
        color=C_RED, linewidth=1.0, linestyle="--", alpha=0.4,
    )
    ax_tg.add_patch(danger_arc)
    ax_tg.text(0, -9.5, "─── Jackknife zone ───",
               color=C_RED, fontsize=6.5, ha="center", alpha=0.7)

    # Current articulation angle indicator
    angle_rad = math.radians(angle)
    ax_len = 6.0
    ax_tg.annotate(
        "", xy=(math.sin(angle_rad) * ax_len, -math.cos(angle_rad) * ax_len),
        xytext=(0, -VEH_L / 2 - 0.3),
        arrowprops=dict(arrowstyle="->", color=C_TRAILER, lw=2),
    )
    ax_tg.text(0.05, 0.95, f"γ = {angle:+.1f}°",
               transform=ax_tg.transAxes, color=C_TRAILER, fontsize=9,
               va="top", fontweight="bold")

    # Steering wheel recommendation
    steer = tsg.recommended_steer_deg
    if steer != 0:
        sw_col = C_RED if abs(angle) >= 55 else C_ACCENT
        ax_tg.text(0.05, 0.85,
                   f"→ STEER: {steer:+.0f}°",
                   transform=ax_tg.transAxes, color=sw_col,
                   fontsize=9, va="top", fontweight="bold")

    # Info panel
    ax_ti = fig.add_subplot(gs_row[3, 4:6])
    state_color = {
        TSGState.IDLE: C_GREY,
        TSGState.TRAILER_DETECTED: C_ACCENT,
        TSGState.TRACKING: C_ACCENT,
        TSGState.REVERSING_ACTIVE: C_GREEN,
        TSGState.JACKKNIFE_RISK: C_RED,
        TSGState.STABLE: C_GREEN,
    }.get(tsg.state, C_WHITE)
    lines = [
        {"text": f"STATE:  {tsg.state.name}", "color": state_color, "size": 8},
        {"text": "", "size": 7},
    ]
    if tsg.trailer:
        tr = tsg.trailer
        lines += [
            {"text": f"Articulation:  {tr.articulation_angle_deg:+.1f}°", "color": C_TRAILER, "size": 7},
            {"text": f"Angular vel:   {tr.angular_velocity_dps:+.1f} °/s", "color": C_WHITE, "size": 7},
            {"text": f"Trailer len:   {tr.trailer_length_m:.1f} m", "color": C_GREY, "size": 7},
            {"text": "", "size": 7},
            {"text": f"Jackknife risk: {tsg.jackknife_risk:.0%}", "color": C_RED if tsg.jackknife_risk > 0.7 else C_YELLOW, "size": 7},
            {"text": f"Steer cmd:     {steer:+.1f}°", "color": C_ACCENT, "size": 7},
            {"text": f"Alert:         {tsg.alert_level.upper()}", "color": state_color, "size": 7},
        ]
    lines += [
        {"text": "", "size": 7},
        {"text": tsg.guidance_text[:44], "color": C_ACCENT, "size": 7},
        {"text": tsg.guidance_text[44:88], "color": C_ACCENT, "size": 7},
    ]
    _info_panel(ax_ti, lines, "TSG STATUS")

    # Jackknife risk gauge
    ax_jk = fig.add_subplot(gs_row[3, 6:])
    risk = tsg.jackknife_risk
    _bar_gauge(ax_jk, risk * 100, 0, 100, "Jackknife Risk", "%",
               color=C_RED if risk > 0.7 else C_YELLOW if risk > 0.4 else C_GREEN)
    ax_jk.set_title("Risk Monitor", color=C_ACCENT, fontsize=8, pad=3)


# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║  Main demo loop                                                              ║
# ╚══════════════════════════════════════════════════════════════════════════════╝

def run_demo(
    mode: str = "all",
    steps: int = 30,
    output_dir: str = ".",
) -> List[str]:
    """
    Run the ADAS ECU demo and save PNG snapshots.

    Returns
    -------
    List[str]
        Paths to all saved screenshot files.
    """
    ecu = ADASECUCore(seed=7)

    saved_files: List[str] = []

    def _render_frame(inputs: ECUInputs, tick: int, label: str):
        outputs = ecu.step(inputs)
        fig = plt.figure(figsize=(20, 14), facecolor=C_BG)
        fig.suptitle(
            f"  VIRTUAL ADAS ECU  |  {label}  |  Tick {tick:03d}  |"
            f"  Health: {outputs.system_health}  |"
            f"  Active: {', '.join(outputs.active_features) or 'none'}",
            color=C_ACCENT, fontsize=10, fontweight="bold",
            x=0.01, ha="left",
        )
        gs = gridspec.GridSpec(
            4, 8,
            figure=fig,
            left=0.03, right=0.98,
            top=0.94, bottom=0.03,
            wspace=0.35, hspace=0.55,
        )
        _build_surround_view(fig, gs, outputs, inputs, tick)
        _build_parking_panel(fig, gs, outputs, inputs, tick)
        _build_hitch_panel(fig, gs, outputs, inputs, tick)
        _build_tsg_panel(fig, gs, outputs, inputs, tick)
        fpath = os.path.join(output_dir, f"adas_demo_{label.replace(' ', '_')}_{tick:03d}.png")
        fig.savefig(fpath, dpi=120, bbox_inches="tight", facecolor=C_BG)
        plt.close(fig)
        return fpath, outputs

    # ── Scenario schedule ─────────────────────────────────────────────
    if mode in ("parking", "all"):
        ecu.activate_parking(ParkingType.PERPENDICULAR)
    if mode in ("hitch", "all"):
        ecu.activate_tha()
    if mode in ("tsg", "all"):
        ecu.activate_tsg()

    scene_labels = {
        "parking": ("Autonomous Parking", _parking_scene),
        "hitch": ("Trailer Hitch Assist", _hitch_scene),
        "tsg": ("Trailer Steering Guidance", _tsg_scene),
        "all": ("All Features Active", lambda t: _parking_scene(t)),
    }
    label, scene_fn = scene_labels.get(mode, scene_labels["all"])

    print(f"\n[ADAS ECU Demo]  mode={mode}  steps={steps}")
    print("=" * 60)

    for tick in range(steps):
        inputs = scene_fn(tick)
        # Inject hitch/TSG inputs for combined mode
        if mode == "all":
            hi = _hitch_scene(tick)
            ti = _tsg_scene(tick)
            inputs.trailer_hitch_offset_px = hi.trailer_hitch_offset_px
            inputs.trailer_articulation_deg = ti.trailer_articulation_deg

        fpath, outputs = _render_frame(inputs, tick, label)
        saved_files.append(fpath)
        # Summary to stdout
        if outputs.parking_status:
            ps = outputs.parking_status
            print(f"  [{tick:02d}] PARK  state={ps.state.name:<16} "
                  f"progress={ps.progress_pct:5.1f}%  "
                  f"rear={ps.rear_clearance_m:.2f}m")
        if outputs.tha_status:
            tha = outputs.tha_status
            lat = tha.hitch.lateral_offset_cm if tha.hitch else float("nan")
            print(f"  [{tick:02d}] THA   state={tha.state.name:<14} "
                  f"lat_offset={lat:+.1f}cm  "
                  f"steer={tha.steering_correction_deg:+.1f}°")
        if outputs.tsg_status:
            ts = outputs.tsg_status
            ang = ts.trailer.articulation_angle_deg if ts.trailer else 0
            print(f"  [{tick:02d}] TSG   state={ts.state.name:<18} "
                  f"angle={ang:+.1f}°  "
                  f"risk={ts.jackknife_risk:.1%}  "
                  f"steer={ts.recommended_steer_deg:+.1f}°")

    print(f"\n[ADAS ECU Demo]  Saved {len(saved_files)} frame(s) to '{output_dir}'")
    return saved_files


# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║  Entry point                                                                 ║
# ╚══════════════════════════════════════════════════════════════════════════════╝

def _parse_args():
    ap = argparse.ArgumentParser(
        description="Virtual ADAS ECU Demo — generates PNG dashboard snapshots",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "--mode",
        choices=["parking", "hitch", "tsg", "all"],
        default="all",
        help="Demo scenario (default: all)",
    )
    ap.add_argument(
        "--steps", type=int, default=30,
        help="Number of simulation steps / frames (default: 30)",
    )
    ap.add_argument(
        "--output-dir", default=".",
        help="Directory to save PNG snapshots (default: current dir)",
    )
    return ap.parse_args()


if __name__ == "__main__":
    args = _parse_args()
    os.makedirs(args.output_dir, exist_ok=True)
    files = run_demo(
        mode=args.mode,
        steps=args.steps,
        output_dir=args.output_dir,
    )
    if files:
        print(f"\nFirst frame: {files[0]}")
        print(f"Last  frame: {files[-1]}")
