import sys
import os
import types
import pytest
import pandas as pd
import numpy as np

# Stub tkinter
for mod_name in ["tkinter", "tkinter.ttk", "tkinter.filedialog",
                  "tkinter.messagebox", "tkinter.scrolledtext"]:
    if mod_name not in sys.modules:
        mod = types.ModuleType(mod_name)
        sys.modules[mod_name] = mod

import matplotlib
matplotlib.use("Agg")

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from can_logger_gui import analytics  # noqa: E402


def make_test_df():
    """Create small in-memory DataFrame for testing."""
    rows = []
    # ID 100, 10 messages, 10ms apart
    for i in range(10):
        rows.append({
            "timestamp_sec": i * 0.010,
            "can_id": "100",
            "dlc": 8,
            "byte0": i * 10, "byte1": 5, "byte2": 0, "byte3": 0,
            "byte4": 0, "byte5": 0, "byte6": 0, "byte7": 0,
            "hex_data": f"{i*10:02X}050000000000",
            "channel": "1", "line_number": i + 1, "timestamp_raw": str(i * 0.010),
        })
    # ID 200, 5 messages, 20ms apart
    for i in range(5):
        rows.append({
            "timestamp_sec": i * 0.020,
            "can_id": "200",
            "dlc": 4,
            "byte0": 100, "byte1": 200, "byte2": np.nan, "byte3": np.nan,
            "byte4": np.nan, "byte5": np.nan, "byte6": np.nan, "byte7": np.nan,
            "hex_data": "64C8",
            "channel": "1", "line_number": i + 11, "timestamp_raw": str(i * 0.020),
        })
    return pd.DataFrame(rows)


DF = make_test_df()


def test_compute_summary_total():
    s = analytics.compute_summary(DF)
    assert s["total_messages"] == 15


def test_compute_summary_duration():
    s = analytics.compute_summary(DF)
    assert s["duration_sec"] == pytest.approx(0.09, abs=0.01)


def test_compute_summary_unique_ids():
    s = analytics.compute_summary(DF)
    assert len(s["unique_can_ids"]) == 2


def test_frequency_per_id_count():
    freq = analytics.compute_frequency_per_id(DF)
    assert "100" in freq["can_id"].values
    row = freq[freq["can_id"] == "100"].iloc[0]
    assert row["count"] == 10


def test_frequency_per_id_hz():
    freq = analytics.compute_frequency_per_id(DF)
    row = freq[freq["can_id"] == "100"].iloc[0]
    assert row["freq_hz"] > 0


def test_inter_arrival_times():
    iat = analytics.compute_inter_arrival_times(DF)
    row = iat[iat["can_id"] == "100"].iloc[0]
    assert row["mean_iat_ms"] == pytest.approx(10.0, abs=1.0)


def test_byte_statistics_columns():
    stats = analytics.compute_byte_statistics(DF, can_id="100")
    assert "byte0_min" in stats.columns
    assert "byte0_max" in stats.columns
    assert "byte0_mean" in stats.columns


def test_detect_high_variance_bytes():
    hv = analytics.detect_high_variance_bytes(DF, "100")
    # byte0 has values 0,10,20,...,90 -> std ~30 -> high variance
    assert 0 in hv


def test_detect_high_variance_bytes_low():
    hv = analytics.detect_high_variance_bytes(DF, "100")
    # byte1 is always 5 -> std=0 -> not high variance
    assert 1 not in hv


def test_message_rate_timeseries():
    rate = analytics.compute_message_rate_timeseries(DF, bin_size_sec=0.05)
    assert "time_sec" in rate.columns
    assert "rate" in rate.columns
    assert len(rate) > 0
