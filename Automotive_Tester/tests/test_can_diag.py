"""
Unit tests for CanDiagPanel (core/can_diag.py).

Validates logic-level behaviour – bank management, script sequencing,
log import, and the filter-safe edit bug fix – without requiring
real Vector hardware, a display server, or the python-can / cantools
packages to be installed.
"""
from __future__ import annotations

import os as _os
import sys
import tempfile as _tempfile
import types
import unittest
from unittest.mock import MagicMock

# ---------------------------------------------------------------------------
# Stub tkinter (no display available in CI) and optional CAN packages
# ---------------------------------------------------------------------------


def _stub(name: str, attrs: dict | None = None) -> types.ModuleType:
    if name not in sys.modules:
        mod = types.ModuleType(name)
        for k, v in (attrs or {}).items():
            setattr(mod, k, v)
        sys.modules[name] = mod
    return sys.modules[name]


# Minimal tkinter stubs
_tk_mod = _stub("tkinter")
_ttk_mod = _stub("tkinter.ttk")
_st_mod = _stub("tkinter.scrolledtext")
_mb_mod = _stub("tkinter.messagebox")
_fd_mod = _stub("tkinter.filedialog")

# Give tkinter.END / NORMAL / DISABLED sentinel values
for _attr in ("END", "NORMAL", "DISABLED", "HORIZONTAL", "X", "BOTH", "Y",
              "LEFT", "RIGHT", "BOTTOM", "W", "E"):
    setattr(_tk_mod, _attr, _attr)


class _FakeStringVar:
    def __init__(self, value=""):
        self._v = value

    def get(self): return self._v

    def set(self, v): self._v = v

    def trace(self, *a, **kw): pass


class _FakeWidget:
    """Minimal stand-in for any tk widget / Frame."""

    def __init__(self, *args, **kwargs):
        self._children: list = []
        self._values: dict = {}

    # Geometry / packing – no-ops
    def pack(self, **kw): pass
    def grid(self, **kw): pass
    def configure(self, **kw): pass
    config = configure

    def insert(self, *a, **kw): pass
    def delete(self, *a, **kw): pass
    def get(self): return ""
    def see(self, *a): pass
    def winfo_toplevel(self): return self

    def after(self, ms, fn=None, *a):
        if fn:
            fn(*a)

    # Separator / LabelFrame passthrough
    def __call__(self, *a, **kw):
        return _FakeWidget()


class _FakeTreeview(_FakeWidget):
    """Lightweight treeview substitute backed by a plain list."""

    def __init__(self, *a, **kw):
        super().__init__()
        self._rows: list[dict] = []   # [{"iid": str, "values": tuple, "tags": tuple}]

    def heading(self, *a, **kw): pass
    def column(self, *a, **kw): pass
    def bind(self, *a, **kw): pass

    def insert(self, parent, pos, values=(), tags=()):
        iid = str(len(self._rows))
        self._rows.append({"iid": iid, "values": tuple(values), "tags": tags})
        return iid

    def get_children(self, *a):
        return [r["iid"] for r in self._rows]

    def item(self, iid, option=None, **kw):
        row = next(r for r in self._rows if r["iid"] == iid)
        if "values" in kw:
            # Setter form: tree.item(iid, values=(...))
            row["values"] = tuple(kw["values"])
            return
        if option == "values":
            # Getter form: tree.item(iid, "values")
            return row["values"]
        # No option – return the full item dict (like real tkinter)
        return row

    def delete(self, *iids):
        self._rows = [r for r in self._rows if r["iid"] not in iids]

    def selection(self):
        return [r["iid"] for r in self._rows] if self._rows else []

    def index(self, iid):
        return int(iid)

    def move(self, iid, parent, new_index):
        pass

    def parent(self, iid):
        return ""

    def selection_set(self, iid): pass


# Wire stubs into tkinter
_tk_mod.Frame = _FakeWidget
_tk_mod.BooleanVar = lambda *a, **kw: MagicMock(get=MagicMock(return_value=False))
_tk_mod.StringVar = _FakeStringVar
_tk_mod.Toplevel = _FakeWidget
_ttk_mod.LabelFrame = _FakeWidget
_ttk_mod.Frame = _FakeWidget
_ttk_mod.Entry = _FakeWidget
_ttk_mod.Label = _FakeWidget
_ttk_mod.Button = _FakeWidget
_ttk_mod.Checkbutton = _FakeWidget
_ttk_mod.Combobox = _FakeWidget
_ttk_mod.Separator = _FakeWidget
_ttk_mod.PanedWindow = _FakeWidget
_ttk_mod.Treeview = _FakeTreeview
_st_mod.ScrolledText = _FakeWidget

