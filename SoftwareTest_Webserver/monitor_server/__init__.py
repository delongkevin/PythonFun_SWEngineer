from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Dict

from flask import Flask, jsonify, render_template, request

from .state import StateStore


def iso_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def create_app(data_file: Path | None = None, stale_after_seconds: int = 180) -> Flask:
    package_dir = Path(__file__).resolve().parent
    app = Flask(
        __name__,
        template_folder=str(package_dir / "templates"),
        static_folder=str(package_dir / "static"),
    )
    store = StateStore(
        data_file or package_dir.parent / "data" / "state.json",
        stale_after_seconds=stale_after_seconds,
    )
    app.extensions["state_store"] = store

    @app.get("/")
    def index() -> str:
        return render_template(
            "index.html",
            dashboard_title="Software Test Network Dashboard",
            refresh_seconds=10,
        )

    @app.get("/api/health")
    def health() -> Any:
        nodes = store.list_nodes()
        return jsonify(
            {
                "status": "healthy",
                "generated_at": iso_now(),
                "node_count": len(nodes),
                "summary": store.summary(),
            }
        )

    @app.get("/api/nodes")
    def list_nodes() -> Any:
        return jsonify(
            {
                "generated_at": iso_now(),
                "summary": store.summary(),
                "nodes": store.list_nodes(),
            }
        )

    @app.get("/api/nodes/<node_id>")
    def get_node(node_id: str) -> Any:
        node = store.get_node(node_id)
        if node is None:
            return jsonify({"error": f"Unknown node '{node_id}'"}), 404
        return jsonify(node)

    @app.post("/api/nodes/register")
    def register_node() -> Any:
        payload: Dict[str, Any] = request.get_json(silent=True) or {}
        if not payload.get("display_name") and not payload.get("node_id"):
            return jsonify({"error": "display_name or node_id is required"}), 400
        node = store.register_node(payload)
        return jsonify(node), 201

    @app.post("/api/nodes/<node_id>/heartbeat")
    def node_heartbeat(node_id: str) -> Any:
        payload: Dict[str, Any] = request.get_json(silent=True) or {}
        if not payload:
            return jsonify({"error": "JSON payload is required"}), 400
        node = store.update_heartbeat(node_id, payload)
        return jsonify(node)

    return app
