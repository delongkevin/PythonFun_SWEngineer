"""Analytics functions for CAN log DataFrames."""

import numpy as np
import pandas as pd


# ---------------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------------

def compute_summary(df: pd.DataFrame) -> dict:
    """Return high-level statistics for a parsed log DataFrame.

    Keys: total_messages, duration_sec, unique_can_ids, start_time, end_time.
    """
    if df.empty:
        return {
            "total_messages": 0,
            "duration_sec": 0.0,
            "unique_can_ids": [],
            "start_time": np.nan,
            "end_time": np.nan,
        }

    ts = df["timestamp_sec"].dropna()
    start = float(ts.min()) if not ts.empty else np.nan
    end = float(ts.max()) if not ts.empty else np.nan
    duration = (end - start) if (not np.isnan(start) and not np.isnan(end)) else 0.0

    return {
        "total_messages": len(df),
        "duration_sec": duration,
        "unique_can_ids": sorted(df["can_id"].dropna().unique().tolist()),
        "start_time": start,
        "end_time": end,
    }


# ---------------------------------------------------------------------------
# Frequency per ID
# ---------------------------------------------------------------------------

def compute_frequency_per_id(df: pd.DataFrame) -> pd.DataFrame:
    """Return per-ID message count and frequency in Hz.

    Returns DataFrame with columns: can_id, count, freq_hz.
    freq_hz is computed as count / total_duration.
    """
    if df.empty:
        return pd.DataFrame(columns=["can_id", "count", "freq_hz"])

    ts = df["timestamp_sec"].dropna()
    duration = float(ts.max() - ts.min()) if len(ts) > 1 else 1.0
    if duration <= 0:
        duration = 1.0

    counts = df.groupby("can_id").size().reset_index(name="count")
    counts["freq_hz"] = counts["count"] / duration
    counts = counts.sort_values("can_id").reset_index(drop=True)
    return counts


# ---------------------------------------------------------------------------
# Inter-arrival times
# ---------------------------------------------------------------------------

def compute_inter_arrival_times(df: pd.DataFrame) -> pd.DataFrame:
    """Compute inter-arrival time statistics per CAN ID.

    Returns DataFrame with columns: can_id, mean_iat_ms, min_iat_ms, max_iat_ms, std_iat_ms.
    """
    if df.empty:
        return pd.DataFrame(columns=["can_id", "mean_iat_ms", "min_iat_ms", "max_iat_ms", "std_iat_ms"])

    rows = []
    for cid, group in df.groupby("can_id"):
        ts = group["timestamp_sec"].dropna().sort_values()
        diffs_ms = ts.diff().dropna() * 1000.0
        if diffs_ms.empty:
            rows.append({
                "can_id": cid,
                "mean_iat_ms": np.nan,
                "min_iat_ms": np.nan,
                "max_iat_ms": np.nan,
                "std_iat_ms": np.nan,
            })
        else:
            rows.append({
                "can_id": cid,
                "mean_iat_ms": float(diffs_ms.mean()),
                "min_iat_ms": float(diffs_ms.min()),
                "max_iat_ms": float(diffs_ms.max()),
                "std_iat_ms": float(diffs_ms.std()),
            })

    return pd.DataFrame(rows)


# ---------------------------------------------------------------------------
# Byte statistics
# ---------------------------------------------------------------------------

def compute_byte_statistics(df: pd.DataFrame, can_id: str = None) -> pd.DataFrame:
    """Compute per-byte statistics, optionally filtered to a single CAN ID.

    Returns DataFrame indexed by can_id with columns:
    byte{n}_min, byte{n}_max, byte{n}_mean, byte{n}_changes  (n = 0..7).
    """
    if can_id is not None:
        df = df[df["can_id"] == can_id]

    if df.empty:
        return pd.DataFrame()

    rows = []
    for cid, group in df.groupby("can_id"):
        row: dict = {}
        for b in range(8):
            col = f"byte{b}"
            if col in group.columns:
                vals = group[col].dropna()
                if len(vals) > 0:
                    row[f"{col}_min"] = float(vals.min())
                    row[f"{col}_max"] = float(vals.max())
                    row[f"{col}_mean"] = float(vals.mean())
                    # Number of transitions (value changes)
                    row[f"{col}_changes"] = int((vals.diff().dropna() != 0).sum())
                else:
                    row[f"{col}_min"] = np.nan
                    row[f"{col}_max"] = np.nan
                    row[f"{col}_mean"] = np.nan
                    row[f"{col}_changes"] = 0
            else:
                row[f"{col}_min"] = np.nan
                row[f"{col}_max"] = np.nan
                row[f"{col}_mean"] = np.nan
                row[f"{col}_changes"] = 0
        rows.append((cid, row))

    result = pd.DataFrame([r for _, r in rows], index=[c for c, _ in rows])
    result.index.name = "can_id"
    return result


# ---------------------------------------------------------------------------
# High-variance bytes
# ---------------------------------------------------------------------------

def detect_high_variance_bytes(df: pd.DataFrame, can_id: str, threshold: float = 10.0) -> list:
    """Return list of byte indices (0-7) with std deviation above *threshold*.

    Filters *df* to *can_id* first.
    """
    sub = df[df["can_id"] == can_id]
    if sub.empty:
        return []

    high_var = []
    for b in range(8):
        col = f"byte{b}"
        if col in sub.columns:
            vals = sub[col].dropna()
            if len(vals) > 1 and float(vals.std()) > threshold:
                high_var.append(b)
    return high_var


# ---------------------------------------------------------------------------
# Message-rate time series
# ---------------------------------------------------------------------------

def compute_message_rate_timeseries(df: pd.DataFrame, bin_size_sec: float = 1.0) -> pd.DataFrame:
    """Bin messages into fixed-size time windows and return rate (msg/s).

    Returns DataFrame with columns: time_sec (bin start), rate.
    """
    if df.empty or "timestamp_sec" not in df.columns:
        return pd.DataFrame(columns=["time_sec", "rate"])

    ts = df["timestamp_sec"].dropna()
    if ts.empty:
        return pd.DataFrame(columns=["time_sec", "rate"])

    t_min = float(ts.min())
    t_max = float(ts.max())

    # Build bin edges
    bins = np.arange(t_min, t_max + bin_size_sec, bin_size_sec)
    if len(bins) < 2:
        bins = np.array([t_min, t_min + bin_size_sec])

    counts, edges = np.histogram(ts.values, bins=bins)
    time_sec = edges[:-1]
    rate = counts / bin_size_sec

    return pd.DataFrame({"time_sec": time_sec, "rate": rate.astype(float)})
