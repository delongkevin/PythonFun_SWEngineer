import os
import html as html_escape_lib
import argparse
import shutil
import base64
import re
import subprocess
import glob
import time
import logging
import chardet
import hashlib
import pandas as pd
from openpyxl import load_workbook
import matplotlib.pyplot as plt
from bs4 import BeautifulSoup

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Default source paths
DEFAULT_SOURCE_PATHS = [
    r"C:\JS\ws\develop\sw\Release",
    os.path.join(os.getcwd(), "images"),
    os.path.join(os.getcwd(),  r"BVTRBS\03_VariantDependent\Customer\CVADAS_RBS_TRSC")
]

logging.info(f"Final DEFAULT_SOURCE_PATHS: {DEFAULT_SOURCE_PATHS}")

# Default destination directory (current working directory)
search_pattern = r"C:\JS\workspace\**\BVTRBS\03_VariantDependent\Customer\**"
matching_paths = glob.glob(search_pattern, recursive=True)

print(matching_paths)  # Print to verify what paths are found

# Ensure we handle the case where multiple matches or no matches exist
if matching_paths:
    DEFAULT_DESTINATION_PATH = matching_paths[0]  # Take the first match
else:
    DEFAULT_DESTINATION_PATH = os.getcwd()  # Fallback to current directory if nothing is found

print(DEFAULT_DESTINATION_PATH)  # Print the selected destination path

# Create report paths
EXCEL_REPORT_PATH = os.path.join(DEFAULT_DESTINATION_PATH, "Software_Test_Report.xlsx")
HTML_REPORT_PATH = os.path.join(DEFAULT_DESTINATION_PATH, "Software_Test_Report.html")

def find_html_files_recursive(directory, matched_files=None):
    """Recursively finds all .html files in the given directory and logs the count."""
    
    if matched_files is None:
        matched_files = set()  # Use a set to store unique file paths

    if not os.path.exists(directory):
        logging.warning(f"Skipping non-existent path: {directory}")
        return matched_files  # Return existing found files

    try:
        logging.info(f"Searching for HTML files in: {directory}")

        for entry in os.scandir(directory):  # Efficient directory iteration
            #if entry.is_file() and entry.name.lower().endswith(".html") or entry.name.lower().endswith(".txt"):
            if entry.is_file() and entry.name.lower().endswith(".html"):
                matched_files.add(os.path.normpath(entry.path))  # Normalize path
            elif entry.is_dir():  # Recurse into subdirectory
                find_html_files_recursive(entry.path, matched_files)

    except Exception as e:
        logging.error(f"Error searching in {directory}: {e}")

    return matched_files

# Wrapper function to process multiple source paths
def find_html_files(source_paths):
    """Handles multiple source directories and returns all found HTML files."""
    
    if isinstance(source_paths, str):  
        logging.error("Error: source_paths should be a list, not a string!")
        return []

    all_matched_files = set()
    
    for path in source_paths:
        all_matched_files.update(find_html_files_recursive(path))  # Call recursive function

    logging.info(f"Total unique HTML files found: {len(all_matched_files)}")
    
    return list(all_matched_files)  # Convert set to list


def extract_summary_data(soup):
    """Extracts executed, passed, and failed test case counts from the summary table."""
    executed_count, pass_count, fail_count = 0, 0, 0

    overview_table = soup.find("table", class_="OverviewTable")
    if overview_table:
        rows = overview_table.find_all("tr")
        for row in rows:
            cells = row.find_all("td")
            if len(cells) < 2:
                continue  # skip header/blank rows that have no value cell
            row_text = [cell.get_text(strip=True) for cell in cells]
            try:
                if "Executed test cases" in row_text[0]:
                    executed_count = int(row_text[1])
                elif "Test cases passed" in row_text[0]:
                    pass_count = int(row_text[1])
                elif "Test cases failed" in row_text[0]:
                    fail_count = int(row_text[1])
            except (ValueError, IndexError):
                pass  # non-numeric or missing cell — skip silently

    return executed_count, pass_count, fail_count

def append_to_excel(test_name, pass_count, fail_count):
    """Appends test data to an Excel sheet while ensuring correct headers exist."""
    sheet_name = "Summary"

    # Ensure the Excel file exists and create it if necessary
    if not os.path.exists(EXCEL_REPORT_PATH):
        df = pd.DataFrame(columns=["Test Name", "Passed", "Failed"])
        df.to_excel(EXCEL_REPORT_PATH, index=False, sheet_name=sheet_name)

    with pd.ExcelWriter(EXCEL_REPORT_PATH, engine="openpyxl", mode="w", if_sheet_exists="new") as writer:
        book = load_workbook(EXCEL_REPORT_PATH)

        if sheet_name in book.sheetnames:
            df = pd.read_excel(EXCEL_REPORT_PATH, sheet_name=sheet_name)

            # Ensure Passed and Failed columns are numeric
            df["Passed"] = pd.to_numeric(df["Passed"], errors="coerce").fillna(0)
            df["Failed"] = pd.to_numeric(df["Failed"], errors="coerce").fillna(0)

            new_data = pd.DataFrame({"Test Name": [test_name], "Passed": [pass_count], "Failed": [fail_count]})
            df = pd.concat([df, new_data]).drop_duplicates(subset=["Test Name"], keep="last")

            df.to_excel(writer, sheet_name=sheet_name, index=False)

        else:
            df = pd.DataFrame({"Test Name": [test_name], "Passed": [pass_count], "Failed": [fail_count]})
            df.to_excel(writer, sheet_name=sheet_name, index=False)

    logging.info(f"Data appended to {EXCEL_REPORT_PATH} under sheet '{sheet_name}'")

def generate_graph():
    """Generates a graph showing pass/fail test trends and a consolidated summary pie chart."""
    try:
        df = pd.read_excel(EXCEL_REPORT_PATH, sheet_name="Summary")
    
        # Convert columns to numeric
        df["Passed"] = pd.to_numeric(df["Passed"], errors="coerce").fillna(0)
        df["Failed"] = pd.to_numeric(df["Failed"], errors="coerce").fillna(0)

        # Check if there's valid data to plot
        if df[["Passed", "Failed"]].sum().sum() == 0:
            logging.warning("No valid test data available. Skipping graph generation.")
            return

        # Create a bar chart for individual test pass/fail trends
        plt.figure(figsize=(12, 6))
        df[['Test Name', 'Passed', 'Failed']].plot(kind='bar', x='Test Name', stacked=True, color=['green', 'red'])
        plt.title("Test Pass/Fail Trends")
        plt.ylabel("Count")
        plt.xticks(rotation=75, ha="right", fontsize=8)
        plt.tight_layout()
        plt.savefig(os.path.join(DEFAULT_DESTINATION_PATH, "Test_Results_Graph.png"))
        logging.info("Test Pass/Fail Trends graph updated and saved.")

        # Create a pie chart for the consolidated summary report
        total_passed = df['Passed'].sum()
        total_failed = df['Failed'].sum()

        plt.figure(figsize=(6, 6))
        plt.pie(
            [total_passed, total_failed], 
            labels=['Passed', 'Failed'], 
            autopct='%1.1f%%', 
            colors=['green', 'red'], 
            startangle=90, 
            wedgeprops={'edgecolor': 'black'}
        )
        plt.title("Consolidated Summary Report")
        plt.savefig(os.path.join(DEFAULT_DESTINATION_PATH, "Consolidated_Summary_Report.png"))
        logging.info("Consolidated Summary Report pie chart updated and saved.")

    except Exception as e:
        logging.error(f"Error generating graph: {e}")

