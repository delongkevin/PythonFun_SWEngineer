# Engineering Dashboard – Web Server

A professional local web server that presents all applications in this
repository as a unified dashboard.  The server continuously monitors the
repository for updates (via `git fetch / pull`) and broadcasts changes to
connected clients in real time using **Server-Sent Events (SSE)**.

---

## Features

| Feature | Details |
|---|---|
| **App catalogue** | Card-based dashboard for every application |
| **Live git monitor** | Background thread polls git every 30 s and auto-pulls |
| **SSE push** | All connected browsers receive updates instantly |
| **Manual sync** | "Sync" button triggers an immediate fetch + pull |
| **Health endpoint** | `/api/health` — suitable for uptime monitors |
| **JSON API** | `/api/apps` and `/api/git` for programmatic access |
| **Dark-themed UI** | Bootstrap 5 dark theme, responsive layout |
| **Multi-user safe** | Thread-safe design; handles many concurrent visitors |

---

## Quick Start

```bash
# 1.  Navigate to this directory
cd webserver/

# 2.  Install dependencies (only Flask is required)
pip install -r requirements.txt

# 3.  Start the server (listens on all interfaces, port 5000)
python server.py

# 4.  Open a browser and navigate to:
#     http://localhost:5000          (local machine)
#     http://<server-ip>:5000        (colleagues on the same network)
```

---

## Command-line Options

```
python server.py [OPTIONS]

Options:
  --host HOST            Bind host (default: 0.0.0.0)
  --port PORT            Bind port (default: 5000)
  --no-auto-pull         Disable automatic git pull
                         (still fetches to detect remote changes)
  --poll-interval SECS   Git poll interval in seconds (default: 30)
  --debug                Enable Flask debug mode (do not use in production)
```

### Examples

```bash
# Listen only on localhost
python server.py --host 127.0.0.1

# Use a custom port, disable auto-pull
python server.py --port 8080 --no-auto-pull

# Poll every 60 seconds
python server.py --poll-interval 60
```

---

## API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| `GET`  | `/`             | Main dashboard HTML page |
| `GET`  | `/api/apps`     | JSON list of registered applications |
| `GET`  | `/api/git`      | Current git state (branch, commit, remote status) |
| `POST` | `/api/git/refresh` | Trigger immediate git fetch + pull |
| `GET`  | `/api/health`   | Health-check — returns `{"status": "healthy", …}` |
| `GET`  | `/stream`       | SSE stream for real-time browser updates |

---

## Running as a Background Service (Linux/systemd)

Create `/etc/systemd/system/eng-dashboard.service`:

```ini
[Unit]
Description=Engineering Dashboard
After=network.target

[Service]
Type=simple
User=<your-user>
WorkingDirectory=/path/to/PythonFun_SWEngineer/webserver
ExecStart=/usr/bin/python3 server.py
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
```

Then enable and start:

```bash
sudo systemctl daemon-reload
sudo systemctl enable --now eng-dashboard
```

---

## Architecture

```
webserver/
├── server.py           # Flask app + git-monitor background thread
├── requirements.txt    # Flask ≥ 3.0
├── templates/
│   └── index.html      # Bootstrap 5 dark-theme dashboard
└── README.md           # This file
```

The server is intentionally **dependency-light** (only Flask).  No external
database or message broker is required — git itself is the source of truth.
