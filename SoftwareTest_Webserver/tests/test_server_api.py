from monitor_server import create_app


def test_register_node_and_publish_heartbeat(tmp_path):
    app = create_app(data_file=tmp_path / "state.json", stale_after_seconds=60)
    client = app.test_client()

    register = client.post(
        "/api/nodes/register",
        json={
            "node_id": "bench-01",
            "display_name": "Bench 01",
            "rdp_host": "192.168.1.11",
            "description": "Nightly node",
        },
    )

    assert register.status_code == 201
    assert register.get_json()["node_id"] == "bench-01"

    heartbeat = client.post(
        "/api/nodes/bench-01/heartbeat",
        json={
            "host": {"hostname": "bench-01", "ip_address": "192.168.1.11"},
            "applications": [
                {"name": "Vector CANoe", "running": True, "instances": 1},
                {"name": "Tera Term", "running": False, "instances": 0},
            ],
            "serial_ports": [{"device": "COM4", "connected": True}],
            "report_summary": {
                "total": 3,
                "pass": 2,
                "fail": 1,
                "not_executed": 0,
                "unknown": 0,
                "pass_rate": 66.7,
                "paths_scanned": 1,
            },
            "report_details": [{"name": "nightly_result.json", "status": "pass"}],
        },
    )

    assert heartbeat.status_code == 200
    assert heartbeat.get_json()["status"] == "online"

    nodes = client.get("/api/nodes")
    payload = nodes.get_json()

    assert nodes.status_code == 200
    assert payload["summary"]["total_nodes"] == 1
    assert payload["summary"]["online_nodes"] == 1
    assert payload["summary"]["applications_running"] == 1
    assert payload["summary"]["report_totals"]["fail"] == 1