def minify_html(html_content):
    """Removes excessive whitespace while preserving structure."""
    # Remove spaces between HTML tags
    html_content = re.sub(r">\s+<", "><", html_content)
    
    # Reduce multiple spaces to a single space
    html_content = re.sub(r"\s{2,}", " ", html_content)
    
    return html_content.strip()

def remove_empty_sections(html):
    """Removes empty <details> and <div> sections."""
    html = re.sub(r"<details>\s*<summary>.*?</summary>\s*<div>\s*</div>\s*</details>", "", html, flags=re.DOTALL)
    html = re.sub(r"<pre>\s*</pre>", "", html, flags=re.DOTALL)
    return html

def generate_html_report(html_files, source_paths, destination_path, keyword):
    """Generates a professional HTML report with a statistics dashboard, consolidated
    failure summary, live search, and per-report collapsible sections.

    Text and log content is embedded inline so the HTML file is portable on its own.
    Images are stored in a 'report_images/' subfolder next to the HTML file and
    referenced by relative URL, keeping the HTML file size small.  The 'report_images/'
    folder must travel with the HTML file for images to display correctly.
    """

    try:
        logging.info("Starting report generation...")

        text_content, image_tags, copied_files = copy_and_embed_files(source_paths, destination_path)

        seen_files = set()
        navigation_links = ""
        report_sections_html = ""
        all_failures_html = ""

        # Aggregate statistics across every embedded report
        total_executed = 0
        total_passed = 0
        total_failed = 0

        for index, html_file in enumerate(html_files):
            if html_file in seen_files:
                continue

            try:
                logging.info(f"Processing HTML file: {html_file}")
                with open(html_file, 'r', encoding='utf-8') as f:
                    soup = BeautifulSoup(f, 'html.parser')

                file_title = html_escape_lib.escape(
                    os.path.basename(html_file)
                    .replace("_", " ")
                    .replace(".html", "")
                    .title()
                )
                section_id = f"section-{index}"

                # Per-file statistics — guard against malformed summary rows
                try:
                    executed, passed, failed = extract_summary_data(soup)
                except Exception as e:
                    logging.warning(
                        f"Failed to extract summary data from {html_file}: {e}. "
                        "Using zero values for executed/passed/failed."
                    )
                    executed, passed, failed = 0, 0, 0
                total_executed += executed
                total_passed += passed
                total_failed += failed

                # Sidebar navigation badge
                if failed > 0:
                    nav_badge_cls = "nb-fail"
                    nav_badge_txt = f"FAIL ({failed})"
                elif passed > 0:
                    nav_badge_cls = "nb-pass"
                    nav_badge_txt = "PASS"
                else:
                    nav_badge_cls = "nb-neutral"
                    nav_badge_txt = "—"

                navigation_links += (
                    f'<li class="nav-item">'
                    f'<a class="nav-link" href="javascript:void(0);" onclick="showSection(\'{section_id}\')">'
                    f'<span class="nav-title">{file_title}</span>'
                    f'<span class="nav-badge {nav_badge_cls}">{nav_badge_txt}</span>'
                    f'</a></li>'
                )

                # Consolidated failures panel content
                failed_html = extract_failed_tests(soup)
                if failed > 0:
                    all_failures_html += (
                        f'<div class="failure-group">'
                        f'<div class="fg-title">{file_title}'
                        f'<span class="badge badge-fail">{failed} FAILED</span>'
                        f'</div>'
                        f'<div class="fg-body">{failed_html}</div>'
                        f'</div>'
                    )

                # Per-section header badges
                sbadges = ""
                if failed > 0:
                    sbadges += f'<span class="sec-badge sec-fail">{failed} Failed</span>'
                if passed > 0:
                    sbadges += f'<span class="sec-badge sec-pass">{passed} Passed</span>'

                stats_html = extract_statistics_table(soup)
                kw_html = extract_keyword_from_tables(soup, keyword)

                report_sections_html += (
                    f'<div class="report-card" id="{section_id}">'
                    f'<div class="card-hdr" onclick="toggleCard(\'{section_id}\')">'
                    f'<div class="card-hdr-left">'
                    f'<span class="card-icon">&#x1F4CB;</span>'
                    f'<span class="card-title">{file_title}</span>'
                    f'{sbadges}'
                    f'</div>'
                    f'<span class="chevron" id="chv-{section_id}">&#9660;</span>'
                    f'</div>'
                    f'<div class="card-body" id="body-{section_id}">'
                    f'<div class="mini-stats-row">'
                    f'<span class="ms ms-exec">&#x25CF; Executed: <strong>{executed}</strong></span>'
                    f'<span class="ms ms-pass">&#x25CF; Passed: <strong>{passed}</strong></span>'
                    f'<span class="ms ms-fail">&#x25CF; Failed: <strong>{failed}</strong></span>'
                    f'</div>'
                    f'{stats_html}'
                    f'{failed_html}'
                    f'{kw_html}'
                    f'</div>'
                    f'</div>'
                )

                seen_files.add(html_file)

            except Exception as e:
                logging.error(f"Error processing {html_file}: {e}")

        logging.info(f"Total HTML reports added: {len(seen_files)}")

        # Derived metrics — clamp fractions to [0, 1] so malformed totals
        # never produce bars/arcs outside a valid range.
        report_timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
        num_reports = len(seen_files)

        if total_executed > 0:
            raw_pass = total_passed / total_executed
            raw_fail = total_failed / total_executed
            pass_frac = min(max(raw_pass, 0.0), 1.0)
            fail_frac = min(max(raw_fail, 0.0), 1.0)
            # Normalize when the two fractions sum beyond 1 (malformed counts)
            total_frac = pass_frac + fail_frac
            if total_frac > 1.0:
                pass_frac /= total_frac
                fail_frac /= total_frac
            pass_rate = round(pass_frac * 100, 1)
            fail_rate = round(fail_frac * 100, 1)
        else:
            pass_frac = 0.0
            fail_frac = 0.0
            pass_rate = 0.0
            fail_rate = 0.0

        # SVG donut chart (circle r=54, circumference ≈ 339.3)
        circ = 339.3
        pass_arc = round(pass_frac * circ, 1)
        fail_arc = round(fail_frac * circ, 1)
        fail_arc_offset = round(-pass_arc, 1)   # negative offset shifts fail arc past the pass arc

        consolidated_failures = (
            all_failures_html
            if all_failures_html
            else '<p class="no-failures">&#x2714; No test failures detected across all embedded reports.</p>'
        )

        files_list_html = (
            '<ul class="file-list">'
            + "".join(f'<li>&#x1F4C4; {os.path.basename(f)}</li>' for f in copied_files)
            + "</ul>"
            if copied_files
            else '<p class="muted-note">No copied files.</p>'
        )

        html_template = f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Software Test Report &ndash; {report_timestamp}</title>
<style>
/* ── RESET ── */
*,*::before,*::after{{box-sizing:border-box;margin:0;padding:0}}

/* ── CUSTOM PROPERTIES ── */
:root{{
  --sw: 285px;
  --hdr: #0b1f35;
  --accent: #1565c0;
  --pass-dk: #1b5e20; --pass-md: #2e7d32; --pass-bg: #e8f5e9; --pass-bd: #43a047;
  --fail-dk: #7f0000; --fail-md: #c62828; --fail-bg: #ffebee; --fail-bd: #ef5350;
  --exec-dk: #0d47a1; --exec-bg: #e3f2fd; --exec-bd: #1e88e5;
  --rate-dk: #4a148c; --rate-bg: #f3e5f5; --rate-bd: #8e24aa;
  --warn-dk: #e65100; --warn-bg: #fff3e0;
  --bdr: #dde1e7; --bg: #eef0f4; --card: #ffffff;
  --txt: #1a1a2e; --muted: #6b7280; --sbg: #0b1f35;
}}

