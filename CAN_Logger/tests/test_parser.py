import sys
import os
import types
import pytest

# Stub tkinter before any imports
for mod_name in ["tkinter", "tkinter.ttk", "tkinter.filedialog",
                  "tkinter.messagebox", "tkinter.scrolledtext"]:
    if mod_name not in sys.modules:
        mod = types.ModuleType(mod_name)
        sys.modules[mod_name] = mod

import matplotlib
matplotlib.use("Agg")

# Add parent dir to path for can_logger_gui
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from can_logger_gui import parser as log_parser  # noqa: E402

FIXTURE = os.path.join(os.path.dirname(__file__), "fixtures", "sample.asc")


def test_parse_returns_dataframe():
    import pandas as pd
    df = log_parser.parse_log(FIXTURE)
    assert isinstance(df, pd.DataFrame)
    assert len(df) > 0


def test_timestamp_starts_at_zero():
    df = log_parser.parse_log(FIXTURE)
    assert df["timestamp_sec"].iloc[0] == pytest.approx(0.0)


def test_can_id_uppercase():
    df = log_parser.parse_log(FIXTURE)
    for cid in df["can_id"]:
        assert cid == cid.upper(), f"CAN ID {cid} should be uppercase"


def test_byte_columns_exist():
    df = log_parser.parse_log(FIXTURE)
    for col in ["byte0", "byte1", "byte2", "byte3"]:
        assert col in df.columns


def test_byte_values_in_range():
    df = log_parser.parse_log(FIXTURE)
    for col in ["byte0", "byte1"]:
        valid = df[col].dropna()
        assert (valid >= 0).all() and (valid <= 255).all()


def test_missing_file_raises():
    with pytest.raises((FileNotFoundError, Exception)):
        log_parser.parse_log("/nonexistent/path/file.asc")


def test_expected_can_ids():
    df = log_parser.parse_log(FIXTURE)
    ids = set(df["can_id"].unique())
    assert "100" in ids or any("100" in i for i in ids)


def test_dlc_column():
    df = log_parser.parse_log(FIXTURE)
    assert "dlc" in df.columns
    assert df["dlc"].dtype in ["int64", "int32", "float64"]
