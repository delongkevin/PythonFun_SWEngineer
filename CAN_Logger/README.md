# CAN Logger GUI

A professional desktop application for visualising, filtering, and analysing CAN bus log files.

## Overview

**CAN Logger GUI** wraps the existing `RXMessageParser` with a polished tkinter interface and a headless CLI, turning raw `.asc`, `.blf`, or `.txt` log files into interactive charts and exportable reports.

Key features:

| Feature | Description |
|---|---|
| Tabular frame browser | Sortable, scrollable treeview with per-byte hex columns |
| Live filtering | Filter by CAN ID, time window, DLC, and data pattern |
| Rate plot | Per-bin message-rate time series with per-ID overlay |
| Byte analysis | Distribution histogram + value time series per byte |
| Exports | CSV, JSON, self-contained HTML report with embedded plots |
| CLI mode | Full headless analysis without a display |

## Supported formats

| Extension | Format |
|---|---|
| `.asc` | Vector ASC (Pattern 1: `timestamp channel Rx/Tx 0 CAN_ID dlc data`) |
| `.blf` | Binary Log File (parsed via the existing `RXMessageParser`) |
| `.txt` | Generic text CAN log |

## Installation

```bash
# 1. Clone / download the repository
cd CAN_Logger

# 2. Install dependencies
pip install pandas numpy matplotlib

# 3. (Optional) Install as a package
pip install -e .
```

> **Python 3.10+** is required.

## Usage

### GUI

```bash
# Open the GUI (file chooser dialog will appear)
python -m can_logger_gui

# Pre-load a file on startup
python -m can_logger_gui path/to/log.asc

# Via the installed console script
can-logger-gui
```

### CLI (headless)

```bash
# Print summary statistics
can-logger-gui path/to/log.asc --stats

# Export to CSV
can-logger-gui path/to/log.asc --csv output.csv

# Export to JSON
can-logger-gui path/to/log.asc --json output.json

# Generate a self-contained HTML analysis report
can-logger-gui path/to/log.asc --report report.html

# Open GUI with file pre-loaded (combines --gui with any export flag)
can-logger-gui path/to/log.asc --gui --stats
```

### Python API

```python
from can_logger_gui import parser as log_parser
from can_logger_gui import analytics

df = log_parser.parse_log("path/to/log.asc")

# Summary
print(analytics.compute_summary(df))

# Per-ID frequency
freq_df = analytics.compute_frequency_per_id(df)

# Inter-arrival times
iat_df = analytics.compute_inter_arrival_times(df)

# Byte statistics for a specific CAN ID
stats_df = analytics.compute_byte_statistics(df, can_id="100")

# Bytes with high variance
high_var = analytics.detect_high_variance_bytes(df, "100")

# Message rate time series (1-second bins)
rate_df = analytics.compute_message_rate_timeseries(df, bin_size_sec=1.0)
```

## DataFrame schema

`parser.parse_log()` returns a `pandas.DataFrame` with the following columns:

| Column | Type | Description |
|---|---|---|
| `timestamp_raw` | str | Original timestamp string from the log |
| `timestamp_sec` | float | Elapsed time in seconds (first message = 0.0) |
| `can_id` | str | CAN identifier as uppercase hex string (e.g. `"1A2"`) |
| `dlc` | int | Data Length Code |
| `byte0` … `byte7` | float / int | Individual byte values (NaN if not present) |
| `hex_data` | str | Full hex payload without spaces |
| `channel` | str | CAN channel number |
| `line_number` | int | Line number in the source file |

## GUI walkthrough

1. **Load File** – opens a file chooser; parsing runs in a background thread so the UI stays responsive.
2. **Summary bar** – shows total duration, message count, and unique CAN ID count at a glance.
3. **Filters panel** (left) – enter one or more comma-separated CAN IDs, a time window, DLC, and/or a hex data pattern, then press **Apply**. Press **Clear** to reset.
4. **Frames tab** – click any column header to sort ascending/descending. Only the first 10 000 rows are displayed for performance.
5. **Rate Plot tab** – select one or more CAN IDs in the listbox to overlay per-ID rates on top of the total rate. Click **Export PNG** to save the chart.
6. **Byte Analysis tab** – choose a CAN ID and a byte column; the lower pane shows a value distribution histogram and a time-series plot. The statistics treeview shows min/max/mean and the number of value changes per byte.
7. **Export** buttons in the toolbar generate CSV, JSON, or a full HTML report from the currently-filtered data.

## Running the tests

```bash
cd CAN_Logger
pip install pytest
pytest tests/ -v
```

The test suite does **not** require a graphical display; tkinter is stubbed automatically.

## Building a wheel

```bash
pip install build
python -m build
# Wheel is placed in dist/
```

## Project structure

```
CAN_Logger/
├── CAN_Log_Parser/
│   └── CAN_log_parser.py       # Existing parser (RXMessageParser)
├── can_logger_gui/
│   ├── __init__.py
│   ├── __main__.py             # python -m can_logger_gui
│   ├── parser.py               # DataFrame adapter around RXMessageParser
│   ├── analytics.py            # Statistical analysis functions
│   ├── gui.py                  # tkinter GUI application
│   └── cli.py                  # Headless CLI entry point
├── tests/
│   ├── fixtures/
│   │   └── sample.asc          # 46-message test fixture
│   ├── test_parser.py
│   └── test_analytics.py
├── pyproject.toml
└── README.md
```

## License

MIT – see repository root for details.
