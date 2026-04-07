# SoftwareTest Webserver

This folder provides a central lab dashboard for software-test PCs on a local
network. It is designed for your use case where multiple remote-desktop
accessible nodes run automated tests, generate reports into local folders, and
need to publish a single professional status view.

## What This Project Solves

- Central dashboard showing all registered PCs in one browser view
- Local-network node onboarding with RDP host/IP metadata
- Live monitoring of Vector CANoe, Tera Term, and Lauterbach Trace32
- USB serial-port inventory per node, including best-effort Tera Term COM-port use
- Aggregated report statistics from node-local result directories
- Overall pass / fail / not executed / unknown status rollup

## Architecture

This solution uses two parts:

1. `server.py`
   Runs the central Flask dashboard that operators open in a browser.
2. `node_agent.py`
   Runs on each Windows node and sends heartbeat snapshots to the server.

This agent-based design is required because a central web server cannot reliably
inspect Windows processes, USB serial devices, or local report folders on remote
PCs without software on those nodes.

## Project Layout

```text
SoftwareTest_Webserver/
├── data/
│   └── state.json               # Auto-created persistent node state
├── examples/
│   └── node_agent_config.json   # Example node configuration
├── monitor_server/
│   ├── __init__.py              # Flask app and API routes
│   ├── report_parser.py         # Heuristic report parsing and statistics
│   ├── state.py                 # Persistent node registry and summary logic
│   ├── static/
│   │   ├── dashboard.js         # Browser-side rendering and polling
│   │   └── styles.css           # Dashboard styling
│   └── templates/
│       └── index.html           # Main dashboard page
├── tests/
│   ├── conftest.py
│   ├── test_report_parser.py
│   └── test_server_api.py
├── node_agent.py                # Windows-friendly agent process
├── requirements.txt
└── server.py                    # Central dashboard entry point
```

## Install

```bash
cd SoftwareTest_Webserver
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

On Windows nodes:

```powershell
cd SoftwareTest_Webserver
py -m venv .venv
.venv\Scripts\Activate.ps1
pip install -r requirements.txt
```

## Run The Dashboard Server

```bash
cd SoftwareTest_Webserver
python server.py --host 0.0.0.0 --port 5050
```

Open:

- `http://localhost:5050` on the host machine
- `http://<server-ip>:5050` from other PCs on the same local network

## Run A Node Agent

1. Copy and edit `examples/node_agent_config.json` on the target PC.
2. Set the correct `server_url`, `node_id`, `rdp_host`, and `report_roots`.
3. Start the agent:

```powershell
py node_agent.py --config examples\node_agent_config.json
```

To test a single publish cycle:

```powershell
py node_agent.py --config examples\node_agent_config.json --once
```

## API Endpoints

- `GET /` dashboard UI
- `GET /api/health` service health and aggregate counters
- `GET /api/nodes` current node list and overall summary
- `GET /api/nodes/<node_id>` details for one node
- `POST /api/nodes/register` register or update node metadata
- `POST /api/nodes/<node_id>/heartbeat` publish process, serial, and report telemetry

## Report Parsing Behavior

The parser scans configured report folders recursively and classifies each file
using file-name and content heuristics for these formats:

- `.json`
- `.xml`
- `.txt`
- `.log`
- `.csv`

Recognized outcomes are:

- `pass`
- `fail`
- `not_executed`
- `unknown`

If your report format is highly specific, extend `monitor_server/report_parser.py`
with project-specific parsing rules.

## Operational Notes

- Tera Term COM-port detection is best-effort and depends on COM-port references
  appearing in the Tera Term process command line.
- Manual node registration from the dashboard is supported, but live application,
  serial, and report data only appear after the node agent starts reporting.
- The current version does not include authentication. Keep it on a trusted lab
  network or add reverse-proxy authentication before broader exposure.

## Tests

```bash
cd SoftwareTest_Webserver
pytest tests
```

## CI/CD

GitHub Actions validation is configured in
`.github/workflows/software_test_webserver_ci.yml`.

For every push or pull request that touches `SoftwareTest_Webserver/`, the
workflow will:

- run `flake8`
- run the test suite on Python 3.10, 3.11, and 3.12
- compile all Python files with `compileall`
- run smoke checks for the Flask app and both CLI entry points
