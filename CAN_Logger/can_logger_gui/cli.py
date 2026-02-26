"""CLI entry point for headless CAN log analysis."""

import argparse
import sys
import os


def main() -> None:
    ap = argparse.ArgumentParser(description="Headless CAN log analysis.")
    ap.add_argument("file", help="path to .asc/.blf/.txt log")
    ap.add_argument("--gui", action="store_true", help="open GUI with file pre-loaded")
    ap.add_argument("--csv", metavar="OUTPUT", help="export filtered frames to CSV")
    ap.add_argument("--json", metavar="OUTPUT", help="export to JSON")
    ap.add_argument("--report", metavar="OUTPUT", help="export HTML analysis report")
    ap.add_argument("--stats", action="store_true", help="print summary stats to stdout")
    args = ap.parse_args()

    from . import parser as log_parser
    from . import analytics

    df = log_parser.parse_log(args.file)

    if args.stats:
        summary = analytics.compute_summary(df)
        for k, v in summary.items():
            print(f"{k}: {v}")

    if args.csv:
        df.to_csv(args.csv, index=False)
        print(f"CSV exported to {args.csv}")

    if args.json:
        import json
        summary = analytics.compute_summary(df)
        data = {
            "summary": {k: str(v) for k, v in summary.items()},
            "frames": df.to_dict(orient="records"),
        }
        with open(args.json, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=2, default=str)
        print(f"JSON exported to {args.json}")

    if args.report:
        _export_html_report(df, args.report)
        print(f"Report exported to {args.report}")

    if args.gui:
        from .gui import main as gui_main
        gui_main(file_path=args.file)


def _export_html_report(df, output_path: str) -> None:
    """Generate a self-contained HTML analysis report."""
    import io
    import base64
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    from . import analytics

    summary = analytics.compute_summary(df)
    freq_df = analytics.compute_frequency_per_id(df)
    rate_df = analytics.compute_message_rate_timeseries(df)

    def _fig_to_b64(fig) -> str:
        buf = io.BytesIO()
        fig.savefig(buf, format="png", bbox_inches="tight")
        buf.seek(0)
        return base64.b64encode(buf.read()).decode()

    # Plot 1: message rate
    fig, ax = plt.subplots(figsize=(10, 4))
    if not rate_df.empty:
        ax.plot(rate_df["time_sec"], rate_df["rate"])
    ax.set_xlabel("Time (s)")
    ax.set_ylabel("Rate (msg/s)")
    ax.set_title("Message Rate")
    rate_b64 = _fig_to_b64(fig)
    plt.close(fig)

    # Plot 2: frequency per ID
    fig, ax = plt.subplots(figsize=(10, 4))
    if not freq_df.empty:
        ax.bar(freq_df["can_id"].astype(str), freq_df["freq_hz"])
    ax.set_xlabel("CAN ID")
    ax.set_ylabel("Frequency (Hz)")
    ax.set_title("Message Frequency per ID")
    plt.xticks(rotation=45, ha="right")
    freq_b64 = _fig_to_b64(fig)
    plt.close(fig)

    html = f"""<!DOCTYPE html>
<html><head><title>CAN Log Analysis Report</title>
<style>body{{font-family:sans-serif;margin:20px}} table{{border-collapse:collapse;width:100%}} td,th{{border:1px solid #ccc;padding:6px}}</style>
</head><body>
<h1>CAN Log Analysis Report</h1>
<h2>Summary</h2>
<table>{''.join(f'<tr><th>{k}</th><td>{v}</td></tr>' for k, v in summary.items())}</table>
<h2>Message Rate</h2>
<img src="data:image/png;base64,{rate_b64}" style="max-width:100%">
<h2>Frequency per CAN ID</h2>
<img src="data:image/png;base64,{freq_b64}" style="max-width:100%">
<h2>Frequency Table</h2>
{freq_df.to_html(index=False)}
</body></html>"""

    with open(output_path, "w", encoding="utf-8") as f:
        f.write(html)


if __name__ == "__main__":
    main()
