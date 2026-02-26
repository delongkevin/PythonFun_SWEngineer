"""Parser bridge: wraps RXMessageParser and returns a tidy pandas DataFrame."""

import os
import sys
import numpy as np
import pandas as pd

# ---------------------------------------------------------------------------
# Make CAN_Log_Parser importable regardless of working directory
# ---------------------------------------------------------------------------
_PARSER_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "CAN_Log_Parser"))
if _PARSER_DIR not in sys.path:
    sys.path.insert(0, _PARSER_DIR)

from CAN_log_parser import RXMessageParser  # noqa: E402

COLUMNS = [
    "timestamp_raw",
    "timestamp_sec",
    "can_id",
    "dlc",
    "byte0", "byte1", "byte2", "byte3",
    "byte4", "byte5", "byte6", "byte7",
    "hex_data",
    "channel",
    "line_number",
]


def parse_log(file_path: str) -> pd.DataFrame:
    """Parse a CAN log file and return a tidy DataFrame.

    Parameters
    ----------
    file_path : str
        Path to the log file (.asc, .blf, .txt).

    Returns
    -------
    pd.DataFrame
        One row per message with the columns defined in ``COLUMNS``.

    Raises
    ------
    FileNotFoundError
        If *file_path* does not exist.
    """
    if not os.path.exists(file_path):
        raise FileNotFoundError(f"File not found: {file_path}")

    parser = RXMessageParser()
    messages = parser.parse_file(file_path)

    if not messages:
        return pd.DataFrame(columns=COLUMNS)

    rows = []
    for msg in messages:
        byte_array = msg.get("byte_array", [])

        # Build byte0-byte7 columns from the byte_array list
        bytes_dict: dict = {}
        for i in range(8):
            if i < len(byte_array):
                try:
                    bytes_dict[f"byte{i}"] = int(byte_array[i])
                except (ValueError, TypeError):
                    bytes_dict[f"byte{i}"] = np.nan
            else:
                bytes_dict[f"byte{i}"] = np.nan

        # Timestamp - Pattern-1 ASC files use a plain float string
        ts_raw = str(msg.get("timestamp", "0"))
        try:
            ts_sec = float(ts_raw)
        except (ValueError, TypeError):
            ts_sec = np.nan

        # CAN ID - always uppercase hex
        can_id = str(msg.get("can_id", "")).upper().strip()

        try:
            dlc = int(msg.get("dlc", 0))
        except (ValueError, TypeError):
            dlc = 0

        row = {
            "timestamp_raw": ts_raw,
            "timestamp_sec": ts_sec,
            "can_id": can_id,
            "dlc": dlc,
            "hex_data": str(msg.get("hex_data", "")),
            "channel": str(msg.get("channel", "")),
            "line_number": int(msg.get("line_number", 0)),
            **bytes_dict,
        }
        rows.append(row)

    df = pd.DataFrame(rows, columns=COLUMNS)

    # Sort by timestamp so iloc[0] is always the earliest message
    df.sort_values("timestamp_sec", kind="stable", inplace=True, ignore_index=True)

    # Normalise: first message starts at 0.0
    if not df.empty and not df["timestamp_sec"].isna().all():
        t0 = df["timestamp_sec"].dropna().iloc[0]
        df["timestamp_sec"] = df["timestamp_sec"] - t0

    return df