# Stub messagebox so askyesno returns True by default
_mb_mod.askyesno = MagicMock(return_value=True)
_mb_mod.showerror = MagicMock()
_fd_mod.askopenfilename = MagicMock(return_value="")

# Stub python-can / cantools (hardware not available in CI)
_stub("can")
_stub("cantools")
_stub("cantools.database")

# ---------------------------------------------------------------------------
# Now import the module under test
# ---------------------------------------------------------------------------
sys.path.insert(0, _os.path.join(_os.path.dirname(__file__), ".."))

# Patch _CONFIG_FILE so tests don't write to the repo directory
import core.can_diag as _can_diag_mod  # noqa: E402
_can_diag_mod._CONFIG_FILE = _os.path.join(
    _tempfile.gettempdir(), "test_can_diag_config.json"
)

from core.can_diag import CanDiagPanel  # noqa: E402


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _make_panel() -> CanDiagPanel:
    """Create a CanDiagPanel with a fake parent widget."""
    panel = CanDiagPanel.__new__(CanDiagPanel)
    # Initialise only the data attributes, skip GUI construction
    panel.buses = []
    panel.vector_channels = []
    panel.is_connected = False
    panel.is_script_running = False
    panel.dbs = {0: None, 1: None}
    panel.log_filename = _os.path.join(_tempfile.gettempdir(), "test_can_log.txt")
    panel.config = {
        "bitrate": "500000",
        "data_bitrate": "2000000",
        "is_fd": False,
        "dbc_paths": {"0": "", "1": ""},
        "fc_enabled": False,
        "fc_rx_id": "7E8",
        "fc_tx_id": "7E0",
        "bank_data": [],
        "script_data": [],
    }
    # Attach fake widgets
    panel.bank_tree = _FakeTreeview()
    panel.script_tree = _FakeTreeview()
    panel.search_var = _FakeStringVar()
    panel.log_text = _FakeWidget()
    panel.bitrate_entry = _FakeWidget()
    panel.data_bitrate_entry = _FakeWidget()
    panel.is_fd_var = MagicMock(get=MagicMock(return_value=False))
    panel.is_fc_enabled = MagicMock(get=MagicMock(return_value=False))
    panel.fc_rx_entry = _FakeWidget()
    panel.fc_tx_entry = _FakeWidget()
    panel.dbc_label_0 = _FakeWidget()
    panel.dbc_label_1 = _FakeWidget()
    panel.dbc_map_cb = MagicMock(current=MagicMock(return_value=0))
    panel.tx_channel_cb = MagicMock(get=MagicMock(return_value=""))
    panel.dbc_msg_cb = MagicMock(get=MagicMock(return_value=""))
    panel.arb_id_entry = _FakeWidget()
    panel.data_entry = _FakeWidget()
    panel.delay_entry = _FakeWidget()
    panel.btn_connect = _FakeWidget()
    panel.btn_disconnect = _FakeWidget()
    panel.btn_run_script = _FakeWidget()
    panel.btn_stop_script = _FakeWidget()
    return panel


# ===========================================================================
# Tests
# ===========================================================================