/* ── BODY LAYOUT ── */
body{{font-family:-apple-system,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,sans-serif;
  font-size:14px;color:var(--txt);background:var(--bg);display:flex;min-height:100vh}}

/* ══════════════════════════════════════
   SIDEBAR
══════════════════════════════════════ */
.sidebar{{
  width:var(--sw);min-height:100vh;background:var(--sbg);
  position:fixed;top:0;left:0;overflow-y:auto;z-index:200;
  display:flex;flex-direction:column;
  box-shadow:3px 0 12px rgba(0,0,0,0.35)
}}
.sb-brand{{padding:22px 20px 16px;background:#061222;border-bottom:1px solid rgba(255,255,255,0.07)}}
.sb-brand .brand-icon{{font-size:26px}}
.sb-brand h2{{color:#fff;font-size:15px;font-weight:700;margin-top:8px;letter-spacing:.3px}}
.sb-brand .brand-sub{{color:rgba(255,255,255,.4);font-size:11px;margin-top:3px}}

/* Sidebar quick stats */
.sb-kpi{{
  display:flex;justify-content:space-around;
  padding:14px 12px;
  background:rgba(21,101,192,.18);
  border-bottom:1px solid rgba(255,255,255,.06)
}}
.sb-kpi .kpi{{text-align:center}}
.sb-kpi .kpi-num{{font-size:22px;font-weight:800;line-height:1}}
.sb-kpi .kpi-lbl{{font-size:10px;color:rgba(255,255,255,.45);text-transform:uppercase;letter-spacing:.8px}}
.kn-exec{{color:#64b5f6}} .kn-pass{{color:#66bb6a}} .kn-fail{{color:#ef9a9a}}

.nav-section-lbl{{
  padding:14px 20px 4px;color:rgba(255,255,255,.3);
  font-size:10px;font-weight:700;letter-spacing:1.6px;text-transform:uppercase
}}
.nav-list{{list-style:none;padding:0 8px}}
.nav-item .nav-link{{
  display:flex;align-items:center;justify-content:space-between;
  color:rgba(255,255,255,.72);text-decoration:none;
  padding:7px 12px;border-radius:6px;margin-bottom:2px;font-size:12.5px;
  border-left:3px solid transparent;transition:all .15s
}}
.nav-item .nav-link:hover{{color:#fff;background:rgba(255,255,255,.09);border-left-color:var(--accent)}}
.nav-title{{flex:1;overflow:hidden;text-overflow:ellipsis;white-space:nowrap}}
.nav-badge{{font-size:9px;font-weight:700;padding:2px 7px;border-radius:8px;margin-left:6px;
  flex-shrink:0;text-transform:uppercase;letter-spacing:.3px}}
.nb-fail{{background:var(--fail-md);color:#fff}}
.nb-pass{{background:var(--pass-md);color:#fff}}
.nb-neutral{{background:rgba(255,255,255,.15);color:rgba(255,255,255,.55)}}

/* ══════════════════════════════════════
   MAIN WRAPPER
══════════════════════════════════════ */
.main-wrap{{margin-left:var(--sw);flex:1;display:flex;flex-direction:column;min-width:0}}

/* ── PAGE HEADER ── */
.page-hdr{{
  background:linear-gradient(135deg,#0b1f35 0%,#1a3a5c 100%);
  padding:26px 36px;display:flex;align-items:flex-start;
  justify-content:space-between;box-shadow:0 4px 16px rgba(0,0,0,.3)
}}
.page-hdr h1{{color:#fff;font-size:24px;font-weight:700;letter-spacing:-.3px}}
.page-hdr .hdr-sub{{color:rgba(255,255,255,.5);font-size:12px;margin-top:5px}}
.hdr-pill{{
  background:rgba(255,255,255,.1);border:1px solid rgba(255,255,255,.15);
  color:rgba(255,255,255,.7);border-radius:20px;padding:6px 14px;font-size:12px;
  white-space:nowrap;margin-top:4px
}}

/* ── CONTENT AREA ── */
.content{{padding:28px 36px}}

/* ══════════════════════════════════════
   STATS DASHBOARD
══════════════════════════════════════ */
.stats-dash{{
  background:var(--card);border-radius:12px;
  box-shadow:0 2px 10px rgba(0,0,0,.08);
  padding:26px 30px;margin-bottom:24px;border:1px solid var(--bdr)
}}
.dash-title{{
  font-size:11px;font-weight:700;color:var(--muted);
  text-transform:uppercase;letter-spacing:1.3px;
  margin-bottom:20px;padding-bottom:12px;border-bottom:1px solid var(--bdr)
}}
.stats-row{{display:flex;gap:16px;align-items:stretch;flex-wrap:wrap}}

.stat-card{{
  flex:1;min-width:140px;border-radius:10px;padding:20px 20px 16px;
  border:1px solid var(--bdr);display:flex;flex-direction:column;
  position:relative;overflow:hidden
}}
.stat-card::before{{
  content:'';position:absolute;top:0;left:0;right:0;height:4px
}}
.sc-exec::before{{background:var(--exec-bd)}} .sc-exec{{background:linear-gradient(150deg,#fff 55%,#dceeff)}}
.sc-pass::before{{background:var(--pass-bd)}} .sc-pass{{background:linear-gradient(150deg,#fff 55%,#e2f5e6)}}
.sc-fail::before{{background:var(--fail-bd)}} .sc-fail{{background:linear-gradient(150deg,#fff 55%,#fde9ec)}}
.sc-rate::before{{background:var(--rate-bd)}} .sc-rate{{background:linear-gradient(150deg,#fff 55%,#f0e8fb)}}

.sc-icon{{font-size:22px;margin-bottom:8px}}
.sc-num{{font-size:42px;font-weight:800;line-height:1;margin-bottom:4px;letter-spacing:-1.5px}}
.sc-exec .sc-num{{color:var(--exec-dk)}} .sc-pass .sc-num{{color:var(--pass-dk)}}
.sc-fail .sc-num{{color:var(--fail-dk)}} .sc-rate .sc-num{{color:var(--rate-dk)}}
.sc-lbl{{font-size:10.5px;font-weight:700;text-transform:uppercase;letter-spacing:.8px;color:var(--muted)}}
.sc-bar{{margin-top:12px;height:5px;border-radius:3px;background:#e5e7eb;overflow:hidden}}
.sc-bar-fill{{height:100%;border-radius:3px;transition:width .4s}}
.fill-exec{{background:var(--exec-bd);width:100%}}
.fill-pass{{background:var(--pass-bd)}}
.fill-fail{{background:var(--fail-bd)}}
.fill-rate{{background:var(--rate-bd)}}

/* Donut chart */
.donut-area{{
  width:200px;flex-shrink:0;display:flex;flex-direction:column;
  align-items:center;justify-content:center
}}
.donut-wrap{{position:relative;width:130px;height:130px}}
.donut-center{{
  position:absolute;top:50%;left:50%;transform:translate(-50%,-50%);
  text-align:center;pointer-events:none
}}
.donut-center .dc-num{{font-size:24px;font-weight:800;color:var(--pass-dk);line-height:1}}
.donut-center .dc-sub{{font-size:10px;color:var(--muted);font-weight:600;
  text-transform:uppercase;letter-spacing:.5px}}
.donut-legend{{display:flex;gap:14px;margin-top:10px}}
.dl-item{{display:flex;align-items:center;gap:5px;font-size:11px;color:var(--muted);font-weight:600}}
.dl-dot{{width:9px;height:9px;border-radius:50%;flex-shrink:0}}

/* ══════════════════════════════════════
   FAILURES PANEL
══════════════════════════════════════ */
.fail-panel{{
  background:var(--card);border-radius:12px;
  border:2px solid var(--fail-bd);
  box-shadow:0 2px 14px rgba(198,40,40,.14);
  margin-bottom:24px;overflow:hidden
}}
.fail-panel-hdr{{
  background:linear-gradient(90deg,#7f0000 0%,#b71c1c 100%);
  color:#fff;padding:14px 24px;display:flex;align-items:center;
  justify-content:space-between;cursor:pointer;user-select:none
}}
.fail-panel-hdr h2{{font-size:15px;font-weight:700;display:flex;align-items:center;gap:10px}}
.fail-count-badge{{
  background:rgba(255,255,255,.2);border:1px solid rgba(255,255,255,.3);
  color:#fff;padding:2px 10px;border-radius:10px;font-size:12px
}}
.fail-panel-body{{padding:20px 24px;display:none}}
.fail-panel-body.open{{display:block}}

.failure-group{{margin-bottom:20px}}
.failure-group:last-child{{margin-bottom:0}}
.fg-title{{
  font-size:13px;font-weight:700;color:var(--fail-dk);
  padding:9px 14px;background:var(--fail-bg);
  border-left:4px solid var(--fail-bd);border-radius:0 5px 5px 0;
  margin-bottom:8px;display:flex;align-items:center;gap:10px
}}
.fg-body{{padding-left:4px}}

/* ══════════════════════════════════════
   SEARCH BAR
══════════════════════════════════════ */
.search-wrap{{margin-bottom:20px}}
.search-box{{
  background:var(--card);border:2px solid var(--bdr);border-radius:8px;
  padding:11px 18px;display:flex;align-items:center;gap:12px;
  box-shadow:0 1px 4px rgba(0,0,0,.06);transition:border-color .2s
}}
.search-box:focus-within{{border-color:var(--accent);box-shadow:0 0 0 3px rgba(21,101,192,.12)}}
.search-icon{{color:var(--muted);font-size:15px;flex-shrink:0}}
.search-box input{{
  flex:1;border:none;outline:none;font-size:14px;color:var(--txt);background:transparent
}}
.search-box input::placeholder{{color:#adb5bd}}
.search-hint{{font-size:11px;color:var(--muted);margin-top:5px;padding-left:4px;min-height:16px}}

/* ══════════════════════════════════════
   REPORT CARDS
══════════════════════════════════════ */
.section-heading{{
  font-size:11px;font-weight:700;color:var(--muted);
  text-transform:uppercase;letter-spacing:1.3px;
  margin-bottom:14px;padding-bottom:8px;border-bottom:1px solid var(--bdr)
}}
.report-card{{
  background:var(--card);border-radius:10px;border:1px solid var(--bdr);
  box-shadow:0 1px 6px rgba(0,0,0,.06);margin-bottom:14px;overflow:hidden;
  transition:box-shadow .2s
}}
.report-card:hover{{box-shadow:0 3px 14px rgba(0,0,0,.1)}}

.card-hdr{{
  display:flex;align-items:center;justify-content:space-between;
  padding:13px 20px;cursor:pointer;background:#f6f8fb;
  border-bottom:1px solid var(--bdr);user-select:none
}}
.card-hdr:hover{{background:#edf1f7}}
.card-hdr-left{{display:flex;align-items:center;gap:10px;flex:1;min-width:0}}
.card-icon{{font-size:15px;flex-shrink:0}}
.card-title{{
  font-size:14px;font-weight:700;color:#1a3a5c;
  white-space:nowrap;overflow:hidden;text-overflow:ellipsis
}}
.sec-badge{{
  font-size:10px;font-weight:700;padding:2px 8px;border-radius:8px;
  flex-shrink:0;text-transform:uppercase;letter-spacing:.3px
}}
.sec-fail{{background:var(--fail-bg);color:var(--fail-dk);border:1px solid var(--fail-bd)}}
.sec-pass{{background:var(--pass-bg);color:var(--pass-dk);border:1px solid var(--pass-bd)}}
.chevron{{color:var(--muted);font-size:12px;transition:transform .25s;flex-shrink:0;margin-left:10px}}
.chevron.open{{transform:rotate(180deg)}}
.card-body{{padding:20px 24px;display:none}}
.card-body.open{{display:block}}

/* Mini stats inside card */
.mini-stats-row{{
  display:flex;gap:22px;margin-bottom:16px;
  padding:10px 14px;background:#f6f8fb;
  border-radius:6px;border:1px solid var(--bdr)
}}
.ms{{font-size:12.5px;font-weight:600}}
.ms-exec{{color:var(--exec-dk)}} .ms-pass{{color:var(--pass-dk)}} .ms-fail{{color:var(--fail-dk)}}

/* ══════════════════════════════════════
   TABLES  (apply to ALL tables in report)
══════════════════════════════════════ */
.tbl-wrap{{width:100%;overflow-x:auto;border-radius:7px;
  border:1px solid var(--bdr);margin:12px 0;
  box-shadow:0 1px 4px rgba(0,0,0,.05)}}
table{{width:100%;border-collapse:collapse;font-size:13px}}
table th{{
  background:#1a3a5c;color:#fff;padding:9px 14px;
  text-align:left;font-size:11px;font-weight:700;
  text-transform:uppercase;letter-spacing:.6px;white-space:nowrap
}}
table td{{
  padding:8px 14px;border-bottom:1px solid #f0f1f3;
  vertical-align:middle;line-height:1.45;word-break:break-word
}}
table tr:last-child td{{border-bottom:none}}
table tr:nth-child(even) td{{background:#fafbfc}}
table tr:hover td{{background:#eef4fb !important}}

/* Fail / Pass row highlighting – applied by JS */
table tr.row-fail td{{background:var(--fail-bg) !important;color:var(--fail-dk) !important;font-weight:500}}
table tr.row-pass td{{background:var(--pass-bg) !important;color:var(--pass-dk) !important}}

/* Headings generated by extract functions */
.card-body h2,.fg-body h2,.fail-panel-body h2{{
  font-size:12px;font-weight:700;text-transform:uppercase;letter-spacing:.9px;
  color:#1a3a5c;margin:18px 0 8px;padding-bottom:6px;
  border-bottom:2px solid var(--accent);display:flex;align-items:center;gap:8px
}}
.card-body h2:first-child,.fg-body h2:first-child{{margin-top:0}}

/* ══════════════════════════════════════
   BADGES
══════════════════════════════════════ */
.badge{{
  display:inline-block;padding:2px 8px;border-radius:10px;
  font-size:10px;font-weight:700;text-transform:uppercase;letter-spacing:.4px
}}
.badge-fail{{background:var(--fail-bd);color:#fff}}
.badge-pass{{background:var(--pass-bd);color:#fff}}
.badge-neutral{{background:#e5e7eb;color:var(--muted)}}

/* ══════════════════════════════════════
   PRE / CODE
══════════════════════════════════════ */
pre{{
  background:#1e1e2e;color:#cdd6f4;border-radius:6px;padding:16px;
  font-size:12px;font-family:"Consolas","Courier New",monospace;
  white-space:pre-wrap;word-break:break-all;
  max-height:450px;overflow-y:auto;margin:8px 0;line-height:1.5
}}

/* ══════════════════════════════════════
   IMAGES  (relative-path gallery cards)
══════════════════════════════════════ */
.img-note{{
  font-size:12px;color:var(--accent);background:var(--exec-bg);
  border:1px solid var(--exec-bd);border-radius:6px;
  padding:9px 14px;margin-bottom:14px;display:flex;align-items:center;gap:8px
}}
.img-grid{{
  display:grid;grid-template-columns:repeat(auto-fill,minmax(260px,1fr));
  gap:16px;margin-top:4px
}}
.img-figure{{
  border:1px solid var(--bdr);border-radius:8px;overflow:hidden;
  background:#fff;box-shadow:0 1px 5px rgba(0,0,0,.08);
  transition:box-shadow .2s;display:flex;flex-direction:column
}}
.img-figure:hover{{box-shadow:0 5px 18px rgba(0,0,0,.16)}}
.img-thumb-link{{
  display:block;overflow:hidden;background:#f6f8fb;height:180px;flex-shrink:0
}}
.img-figure img{{
  width:100%;height:180px;object-fit:contain;display:block;
  transition:transform .3s
}}
.img-figure:hover img{{transform:scale(1.04)}}
.img-figcap{{
  padding:8px 10px;border-top:1px solid var(--bdr);
  display:flex;flex-direction:column;gap:3px
}}
.img-name{{
  font-size:11.5px;color:var(--txt);font-weight:600;
  white-space:nowrap;overflow:hidden;text-overflow:ellipsis;display:block
}}
.img-open-link{{
  font-size:10.5px;color:var(--accent);text-decoration:none;
  display:inline-flex;align-items:center;gap:3px
}}
.img-open-link:hover{{text-decoration:underline}}

/* ══════════════════════════════════════
   MISC HELPERS
══════════════════════════════════════ */
.no-failures{{
  color:var(--pass-dk);background:var(--pass-bg);border:1px solid var(--pass-bd);
  border-radius:6px;padding:12px 18px;font-size:13px;font-weight:600;
  display:flex;align-items:center;gap:8px
}}
.muted-note{{color:var(--muted);font-style:italic;font-size:13px;padding:8px 0}}
.file-list{{list-style:none}}
.file-list li{{
  padding:6px 0;border-bottom:1px solid #f5f5f5;font-size:13px;color:var(--muted);
  display:flex;align-items:center;gap:8px
}}
.file-list li:last-child{{border-bottom:none}}
.hidden{{display:none !important}}

/* ══════════════════════════════════════
   FOOTER
══════════════════════════════════════ */
.report-footer{{
  text-align:center;padding:20px;font-size:11px;color:var(--muted);
  border-top:1px solid var(--bdr);margin-top:24px
}}

/* ══════════════════════════════════════
   PRINT
══════════════════════════════════════ */
@media print{{
  .sidebar,.search-wrap,.page-hdr{{display:none!important}}
  .main-wrap{{margin-left:0!important}}
  .card-body,.fail-panel-body{{display:block!important}}
  .stats-dash,.fail-panel,.report-card{{break-inside:avoid}}
}}
</style>
<script>
/* ── CARD TOGGLE ── */
function toggleCard(id) {{
  var body = document.getElementById('body-' + id);
  var chv  = document.getElementById('chv-'  + id);
  if (!body) return;
  var open = body.classList.toggle('open');
  if (chv) chv.classList.toggle('open', open);
}}

/* ── SHOW + SCROLL TO SECTION ── */
function showSection(id) {{
  var body = document.getElementById('body-' + id);
  var chv  = document.getElementById('chv-'  + id);
  if (!body) return;
  body.classList.add('open');
  if (chv) chv.classList.add('open');
  var card = document.getElementById(id);
  if (card) card.scrollIntoView({{behavior:'smooth',block:'start'}});
}}

/* ── FAILURES PANEL TOGGLE ── */
function toggleFailPanel() {{
  var body = document.getElementById('fail-panel-body');
  if (!body) return;
  body.classList.toggle('open');
}}

/* ── LIVE SEARCH ── */
function searchReports() {{
  var q     = document.getElementById('searchInput').value.toLowerCase().trim();
  var cards = document.querySelectorAll('.report-card');
  var vis   = 0;
  cards.forEach(function(card) {{
    if (!q) {{
      card.classList.remove('hidden');
      vis++;
      return;
    }}
    if (card.textContent.toLowerCase().includes(q)) {{
      card.classList.remove('hidden');
      vis++;
      var body = card.querySelector('.card-body');
      var chv  = card.querySelector('.chevron');
      if (body) body.classList.add('open');
      if (chv)  chv.classList.add('open');
    }} else {{
      card.classList.add('hidden');
    }}
  }});
  var hint = document.getElementById('searchHint');
  if (hint) {{
    hint.textContent = q
      ? (vis + ' of ' + cards.length + ' report(s) match \u201c' + q + '\u201d')
      : '';
  }}
}}

/* ── HIGHLIGHT FAIL / PASS ROWS ── */
function styleTableRows() {{
  document.querySelectorAll('table tbody tr').forEach(function(row) {{
    var t = row.textContent.toLowerCase();
    if (t.includes('fail')) {{
      row.classList.add('row-fail');
    }} else if (t.includes('pass') || t.includes(' ok') || t.includes('success')) {{
      row.classList.add('row-pass');
    }}
  }});
}}

/* ── WRAP TABLES IN SCROLLABLE DIV ── */
function wrapTables() {{
  document.querySelectorAll(
    '.card-body table, .fg-body table, .fail-panel-body table'
  ).forEach(function(tbl) {{
    if (tbl.parentNode.classList.contains('tbl-wrap')) return;
    var w = document.createElement('div');
    w.className = 'tbl-wrap';
    tbl.parentNode.insertBefore(w, tbl);
    w.appendChild(tbl);
  }});
}}

window.addEventListener('DOMContentLoaded', function() {{
  styleTableRows();
  wrapTables();
  /* Open the failures panel by default when there are failures */
  var fpBody = document.getElementById('fail-panel-body');
  if (fpBody && document.querySelector('.failure-group')) {{
    fpBody.classList.add('open');
  }}
}});
</script>
</head>
<body>

<!-- ══════════════ SIDEBAR ══════════════ -->
<nav class="sidebar">
  <div class="sb-brand">
    <div class="brand-icon">&#x1F4CA;</div>
    <h2>Software Test Report</h2>
    <div class="brand-sub">Jenkins Pipeline &bull; Consolidated</div>
  </div>

  <div class="sb-kpi">
    <div class="kpi"><div class="kpi-num kn-exec">{total_executed}</div><div class="kpi-lbl">Executed</div></div>
    <div class="kpi"><div class="kpi-num kn-pass">{total_passed}</div><div class="kpi-lbl">Passed</div></div>
    <div class="kpi"><div class="kpi-num kn-fail">{total_failed}</div><div class="kpi-lbl">Failed</div></div>
  </div>

  <div class="nav-section-lbl">Quick Jump</div>
  <ul class="nav-list">
    <li class="nav-item">
      <a class="nav-link" href="javascript:void(0);" onclick="toggleFailPanel()">
        <span class="nav-title">&#x26A0; Failure Summary</span>
        <span class="nav-badge nb-fail">{total_failed}</span>
      </a>
    </li>
    <li class="nav-item">
      <a class="nav-link" href="javascript:void(0);" onclick="showSection('logs')">
        <span class="nav-title">&#x1F4C4; Logs &amp; Info</span>
      </a>
    </li>
    <li class="nav-item">
      <a class="nav-link" href="javascript:void(0);" onclick="showSection('images')">
        <span class="nav-title">&#x1F5BC; Embedded Images</span>
      </a>
    </li>
  </ul>

  <div class="nav-section-lbl">Embedded Reports ({num_reports})</div>
  <ul class="nav-list">
    {navigation_links}
  </ul>
</nav>

<!-- ══════════════ MAIN CONTENT ══════════════ -->
<div class="main-wrap">

  <header class="page-hdr">
    <div>
      <h1>&#x1F4CA; Software Test Report</h1>
      <div class="hdr-sub">
        Consolidated Jenkins Pipeline Report &nbsp;&bull;&nbsp;
        {num_reports} embedded report(s) &nbsp;&bull;&nbsp;
        Generated: {report_timestamp}
      </div>
    </div>
    <div class="hdr-pill">&#x1F552; {report_timestamp}</div>
  </header>

  <div class="content">

    <!-- ══ STATISTICS DASHBOARD ══ -->
    <div class="stats-dash">
      <div class="dash-title">&#x1F4C8; Executive Test Summary &mdash; All Reports Combined</div>
      <div class="stats-row">
        <div class="stat-card sc-exec">
          <div class="sc-icon">&#x1F3AF;</div>
          <div class="sc-num">{total_executed}</div>
          <div class="sc-lbl">Total Executed</div>
          <div class="sc-bar"><div class="sc-bar-fill fill-exec"></div></div>
        </div>
        <div class="stat-card sc-pass">
          <div class="sc-icon">&#x2705;</div>
          <div class="sc-num">{total_passed}</div>
          <div class="sc-lbl">Tests Passed</div>
          <div class="sc-bar"><div class="sc-bar-fill fill-pass" style="width:{pass_rate}%"></div></div>
        </div>
        <div class="stat-card sc-fail">
          <div class="sc-icon">&#x274C;</div>
          <div class="sc-num">{total_failed}</div>
          <div class="sc-lbl">Tests Failed</div>
          <div class="sc-bar"><div class="sc-bar-fill fill-fail" style="width:{fail_rate}%"></div></div>
        </div>
        <div class="stat-card sc-rate">
          <div class="sc-icon">&#x1F4AF;</div>
          <div class="sc-num">{pass_rate}%</div>
          <div class="sc-lbl">Pass Rate</div>
          <div class="sc-bar"><div class="sc-bar-fill fill-rate" style="width:{pass_rate}%"></div></div>
        </div>
        <!-- SVG Donut Chart (self-contained, no CDN) -->
        <div class="donut-area">
          <div class="donut-wrap">
            <svg viewBox="0 0 130 130" width="130" height="130" aria-label="Pass/Fail donut chart">
              <!-- background ring -->
              <circle cx="65" cy="65" r="54" fill="none" stroke="#e5e7eb" stroke-width="16"/>
              <!-- pass arc -->
              <circle cx="65" cy="65" r="54" fill="none" stroke="#43a047" stroke-width="16"
                stroke-dasharray="{pass_arc} {circ}"
                stroke-dashoffset="0"
                transform="rotate(-90 65 65)"/>
              <!-- fail arc (offset starts right after pass arc) -->
              <circle cx="65" cy="65" r="54" fill="none" stroke="#ef5350" stroke-width="16"
                stroke-dasharray="{fail_arc} {circ}"
                stroke-dashoffset="{fail_arc_offset}"
                transform="rotate(-90 65 65)"/>
            </svg>
            <div class="donut-center">
              <div class="dc-num">{pass_rate}%</div>
              <div class="dc-sub">Pass Rate</div>
            </div>
          </div>
          <div class="donut-legend">
            <div class="dl-item"><div class="dl-dot" style="background:#43a047"></div>Pass</div>
            <div class="dl-item"><div class="dl-dot" style="background:#ef5350"></div>Fail</div>
          </div>
        </div>
      </div>
    </div>

    <!-- ══ CONSOLIDATED FAILURES PANEL ══ -->
    <div class="fail-panel">
      <div class="fail-panel-hdr" onclick="toggleFailPanel()">
        <h2>
          &#x26A0;&#xFE0F; Consolidated Failure Summary
          <span class="fail-count-badge">{total_failed} Failure(s) Across All Reports</span>
        </h2>
        <span style="font-size:12px;opacity:.7">&#x25BC; expand / collapse</span>
      </div>
      <div class="fail-panel-body" id="fail-panel-body">
        {consolidated_failures}
      </div>
    </div>

    <!-- ══ SEARCH ══ -->
    <div class="search-wrap">
      <div class="search-box">
        <span class="search-icon">&#x1F50D;</span>
        <input type="text" id="searchInput"
          placeholder="Search reports by name, test case, keyword, status&hellip;"
          oninput="searchReports()">
      </div>
      <div class="search-hint" id="searchHint"></div>
    </div>

    <!-- ══ INDIVIDUAL REPORT CARDS ══ -->
    <div class="section-heading">&#x1F4CB; Embedded Reports ({num_reports} total)</div>
    {report_sections_html}

    <!-- ══ LOGS ══ -->
    <div class="report-card" id="logs">
      <div class="card-hdr" onclick="toggleCard('logs')">
        <div class="card-hdr-left">
          <span class="card-icon">&#x1F4C4;</span>
          <span class="card-title">Logs &amp; Additional Information</span>
        </div>
        <span class="chevron" id="chv-logs">&#9660;</span>
      </div>
      <div class="card-body" id="body-logs">
        {text_content if text_content else '<p class="muted-note">No logs available.</p>'}
      </div>
    </div>

    <!-- ══ IMAGES ══ -->
    <div class="report-card" id="images">
      <div class="card-hdr" onclick="toggleCard('images')">
        <div class="card-hdr-left">
          <span class="card-icon">&#x1F5BC;</span>
          <span class="card-title">Embedded Images</span>
        </div>
        <span class="chevron" id="chv-images">&#9660;</span>
      </div>
      <div class="card-body" id="body-images">
        <p class="img-note">
          &#x2139; Images are stored in the <strong>report_images/</strong> subfolder alongside this file.
          <strong>Do not delete or move the report_images/ folder</strong> — doing so will break all image links.
          When sharing this report, always include the report_images/ folder.
          Click any thumbnail to open at full resolution in a new tab.
        </p>
        <div class="img-grid">
          {image_tags if image_tags else '<p class="muted-note">No images found.</p>'}
        </div>
      </div>
    </div>

    <!-- ══ COPIED FILES ══ -->
    <div class="report-card" id="copied-files">
      <div class="card-hdr" onclick="toggleCard('copied-files')">
        <div class="card-hdr-left">
          <span class="card-icon">&#x1F4C1;</span>
          <span class="card-title">Copied Files</span>
        </div>
        <span class="chevron" id="chv-copied-files">&#9660;</span>
      </div>
      <div class="card-body" id="body-copied-files">
        {files_list_html}
      </div>
    </div>

    <div class="report-footer">
      Software Test Report &bull; Jenkins Pipeline &bull; {report_timestamp}
      &bull; {num_reports} report(s) embedded
    </div>

  </div><!-- /content -->
</div><!-- /main-wrap -->
</body>
</html>"""

        output_path = os.path.join(destination_path, "Software_Test_Report.html")
        with open(output_path, "w", encoding="utf-8") as html_out:
            html_out.write(html_template)

        logging.info(f"Report successfully generated at {output_path}")

    except Exception as e:
        logging.critical(f"Unexpected error generating the report: {e}")

def extract_results_table(soup):
    results_table = []
    start_write = False

    for div in soup.find_all('div'):
        # Start 
        if "Results" in div.get_text():
            start_write = True

        # Stop 
        if "Test Configuration Information" in div.get_text() and start_write:
            start_write = False

        # look for the table containing the results
        if start_write and div.find('table'):
            table = div.find('table')
            for row in table.find_all('tr'):
                columns = [col.get_text(strip=True) for col in row.find_all('td')]
                
                # start adding rows once the first column is "1"
                if len(columns) > 0 and columns[0] == "1":
                    if len(columns) >= 3 and columns[2].lower() == "fail": 
                        results_table.append(columns[:3]) 

                # keep capturing only 'fail' rows
                elif len(results_table) > 0 and len(columns) >= 3 and columns[2].lower() == "fail":
                    results_table.append(columns[:3])  
    
    return results_table
def extract_keyword_table(soup, keyword):
    """Extracts tables related to the specific keywords from the HTML report."""
    keyword_tables = {keyword: [] for keyword in keywords}
    found_keyword_section = {keyword: False for keyword in keywords}
    parsed_tables = {keyword: False for keyword in keywords} 

    for table in soup.find_all('table'):
        rows = table.find_all('tr')
        for row in rows:
            text = row.get_text(strip=True)

            for keyword in keywords:
                # check both conditions 
                if (f"CAN signal '{keyword}'" in text or f"_22{keyword}" in text) and not parsed_tables[keyword]:  
                    found_keyword_section[keyword] = True

                if found_keyword_section[keyword] and "Check of expected values" in text:
                    # Look for the next table
                    response_table = row.find_next('table', class_='InfoTableExpand')
                    if response_table:
                        # Extract data from the found table
                        for data_row in response_table.find_all('tr'):
                            columns = [col.get_text(strip=True) for col in data_row.find_all('td')]
                            if columns:  
                                keyword_tables[keyword].append(columns)
                        # Mark this keyword's table as parsed
                        parsed_tables[keyword] = True
                    # Stop after the first match for this keyword
                    found_keyword_section[keyword] = False

    return keyword_tables


def extract_statistics_table(soup):
    # Locate the statistics table (modify class or ID if needed)
    statistics_table = soup.find("table", class_="OverviewTable")  # Adjust class if necessary

    if statistics_table:
        return f"<h2>Test Statistics</h2>{str(statistics_table)}"
    else:
        return "<p><b>No statistics table found in the report.</b></p>"

def extract_failed_tests(soup):
    failed_tests = []

    for table in soup.find_all("table"):
        for row in table.find_all("tr"):
            cells = row.find_all(["th", "td"])
            for cell in cells:
                if "fail" in cell.get_text(strip=True).lower():
                    failed_tests.append(str(row))  # Keep row as-is without styling
                    break  # Stop checking other cells in this row

    return f"<h2>Failed Tests Summary</h2><table>{''.join(failed_tests)}</table>" if failed_tests else "<p><b>No failed tests found.</b></p>"

def extract_keyword_from_tables(soup, keyword):
    """Extracts and formats table rows containing the given keyword from an HTML soup object."""
    keyword_lower = keyword.lower()
    extracted_rows = []

    # Iterate over all tables in the soup
    for table in soup.find_all("table"):
        for row in table.find_all("tr"):
            cells = row.find_all(["th", "td"])
            # Check if any cell in the row contains the keyword
            if any(keyword_lower in cell.get_text(strip=True).lower() for cell in cells):
                extracted_rows.append(str(row))

    # Format the output neatly without table borders
    if extracted_rows:
        table_html = "<table>\n" + "\n".join(extracted_rows) + "\n</table>"
        return f"<h2>Table Data Matching Keyword: '{keyword}'</h2>\n{table_html}"
    else:
        return f"<p><b>No table rows found containing keyword: '{keyword}'</b></p>"

def extract_overview_table(soup):
    """Extracts executed, pass, and fail count from the 'OverviewTable'."""
    global pass_count, fail_count, executed_count

    overview_table = soup.find("table", class_="Statistics")
    if not overview_table:
        return "<p><b>OverviewTable not found in the report.</b></p>"

    rows = overview_table.find_all("tr")
    extracted_table = "<h2>Test Summary</h2><table border='1'>"

    for row in rows:
        cells = row.find_all("td")
        row_text = [cell.get_text(strip=True) for cell in cells]

        if "Executed test cases" in row_text[0]:
            executed_count = int(row_text[1])
        elif "Test cases passed" in row_text[0]:
            pass_count = int(row_text[1])
        elif "Test cases failed" in row_text[0]:
            fail_count = int(row_text[1])

        extracted_table += f"<tr>{''.join(f'<td>{cell}</td>' for cell in row_text)}</tr>"

    extracted_table += "</table>"
    return extracted_table

# Allowed file extensions (only images & text files)
ALLOWED_EXTENSIONS = {"png", "jpg", "jpeg", "gif", "txt", "html"}

def detect_encoding(file_path):
    """Detects file encoding before reading."""
    with open(file_path, "rb") as f:
        raw_data = f.read(4096)  # Read the first 4KB for detection
        result = chardet.detect(raw_data)
        return result["encoding"] if result["encoding"] else "utf-8"

def get_unique_filename(dest_dir, filename):
    """Ensures a unique filename by appending a number if it already exists."""
    base, ext = os.path.splitext(filename)
    counter = 1
    new_filename = filename

    while os.path.exists(os.path.join(dest_dir, new_filename)):
        new_filename = f"{base}_{counter}{ext}"
        counter += 1

    return new_filename

def get_file_hash(file_path, chunk_size=65536):
    """Generate an MD5 hash for a file using chunked reads to avoid memory spikes
    on large images or log files."""
    hasher = hashlib.md5()
    with open(file_path, "rb") as f:
        while True:
            chunk = f.read(chunk_size)
            if not chunk:
                break
            hasher.update(chunk)
    return hasher.hexdigest()

def copy_and_embed_files(source_paths, destination_path, delete_after_embedding=True):
    """Copies and embeds text/HTML files inline and images as relative-path gallery cards.

    Images are placed in a flat 'report_images/' subfolder next to the HTML output so
    that the report file itself stays small.  Text and HTML files are still embedded
    inline so the report is self-contained for log/trace data.  Only embedded text
    files are deleted after processing; image files are intentionally kept because the
    HTML references them by relative path.
    """

    image_tags = ""
    text_content = ""
    image_count = 0
    text_count = 0
    copied_files = []          # All successfully copied files (for the "Copied Files" section)
    text_files_to_delete = []  # Only text/HTML files are deleted after inline embedding
    embedded_hashes = set()    # Deduplicate by content hash

    if not os.path.exists(destination_path):
        os.makedirs(destination_path)

    # Flat subfolder that sits next to the HTML output file
    images_dir = os.path.join(destination_path, "report_images")

    for source_path in source_paths:
        if not os.path.exists(source_path):
            logging.warning(f"Skipping non-existent path: {source_path}")
            continue

        for root, _, files in os.walk(source_path):
            for filename in files:
                file_ext = filename.lower().split(".")[-1]

                if file_ext not in ALLOWED_EXTENSIONS:
                    logging.info(f"Skipping unsupported file: {filename}")
                    continue

                src_file = os.path.join(root, filename)

                try:
                    if file_ext in ["png", "jpg", "jpeg", "gif"]:
                        # ── Images: copy to flat report_images/ subfolder ──────────
                        # Hash the source first to skip copying duplicate content
                        src_hash = get_file_hash(src_file)
                        if src_hash in embedded_hashes:
                            logging.info(f"Skipping duplicate image (source): {filename}")
                            continue

                        os.makedirs(images_dir, exist_ok=True)
                        unique_filename = get_unique_filename(images_dir, filename)
                        dest_file = os.path.join(images_dir, unique_filename)
                        shutil.copy2(src_file, dest_file)

                        if not os.path.exists(dest_file):
                            continue

                        embedded_hashes.add(src_hash)
                        copied_files.append(dest_file)

                        # Relative URL path (forward slashes for HTML on all OS).
                        # Escape the filename for safe use in HTML attributes and text.
                        safe_name = html_escape_lib.escape(unique_filename, quote=True)
                        rel_url = "report_images/" + unique_filename
                        image_tags += (
                            f'<figure class="img-figure">'
                            f'<a class="img-thumb-link" href="{rel_url}" target="_blank"'
                            f'   rel="noopener noreferrer"'
                            f'   title="Click to open full size: {safe_name}">'
                            f'<img src="{rel_url}" alt="{safe_name}" loading="lazy">'
                            f'</a>'
                            f'<div class="img-figcap">'
                            f'<span class="img-name" title="{safe_name}">{safe_name}</span>'
                            f'<a class="img-open-link" href="{rel_url}" target="_blank"'
                            f'   rel="noopener noreferrer">'
                            f'&#x1F517; Open full size</a>'
                            f'</div>'
                            f'</figure>\n'
                        )
                        image_count += 1
                        # NOTE: image files are NOT added to text_files_to_delete –
                        # they must remain on disk so the HTML links resolve correctly.

                    elif file_ext in ["txt", "html"]:
                        # ── Text/HTML: preserve folder structure, embed inline ─────
                        # Hash the source first to skip copying duplicate content
                        src_hash = get_file_hash(src_file)
                        if src_hash in embedded_hashes:
                            logging.info(f"Skipping duplicate text file (source): {filename}")
                            continue

                        relative_path = os.path.relpath(root, source_path)
                        dest_dir = os.path.join(destination_path, relative_path)
                        os.makedirs(dest_dir, exist_ok=True)
                        unique_filename = get_unique_filename(dest_dir, filename)
                        dest_file = os.path.join(dest_dir, unique_filename)
                        shutil.copy2(src_file, dest_file)

                        if not os.path.exists(dest_file):
                            continue

                        embedded_hashes.add(src_hash)
                        copied_files.append(dest_file)

                        encoding = detect_encoding(dest_file)
                        with open(dest_file, "r", encoding=encoding, errors="replace") as txt_file:
                            text_content += f"<h3>{unique_filename}</h3><pre>{txt_file.read()}</pre><br>"
                        text_count += 1
                        text_files_to_delete.append(dest_file)

                except Exception as e:
                    logging.error(f"Failed to process {src_file}: {e}")

    logging.info(f"Total text/HTML files embedded: {text_count}")
    logging.info(f"Total image files linked: {image_count}")
    logging.info(f"Total successfully copied files: {len(copied_files)}")

    # Delete only the inline-embedded text/HTML files (images stay for the links)
    if delete_after_embedding:
        for file_path in text_files_to_delete:
            try:
                os.remove(file_path)
                logging.info(f"Deleted embedded text file: {file_path}")
            except Exception as e:
                logging.error(f"Failed to delete {file_path}: {e}")

    return text_content, image_tags, copied_files

def getCPULoadResults():
    script_name = "CPU_Load_Graph_Parser.py"
    script_path = None

    # Search for the script in DEFAULT_SOURCE_PATHS
    for path in DEFAULT_SOURCE_PATHS:
        candidate_path = os.path.join(path, script_name)
        if os.path.isfile(candidate_path):
            script_path = candidate_path
            break

    if not script_path:
        print(f"Error: {script_name} not found in DEFAULT_SOURCE_PATHS!")
        return

    print(f"Found {script_name} at: {script_path}")

    # Extract directory where the script is located
    script_dir = os.path.dirname(script_path)

    command_args = ["python", script_path]
    try:
        result = subprocess.run(command_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, cwd=script_dir)
        
        print(result.stdout)
        if result.returncode != 0:
            print(f"Error occurred:\n{result.stderr}")
        else:
            print("CPU Load processing complete. Now cleaning workspaces...")

    except Exception as e:
        print(f"Failed to start {script_name}: {e}")

if __name__ == '__main__':
    
    # Retrieve Jenkins workspace environment variable
    jenkins_workspace = os.environ.get('WORKSPACE')

    if jenkins_workspace:
        base_path = os.path.join(jenkins_workspace, "BVTRBS", "03_VariantDependent", "Customer")
    
        # Find the folder dynamically using glob
        matching_folders = glob.glob(os.path.join(base_path, "*"))
    
        if matching_folders:
            dynamic_path = matching_folders[0]  # Pick the first matching folder
        else:
            print("Warning: No matching folder found. Falling back to base path.")
            dynamic_path = base_path  # Fallback to base path if no folder is found
    else:
        print("Warning: WORKSPACE environment variable not set. Falling back to the current working directory.")
        dynamic_path = os.getcwd()  # Use the current working directory as the fallback path

    # Add dynamic_path to default source paths
    DEFAULT_SOURCE_PATHS.append(dynamic_path)

    print(f"Using dynamic path: {dynamic_path}")  # Debugging print

    parser = argparse.ArgumentParser(description="Generate an HTML report with extracted test data, failures, logs, and images.")
    parser.add_argument('html_file', type=str, nargs='?', default="Report_Sanity.html", help="Path to the HTML file. If not provided, the script will find one automatically.")
    parser.add_argument('keyword', type=str, nargs='?', default="Evaluate response", help="Keyword to search for in the file.")
    parser.add_argument('--source_paths', type=str, nargs='+', default=DEFAULT_SOURCE_PATHS, help="List of source directories.")
    parser.add_argument('--destination_path', type=str, default=DEFAULT_DESTINATION_PATH, help="Destination path for copied files.")
    args = parser.parse_args()

    #Check for cpu load results if found
    getCPULoadResults()

    #Automatically search for all report files in source paths
    found_html_files = find_html_files(DEFAULT_SOURCE_PATHS)
    if not found_html_files:
        exit(1)

    #Generate a consolidated Software Test Report of all HTML files found
    generate_html_report(found_html_files, args.source_paths, args.destination_path, args.keyword)

    #Clean up work spaces of old report files for next iterations on jenkins node
    print(f"Cleaning Workspaces...")
    os.system("del /f /q /s C:\\JS\\ws\\develop\\sw\\Release\\FlashLog.txt")
    os.system("del /f /q /s C:\\JS\\CT_Server_Standard_files_Continous_Testing\\python\\*.html")
    os.system("del /f /q /s C:\\JS\\CT_Server_Standard_files_Continous_Testing\\python\\*.txt")
    os.system("del /f /q /s C:\\JS\\CT_Server_Standard_files_Continous_Testing\\python\\*.xlsx")
    os.system("del /f /q /s C:\\JS\\CT_Server_Standard_files_Continous_Testing\\python\\*jpg")
   
