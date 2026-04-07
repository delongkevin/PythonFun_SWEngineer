import json

from monitor_server.report_parser import scan_report_roots


def test_scan_report_roots_classifies_multiple_statuses(tmp_path):
    (tmp_path / "pass_report.json").write_text(
        json.dumps({"status": "passed"}),
        encoding="utf-8",
    )
    (tmp_path / "failure.log").write_text("Test execution FAILED", encoding="utf-8")
    (tmp_path / "skip.txt").write_text("not executed", encoding="utf-8")

    result = scan_report_roots([tmp_path], limit=10)

    assert result["summary"]["total"] == 3
    assert result["summary"]["pass"] == 1
    assert result["summary"]["fail"] == 1
    assert result["summary"]["not_executed"] == 1
    assert result["summary"]["paths_scanned"] == 1