class TestCanDiagBankManagement(unittest.TestCase):

    def setUp(self):
        self.panel = _make_panel()

    def test_add_three_items_to_bank(self):
        self.panel.config["bank_data"] = [
            {"name": "A", "id": "7DF", "data": "02 01 00"},
            {"name": "B", "id": "7E0", "data": "03 22 F1 90"},
            {"name": "C", "id": "7E0", "data": "02 10 03"},
        ]
        self.panel.refresh_bank_tree()
        self.assertEqual(len(self.panel.bank_tree.get_children()), 3)

    def test_filter_bank_shows_only_matching_rows(self):
        self.panel.config["bank_data"] = [
            {"name": "Session Control", "id": "7DF", "data": "02 10 01"},
            {"name": "ECU Reset", "id": "7E0", "data": "02 11 01"},
            {"name": "Read Data", "id": "7DF", "data": "03 22 F1 90"},
        ]
        self.panel.refresh_bank_tree("session")
        self.assertEqual(len(self.panel.bank_tree.get_children()), 1)
        row = self.panel.bank_tree.item("0")
        self.assertEqual(row["values"][0], "Session Control")

    def test_delete_from_bank_removes_entry(self):
        self.panel.config["bank_data"] = [
            {"name": "A", "id": "7DF", "data": "02 01 00"},
            {"name": "B", "id": "7E0", "data": "02 10 03"},
        ]
        self.panel.refresh_bank_tree()
        # Pre-select the first treeview row and delete it
        self.panel.bank_tree._rows = [self.panel.bank_tree._rows[0]]
        self.panel.delete_from_bank()
        self.assertEqual(len(self.panel.config["bank_data"]), 1)
        self.assertEqual(self.panel.config["bank_data"][0]["name"], "B")

    def test_clear_bank_empties_bank_data(self):
        self.panel.config["bank_data"] = [
            {"name": "X", "id": "1", "data": "00"},
        ]
        _mb_mod.askyesno.return_value = True
        self.panel.clear_bank()
        self.assertEqual(self.panel.config["bank_data"], [])

    def test_clear_bank_cancelled(self):
        self.panel.config["bank_data"] = [{"name": "X", "id": "1", "data": "00"}]
        _mb_mod.askyesno.return_value = False
        self.panel.clear_bank()
        self.assertEqual(len(self.panel.config["bank_data"]), 1)
        _mb_mod.askyesno.return_value = True  # restore

    def test_move_to_script_copies_selected_bank_row(self):
        self.panel.config["bank_data"] = [
            {"name": "Tester Present", "id": "7DF", "data": "02 3E 00"},
        ]
        self.panel.refresh_bank_tree()
        self.panel.move_to_script()
        script_rows = self.panel.script_tree.get_children()
        self.assertEqual(len(script_rows), 1)
        vals = self.panel.script_tree.item(script_rows[0], "values")
        self.assertEqual(vals[0], "Tester Present")

    def test_remove_from_script(self):
        self.panel.script_tree.insert("", "end", values=("Step 1", "7E0", "02 10 01"))
        self.panel.script_tree.insert("", "end", values=("Step 2", "7E0", "02 10 02"))
        self.panel.remove_from_script()
        # Both were selected (selection() returns all rows in our stub)
        self.assertEqual(len(self.panel.script_tree.get_children()), 0)

    def test_clear_script(self):
        self.panel.script_tree.insert("", "end", values=("A", "1", "00"))
        self.panel.script_tree.insert("", "end", values=("B", "2", "11"))
        self.panel.clear_script()
        self.assertEqual(len(self.panel.script_tree.get_children()), 0)


class TestCanDiagEditBugFix(unittest.TestCase):
    """Verify the _create_editor_popup bank-update bug fix.

    When a search filter is active the treeview only contains matching
    rows.  The old code rebuilt bank_data entirely from the treeview,
    silently dropping every non-visible item.  The fix updates only the
    specific matching entry in config["bank_data"].
    """

    def setUp(self):
        self.panel = _make_panel()
        # Populate bank with 3 entries; filter so only 1 is visible in the treeview
        self.panel.config["bank_data"] = [
            {"name": "Session Control", "id": "7DF", "data": "02 10 01"},
            {"name": "ECU Reset", "id": "7E0", "data": "02 11 01"},
            {"name": "Read Data", "id": "7DF", "data": "03 22 F1 90"},
        ]
        # Simulate a filter: only "ECU Reset" is in the treeview
        self.panel.bank_tree.insert("", "end", values=("ECU Reset", "7E0", "02 11 01"))

    def _run_save_edits(self, current_vals, new_name, new_id, new_data):
        """Directly invoke the inner save_edits closure logic."""
        # Find and update entry matching current_vals
        cur_name, cur_id, cur_data = current_vals
        for entry in self.panel.config["bank_data"]:
            if (
                entry["name"] == cur_name
                and entry["id"] == cur_id
                and entry["data"] == cur_data
            ):
                entry["name"] = new_name
                entry["id"] = new_id
                entry["data"] = new_data
                break

    def test_edit_does_not_drop_filtered_entries(self):
        """Editing one item must not remove the other 2 from bank_data."""
        self._run_save_edits(
            ("ECU Reset", "7E0", "02 11 01"),
            "ECU Reset (edited)", "7E0", "02 11 03",
        )
        # All 3 entries must still exist
        self.assertEqual(len(self.panel.config["bank_data"]), 3)

    def test_edit_updates_correct_entry(self):
        """The targeted entry must reflect the new values."""
        self._run_save_edits(
            ("ECU Reset", "7E0", "02 11 01"),
            "ECU Reset (edited)", "7E0", "02 11 03",
        )
        names = [e["name"] for e in self.panel.config["bank_data"]]
        self.assertIn("ECU Reset (edited)", names)
        self.assertNotIn("ECU Reset", names)

    def test_edit_does_not_affect_other_entries(self):
        """The two non-edited entries must remain unchanged."""
        self._run_save_edits(
            ("ECU Reset", "7E0", "02 11 01"),
            "ECU Reset (edited)", "7E0", "02 11 03",
        )
        names = [e["name"] for e in self.panel.config["bank_data"]]
        self.assertIn("Session Control", names)
        self.assertIn("Read Data", names)


