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

try:
    import cantools
    _CANTOOLS_OK = True
except ImportError:
    _CANTOOLS_OK = False

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


def load_database(db_path: str):
    """Load a DBC or CDD signal database via cantools.

    Parameters
    ----------
    db_path : str
        Path to a ``.dbc`` or ``.cdd`` file.

    Returns
    -------
    cantools.database.can.Database or None
        The loaded database, or ``None`` when cantools is unavailable.

    Raises
    ------
    FileNotFoundError
        If *db_path* does not exist.
    cantools.database.UnsupportedDatabaseFormatError
        If the file format is not recognised.
    """
    if not _CANTOOLS_OK:
        raise ImportError("cantools is not installed; cannot load DBC/CDD files.")
    if not os.path.exists(db_path):
        raise FileNotFoundError(f"Database file not found: {db_path}")
    return cantools.database.load_file(db_path)


def decode_signals(df: pd.DataFrame, db) -> pd.DataFrame:
    """Decode CAN signals for every row in *df* using *db*.

    Each decoded signal produces one row in the returned DataFrame which has
    columns: ``timestamp_sec``, ``can_id``, ``signal_name``, ``signal_value``,
    ``unit``.  Rows for messages not present in the database are silently
    skipped.

    Parameters
    ----------
    df : pd.DataFrame
        Parsed CAN log DataFrame as returned by :func:`parse_log`.
    db : cantools.database.can.Database
        Loaded signal database.

    Returns
    -------
    pd.DataFrame
    """
    if df is None or df.empty or db is None:
        return pd.DataFrame(columns=["timestamp_sec", "can_id",
                                     "signal_name", "signal_value", "unit"])

    rows = []
    for _, row in df.iterrows():
        # Convert hex CAN ID to integer for lookup
        try:
            frame_id = int(row["can_id"], 16)
        except (ValueError, TypeError):
            continue

        try:
            msg_def = db.get_message_by_frame_id(frame_id)
        except KeyError:
            continue

        # Build payload bytes from byte columns
        payload = bytes(
            int(row[f"byte{i}"])
            for i in range(min(int(row["dlc"]) if pd.notna(row["dlc"]) else 0, 8))
            if pd.notna(row.get(f"byte{i}"))
        )
        if len(payload) < msg_def.length:
            payload = payload.ljust(msg_def.length, b'\x00')

        try:
            decoded = msg_def.decode(payload, decode_choices=False)
        except Exception:
            continue

        for sig_name, sig_val in decoded.items():
            unit = ""
            try:
                sig_def = msg_def.get_signal_by_name(sig_name)
                unit = sig_def.unit or ""
            except Exception:
                pass
            rows.append({
                "timestamp_sec": row["timestamp_sec"],
                "can_id": row["can_id"],
                "signal_name": sig_name,
                "signal_value": sig_val,
                "unit": unit,
            })

    return pd.DataFrame(rows, columns=["timestamp_sec", "can_id",
                                       "signal_name", "signal_value", "unit"])


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
