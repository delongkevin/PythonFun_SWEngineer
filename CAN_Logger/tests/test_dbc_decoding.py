"""Tests for DBC/CDD loading and signal decoding."""
import sys
import os
import types
import tempfile
import pytest
import pandas as pd

# Stub tkinter before any imports
for mod_name in ["tkinter", "tkinter.ttk", "tkinter.filedialog",
                  "tkinter.messagebox", "tkinter.scrolledtext"]:
    if mod_name not in sys.modules:
        mod = types.ModuleType(mod_name)
        sys.modules[mod_name] = mod

import matplotlib
matplotlib.use("Agg")

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from can_logger_gui import parser as log_parser  # noqa: E402

# ---------------------------------------------------------------------------
# Minimal DBC fixture
# ---------------------------------------------------------------------------

_DBC_CONTENT = '''\
VERSION ""

NS_ :

BS_:

BU_:

BO_ 256 TestMsg: 8 Vector__XXX
 SG_ Speed : 0|8@1+ (1,0) [0|255] "km/h" Vector__XXX
 SG_ RPM : 8|8@1+ (10,0) [0|2550] "rpm" Vector__XXX

'''


@pytest.fixture()
def dbc_path(tmp_path):
    """Write a minimal DBC file and return its path."""
    p = tmp_path / "test.dbc"
    p.write_text(_DBC_CONTENT)
    return str(p)


@pytest.fixture()
def sample_df():
    """Create a small DataFrame matching the DBC above (CAN ID 0x100 = 256)."""
    rows = []
    for i in range(5):
        rows.append({
            "timestamp_raw": str(i * 0.010),
            "timestamp_sec": float(i * 0.010),
            "can_id": "100",       # hex 0x100 == 256
            "dlc": 8,
            "byte0": i + 10,
            "byte1": i + 20,
            "byte2": 0, "byte3": 0,
            "byte4": 0, "byte5": 0, "byte6": 0, "byte7": 0,
            "hex_data": f"{i+10:02X}{i+20:02X}000000000000",
            "channel": "1",
            "line_number": i + 1,
        })
    return pd.DataFrame(rows)


# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

def test_load_database_returns_db(dbc_path):
    db = log_parser.load_database(dbc_path)
    assert db is not None


def test_load_database_has_messages(dbc_path):
    db = log_parser.load_database(dbc_path)
    assert len(db.messages) == 1
    assert db.messages[0].name == "TestMsg"


def test_load_database_missing_file():
    with pytest.raises((FileNotFoundError, Exception)):
        log_parser.load_database("/nonexistent/path/missing.dbc")


def test_decode_signals_returns_dataframe(dbc_path, sample_df):
    db = log_parser.load_database(dbc_path)
    result = log_parser.decode_signals(sample_df, db)
    assert isinstance(result, pd.DataFrame)


def test_decode_signals_columns(dbc_path, sample_df):
    db = log_parser.load_database(dbc_path)
    result = log_parser.decode_signals(sample_df, db)
    for col in ("timestamp_sec", "can_id", "signal_name", "signal_value", "unit"):
        assert col in result.columns, f"Column '{col}' missing from decoded signals"


def test_decode_signals_signal_names(dbc_path, sample_df):
    db = log_parser.load_database(dbc_path)
    result = log_parser.decode_signals(sample_df, db)
    assert not result.empty
    names = set(result["signal_name"].unique())
    assert "Speed" in names
    assert "RPM" in names


def test_decode_signals_units(dbc_path, sample_df):
    db = log_parser.load_database(dbc_path)
    result = log_parser.decode_signals(sample_df, db)
    speed_rows = result[result["signal_name"] == "Speed"]
    assert not speed_rows.empty
    assert speed_rows["unit"].iloc[0] == "km/h"


def test_decode_signals_empty_df(dbc_path):
    db = log_parser.load_database(dbc_path)
    result = log_parser.decode_signals(pd.DataFrame(), db)
    assert result.empty


def test_decode_signals_no_matching_id(dbc_path):
    """Messages with IDs not in the DB produce an empty signals DataFrame."""
    db = log_parser.load_database(dbc_path)
    df = pd.DataFrame([{
        "timestamp_raw": "0.0", "timestamp_sec": 0.0,
        "can_id": "FFF",  # not in DB
        "dlc": 8,
        "byte0": 1, "byte1": 2, "byte2": 0, "byte3": 0,
        "byte4": 0, "byte5": 0, "byte6": 0, "byte7": 0,
        "hex_data": "0102000000000000", "channel": "1", "line_number": 1,
    }])
    result = log_parser.decode_signals(df, db)
    assert result.empty