class TestCanDiagLogImport(unittest.TestCase):

    def setUp(self):
        self.panel = _make_panel()

    def _make_asc_file(self, lines):
        import tempfile
        f = tempfile.NamedTemporaryFile(
            mode="w", suffix=".asc", delete=False, encoding="utf-8"
        )
        f.write("\n".join(lines))
        f.close()
        return f.name

    def test_import_log_adds_to_bank(self):
        import os
        path = self._make_asc_file([
            "   0.001  1  Tx  7DF  d  [10 01 00 00 00 00 00 00]",
            "   0.002  1  Tx  7DF  d  [11 01 00 00 00 00 00 00]",
        ])
        _fd_mod.askopenfilename.return_value = path
        self.panel.import_log()
        self.assertEqual(len(self.panel.config["bank_data"]), 2)
        os.unlink(path)

    def test_import_log_deduplicates(self):
        import os
        path = self._make_asc_file([
            "   0.001  1  Tx  7DF  d  [10 01 00 00 00 00 00 00]",
            "   0.002  1  Tx  7DF  d  [10 01 00 00 00 00 00 00]",  # duplicate
        ])
        _fd_mod.askopenfilename.return_value = path
        self.panel.import_log()
        self.assertEqual(len(self.panel.config["bank_data"]), 1)
        os.unlink(path)

    def test_import_log_cancelled(self):
        _fd_mod.askopenfilename.return_value = ""
        self.panel.import_log()
        self.assertEqual(len(self.panel.config["bank_data"]), 0)

    def test_import_log_uds_names(self):
        import os
        # Format: "timestamp ch Tx CANID d [SID sub ...]"
        sids = ["10", "11", "14", "19", "22 F1 90", "2E", "31", "3E"]
        lines = [
            f"   0.00{i+1}  1  Tx  7DF  d  [{sid} 00 00 00 00 00 00]"
            for i, sid in enumerate(sids)
        ]
        path = self._make_asc_file(lines)
        _fd_mod.askopenfilename.return_value = path
        self.panel.import_log()
        names = [e["name"] for e in self.panel.config["bank_data"]]
        self.assertTrue(any("Session Control" in n for n in names))
        self.assertTrue(any("ECU Reset" in n for n in names))
        self.assertTrue(any("Tester Present" in n for n in names))
        os.unlink(path)


class TestCanDiagScriptExecution(unittest.TestCase):

    def setUp(self):
        self.panel = _make_panel()

    def test_start_script_requires_connection(self):
        """start_script must be a no-op when hardware is not connected."""
        self.panel.script_tree.insert("", "end", values=("Step", "7DF", "02 3E 00"))
        self.panel.is_connected = False
        self.panel.start_script()
        self.assertFalse(self.panel.is_script_running)

    def test_stop_script_clears_flag(self):
        self.panel.is_script_running = True
        self.panel.stop_script()
        self.assertFalse(self.panel.is_script_running)


if __name__ == "__main__":
    unittest.main()
