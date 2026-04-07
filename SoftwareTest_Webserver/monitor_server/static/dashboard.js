const summaryIds = {
    onlineNodes: document.getElementById("online-nodes"),
    totalNodes: document.getElementById("total-nodes"),
    passRate: document.getElementById("pass-rate"),
    reportTotal: document.getElementById("report-total"),
    appsRunning: document.getElementById("apps-running"),
    serialTotal: document.getElementById("serial-total"),
    generatedAt: document.getElementById("generated-at"),
};

const nodesGrid = document.getElementById("nodes-grid");
const template = document.getElementById("node-template");
const form = document.getElementById("node-form");
const formStatus = document.getElementById("form-status");

function formatDate(value) {
    if (!value) {
        return "Never";
    }
    const date = new Date(value);
    if (Number.isNaN(date.getTime())) {
        return value;
    }
    return date.toLocaleString();
}

function setSummary(summary, generatedAt) {
    const reports = summary.report_totals || {};
    summaryIds.onlineNodes.textContent = summary.online_nodes || 0;
    summaryIds.totalNodes.textContent = `${summary.total_nodes || 0} total`;
    summaryIds.passRate.textContent = `${reports.pass_rate || 0}%`;
    summaryIds.reportTotal.textContent = `${reports.total || 0} reports`;
    summaryIds.appsRunning.textContent = `${summary.applications_running || 0} / ${summary.applications_total || 0}`;
    summaryIds.serialTotal.textContent = summary.connected_serial_ports || 0;
    summaryIds.generatedAt.textContent = `Last refresh: ${formatDate(generatedAt)}`;
}

function ratio(value, total) {
    if (!total) {
        return "0%";
    }
    return `${Math.max(8, Math.round((value / total) * 100))}%`;
}

function renderChips(container, items, emptyText, builder) {
    container.innerHTML = "";
    if (!items || !items.length) {
        const chip = document.createElement("span");
        chip.className = "chip";
        chip.textContent = emptyText;
        container.appendChild(chip);
        return;
    }
    items.forEach((item) => {
        const chip = document.createElement("span");
        chip.className = builder.className(item);
        chip.textContent = builder.text(item);
        container.appendChild(chip);
    });
}

function renderNode(node) {
    const fragment = template.content.cloneNode(true);
    const reportSummary = node.report_summary || {};
    const reportTotal = reportSummary.total || 0;

    const statusDot = fragment.querySelector(".status-dot");
    statusDot.classList.add(node.status || "offline");
    fragment.querySelector(".status-pill").textContent = node.status || "offline";
    fragment.querySelector(".status-pill").classList.add(node.status || "offline");
    fragment.querySelector(".node-name").textContent = node.display_name || node.node_id;
    fragment.querySelector(".node-subtitle").textContent = node.description || "No description supplied.";
    fragment.querySelector(".host-name").textContent = node.host?.hostname || "Unknown";
    fragment.querySelector(".rdp-host").textContent = node.rdp_host || "Not set";
    fragment.querySelector(".last-seen").textContent = formatDate(node.last_seen);
    fragment.querySelector(".agent-version").textContent = node.agent_version || "Pending";
    fragment.querySelector(".apps-summary").textContent = `${(node.applications || []).filter((app) => app.running).length} running`;
    fragment.querySelector(".serial-summary").textContent = `${(node.serial_ports || []).length} detected`;
    fragment.querySelector(".report-rate").textContent = `${reportSummary.pass_rate || 0}% pass`;
    fragment.querySelector(".report-counts").textContent = `Pass ${reportSummary.pass || 0} • Fail ${reportSummary.fail || 0} • Not Executed ${reportSummary.not_executed || 0} • Unknown ${reportSummary.unknown || 0}`;

    fragment.querySelector(".pass-bar").style.width = ratio(reportSummary.pass || 0, reportTotal);
    fragment.querySelector(".fail-bar").style.width = ratio(reportSummary.fail || 0, reportTotal);
    fragment.querySelector(".skip-bar").style.width = ratio(reportSummary.not_executed || 0, reportTotal);
    fragment.querySelector(".unknown-bar").style.width = ratio(reportSummary.unknown || 0, reportTotal);

    renderChips(
        fragment.querySelector(".apps-chips"),
        node.applications || [],
        "No application telemetry yet",
        {
            className: (app) => `chip ${app.running ? "running" : "stopped"}`,
            text: (app) => `${app.name}: ${app.running ? `running (${app.instances})` : "stopped"}`,
        },
    );

    renderChips(
        fragment.querySelector(".serial-chips"),
        node.serial_ports || [],
        "No serial ports detected",
        {
            className: (port) => `chip ${port.in_use_by_teraterm ? "serial-active" : ""}`.trim(),
            text: (port) => `${port.device} ${port.in_use_by_teraterm ? "• Tera Term" : ""}`.trim(),
        },
    );

    const recentReports = fragment.querySelector(".recent-reports");
    recentReports.innerHTML = "";
    (node.report_details || []).slice(0, 5).forEach((report) => {
        const item = document.createElement("li");
        item.textContent = `${report.name} • ${report.status.replace("_", " ")}`;
        recentReports.appendChild(item);
    });
    if (!recentReports.children.length) {
        const item = document.createElement("li");
        item.textContent = "No report files discovered yet";
        recentReports.appendChild(item);
    }

    return fragment;
}

async function refreshDashboard() {
    const response = await fetch("/api/nodes");
    if (!response.ok) {
        throw new Error(`HTTP ${response.status}`);
    }
    const payload = await response.json();
    setSummary(payload.summary || {}, payload.generated_at);
    nodesGrid.innerHTML = "";
    (payload.nodes || []).forEach((node) => {
        nodesGrid.appendChild(renderNode(node));
    });
    if (!(payload.nodes || []).length) {
        nodesGrid.innerHTML = "<article class='panel-card'>No nodes registered yet.</article>";
    }
}

form.addEventListener("submit", async (event) => {
    event.preventDefault();
    const formData = new FormData(form);
    const payload = {
        display_name: formData.get("display_name"),
        node_id: formData.get("node_id"),
        rdp_host: formData.get("rdp_host"),
        description: formData.get("description"),
        report_roots: String(formData.get("report_roots") || "")
            .split(/\n+/)
            .map((line) => line.trim())
            .filter(Boolean),
        tags: String(formData.get("tags") || "")
            .split(",")
            .map((entry) => entry.trim())
            .filter(Boolean),
    };

    try {
        const response = await fetch("/api/nodes/register", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(payload),
        });
        const result = await response.json();
        if (!response.ok) {
            throw new Error(result.error || "Unable to register node");
        }
        form.reset();
        formStatus.textContent = `Registered ${result.display_name}`;
        await refreshDashboard();
    } catch (error) {
        formStatus.textContent = error.message;
    }
});

refreshDashboard().catch((error) => {
    summaryIds.generatedAt.textContent = `Unable to load dashboard: ${error.message}`;
});
setInterval(() => {
    refreshDashboard().catch((error) => {
        summaryIds.generatedAt.textContent = `Refresh failed: ${error.message}`;
    });
}, 10000);
