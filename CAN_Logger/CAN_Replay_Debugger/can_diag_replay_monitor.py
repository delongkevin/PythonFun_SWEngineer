import time
import sys
import subprocess
import os
import datetime
import threading
import json
import xml.etree.ElementTree as ET
from enum import Enum
from collections import defaultdict
import re

from PySide6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, 
                             QHBoxLayout, QPushButton, QLabel, QTextEdit, 
                             QFileDialog, QProgressBar, QFrame, QStyleFactory,
                             QComboBox, QGridLayout, QGroupBox, QCheckBox, QRadioButton, QButtonGroup,
                             QLineEdit, QListWidget, QListWidgetItem, QSplitter, QTabWidget, QTabBar)
from PySide6.QtCore import Qt, Signal, QObject, QTimer
from PySide6.QtGui import QFont, QPalette, QColor, QTextCursor

# --- Dependency Management ---
def ensure_dependencies():
    packages = {
        "can": "python-can",
        "cantools": "cantools",
        "asammdf": "asammdf",
        "lxml": "lxml"
    }
    for import_name, install_cmd in packages.items():
        try:
            __import__(import_name)
        except ImportError:
            print(f"[SETUP] Installing {import_name}...")
            subprocess.check_call([sys.executable, "-m", "pip", "install", install_cmd])

ensure_dependencies()

import can
import cantools
import asammdf
from lxml import etree

# --- Enums & Helpers ---

class LogFormat(Enum):
    ASC = 'asc'
    BLF = 'blf'
    UNKNOWN = 'unknown'

class AppMode(Enum):
    REPLAY = 'replay'
    PARSER = 'parser'

class DIDType(Enum):
    DIAGNOSTIC = "Diagnostic"
    ROUTINE = "Routine"
    DTC = "DTC"
    SECURITY = "Security"
    UNKNOWN = "Unknown"

class Stream(QObject):
    new_text = Signal(str)
    def write(self, text): 
        self.new_text.emit(str(text))
    def flush(self): pass

# --- CDD Parser Class ---

class CDDParser:
    """Parser for Vector CDD (CANdela) diagnostic files"""
    
    def __init__(self):
        self.dids = {}
        self.dtcs = {}
        self.services = {}
        self.is_loaded = False
        self.parsed_file = None  # Track which file was parsed
        
    def parse_cdd_file(self, file_path):
        """Parse Vector CDD XML file"""
        try:
            print(f"[CDD] Parsing {os.path.basename(file_path)}...")
            self.parsed_file = os.path.basename(file_path)
            
            # First, check if it's actually an XML file
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                first_lines = ''.join([next(f) for _ in range(5)])
                if '<?xml' not in first_lines and '<CDD' not in first_lines and '<CANDELA' not in first_lines:
                    print(f"[CDD] File doesn't appear to be valid XML")
                    return self._parse_cdd_alternative(file_path)
            
            # Parse XML with lxml
            tree = etree.parse(file_path)
            root = tree.getroot()
            
            print(f"[CDD DEBUG] Root tag: {root.tag}")

            # Optimize: Detect Native CANDELA format (CVADAS style)
            if root.tag == 'CANDELA':
                print("[CDD] Detected native CANDELA format.")
                return self._parse_candela_native(root)

            # --- Existing Logic for ODX-like/Autosar CDD ---
            # Try different namespace patterns
            ns_mappings = [
                {'cdd': 'http://www.vector-informatik.com/CANDELA'},
                {'cdd': 'http://www.asam.net/xml'},
                {'cdd': ''},  # Try without namespace
                None  # Try without namespace dict
            ]
            
            for ns in ns_mappings:
                try:
                    if ns is None:
                        # Try without namespace
                        did_elements = root.findall(".//DIAG-DATA-IDENTIFIER")
                        dtc_elements = root.findall(".//DTC")
                    else:
                        did_elements = root.xpath("//cdd:DIAG-DATA-IDENTIFIER", namespaces=ns) if ns else []
                        dtc_elements = root.xpath("//cdd:DTC", namespaces=ns) if ns else []
                    
                    print(f"[CDD DEBUG] Found {len(did_elements)} DID elements with ns={ns}")
                    
                    if did_elements or dtc_elements:
                        self._parse_dids(root, ns)
                        self._parse_dtcs(root, ns)
                        self._parse_services(root, ns)
                        self.is_loaded = True
                        print(f"[CDD] Successfully parsed {os.path.basename(file_path)}")
                        print(f"[CDD] Loaded {len(self.dids)} DIDs and {len(self.dtcs)} DTCs")
                        return True
                        
                except Exception as e:
                    print(f"[CDD DEBUG] Namespace {ns} failed: {e}")
                    continue
            
            print(f"[CDD] No valid content found with standard parsing, trying alternative...")
            return self._parse_cdd_alternative(file_path)
            
        except Exception as e:
            print(f"[CDD] Error parsing {file_path}: {str(e)}")
            import traceback
            traceback.print_exc()
            return self._parse_cdd_alternative(file_path)

    def _parse_candela_native(self, root):
        """Parse DIDs and DTCs from native CANDELA structure"""
        try:
            # 1. Parse DIDs
            # In your file, DIDs are <DID n="4096">...
            did_elements = root.xpath("//DID")
            print(f"[CDD DEBUG] Found {len(did_elements)} native DID elements")
            
            for elem in did_elements:
                try:
                    # 'n' attribute usually holds the Decimal ID in this format (e.g. n="4098" -> 0x1002)
                    did_id_str = elem.get('n')
                    if not did_id_str:
                        continue
                        
                    did_value = int(did_id_str)
                    
                    # Get Name
                    did_name = "Unknown"
                    name_elem = elem.find(".//NAME")
                    if name_elem is not None:
                        # Sometimes NAME has TUV children for languages
                        tuv = name_elem.find("TUV")
                        if tuv is not None and tuv.text:
                            did_name = tuv.text.strip()
                        elif name_elem.text:
                            did_name = name_elem.text.strip()
                    
                    # Get Description/Qual
                    qual = ""
                    qual_elem = elem.find("QUAL")
                    if qual_elem is not None and qual_elem.text:
                        qual = qual_elem.text.strip()
                        if did_name == "Unknown": did_name = qual
                    
                    # Store
                    self.dids[did_value] = {
                        'name': did_name,
                        'length': 0, # Length might be in STRUCTURE/DATAOBJ but is complex to parse
                        'type': DIDType.DIAGNOSTIC,
                        'description': qual
                    }
                except Exception as e:
                    continue

            # 2. Parse DTCs
            # Look for Trouble Codes. Often in <TROUBLECODES> or <DTC>
            dtc_elements = root.xpath("//DTC")
            if not dtc_elements:
                dtc_elements = root.xpath("//TROUBLECODE")
                
            print(f"[CDD DEBUG] Found {len(dtc_elements)} native DTC elements")
            
            for elem in dtc_elements:
                try:
                    # Try 'id' attribute or 'n' attribute
                    dtc_id_str = elem.get('id')
                    if not dtc_id_str: dtc_id_str = elem.get('n')
                    
                    # Sometimes the DTC code is explicit in a child
                    display_code = elem.find(".//DISPLAYCODE")
                    if display_code is not None and display_code.text:
                        dtc_hex = display_code.text.strip()
                    else:
                        # Fallback logic if needed
                        continue

                    dtc_val = int(dtc_hex.replace('0x',''), 16)
                    
                    dtc_name = "Unknown DTC"
                    name_elem = elem.find(".//NAME")
                    if name_elem is not None:
                         tuv = name_elem.find("TUV")
                         if tuv is not None and tuv.text:
                             dtc_name = tuv.text.strip()
                    
                    self.dtcs[dtc_val] = {
                        'name': dtc_name,
                        'description': ""
                    }
                except:
                    pass

            self.is_loaded = True
            print(f"[CDD] Successfully parsed {self.parsed_file}")
            print(f"[CDD] Loaded {len(self.dids)} DIDs and {len(self.dtcs)} DTCs")
            return True

        except Exception as e:
            print(f"[CDD] Native parsing failed: {e}")
            return False
    
    def _parse_dids(self, root, ns):
        """Parse Diagnostic Identifiers from CDD"""
        # Look for DID elements in various possible locations
        did_elements = root.xpath("//cdd:DIAG-DATA-IDENTIFIER", namespaces=ns)
        
        if not did_elements:
            # Try alternative XPath
            did_elements = root.xpath("//cdd:DIAG-COMMON-DATA//cdd:DIAG-DATA-IDENTIFIER", namespaces=ns)
        
        for elem in did_elements:
            try:
                did_id_elem = elem.find("cdd:SHORT-NAME", ns)
                did_value_elem = elem.find("cdd:IDENTIFIER-VALUE", ns)
                did_length_elem = elem.find("cdd:LENGTH", ns)
                
                # Alternative element names
                if did_id_elem is None:
                    did_id_elem = elem.find("cdd:ID", ns)
                if did_value_elem is None:
                    did_value_elem = elem.find("cdd:VALUE", ns)
                
                if did_id_elem is not None and did_value_elem is not None:
                    did_name = did_id_elem.text.strip() if did_id_elem.text else "Unknown"
                    did_hex = did_value_elem.text.strip() if did_value_elem.text else ""
                    
                    # Clean hex string
                    did_hex = did_hex.replace("0x", "").replace("0X", "").strip()
                    
                    # Convert hex string to integer
                    if did_hex:
                        try:
                            did_value = int(did_hex, 16)
                        except ValueError:
                            # Try decimal
                            did_value = int(did_hex)
                    else:
                        continue  # Skip if no valid hex value
                    
                    # Determine DID type
                    did_type = self._determine_did_type(did_name, elem)
                    
                    # Get length
                    length = 0
                    if did_length_elem is not None and did_length_elem.text:
                        try:
                            length = int(did_length_elem.text)
                        except:
                            pass
                    
                    self.dids[did_value] = {
                        'name': did_name,
                        'length': length,
                        'type': did_type,
                        'description': self._get_description(elem, ns)
                    }
                    
            except Exception as e:
                print(f"[CDD] Error parsing DID element: {e}")
                continue
    
    def _parse_dtcs(self, root, ns):
        """Parse Diagnostic Trouble Codes from CDD"""
        # Look for DTC elements
        for elem in root.xpath("//cdd:DIAG-COMMON-DATA//cdd:DTC", namespaces=ns):
            try:
                dtc_id_elem = elem.find("cdd:SHORT-NAME", ns)
                dtc_value_elem = elem.find("cdd:IDENTIFIER-VALUE", ns)
                dtc_severity_elem = elem.find("cdd:SEVERITY", ns)
                
                if dtc_id_elem is not None and dtc_value_elem is not None:
                    dtc_name = dtc_id_elem.text.strip() if dtc_id_elem.text else "Unknown"
                    dtc_hex = dtc_value_elem.text.strip() if dtc_value_elem.text else ""
                    
                    # Convert hex string to integer
                    if dtc_hex.startswith('0x'):
                        dtc_value = int(dtc_hex, 16)
                    else:
                        dtc_value = int(dtc_hex, 16) if dtc_hex else 0
                    
                    self.dtcs[dtc_value] = {
                        'name': dtc_name,
                        'severity': dtc_severity_elem.text if dtc_severity_elem is not None else "UNKNOWN",
                        'description': self._get_description(elem, ns)
                    }
                    
            except Exception as e:
                print(f"[CDD] Error parsing DTC element: {e}")
                continue
    
    def _parse_services(self, root, ns):
        """Parse Diagnostic Services from CDD"""
        # UDS Service IDs (ISO 14229)
        uds_services = {
            0x10: "Diagnostic Session Control",
            0x11: "ECU Reset",
            0x14: "Clear Diagnostic Information",
            0x19: "Read DTC Information",
            0x22: "Read Data By Identifier",
            0x23: "Read Memory By Address",
            0x27: "Security Access",
            0x28: "Communication Control",
            0x2E: "Write Data By Identifier",
            0x2F: "Input Output Control By Identifier",
            0x31: "Routine Control",
            0x34: "Request Download",
            0x35: "Request Upload",
            0x36: "Transfer Data",
            0x37: "Request Transfer Exit",
            0x3E: "Tester Present",
            0x85: "Control DTC Setting"
        }
        
        # Check for custom service definitions
        for elem in root.xpath("//cdd:DIAG-SERVICE", namespaces=ns):
            try:
                service_id_elem = elem.find("cdd:SERVICE-ID", ns)
                service_name_elem = elem.find("cdd:SHORT-NAME", ns)
                
                if service_id_elem is not None and service_name_elem is not None:
                    service_id = int(service_id_elem.text, 16) if service_id_elem.text.startswith('0x') else int(service_id_elem.text)
                    service_name = service_name_elem.text.strip() if service_name_elem.text else "Unknown"
                    
                    self.services[service_id] = service_name
                    
            except Exception as e:
                print(f"[CDD] Error parsing service element: {e}")
                continue
        
        # Add standard UDS services if not already defined
        for service_id, service_name in uds_services.items():
            if service_id not in self.services:
                self.services[service_id] = service_name
    
    def _determine_did_type(self, did_name, element):
        """Determine the type of DID based on name and context"""
        did_name_lower = did_name.lower()
        
        # Check for DTC related DIDs
        if any(keyword in did_name_lower for keyword in ['dtc', 'trouble', 'fault', 'error']):
            return DIDType.DTC
        
        # Check for Routine related DIDs
        if any(keyword in did_name_lower for keyword in ['routine', 'test', 'check']):
            return DIDType.ROUTINE
        
        # Check for Security related DIDs
        if any(keyword in did_name_lower for keyword in ['security', 'access', 'key', 'seed']):
            return DIDType.SECURITY
        
        # Default to Diagnostic
        return DIDType.DIAGNOSTIC
    
    def _get_description(self, element, ns):
        """Extract description from element"""
        desc_elem = element.find("cdd:DESC", ns)
        if desc_elem is not None and desc_elem.text:
            return desc_elem.text.strip()
        
        # Try alternative description elements
        for desc_tag in ['LONG-NAME', 'DESCRIPTION', 'ANNOTATION']:
            desc_elem = element.find(f"cdd:{desc_tag}", ns)
            if desc_elem is not None and desc_elem.text:
                return desc_elem.text.strip()
        
        return ""
    
    def _parse_cdd_alternative(self, file_path):
        """Alternative parsing method for CDD files"""
        try:
            print(f"[CDD] Trying alternative parsing for {os.path.basename(file_path)}")
            
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Extract DIDs using more flexible regex patterns
            did_patterns = [
                r'(?:SHORT-NAME|ID)\s*[=>]\s*["\']?([^"\'\s>]+)["\']?\s*(?:IDENTIFIER-VALUE|VALUE)\s*[=>]\s*["\']?(?:0x)?([0-9A-Fa-f]{1,4})["\']?',
                r'<DIAG-DATA-IDENTIFIER[^>]*>.*?<SHORT-NAME>([^<]+)</SHORT-NAME>.*?<IDENTIFIER-VALUE>(?:0x)?([0-9A-Fa-f]{1,4})</IDENTIFIER-VALUE>',
                r'DID_\w+\s*=\s*(?:0x)?([0-9A-Fa-f]{1,4})\s*;?\s*/\*([^*]+)\*/',
                r'DataIdentifier\s+0x([0-9A-Fa-f]{1,4})\s*{\s*name\s*=\s*"([^"]+)"'
            ]
            
            dtc_patterns = [
                r'<DTC[^>]*>.*?<SHORT-NAME>([^<]+)</SHORT-NAME>.*?<IDENTIFIER-VALUE>(?:0x)?([0-9A-Fa-f]{1,6})</IDENTIFIER-VALUE>',
                r'(?:SHORT-NAME|ID)\s*[=>]\s*["\']?([^"\'\s>]+)["\']?\s*(?:IDENTIFIER-VALUE|VALUE)\s*[=>]\s*["\']?(?:0x)?([0-9A-Fa-f]{1,6})["\']?',
                r'DTC_\w+\s*=\s*(?:0x)?([0-9A-Fa-f]{1,6})\s*;?\s*/\*([^*]+)\*/',
                r'TroubleCode\s+0x([0-9A-Fa-f]{1,6})\s*{\s*name\s*=\s*"([^"]+)"'
            ]
            
            dids_found = 0
            dtcs_found = 0
            
            for pattern in did_patterns:
                for match in re.finditer(pattern, content, re.DOTALL | re.IGNORECASE):
                    try:
                        if len(match.groups()) >= 2:
                            did_hex = match.group(2).upper().replace("0X", "").replace("0x", "")
                            did_name = match.group(1).strip()
                            
                            if did_hex and did_name:
                                did_value = int(did_hex, 16)
                                self.dids[did_value] = {
                                    'name': did_name,
                                    'length': 0,
                                    'type': DIDType.DIAGNOSTIC,
                                    'description': f"Extracted from CDD: {did_name}"
                                }
                                dids_found += 1
                    except:
                        continue
            
            for pattern in dtc_patterns:
                for match in re.finditer(pattern, content, re.DOTALL | re.IGNORECASE):
                    try:
                        if len(match.groups()) >= 2:
                            dtc_hex = match.group(2).upper().replace("0X", "").replace("0x", "")
                            dtc_name = match.group(1).strip()
                            
                            if dtc_hex and dtc_name:
                                dtc_value = int(dtc_hex, 16)
                                self.dtcs[dtc_value] = {
                                    'name': dtc_name,
                                    'severity': "UNKNOWN",
                                    'description': f"Extracted from CDD: {dtc_name}"
                                }
                                dtcs_found += 1
                    except:
                        continue
            
            if dids_found > 0 or dtcs_found > 0:
                self.is_loaded = True
                print(f"[CDD] Alternative parsing successful: {dids_found} DIDs, {dtcs_found} DTCs")
                return True
            
            print(f"[CDD] Alternative parsing found 0 DIDs/DTCs")
            
            # Last resort: check if it's actually a DBC file misnamed as CDD
            if file_path.lower().endswith('.cdd'):
                try:
                    print(f"[CDD] File may be misnamed DBC, trying DBC parser...")
                    temp_db = cantools.database.Database()
                    temp_db.add_dbc_file(file_path)
                    print(f"[CDD] File is actually a DBC, not CDD")
                    return False
                except:
                    pass
            
            return False
            
        except Exception as e:
            print(f"[CDD] Alternative parsing failed: {e}")
            import traceback
            traceback.print_exc()
            return False
    
    def find_did(self, did_value):
        """Look up DID information"""
        return self.dids.get(did_value)
    
    def find_dtc(self, dtc_value):
        """Look up DTC information"""
        return self.dtcs.get(dtc_value)
    
    def get_service_name(self, service_id):
        """Get service name for a given service ID"""
        return self.services.get(service_id, f"Service 0x{service_id:02X}")

# --- Generic DID/DTC Detector ---

class GenericDiagDetector:
    """Generic DID/DTC detector for when no CDD is available"""
    
    # Common UDS service IDs
    UDS_SERVICES = {
        0x22: "ReadDataByIdentifier",
        0x2E: "WriteDataByIdentifier",
        0x19: "ReadDTCInformation",
        0x14: "ClearDiagnosticInformation",
        0x27: "SecurityAccess",
        0x31: "RoutineControl"
    }
    
    # Common DID ranges for different manufacturers
    COMMON_DID_RANGES = {
        'General': (0xF100, 0xF1FF),
        'Volkswagen': (0xF100, 0xF1FF),
        'BMW': (0xF000, 0xF0FF),
        'Mercedes': (0xF200, 0xF2FF),
        'Toyota': (0xF400, 0xF4FF),
        'Ford': (0xF500, 0xF5FF),
        'GM': (0xF600, 0xF6FF),
        'Hyundai': (0xF700, 0xF7FF)
    }
    
    @staticmethod
    def is_diagnostic_message(msg_id):
        """Check if message ID is in diagnostic range"""
        # Common diagnostic message IDs (CAN ISO-TP, UDS)
        diagnostic_base_ids = [0x7DF, 0x7E0, 0x7E8, 0x7E1, 0x7E2, 0x7E3, 0x7E4, 0x7E5]
        
        # Check if it's a standard diagnostic ID
        if msg_id in diagnostic_base_ids:
            return True
        
        # Check extended addressing (29-bit IDs with diagnostic bits)
        if (msg_id >> 8) & 0xFF in [0x18, 0x1A, 0x1C]:
            return True
        
        return False
    
    @staticmethod
    def detect_did_in_data(data_bytes):
        """Detect potential DIDs in CAN data"""
        potential_dids = []
        
        # Minimum 3 bytes needed for UDS DID request (SID + DID_H + DID_L)
        if len(data_bytes) >= 3:
            # Check for ReadDataByIdentifier (0x22) or WriteDataByIdentifier (0x2E)
            service_id = data_bytes[0]
            
            if service_id in [0x22, 0x2E]:
                # DID is typically bytes 1-2 (big endian)
                did_value = (data_bytes[1] << 8) | data_bytes[2]
                
                # Check if DID is in common ranges
                for manufacturer, (low, high) in GenericDiagDetector.COMMON_DID_RANGES.items():
                    if low <= did_value <= high:
                        potential_dids.append({
                            'value': did_value,
                            'service': GenericDiagDetector.UDS_SERVICES.get(service_id, f"Service 0x{service_id:02X}"),
                            'confidence': 'HIGH',
                            'manufacturer': manufacturer,
                            'data': data_bytes
                        })
                        break
                else:
                    # DID not in common ranges but service indicates it's diagnostic
                    potential_dids.append({
                        'value': did_value,
                        'service': GenericDiagDetector.UDS_SERVICES.get(service_id, f"Service 0x{service_id:02X}"),
                        'confidence': 'MEDIUM',
                        'manufacturer': 'Unknown',
                        'data': data_bytes
                    })
        
        return potential_dids
    
    @staticmethod
    def detect_dtc_in_data(data_bytes):
        """Detect potential DTCs in CAN data"""
        potential_dtcs = []
        
        # Minimum 3 bytes needed for DTC information (SID + DTC bytes)
        if len(data_bytes) >= 3:
            service_id = data_bytes[0]
            
            # Check for ReadDTCInformation (0x19)
            if service_id == 0x19:
                # DTCs typically start from byte 2
                for i in range(2, len(data_bytes) - 2, 4):
                    if i + 3 < len(data_bytes):
                        dtc_bytes = data_bytes[i:i+4]
                        if dtc_bytes != b'\x00\x00\x00\x00':  # Skip null DTCs
                            # DTC format: 2 bytes for DTC number + 1 byte status
                            dtc_value = (dtc_bytes[0] << 8) | dtc_bytes[1]
                            dtc_status = dtc_bytes[2]
                            
                            potential_dtcs.append({
                                'value': dtc_value,
                                'status': dtc_status,
                                'confidence': 'HIGH',
                                'service': 'ReadDTCInformation',
                                'data': data_bytes
                            })
            
            # Check for ClearDiagnosticInformation (0x14)
            elif service_id == 0x14:
                # Clear DTC typically includes DTC value
                if len(data_bytes) >= 4:
                    dtc_value = (data_bytes[1] << 8) | data_bytes[2]
                    potential_dtcs.append({
                        'value': dtc_value,
                        'status': 0x00,
                        'confidence': 'HIGH',
                        'service': 'ClearDiagnosticInformation',
                        'data': data_bytes
                    })
        
        return potential_dtcs
    
    @staticmethod
    def detect_security_access(data_bytes):
        """Detect security access messages"""
        security_messages = []
        
        if len(data_bytes) >= 2:
            service_id = data_bytes[0]
            subfunction = data_bytes[1] if len(data_bytes) > 1 else None
            
            # Security Access service (0x27)
            if service_id == 0x27:
                if subfunction is not None:
                    if subfunction % 2 == 1:  # Request seed
                        security_type = f"RequestSeed (Level {subfunction})"
                    else:  # Send key
                        security_type = f"SendKey (Level {subfunction})"
                    
                    security_messages.append({
                        'service': 'SecurityAccess',
                        'type': security_type,
                        'level': subfunction,
                        'data': data_bytes
                    })
        
        return security_messages

# --- Updated GUI Class ---

class MagnaDebugApp(QMainWindow):
    
    task_finished = Signal(bool)
    
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Magna CAN-LOG Tool (Can-Replay and Log Parser) ")
        self.setMinimumSize(1350, 900)
        self.db_files = []
        self.log_file = ""
        self.worker_thread = None
        self.can_engine = None
        
        # Available signals and messages from loaded DBCs
        self.available_messages = []  # List of (id, name) tuples
        self.available_signals = []   # List of (message_name, signal_name) tuples
        
        # CDD Parser instance
        self.cdd_parser = CDDParser()
        self.has_cdd_file = False
        
        self.init_ui()
        self.task_finished.connect(self.finish_execution)
        
        # Redirect stdout/stderr
        sys.stdout = Stream(new_text=self.on_print)
        sys.stderr = Stream(new_text=self.on_print)

    def init_ui(self):
        central = QWidget()
        self.setCentralWidget(central)
        layout = QVBoxLayout(central)
        layout.setSpacing(10)
        layout.setContentsMargins(15, 15, 15, 15)

         # --- Top Control Panel ---
        control_panel = QGroupBox("Configuration")
        control_panel.setStyleSheet("QGroupBox { font-weight: bold; }")
        grid = QGridLayout()
        
        # Mode Selection
        mode_group = QGroupBox("Operation Mode")
        mode_layout = QHBoxLayout()
        self.radio_replay = QRadioButton("Live Replay (Hardware)")
        self.radio_parse = QRadioButton("Log Parser (Offline Report)")
        self.radio_replay.setChecked(True)
        self.radio_replay.toggled.connect(self.toggle_mode_ui)
        
        mode_btn_group = QButtonGroup(self)
        mode_btn_group.addButton(self.radio_replay)
        mode_btn_group.addButton(self.radio_parse)
        
        mode_layout.addWidget(self.radio_replay)
        mode_layout.addWidget(self.radio_parse)
        mode_group.setLayout(mode_layout)

        # File Controls
        self.btn_db = QPushButton("📂 Add DBC/CDD")
        self.btn_log = QPushButton("📄 Select Log File")
        self.btn_clear = QPushButton("🗑️ Reset")
        self.btn_clear.clicked.connect(self.clear_all)
        
        self.lbl_db_count = QLabel("Databases: 0")
        self.lbl_log_info = QLabel("Log: None selected")
        
        # CDD Status Indicator
        self.lbl_cdd_status = QLabel("CDD: Not Loaded")
        self.lbl_cdd_status.setStyleSheet("color: #FF9800; font-weight: bold;")
        
        # CHANNEL SELECTION (NEW)
        self.lbl_channel = QLabel("CAN Channel:")
        self.cmb_channel = QComboBox()
        self.cmb_channel.addItems(["Auto-detect", "Channel 1", "Channel 2", "Channel 3", "Channel 4", "Channel 5", "Channel 6", "Channel 7", "Channel 8"])
        self.cmb_channel.setEnabled(False)
        self.btn_scan_channels = QPushButton("🔍 Scan")
        self.btn_scan_channels.setEnabled(False)
        self.btn_scan_channels.clicked.connect(self.scan_available_channels)
        
        # Interface selection
        self.lbl_interface = QLabel("Interface:")
        self.cmb_interface = QComboBox()
        self.cmb_interface.addItems(["Vector", "SocketCAN", "PCAN", "Virtual"])
        self.cmb_interface.setEnabled(False)
        
        # Bitrate selection
        self.lbl_bitrate = QLabel("Bitrate:")
        self.cmb_bitrate = QComboBox()
        self.cmb_bitrate.addItems(["500 kbps", "250 kbps", "125 kbps", "1 Mbps", "2 Mbps", "5 Mbps", "Auto"])
        self.cmb_bitrate.setEnabled(False)
        
        # ECU Filter Control
        self.lbl_filter = QLabel("Filter by ECU:")
        self.cmb_filter = QComboBox()
        self.cmb_filter.addItems(["ALL"])
        self.cmb_filter.setEnabled(False)
        
        # Replay Specific Controls
        self.lbl_speed = QLabel("Replay Speed:")
        self.cmb_speed = QComboBox()
        self.cmb_speed.addItems(["Real-time", "2x Speed", "5x Speed", "Max Speed"])
        self.cmb_speed.setEnabled(False)
        
        self.chk_loop = QCheckBox("Loop Replay")
        self.chk_loop.setEnabled(False)
        self.chk_responses = QCheckBox("Monitor Responses")
        self.chk_responses.setChecked(True)
        self.chk_responses.setEnabled(False)
        
        # Diagnostic Detection Options
        self.chk_detect_diag = QCheckBox("Detect Diagnostics (DID/DTC)")
        self.chk_detect_diag.setChecked(True)
        self.chk_detect_diag.setToolTip("Enable automatic detection of diagnostic messages")

        # Layout Assembly - Updated grid
        grid.addWidget(mode_group, 0, 0, 1, 6)
        grid.addWidget(self.btn_db, 1, 0)
        grid.addWidget(self.btn_log, 1, 1)
        grid.addWidget(self.btn_clear, 1, 2)
        grid.addWidget(self.lbl_cdd_status, 1, 3, 1, 3)
        
        grid.addWidget(self.lbl_db_count, 2, 0)
        grid.addWidget(self.lbl_log_info, 2, 1, 1, 5)
        
        # Hardware Configuration Row
        grid.addWidget(self.lbl_interface, 3, 0)
        grid.addWidget(self.cmb_interface, 3, 1)
        grid.addWidget(self.lbl_channel, 3, 2)
        grid.addWidget(self.cmb_channel, 3, 3)
        grid.addWidget(self.btn_scan_channels, 3, 4)
        grid.addWidget(self.lbl_bitrate, 3, 5)
        grid.addWidget(self.cmb_bitrate, 3, 6)
        
        # Replay Configuration Row
        grid.addWidget(self.lbl_speed, 4, 0)
        grid.addWidget(self.cmb_speed, 4, 1)
        grid.addWidget(self.chk_loop, 4, 2)
        grid.addWidget(self.chk_responses, 4, 3)
        grid.addWidget(self.chk_detect_diag, 4, 4)
        
        # Filter Row
        grid.addWidget(self.lbl_filter, 5, 0)
        grid.addWidget(self.cmb_filter, 5, 1)
        
        control_panel.setLayout(grid)
        layout.addWidget(control_panel)
        
        control_panel.setLayout(grid)
        layout.addWidget(control_panel)

        # --- Signal/Message Filter Panel (New) ---
        self.filter_panel = QGroupBox("Signal/Message Filter (Parser Mode Only)")
        self.filter_panel.setStyleSheet("QGroupBox { font-weight: bold; }")
        filter_layout = QGridLayout()
        
        # Mode selector for filter type
        filter_mode_group = QGroupBox("Filter by:")
        filter_mode_layout = QHBoxLayout()
        self.radio_filter_ecu = QRadioButton("ECU")
        self.radio_filter_signal = QRadioButton("Signal/Message")
        self.radio_filter_ecu.setChecked(True)
        self.radio_filter_ecu.toggled.connect(self.toggle_filter_mode)
        
        filter_mode_btn_group = QButtonGroup(self)
        filter_mode_btn_group.addButton(self.radio_filter_ecu)
        filter_mode_btn_group.addButton(self.radio_filter_signal)
        
        filter_mode_layout.addWidget(self.radio_filter_ecu)
        filter_mode_layout.addWidget(self.radio_filter_signal)
        filter_mode_group.setLayout(filter_mode_layout)
        
        # Signal/Message filter controls
        self.lbl_signal_filter = QLabel("Select Messages/Signals:")
        self.list_signal_filter = QListWidget()
        self.list_signal_filter.setSelectionMode(QListWidget.MultiSelection)
        self.list_signal_filter.setMaximumHeight(150)
        
        # Quick selection buttons
        btn_filter_layout = QHBoxLayout()
        self.btn_select_all = QPushButton("Select All")
        self.btn_clear_selection = QPushButton("Clear Selection")
        self.btn_select_all.clicked.connect(self.select_all_signals)
        self.btn_clear_selection.clicked.connect(self.clear_signal_selection)
        
        btn_filter_layout.addWidget(self.btn_select_all)
        btn_filter_layout.addWidget(self.btn_clear_selection)
        btn_filter_layout.addStretch()
        
        # ID filter (manual input)
        self.lbl_id_filter = QLabel("Or enter Message IDs (hex, comma-separated):")
        self.edit_id_filter = QLineEdit()
        self.edit_id_filter.setPlaceholderText("e.g., 0x100, 0x200, 0x300")
        
        # Search box for filtering the list
        self.lbl_search = QLabel("Search:")
        self.edit_search = QLineEdit()
        self.edit_search.setPlaceholderText("Type to filter list...")
        self.edit_search.textChanged.connect(self.filter_signal_list)
        
        filter_layout.addWidget(filter_mode_group, 0, 0, 1, 2)
        filter_layout.addWidget(self.lbl_signal_filter, 1, 0, 1, 2)
        filter_layout.addWidget(self.list_signal_filter, 2, 0, 1, 2)
        filter_layout.addLayout(btn_filter_layout, 3, 0, 1, 2)
        filter_layout.addWidget(self.lbl_search, 4, 0)
        filter_layout.addWidget(self.edit_search, 4, 1)
        filter_layout.addWidget(self.lbl_id_filter, 5, 0, 1, 2)
        filter_layout.addWidget(self.edit_id_filter, 6, 0, 1, 2)
        
        self.filter_panel.setLayout(filter_layout)
        layout.addWidget(self.filter_panel)
        
        # Initially hide signal filter panel for replay mode
        self.filter_panel.setVisible(False)

        # --- Console ---
        console_box = QGroupBox("System Output")
        console_layout = QVBoxLayout()
        self.console = QTextEdit()
        self.console.setReadOnly(True)
 
        btn_clear_console = QPushButton("Clear Output")
        btn_clear_console.setFixedWidth(100)
        btn_clear_console.clicked.connect(self.console.clear)
        
        console_layout.addWidget(self.console)
        console_layout.addWidget(btn_clear_console, alignment=Qt.AlignRight)
        console_box.setLayout(console_layout)
        layout.addWidget(console_box)

        # --- Status Bar ---
        status_frame = QFrame()
        status_layout = QHBoxLayout(status_frame)
        
        self.lbl_status = QLabel("🟢 Ready")
        self.lbl_status.setStyleSheet("color: #4CAF50; font-weight: bold;")
        self.lbl_stats = QLabel("")
        self.prog = QProgressBar()
        self.prog.setTextVisible(True)
        
        status_layout.addWidget(self.lbl_status)
        status_layout.addWidget(self.lbl_stats)
        status_layout.addWidget(self.prog)
        layout.addWidget(status_frame)

        # --- Action Buttons ---
        btn_layout = QHBoxLayout()
        self.btn_run = QPushButton("▶️ EXECUTE")
        self.btn_run.setFixedHeight(50)
        self.btn_run.setStyleSheet("background-color: #0078d4; color: white; font-weight: bold; font-size: 14px; border-radius: 5px;")
        self.btn_run.clicked.connect(self.execute)
        
        self.btn_stop = QPushButton("⏹️ STOP")
        self.btn_stop.setEnabled(False)
        self.btn_stop.clicked.connect(self.stop_process)
        
        self.btn_report = QPushButton("📊 Open Report")
        self.btn_report.setEnabled(False)
        self.btn_report.clicked.connect(self.open_report)
        
        btn_layout.addWidget(self.btn_run)
        btn_layout.addWidget(self.btn_stop)
        btn_layout.addWidget(self.btn_report)
        layout.addLayout(btn_layout)

        # Connect signals
        self.btn_db.clicked.connect(self.get_db)
        self.btn_log.clicked.connect(self.get_log)
        
        # Timer for UI updates
        self.update_timer = QTimer()
        self.update_timer.timeout.connect(self.update_ui_stats)
        self.update_timer.start(500)

    def get_db(self):
        files, _ = QFileDialog.getOpenFileNames(self, "Load CAN Databases", "", "CAN Database (*.dbc *.cdd)")
        if files: 
            self.db_files.extend(files)
            self.lbl_db_count.setText(f"Databases: {len(self.db_files)}")
            print(f"[UI] Added {len(files)} database(s)")
            
            # Check for CDD files and parse them
            self.check_and_parse_cdd_files(files)
            
            # Update both ECU and Signal filters
            self.populate_node_filter()
            self.populate_signal_filter()

    def check_and_parse_cdd_files(self, files):
        """Check if any of the loaded files are CDD and parse them"""
        for file in files:
            if file.lower().endswith('.cdd'):
                print(f"[CDD] Found CDD file: {os.path.basename(file)}")
                
                # Check file size
                file_size = os.path.getsize(file)
                print(f"[CDD] File size: {file_size} bytes")
                
                if self.cdd_parser.parse_cdd_file(file):
                    self.has_cdd_file = True
                    self.lbl_cdd_status.setText(f"CDD: ✓ ({len(self.cdd_parser.dids)} DIDs, {len(self.cdd_parser.dtcs)} DTCs)")
                    self.lbl_cdd_status.setStyleSheet("color: #4CAF50; font-weight: bold;")
                    print(f"[CDD] Successfully parsed: {len(self.cdd_parser.dids)} DIDs, {len(self.cdd_parser.dtcs)} DTCs")
                    
                    # Debug: Print first few DIDs and DTCs
                    print("[CDD DEBUG] First 5 DIDs:")
                    for i, (did, info) in enumerate(list(self.cdd_parser.dids.items())[:5]):
                        print(f"  0x{did:04X}: {info['name']}")
                    
                    print("[CDD DEBUG] First 5 DTCs:")
                    for i, (dtc, info) in enumerate(list(self.cdd_parser.dtcs.items())[:5]):
                        print(f"  0x{dtc:04X}: {info['name']}")
                else:
                    self.lbl_cdd_status.setText("CDD: ✗ (No DIDs/DTCs found)")
                    self.lbl_cdd_status.setStyleSheet("color: #F44336; font-weight: bold;")
                    print(f"[CDD] Failed to parse CDD file or file contains no DIDs/DTCs")

    def toggle_mode_ui(self):
        is_replay = self.radio_replay.isChecked()
        
        # Replay controls
        self.cmb_speed.setEnabled(is_replay)
        self.chk_loop.setEnabled(is_replay)
        self.chk_responses.setEnabled(is_replay)
        
        # Hardware controls
        self.cmb_interface.setEnabled(is_replay)
        self.cmb_channel.setEnabled(is_replay)
        self.btn_scan_channels.setEnabled(is_replay)
        self.cmb_bitrate.setEnabled(is_replay)
        
        # Filter controls
        self.cmb_filter.setEnabled(not is_replay)
        
        # Signal filter panel visibility
        self.filter_panel.setVisible(not is_replay)
        
        # Diagnostic detection checkbox
        self.chk_detect_diag.setEnabled(True)
        
        self.btn_run.setText("▶️ START REPLAY" if is_replay else "▶️ GENERATE REPORT")
        color = "#0078d4" if is_replay else "#28a745"
        self.btn_run.setStyleSheet(f"background-color: {color}; color: white; font-weight: bold; font-size: 14px; border-radius: 5px;")
        
        # Scan channels automatically when switching to replay mode
        if is_replay:
            QTimer.singleShot(100, self.scan_available_channels)  # Small delay for UI to update
        
        # Reset filter mode when switching
        if not is_replay:
            self.radio_filter_ecu.setChecked(True)
            self.toggle_filter_mode()

    def scan_available_channels(self):
        """Scan for available CAN channels (cross-platform compatible)"""
        print("[HW] Scanning for available CAN interfaces...")
        
        # Clear and reset channel list
        self.cmb_channel.clear()
        self.cmb_channel.addItem("Auto-detect")
        
        available_channels = []
        found_interfaces = []
        
        # Try Vector interfaces
        try:
            configs = can.detect_available_configs(interfaces=['vector'])
            if configs:
                print(f"[HW] Found {len(configs)} Vector interface(s)")
                found_interfaces.append(('vector', len(configs)))
                
                for i, config in enumerate(configs):
                    channel = config.get('channel', i)
                    description = config.get('description', f'Vector Interface {i+1}')
                    device_name = config.get('device', f'VN16xx')
                    serial = config.get('serial', '')
                    
                    # Format channel display
                    if serial:
                        channel_text = f"Vector Ch{channel}: {description} ({device_name}, S/N: {serial})"
                    else:
                        channel_text = f"Vector Ch{channel}: {description} ({device_name})"
                    
                    available_channels.append(channel_text)
                    print(f"[HW]   - {channel_text}")
        except Exception as e:
            print(f"[HW] Vector scan error: {e}")
        
        # Try PCAN interfaces
        try:
            configs = can.detect_available_configs(interfaces=['pcan'])
            if configs:
                print(f"[HW] Found {len(configs)} PCAN interface(s)")
                found_interfaces.append(('pcan', len(configs)))
                
                for i, config in enumerate(configs):
                    channel = config.get('channel', i)
                    device = config.get('device', f'PCAN-USB')
                    state = config.get('state', '')
                    
                    channel_text = f"PCAN Ch{channel}: {device}"
                    if state:
                        channel_text += f" ({state})"
                    
                    available_channels.append(channel_text)
                    print(f"[HW]   - {channel_text}")
        except Exception as e:
            print(f"[HW] PCAN scan error: {e}")
        
        # Try SocketCAN interfaces (Linux only)
        if sys.platform.startswith('linux'):
            try:
                import subprocess
                result = subprocess.run(['ip', 'link', 'show'], capture_output=True, text=True, timeout=2)
                socketcan_ifaces = []
                for line in result.stdout.split('\n'):
                    if 'can' in line and 'state' in line:
                        iface_name = line.split(':')[1].strip()
                        # Check if interface is up
                        if 'UP' in line or 'UNKNOWN' in line:
                            status = 'UP'
                        else:
                            status = 'DOWN'
                        
                        socketcan_ifaces.append((iface_name, status))
                
                if socketcan_ifaces:
                    print(f"[HW] Found {len(socketcan_ifaces)} SocketCAN interface(s)")
                    found_interfaces.append(('socketcan', len(socketcan_ifaces)))
                    
                    for iface_name, status in socketcan_ifaces:
                        channel_text = f"SocketCAN: {iface_name} ({status})"
                        available_channels.append(channel_text)
                        print(f"[HW]   - {channel_text}")
            except Exception as e:
                print(f"[HW] SocketCAN scan error: {e}")
        else:
            print("[HW] SocketCAN scanning skipped (Windows/Mac)")
        
        # Try IXXAT interfaces
        try:
            configs = can.detect_available_configs(interfaces=['ixxat'])
            if configs:
                print(f"[HW] Found {len(configs)} IXXAT interface(s)")
                found_interfaces.append(('ixxat', len(configs)))
                
                for i, config in enumerate(configs):
                    channel = config.get('channel', i)
                    device = config.get('device', 'IXXAT Interface')
                    
                    channel_text = f"IXXAT Ch{channel}: {device}"
                    available_channels.append(channel_text)
                    print(f"[HW]   - {channel_text}")
        except Exception as e:
            print(f"[HW] IXXAT scan error: {e}")
        
        # Try Kvaser interfaces
        try:
            configs = can.detect_available_configs(interfaces=['kvaser'])
            if configs:
                print(f"[HW] Found {len(configs)} Kvaser interface(s)")
                found_interfaces.append(('kvaser', len(configs)))
                
                for i, config in enumerate(configs):
                    channel = config.get('channel', i)
                    device = config.get('device', 'Kvaser Interface')
                    
                    channel_text = f"Kvaser Ch{channel}: {device}"
                    available_channels.append(channel_text)
                    print(f"[HW]   - {channel_text}")
        except Exception as e:
            print(f"[HW] Kvaser scan error: {e}")
        
        # Add virtual channel options
        virtual_channels = ["Virtual: vcan0", "Virtual: vcan1", "Virtual: vcan2", "Virtual: vcan3"]
        for vchan in virtual_channels:
            available_channels.append(vchan)
        
        print(f"[HW] Found {len(found_interfaces)} interface types with {sum(count for _, count in found_interfaces)} total channels")
        
        if available_channels:
            # Sort channels by interface type for better organization
            def channel_sort_key(channel_text):
                if channel_text.startswith("Vector"):
                    return (0, channel_text)
                elif channel_text.startswith("PCAN"):
                    return (1, channel_text)
                elif channel_text.startswith("SocketCAN"):
                    return (2, channel_text)
                elif channel_text.startswith("IXXAT"):
                    return (3, channel_text)
                elif channel_text.startswith("Kvaser"):
                    return (4, channel_text)
                else:
                    return (5, channel_text)
            
            available_channels.sort(key=channel_sort_key)
            self.cmb_channel.addItems(available_channels)
            
            # Auto-select the first Vector interface if available, otherwise first available
            for i, channel_text in enumerate(available_channels):
                if channel_text.startswith("Vector"):
                    self.cmb_channel.setCurrentIndex(i + 1)  # +1 for "Auto-detect"
                    break
            
            print(f"[HW] Added {len(available_channels)} available channel(s) to dropdown")
        else:
            self.cmb_channel.addItem("Virtual: vcan0 (fallback)")
            print("[HW] No hardware interfaces found, using virtual fallback")
        
        # Update status label
        total_channels = sum(count for _, count in found_interfaces)
        if total_channels > 0:
            interface_types = ", ".join([f"{iftype}({count})" for iftype, count in found_interfaces])
            self.lbl_status.setText(f"🟢 Found {total_channels} channels on {interface_types}")
            self.lbl_status.setStyleSheet("color: #4CAF50; font-weight: bold;")

    def toggle_filter_mode(self):
        """Switch between ECU filter and Signal/Message filter"""
        is_ecu_filter = self.radio_filter_ecu.isChecked()
        
        # Show/hide appropriate controls
        self.cmb_filter.setEnabled(is_ecu_filter)
        self.lbl_filter.setEnabled(is_ecu_filter)
        
        # Enable/disable signal filter controls
        signal_filter_enabled = not is_ecu_filter
        self.list_signal_filter.setEnabled(signal_filter_enabled)
        self.btn_select_all.setEnabled(signal_filter_enabled)
        self.btn_clear_selection.setEnabled(signal_filter_enabled)
        self.edit_id_filter.setEnabled(signal_filter_enabled)
        self.edit_search.setEnabled(signal_filter_enabled)
        self.lbl_signal_filter.setEnabled(signal_filter_enabled)
        self.lbl_id_filter.setEnabled(signal_filter_enabled)
        self.lbl_search.setEnabled(signal_filter_enabled)

    def populate_node_filter(self):
        """Extract nodes from DBC and populate dropdown"""
        try:
            temp_db = cantools.database.Database()
            for f in self.db_files:
                try:
                    if f.lower().endswith('.cdd'):
                        continue  # Skip CDD files for node extraction
                    temp_db.add_dbc_file(f)
                except Exception as e:
                    print(f"[ERROR] Failed to load {os.path.basename(f)}: {e}")
                    continue
            
            nodes = sorted([node.name for node in temp_db.nodes])
            
            print(f"[DEBUG] Found Nodes: {nodes}")

            if nodes:
                self.cmb_filter.clear()
                self.cmb_filter.addItem("ALL")
                self.cmb_filter.addItems(nodes)
                self.cmb_filter.setEnabled(True)
                print(f"[UI] ECU Filter updated with {len(nodes)} ECUs")
            else:
                print("[WARNING] No Nodes (BU_) found in this DBC.")
                
        except Exception as e:
            print(f"[UI] Critical Error parsing nodes: {e}")

    def populate_signal_filter(self):
        """Extract all messages and signals from DBC for filtering"""
        try:
            temp_db = cantools.database.Database()
            for f in self.db_files:
                try:
                    if f.lower().endswith('.cdd'):
                        continue  # Skip CDD files for signal extraction
                    temp_db.add_dbc_file(f)
                except Exception as e:
                    print(f"[ERROR] Failed to load {os.path.basename(f)}: {e}")
                    continue
            
            # Clear existing lists
            self.available_messages = []
            self.available_signals = []
            self.list_signal_filter.clear()
            
            # Extract all messages
            for message in temp_db.messages:
                msg_id = message.frame_id
                msg_name = message.name
                self.available_messages.append((msg_id, msg_name))
                
                # Add message entry
                item_text = f"0x{msg_id:03X} - {msg_name} [MESSAGE]"
                self.list_signal_filter.addItem(item_text)
                
                # Extract all signals in this message
                for signal in message.signals:
                    signal_name = signal.name
                    self.available_signals.append((msg_name, signal_name))
                    
                    # Add signal entry
                    item_text = f"    └─ {signal_name} [SIGNAL]"
                    self.list_signal_filter.addItem(item_text)
            
            print(f"[UI] Signal Filter loaded: {len(self.available_messages)} messages, {len(self.available_signals)} signals")
            
        except Exception as e:
            print(f"[UI] Error loading signals: {e}")

    def filter_signal_list(self, text):
        """Filter the signal list based on search text"""
        search_text = text.lower()
        for i in range(self.list_signal_filter.count()):
            item = self.list_signal_filter.item(i)
            item_text = item.text().lower()
            item.setHidden(search_text not in item_text and search_text != "")

    def select_all_signals(self):
        """Select all items in the signal filter list"""
        for i in range(self.list_signal_filter.count()):
            item = self.list_signal_filter.item(i)
            if not item.isHidden():
                item.setSelected(True)

    def clear_signal_selection(self):
        """Clear all selections in the signal filter list"""
        self.list_signal_filter.clearSelection()

    def get_log(self):
        file, _ = QFileDialog.getOpenFileName(self, "Select CAN Log", "", "CAN Logs (*.asc *.blf *.log)")
        if file:
            self.log_file = file
            self.lbl_log_info.setText(f"Log: {os.path.basename(file)}")
            print(f"[UI] Selected log: {os.path.basename(file)}")

    def clear_all(self):
        self.db_files.clear()
        self.log_file = ""
        self.available_messages = []
        self.available_signals = []
        self.list_signal_filter.clear()
        self.edit_id_filter.clear()
        self.edit_search.clear()
        self.lbl_db_count.setText("Databases: 0")
        self.lbl_log_info.setText("Log: None selected")
        self.cmb_filter.clear()
        self.cmb_filter.addItems(["ALL"])
        self.console.clear()
        
        # Reset CDD parser
        self.cdd_parser = CDDParser()
        self.has_cdd_file = False
        self.lbl_cdd_status.setText("CDD: Not Loaded")
        self.lbl_cdd_status.setStyleSheet("color: #FF9800; font-weight: bold;")

    def on_print(self, text):
        self.console.moveCursor(QTextCursor.End)
        self.console.insertPlainText(text)
        self.console.ensureCursorVisible()

    def update_ui_stats(self):
        if self.can_engine and hasattr(self.can_engine, 'stats'):
            stats = self.can_engine.stats
            total = stats.get('total_messages', 1)
            processed = stats.get('processed', 0)
            
            if total > 0:
                pct = (processed / total) * 100
                self.prog.setValue(int(pct))
                
                if self.radio_replay.isChecked():
                    self.lbl_stats.setText(f"TX: {stats.get('sent',0)} | RX: {stats.get('received',0)}")
                else:
                    self.lbl_stats.setText(f"Parsed: {processed} / {total} messages | DIDs: {stats.get('dids_found',0)} | DTCs: {stats.get('dtcs_found',0)}")

    def execute(self):
        if not self.log_file:
            print("[ERROR] No log file selected!")
            return

        self.btn_run.setEnabled(False)
        self.btn_stop.setEnabled(True)
        self.btn_report.setEnabled(False)
        self.lbl_status.setText("🟡 Running...")
        self.lbl_status.setStyleSheet("color: #FF9800; font-weight: bold;")
        
        mode = AppMode.REPLAY if self.radio_replay.isChecked() else AppMode.PARSER
        
        # Get Options
        speed_map = {0: 1.0, 1: 0.5, 2: 0.2, 3: 0.0}
        speed = speed_map[self.cmb_speed.currentIndex()]
        
        # Diagnostic detection option
        detect_diagnostics = self.chk_detect_diag.isChecked()
        
        # Hardware parameters (for replay mode only)
        interface = self.cmb_interface.currentText() if self.radio_replay.isChecked() else "Virtual"
        channel = self.cmb_channel.currentText() if self.radio_replay.isChecked() else "Auto-detect"
        bitrate = self.cmb_bitrate.currentText() if self.radio_replay.isChecked() else "500 kbps"
        
        # Determine filter type and parameters
        if mode == AppMode.PARSER and self.radio_filter_signal.isChecked():
            # Signal/Message filter mode
            filter_type = "signal"
            
            # Get selected signals/messages from list
            selected_items = []
            for item in self.list_signal_filter.selectedItems():
                selected_items.append(item.text())
            
            # Parse manual ID filter
            manual_ids = []
            id_text = self.edit_id_filter.text().strip()
            if id_text:
                for id_str in id_text.split(','):
                    id_str = id_str.strip()
                    if id_str.startswith('0x'):
                        try:
                            manual_ids.append(int(id_str, 16))
                        except:
                            print(f"[WARNING] Invalid hex ID: {id_str}")
                    else:
                        try:
                            manual_ids.append(int(id_str))
                        except:
                            print(f"[WARNING] Invalid ID: {id_str}")
            
            filter_params = {
                'selected_items': selected_items,
                'manual_ids': manual_ids
            }
            filter_node = None
        else:
            # ECU filter mode (or replay mode)
            filter_type = "ecu"
            selected_filter = self.cmb_filter.currentText()
            filter_node = None if selected_filter == "ALL" else selected_filter
            filter_params = {}
        
        # Pass CDD parser to engine
        cdd_parser = self.cdd_parser if self.has_cdd_file else None
        
        self.worker_thread = threading.Thread(
            target=self.run_engine,
            args=(mode, speed, filter_node, filter_type, filter_params, detect_diagnostics, 
                  cdd_parser, interface, channel, bitrate),
            daemon=True
        )
        self.worker_thread.start()

    def run_engine(self, mode, speed, filter_node, filter_type, filter_params, detect_diagnostics, 
                   cdd_parser, interface="Vector", channel="Auto-detect", bitrate="500 kbps"):
        try:
            self.can_engine = CANLogEngine(
                self.db_files, 
                self.log_file,
                mode=mode,
                speed_factor=speed,
                monitor_responses=self.chk_responses.isChecked(),
                filter_node=filter_node,
                filter_type=filter_type,
                filter_params=filter_params,
                detect_diagnostics=detect_diagnostics,
                cdd_parser=cdd_parser,
                interface=interface,
                channel=channel,
                bitrate=bitrate
            )
            
            if mode == AppMode.REPLAY:
                self.can_engine.run_replay()
            else:
                self.can_engine.analyze_log()
            
            self.task_finished.emit(True)
            
        except Exception as e:
            print(f"[FATAL] Execution failed: {str(e)}")
            self.task_finished.emit(False)

    def finish_execution(self, success):
        # This function now runs safely on the Main Thread
        self.btn_run.setEnabled(True)
        self.btn_stop.setEnabled(False)
        self.btn_report.setEnabled(True)
        self.prog.setValue(100 if success else 0)
        
        if success:
            self.lbl_status.setText("🟢 Complete")
            self.lbl_status.setStyleSheet("color: #4CAF50; font-weight: bold;")
        else:
            self.lbl_status.setText("🔴 Failed")
            self.lbl_status.setStyleSheet("color: #F44336; font-weight: bold;")

    def stop_process(self):
        if self.can_engine:
            self.can_engine.stop()
            print("[UI] Stopping...")

    def open_report(self):
        if os.path.exists("can_report.html"):
            os.startfile("can_report.html")

# --- Logic Classes ---

class LogParser:
    @staticmethod
    def detect_format(log_file):
        ext = os.path.splitext(log_file)[1].lower()
        if ext == '.asc': return LogFormat.ASC
        if ext == '.blf': return LogFormat.BLF
        return LogFormat.UNKNOWN

    @staticmethod
    def parse_asc_line(line):
        parts = line.strip().split()
        if len(parts) < 6: return None
        if not ("CAN" in line or "Rx" in line or "Tx" in line): return None
        
        try:
            ts = float(parts[0])
            is_rx = 'Rx' in line
            
            try:
                channel = int(parts[2])
            except:
                channel = 1
                
            try:
                id_str = parts[5]
                if id_str.endswith('x'): id_str = id_str[:-1]
                msg_id = int(id_str, 16)
            except:
                return None

            try:
                dlc_idx = parts.index('d') + 1
                dlc = int(parts[dlc_idx])
                data_start = dlc_idx + 1
                hex_data = parts[data_start:data_start+dlc]
                data = bytearray([int(h, 16) for h in hex_data])
            except:
                return None

            return {
                'timestamp': ts,
                'channel': channel,
                'id': msg_id,
                'data': bytes(data),
                'dlc': dlc,
                'is_fd': 'CANFD' in line,
                'is_rx': is_rx
            }
        except:
            return None

# --- Updated CANLogEngine Class ---

class CANLogEngine:
    def __init__(self, db_files, log_file, mode=AppMode.REPLAY, speed_factor=1.0, 
                 monitor_responses=True, filter_node=None, filter_type="ecu", 
                 filter_params=None, detect_diagnostics=False, cdd_parser=None,
                 interface="Vector", channel="Auto-detect", bitrate="500 kbps"):
        self.db = cantools.database.Database()
        self.log_file = log_file
        self.mode = mode
        self.speed_factor = speed_factor
        self.monitor_responses = monitor_responses
        self.filter_node = filter_node
        self.filter_type = filter_type
        self.filter_params = filter_params or {}
        self.detect_diagnostics = detect_diagnostics
        self.cdd_parser = cdd_parser
        self.interface = interface
        self.channel = channel
        self.bitrate = bitrate
        self.buses = {}
        self.messages = []
        self.report_data = [] 
        self.diagnostic_data = []
        self.stop_event = threading.Event()
        
        # Channel-specific message tracking
        self.channel_messages = defaultdict(list)
        
        # Build message/signal mapping for filtering
        self.message_name_to_id = {}
        self.signal_to_message = {}
        
        self.stats = {
            "sent": 0, "received": 0, "processed": 0, "total_messages": 0,
            "start_time": 0, "end_time": 0, "dids_found": 0, "dtcs_found": 0,
            "channel_stats": defaultdict(lambda: {"sent": 0, "received": 0})
        }
        
        self.load_databases(db_files)
        self.parse_log()
        
        # Initialize generic detector
        self.generic_detector = GenericDiagDetector()

    def load_databases(self, db_files):
        for f in db_files:
            try:
                if f.lower().endswith('.cdd'):
                    continue  # CDD files are handled separately
                self.db.add_dbc_file(f)
                print(f"[DB] Loaded {os.path.basename(f)}")
            except Exception as e:
                print(f"[DB] Error loading {os.path.basename(f)}: {e}")
                continue
        
        # Build lookup dictionaries for efficient filtering
        try:
            for message in self.db.messages:
                msg_id = message.frame_id
                msg_name = message.name
                self.message_name_to_id[msg_name] = msg_id
                
                for signal in message.signals:
                    signal_name = signal.name
                    self.signal_to_message[signal_name] = msg_name
                    
        except Exception as e:
            print(f"[DB] Error building filter maps: {e}")

    def parse_log(self):
        print(f"[LOG] Parsing file: {self.log_file}")
        fmt = LogParser.detect_format(self.log_file)
        
        if fmt == LogFormat.BLF:
            try:
                log = can.BLFReader(self.log_file)
                for msg in log:
                    parsed_msg = {
                        'timestamp': msg.timestamp,
                        'channel': msg.channel if hasattr(msg, 'channel') else 0,
                        'id': msg.arbitration_id,
                        'data': msg.data,
                        'dlc': msg.dlc,
                        'is_fd': msg.is_fd,
                        'is_rx': msg.is_rx if hasattr(msg, 'is_rx') else False
                    }
                    self.messages.append(parsed_msg)
                    # Group messages by channel for multi-channel replay
                    self.channel_messages[parsed_msg['channel']].append(parsed_msg)
            except Exception as e:
                print(f"[LOG] BLF Parse Error: {e}")
        
        elif fmt == LogFormat.ASC:
            with open(self.log_file, 'r', encoding='utf-8', errors='ignore') as f:
                for line in f:
                    msg = LogParser.parse_asc_line(line)
                    if msg:
                        self.messages.append(msg)
                        # Group messages by channel for multi-channel replay
                        self.channel_messages[msg['channel']].append(msg)
        
        self.stats['total_messages'] = len(self.messages)
        print(f"[LOG] Parsed {len(self.messages)} messages across {len(self.channel_messages)} channels")
        for channel, msgs in self.channel_messages.items():
            print(f"[LOG] Channel {channel}: {len(msgs)} messages")

    def analyze_log(self):
        print(f"[PARSER] Analyzing Log Data...")
        
        if self.filter_type == "ecu":
            print(f"[PARSER] ECU Filter: {self.filter_node or 'ALL'}")
        else:
            selected_count = len(self.filter_params.get('selected_items', []))
            manual_ids_count = len(self.filter_params.get('manual_ids', []))
            print(f"[PARSER] Signal/Message Filter: {selected_count} items selected, {manual_ids_count} manual IDs")
        
        print(f"[DIAG] Diagnostic Detection: {'ENABLED' if self.detect_diagnostics else 'DISABLED'}")
        if self.cdd_parser and self.cdd_parser.is_loaded:
            print(f"[DIAG] CDD Database: {len(self.cdd_parser.dids)} DIDs, {len(self.cdd_parser.dtcs)} DTCs available")
        
        self.stats['start_time'] = time.time()
        self.stats['dids_found'] = 0  # Reset counters
        self.stats['dtcs_found'] = 0
        
        filtered_count = 0
        
        for i, msg in enumerate(self.messages):
            if self.stop_event.is_set(): 
                break
            
            # Apply filter based on filter type
            if self.filter_type == "ecu":
                if not self.check_node_filter(msg['id']):
                    self.stats['processed'] = i + 1
                    continue
            else:
                if not self.check_signal_filter(msg['id']):
                    self.stats['processed'] = i + 1
                    continue
            
            filtered_count += 1
            
            # Decode Signals
            decoded_signals = ""
            try:
                decoded = self.db.decode_message(msg['id'], msg['data'])
                decoded_signals = ", ".join([f"{k}: {v}" for k,v in decoded.items()])
            except:
                decoded_signals = "-"
            
            # Detect diagnostics if enabled
            diag_info = ""
            has_diagnostics = False
            if self.detect_diagnostics:
                diag_findings = self.analyze_for_diagnostics(msg)
                if diag_findings:
                    diag_info = self.format_diagnostic_info(diag_findings)
                    has_diagnostics = True
            
            # Combine decoded signals and diagnostic info
            extra_info = decoded_signals
            if diag_info:
                extra_info = f"{decoded_signals} | {diag_info}" if decoded_signals != "-" else diag_info
            
            direction = "RX" if msg.get('is_rx', False) else "TX"
            
            self.report_data.append({
                'ts': msg['timestamp'],
                'channel': msg.get('channel', 0),
                'id': msg['id'],
                'dir': direction,
                'data': msg['data'].hex().upper(),
                'name': self.get_msg_name(msg['id']),
                'extra': extra_info,
                'has_diagnostics': has_diagnostics
            })
            
            self.stats['processed'] = i + 1
            if i % 2000 == 0:
                time.sleep(0.001)
        
        print(f"[PARSER] Found {filtered_count} messages matching filter.")
        print(f"[DIAG] Total DIDs found: {self.stats['dids_found']}")
        print(f"[DIAG] Total DTCs found: {self.stats['dtcs_found']}")
        
        self.stats['end_time'] = time.time()
        self.generate_report()

    def analyze_for_diagnostics(self, message):
        """Analyze message for diagnostic content with improved CDD matching"""
        findings = []
        
        # Get data bytes as list for easier processing
        data_bytes = list(message['data'])
        
        # Check if message is likely diagnostic
        is_diag_message = self.generic_detector.is_diagnostic_message(message['id'])
        
        # Also check if data indicates diagnostic content (UDS services)
        if len(data_bytes) >= 1:
            service_id = data_bytes[0]
            is_uds_service = service_id in [
                0x10, 0x11, 0x14, 0x19, 0x22, 0x23, 0x27, 0x28,
                0x2E, 0x2F, 0x31, 0x34, 0x35, 0x36, 0x37, 0x3E, 0x85
            ]
            
            if is_diag_message or is_uds_service:
                print(f"[DIAG DEBUG] Analyzing diagnostic message: ID=0x{message['id']:X}, Service=0x{service_id:02X}")
                
                # Detect DIDs
                did_findings = self.generic_detector.detect_did_in_data(data_bytes)
                for did_finding in did_findings:
                    did_value = did_finding['value']
                    
                    # ONLY count if we have CDD database info and it matches
                    if self.cdd_parser and self.cdd_parser.is_loaded:
                        cdd_info = self.cdd_parser.find_did(did_value)
                        if cdd_info:
                            # Found in CDD - valid DID
                            finding = {
                                'type': 'DID',
                                'value': did_value,
                                'confidence': 'CDD_MATCH',
                                'service': did_finding['service'],
                                'source': 'CDD',
                                'info': cdd_info
                            }
                            
                            findings.append(finding)
                            self.stats['dids_found'] += 1
                            print(f"[DIAG] Found DID in CDD: 0x{did_value:04X} - {cdd_info['name']}")
                        else:
                            # DID not in CDD - don't count it
                            print(f"[DIAG] DID 0x{did_value:04X} not found in loaded CDD")
                    else:
                        # No CDD loaded - use generic detection
                        finding = {
                            'type': 'DID',
                            'value': did_value,
                            'confidence': did_finding['confidence'],
                            'service': did_finding['service'],
                            'source': 'Generic',
                            'info': did_finding
                        }
                        
                        findings.append(finding)
                        self.stats['dids_found'] += 1
                        print(f"[DIAG] Found DID (generic): 0x{did_value:04X}")
                
                # Detect DTCs
                dtc_findings = self.generic_detector.detect_dtc_in_data(data_bytes)
                for dtc_finding in dtc_findings:
                    dtc_value = dtc_finding['value']
                    
                    # ONLY count if we have CDD database info and it matches
                    if self.cdd_parser and self.cdd_parser.is_loaded:
                        cdd_info = self.cdd_parser.find_dtc(dtc_value)
                        if cdd_info:
                            # Found in CDD - valid DTC
                            finding = {
                                'type': 'DTC',
                                'value': dtc_value,
                                'confidence': 'CDD_MATCH',
                                'service': dtc_finding['service'],
                                'source': 'CDD',
                                'info': cdd_info
                            }
                            
                            findings.append(finding)
                            self.stats['dtcs_found'] += 1
                            print(f"[DIAG] Found DTC in CDD: 0x{dtc_value:04X} - {cdd_info['name']}")
                        else:
                            # DTC not in CDD - don't count it
                            print(f"[DIAG] DTC 0x{dtc_value:04X} not found in loaded CDD")
                    else:
                        # No CDD loaded - use generic detection
                        finding = {
                            'type': 'DTC',
                            'value': dtc_value,
                            'confidence': dtc_finding['confidence'],
                            'service': dtc_finding['service'],
                            'source': 'Generic',
                            'info': dtc_finding
                        }
                        
                        findings.append(finding)
                        self.stats['dtcs_found'] += 1
                        print(f"[DIAG] Found DTC (generic): 0x{dtc_value:04X}")
                
                # Detect Security Access (always count, not specific to CDD)
                security_findings = self.generic_detector.detect_security_access(data_bytes)
                for security_finding in security_findings:
                    finding = {
                        'type': 'SECURITY',
                        'service': security_finding['service'],
                        'info': security_finding
                    }
                    findings.append(finding)
        
        return findings

    def format_diagnostic_info(self, findings):
        """Format diagnostic findings for display"""
        formatted = []
        
        for finding in findings:
            if finding['type'] == 'DID':
                if finding['source'] == 'CDD':
                    info = finding['info']
                    did_type_str = info['type'].value if hasattr(info['type'], 'value') else str(info['type'])
                    formatted.append(f"📊 DID 0x{finding['value']:04X} ({info['name']}) - {did_type_str}")
                else:
                    info = finding['info']
                    formatted.append(f"🔍 DID 0x{finding['value']:04X} - {info['service']} ({info['confidence']})")
            
            elif finding['type'] == 'DTC':
                if finding['source'] == 'CDD':
                    info = finding['info']
                    formatted.append(f"⚠️ DTC 0x{finding['value']:04X} ({info['name']}) - Severity: {info['severity']}")
                else:
                    info = finding['info']
                    formatted.append(f"⚠️ DTC 0x{finding['value']:04X} - {info['service']} ({info['confidence']})")
            
            elif finding['type'] == 'SECURITY':
                info = finding['info']
                formatted.append(f"🔐 {info['type']} - Level {info.get('level', 'N/A')}")
        
        return " | ".join(formatted) if formatted else ""

    def check_node_filter(self, msg_id):
        """Check if message is relevant to the selected ECU (Sender or Receiver)"""
        if not self.filter_node:
            return True
        
        try:
            message_def = self.db.get_message_by_frame_id(msg_id)
            
            # Check 1: Is the ECU the sender?
            if self.filter_node in message_def.senders:
                return True
                
            # Check 2: Is the ECU a receiver of any signal in this message?
            for signal in message_def.signals:
                if self.filter_node in signal.receivers:
                    return True
                    
            return False
        except KeyError:
            # If message is not in DBC, we can't filter by node. Exclude it if filter is active.
            return False

    def check_signal_filter(self, msg_id):
        """Check if message passes signal/message filter criteria"""
        if self.filter_type != "signal":
            return True
            
        selected_items = self.filter_params.get('selected_items', [])
        manual_ids = self.filter_params.get('manual_ids', [])
        
        # If nothing is selected and no manual IDs, show everything
        if not selected_items and not manual_ids:
            return True
            
        # Check manual IDs first
        if msg_id in manual_ids:
            return True
            
        # Check selected items from list
        try:
            msg_name = self.db.get_message_by_frame_id(msg_id).name
            
            # Check if message itself is selected
            for item_text in selected_items:
                if f"0x{msg_id:03X} - {msg_name} [MESSAGE]" in item_text:
                    return True
                    
            # Check if any signal in this message is selected
            for item_text in selected_items:
                # Extract signal name from item text
                if "[SIGNAL]" in item_text:
                    # Format is "    └─ SignalName [SIGNAL]"
                    signal_name = item_text.split("└─ ")[1].split(" [SIGNAL]")[0].strip()
                    if signal_name in self.signal_to_message:
                        if self.signal_to_message[signal_name] == msg_name:
                            return True
                            
        except KeyError:
            # Message not in DBC
            pass
            
        return False

    def get_msg_name(self, msg_id):
        try:
            return self.db.get_message_by_frame_id(msg_id).name
        except:
            return f"0x{msg_id:X}"

    def determine_replay_channels(self):
        """Determine which channels to replay based on selection and log content"""
        channels_to_replay = []
        
        # Parse channel selection
        selected_channel = self.channel
        
        if "Auto-detect" in selected_channel:
            # Replay on all channels found in log
            for channel_num, messages in self.channel_messages.items():
                if messages:
                    channels_to_replay.append({
                        'channel_num': channel_num,
                        'messages': messages,
                        'channel_name': f"Log Channel {channel_num}"
                    })
            print(f"[REPLAY] Auto-detect: Will replay on {len(channels_to_replay)} channels from log")
        else:
            # User selected specific channel - parse it intelligently
            channel_num = self.parse_channel_selection(selected_channel)
            
            # Get messages for this channel
            messages = self.channel_messages.get(channel_num, [])
            if not messages:
                # If no messages for this channel, use all messages
                messages = self.messages
                print(f"[REPLAY] No messages found for channel {channel_num} in log, using all {len(messages)} messages")
            
            channels_to_replay.append({
                'channel_num': channel_num,
                'messages': messages,
                'channel_name': selected_channel
            })
        
        return channels_to_replay

    def parse_channel_selection(self, channel_text):
        """Parse channel selection string to extract channel number"""
        # Default channel
        channel_num = 0
        
        try:
            # Remove "Virtual: " prefix if present
            channel_text_clean = channel_text.replace("Virtual: ", "")
            
            # Check for Vector format: "Vector Ch1: VN1630 (VN1640, S/N: 12345)"
            if "Vector Ch" in channel_text_clean:
                # Extract the number after "Ch"
                match = re.search(r'Ch(\d+)', channel_text_clean)
                if match:
                    channel_num = int(match.group(1))
                    # Note: For Vector interfaces, channel numbers can be 0, 2, 3, etc.
                    # We'll keep them as-is since they're already hardware channel numbers
            
            # Check for PCAN format: "PCAN Ch0: PCAN-USB (OK)"
            elif "PCAN Ch" in channel_text_clean:
                match = re.search(r'Ch(\d+)', channel_text_clean)
                if match:
                    channel_num = int(match.group(1))
            
            # Check for simple format: "Channel 2"
            elif "Channel" in channel_text_clean:
                match = re.search(r'Channel\s+(\d+)', channel_text_clean)
                if match:
                    channel_num = int(match.group(1)) - 1  # Convert to 0-indexed
            
            # Check for SocketCAN format: "SocketCAN: can0 (UP)"
            elif "SocketCAN:" in channel_text_clean:
                match = re.search(r'can(\d+)', channel_text_clean)
                if match:
                    channel_num = int(match.group(1))
            
            # Check for virtual format: "vcan0"
            elif channel_text_clean.startswith("vcan"):
                match = re.search(r'vcan(\d+)', channel_text_clean)
                if match:
                    channel_num = int(match.group(1))
            
            print(f"[REPLAY] Parsed channel '{channel_text}' as channel number {channel_num}")
            
        except Exception as e:
            print(f"[REPLAY] Error parsing channel selection '{channel_text}': {e}. Using channel 0.")
        
        return channel_num

    def initialize_can_bus(self, channel_info, bitrate_value):
        """Initialize CAN bus for a specific channel"""
        channel_num = channel_info['channel_num']
        channel_name = channel_info.get('channel_name', f"Channel {channel_num}")
        
        print(f"[HW] Initializing {channel_name}...")
        
        # Determine interface type from channel name
        interface_lower = self.interface.lower()
        selected_channel = self.channel
        
        # If user selected a specific channel type, use that interface
        if "Vector" in selected_channel:
            interface_lower = 'vector'
        elif "PCAN" in selected_channel:
            interface_lower = 'pcan'
        elif "SocketCAN" in selected_channel:
            interface_lower = 'socketcan'
        elif "IXXAT" in selected_channel:
            interface_lower = 'ixxat'
        elif "Kvaser" in selected_channel:
            interface_lower = 'kvaser'
        elif "Virtual" in selected_channel:
            interface_lower = 'virtual'
        
        bus_config = {
            'fd': True,
        }
        
        if bitrate_value:
            bus_config['bitrate'] = bitrate_value
        
        try:
            if interface_lower == 'vector':
                bus_config['interface'] = 'vector'
                bus_config['channel'] = channel_num
                
                # Try to get more specific config for this channel
                try:
                    configs = can.detect_available_configs(interfaces=['vector'])
                    if configs and channel_num < len(configs):
                        # Try to find the specific channel
                        for config in configs:
                            if config.get('channel') == channel_num:
                                bus_config.update(config)
                                break
                except:
                    pass
                
                bus = can.Bus(**bus_config)
                print(f"[HW] Initialized Vector channel {channel_num} successfully")
                return bus
                
            elif interface_lower == 'pcan':
                bus_config['interface'] = 'pcan'
                # PCAN channel numbering can be different
                bus_config['channel'] = f'PCAN_USBBUS{channel_num}'
                
                bus = can.Bus(**bus_config)
                print(f"[HW] Initialized PCAN channel {channel_num} successfully")
                return bus
                
            elif interface_lower == 'socketcan':
                bus_config['interface'] = 'socketcan'
                bus_config['channel'] = f'can{channel_num}'
                
                bus = can.Bus(**bus_config)
                print(f"[HW] Initialized SocketCAN channel can{channel_num} successfully")
                return bus
                
            elif interface_lower in ['ixxat', 'kvaser']:
                bus_config['interface'] = interface_lower
                bus_config['channel'] = channel_num
                
                bus = can.Bus(**bus_config)
                print(f"[HW] Initialized {interface_lower} channel {channel_num} successfully")
                return bus
                
        except Exception as e:
            print(f"[HW] {interface_lower.upper()} initialization failed: {e}")
        
        # Fallback to virtual
        print(f"[HW] Using virtual interface as fallback for {channel_name}")
        return can.ThreadSafeBus(interface='virtual', channel=f'vcan{channel_num}', fd=True)

    def replay_channel_messages(self, channel_num, messages):
        """Replay messages on a specific channel"""
        bus = self.buses.get(channel_num)
        if not bus:
            print(f"[REPLAY] No bus available for channel {channel_num}")
            return
        
        print(f"[REPLAY Channel {channel_num}] Starting replay of {len(messages)} messages")
        
        if not messages:
            return
        
        start_ts = messages[0]['timestamp']
        
        for i, msg in enumerate(messages):
            if self.stop_event.is_set():
                break
            
            # Calculate delay
            if i > 0:
                prev_ts = messages[i-1]['timestamp']
                curr_ts = msg['timestamp']
                delay = (curr_ts - prev_ts) * self.speed_factor
                if delay > 0 and delay < 1.0:
                    time.sleep(delay)
            
            # Analyze for diagnostics
            diag_info = ""
            has_diagnostics = False
            
            if self.detect_diagnostics:
                diag_findings = self.analyze_for_diagnostics(msg)
                if diag_findings:
                    diag_info = self.format_diagnostic_info(diag_findings)
                    has_diagnostics = True
            
            # Try to decode signals
            decoded_signals = ""
            try:
                decoded = self.db.decode_message(msg['id'], msg['data'])
                decoded_signals = ", ".join([f"{k}: {v}" for k,v in decoded.items()])
            except:
                decoded_signals = "-"
            
            extra_info = decoded_signals
            if diag_info:
                extra_info = f"{decoded_signals} | {diag_info}" if decoded_signals != "-" else diag_info
            
            # Send message
            try:
                can_msg = can.Message(
                    arbitration_id=msg['id'],
                    data=msg['data'],
                    is_fd=msg['is_fd'],
                    is_extended_id=msg['id'] > 0x7FF,
                    channel=channel_num
                )
                bus.send(can_msg)
                self.stats['sent'] += 1
                self.stats['channel_stats'][channel_num]['sent'] += 1
                
                direction = "RX" if msg.get('is_rx', False) else "TX"
                
                self.report_data.append({
                    'ts': time.time() - self.stats['start_time'],
                    'channel': channel_num,
                    'id': msg['id'],
                    'dir': direction,
                    'data': msg['data'].hex().upper(),
                    'name': self.get_msg_name(msg['id']),
                    'extra': f"Ch{channel_num}: {extra_info}",
                    'has_diagnostics': has_diagnostics
                })
                
            except Exception as e:
                print(f"[REPLAY Channel {channel_num}] Send error: {e}")
                direction = "RX" if msg.get('is_rx', False) else "TX"
                self.report_data.append({
                    'ts': time.time() - self.stats['start_time'],
                    'channel': channel_num,
                    'id': msg['id'],
                    'dir': direction,
                    'data': msg['data'].hex().upper(),
                    'name': self.get_msg_name(msg['id']),
                    'extra': f"Ch{channel_num}: Send Failed: {e}",
                    'has_diagnostics': has_diagnostics
                })
            
            self.stats['processed'] = i + 1
            if i % 1000 == 0:
                print(f"[REPLAY Channel {channel_num}] Progress: {i}/{len(messages)} messages")
        
        print(f"[REPLAY Channel {channel_num}] Replay complete")

    def rx_listener(self, bus, channel_num):
        """Listen for responses on a specific channel"""
        print(f"[RX Channel {channel_num}] Starting response listener")
        
        while not self.stop_event.is_set() and bus:
            try:
                msg = bus.recv(0.1)
                if msg:
                    # Analyze received message
                    diag_info = ""
                    has_diagnostics = False
                    
                    if self.detect_diagnostics:
                        msg_dict = {
                            'timestamp': time.time() - self.stats['start_time'],
                            'id': msg.arbitration_id,
                            'data': msg.data,
                            'dlc': msg.dlc,
                            'is_fd': msg.is_fd,
                            'is_rx': True,
                            'channel': channel_num
                        }
                        
                        diag_findings = self.analyze_for_diagnostics(msg_dict)
                        if diag_findings:
                            diag_info = self.format_diagnostic_info(diag_findings)
                            has_diagnostics = True
                    
                    # Decode signals
                    decoded_signals = ""
                    try:
                        decoded = self.db.decode_message(msg.arbitration_id, msg.data)
                        decoded_signals = ", ".join([f"{k}: {v}" for k,v in decoded.items()])
                    except:
                        decoded_signals = "-"
                    
                    extra_info = decoded_signals
                    if diag_info:
                        extra_info = f"{decoded_signals} | {diag_info}" if decoded_signals != "-" else diag_info
                    
                    self.stats['received'] += 1
                    self.stats['channel_stats'][channel_num]['received'] += 1
                    
                    self.report_data.append({
                        'ts': time.time() - self.stats['start_time'],
                        'channel': channel_num,
                        'id': msg.arbitration_id,
                        'dir': 'RX',
                        'data': msg.data.hex().upper(),
                        'name': self.get_msg_name(msg.arbitration_id),
                        'extra': f"Ch{channel_num}: Response - {extra_info}",
                        'has_diagnostics': has_diagnostics
                    })
                    
            except Exception as e:
                if not self.stop_event.is_set():
                    print(f"[RX Channel {channel_num}] Error: {e}")

    def run_replay(self):
        print("[REPLAY] Starting Hardware Replay...")
        print(f"[REPLAY] Interface: {self.interface}, Selected Channel: {self.channel}, Bitrate: {self.bitrate}")
        
        # Debug: Show what's in channel_messages
        print(f"[DEBUG] Messages by channel:")
        for channel_num, messages in self.channel_messages.items():
            print(f"  Channel {channel_num}: {len(messages)} messages")
            if messages:
                # Show first few message IDs
                first_ids = [f"0x{msg['id']:X}" for msg in messages[:3]]
                print(f"    First messages: {', '.join(first_ids)}{'...' if len(messages) > 3 else ''}")
        
        self.stats['start_time'] = time.time()
        self.stats['dids_found'] = 0
        self.stats['dtcs_found'] = 0
        
        # Parse bitrate
        bitrate_map = {
            "500 kbps": 500000,
            "250 kbps": 250000,
            "125 kbps": 125000,
            "1 Mbps": 1000000,
            "2 Mbps": 2000000,
            "5 Mbps": 5000000,
            "Auto": None
        }
        bitrate_value = bitrate_map.get(self.bitrate, 500000)
        
        # Determine which channels to replay
        channels_to_replay = self.determine_replay_channels()
        
        # Initialize CAN buses for each channel
        for channel_info in channels_to_replay:
            channel_num = channel_info['channel_num']
            try:
                bus = self.initialize_can_bus(channel_info, bitrate_value)
                if bus:
                    self.buses[channel_num] = bus
                    print(f"[HW] Initialized channel {channel_num} successfully")
            except Exception as e:
                print(f"[HW] Failed to initialize channel {channel_num}: {e}")
        
        if not self.buses:
            print("[HW] No buses initialized, using virtual fallback")
            self.buses[0] = can.ThreadSafeBus(interface='virtual', channel='vcan0', fd=True)
            channels_to_replay = [{'channel_num': 0, 'messages': self.messages}]

        # Start response listeners if enabled
        if self.monitor_responses:
            for channel_num, bus in self.buses.items():
                t = threading.Thread(target=self.rx_listener, args=(bus, channel_num), daemon=True)
                t.start()

        # Start replay threads for each channel
        replay_threads = []
        for channel_info in channels_to_replay:
            channel_num = channel_info['channel_num']
            messages = channel_info['messages']
            
            if channel_num in self.buses and messages:
                print(f"[REPLAY] Starting replay on channel {channel_num} ({len(messages)} messages)")
                thread = threading.Thread(
                    target=self.replay_channel_messages,
                    args=(channel_num, messages),
                    daemon=True
                )
                replay_threads.append(thread)
                thread.start()

        # Wait for all replay threads to complete
        for thread in replay_threads:
            thread.join()

        self.stop_event.set()
        self.stats['end_time'] = time.time()
        
        # Print statistics
        self.print_replay_statistics()
        self.generate_report()

    def print_replay_statistics(self):
        """Print detailed replay statistics"""
        print("\n" + "="*50)
        print("REPLAY STATISTICS")
        print("="*50)
        print(f"Total Messages Processed: {self.stats['processed']}")
        print(f"Total Messages Sent: {self.stats['sent']}")
        print(f"Total Responses Received: {self.stats['received']}")
        print(f"Total DIDs Found: {self.stats['dids_found']}")
        print(f"Total DTCs Found: {self.stats['dtcs_found']}")
        
        if self.stats['channel_stats']:
            print("\nChannel Statistics:")
            for channel_num, stats in self.stats['channel_stats'].items():
                print(f"  Channel {channel_num}: Sent={stats['sent']}, Received={stats['received']}")
        
        duration = self.stats['end_time'] - self.stats['start_time']
        print(f"\nTotal Duration: {duration:.2f} seconds")
        if duration > 0:
            print(f"Average Rate: {self.stats['processed']/duration:.1f} messages/second")
        print("="*50)

    def generate_report(self):
        is_replay = self.mode == AppMode.REPLAY
        title = "Live Replay Report" if is_replay else "Log Analysis Report"
        
        # Build filter info for report
        if self.filter_type == "ecu":
            filter_info = f"ECU Filter: {self.filter_node}" if self.filter_node else "Filter: ALL ECUs"
        else:
            selected_count = len(self.filter_params.get('selected_items', []))
            manual_ids = self.filter_params.get('manual_ids', [])
            filter_info = f"Signal/Message Filter: {selected_count} items"
            if manual_ids:
                filter_info += f", {len(manual_ids)} manual IDs"
        
        # Diagnostic detection info
        diag_info = ""
        if self.detect_diagnostics:
            diag_info = f"<strong>Diagnostic Detection: ENABLED</strong><br>"
            diag_info += f"DIDs Found: {self.stats['dids_found']} | DTCs Found: {self.stats['dtcs_found']}<br>"
            if self.cdd_parser and self.cdd_parser.is_loaded:
                diag_info += f"CDD Database: {len(self.cdd_parser.dids)} DIDs, {len(self.cdd_parser.dtcs)} DTCs available"
            else:
                diag_info += "CDD Database: Not available (using generic detection)"
        
        # Replay hardware info
        replay_info = ""
        if is_replay:
            replay_info = f"<strong>Replay Configuration:</strong><br>"
            replay_info += f"Interface: {self.interface} | Channel: {self.channel} | Bitrate: {self.bitrate}<br>"
        
        extra_col_name = "Decoded Signals & Diagnostics"
        
        html = f"""
        <html>
        <head>
            <style>
                body {{ font-family: 'Segoe UI', sans-serif; margin: 20px; background: #f4f4f9; }}
                .container {{ background: white; padding: 20px; border-radius: 8px; box-shadow: 0 2px 5px rgba(0,0,0,0.1); }}
                h1 {{ color: #2c3e50; border-bottom: 2px solid #3498db; padding-bottom: 10px; }}
                table {{ width: 100%; border-collapse: collapse; margin-top: 20px; font-size: 14px; table-layout: fixed; }}
                th {{ background: #2c3e50; color: white; padding: 12px; text-align: left; }}
                td {{ padding: 8px 12px; border-bottom: 1px solid #eee; word-wrap: break-word; }}
                tr:nth-child(even) {{ background-color: #f8f9fa; }}
                tr.diag-row {{ background-color: #fff3cd !important; border-left: 3px solid #ffc107; }}
                .tx {{ color: #d35400; font-weight: bold; }}
                .rx {{ color: #27ae60; font-weight: bold; }}
                .badge {{ background: #e1e1e1; padding: 2px 6px; border-radius: 4px; font-size: 0.9em; font-family: monospace; }}
                .diag-badge {{ background: #ffc107; color: #856404; font-weight: bold; }}
                .info-box {{ background: #e8f4f8; padding: 10px; border-left: 4px solid #3498db; margin-bottom: 20px; }}
                .diag-box {{ background: #fff3cd; padding: 10px; border-left: 4px solid #ffc107; margin-top: 10px; }}
                .legend {{ margin-top: 20px; padding: 10px; background: #f8f9fa; border-radius: 5px; }}
                .legend-item {{ display: inline-block; margin-right: 20px; }}
                .legend-color {{ width: 20px; height: 20px; display: inline-block; margin-right: 5px; vertical-align: middle; }}
            </style>
        </head>
        <body>
            <div class="container">
                <h1>{title}</h1>
                <div class="info-box">
                    <strong>File:</strong> {os.path.basename(self.log_file)} <br>
                    <strong>Total Messages in Log:</strong> {len(self.messages)} <br>
                    <strong>Visible Messages:</strong> {len(self.report_data)} <br>
                    <strong>{filter_info}</strong>
                    {f'<br>{replay_info}' if replay_info else ''}
                    {f'<br>{diag_info}' if diag_info else ''}
                </div>
                
                {self._generate_diagnostic_summary()}
                
                <div class="legend">
                    <strong>Legend:</strong>
                    <span class="legend-item"><span class="legend-color" style="background-color: #fff3cd;"></span> Diagnostic Message</span>
                    <span class="legend-item"><span class="legend-color" style="background-color: #d4edda;"></span> DTC Found</span>
                    <span class="legend-item"><span class="legend-color" style="background-color: #cce5ff;"></span> DID Found</span>
                    <span class="legend-item"><span class="legend-color" style="background-color: #d35400;"></span> TX Message</span>
                    <span class="legend-item"><span class="legend-color" style="background-color: #27ae60;"></span> RX Message</span>
                </div>
                
                <table>
                    <thead>
                        <tr>
                            <th width="5%">Ch</th>
                            <th width="8%">Time</th>
                            <th width="5%">Dir</th>
                            <th width="10%">ID</th>
                            <th width="15%">Name</th>
                            <th width="15%">Data</th>
                            <th width="42%">{extra_col_name}</th>
                        </tr>
                    </thead>
                    <tbody>
        """
        
        # Display up to 10000 rows max to keep browser responsive
        limit = 10000
        data_to_show = self.report_data[:limit]
        
        for row in data_to_show:
            dir_class = "rx" if row['dir'] == "RX" else "tx"
            
            # Add special class for diagnostic messages
            row_class = "diag-row" if row.get('has_diagnostics', False) else ""
            
            html += f"""
                <tr class="{row_class}">
                    <td>Ch{row.get('channel', 0)}</td>
                    <td>{row['ts']:.4f}</td>
                    <td class="{dir_class}">{row['dir']}</td>
                    <td>{hex(row['id'])}</td>
                    <td>{row['name']}</td>
                    <td><span class="badge">{row['data']}</span></td>
                    <td style="font-size:0.9em; color:#555;">{row['extra']}</td>
                </tr>
            """
            
        if len(self.report_data) > limit:
             html += f"<tr><td colspan='7' style='text-align:center; padding:20px;'><strong>... {len(self.report_data) - limit} more messages hidden ...</strong></td></tr>"

        html += """
                    </tbody>
                </table>
            </div>
        </body>
        </html>
        """
        
        with open("can_report.html", "w", encoding='utf-8') as f:
            f.write(html)
        print(f"[REPORT] Generated 'can_report.html'.")

    def _generate_diagnostic_summary(self):
        """Generate diagnostic findings summary"""
        if not self.detect_diagnostics or (self.stats['dids_found'] == 0 and self.stats['dtcs_found'] == 0):
            return ""
        
        # Collect unique diagnostic findings from report data
        unique_dids = {}
        unique_dtcs = {}
        
        for row in self.report_data:
            if row.get('has_diagnostics', False):
                extra = row['extra']
                
                # Extract DID information with name
                did_matches = re.findall(r'DID 0x([0-9A-F]{4})\s*\(([^)]+)\)', extra, re.IGNORECASE)
                for did_hex, did_name in did_matches:
                    unique_dids[did_hex] = did_name
                
                # Extract DIDs without names
                did_matches_simple = re.findall(r'DID 0x([0-9A-F]{4})', extra, re.IGNORECASE)
                for did_hex in did_matches_simple:
                    if did_hex not in unique_dids:
                        unique_dids[did_hex] = f"DID_0x{did_hex}"
                
                # Extract DTC information with name
                dtc_matches = re.findall(r'DTC 0x([0-9A-F]{4})\s*\(([^)]+)\)', extra, re.IGNORECASE)
                for dtc_hex, dtc_name in dtc_matches:
                    unique_dtcs[dtc_hex] = dtc_name
                
                # Extract DTCs without names
                dtc_matches_simple = re.findall(r'DTC 0x([0-9A-F]{4})', extra, re.IGNORECASE)
                for dtc_hex in dtc_matches_simple:
                    if dtc_hex not in unique_dtcs:
                        unique_dtcs[dtc_hex] = f"DTC_0x{dtc_hex}"
        
        summary_html = f"""
        <div class="diag-box">
            <h3 style="margin-top: 0; color: #856404;">Diagnostic Findings Summary</h3>
            <strong>Total Diagnostic Messages Found:</strong> {self.stats['dids_found'] + self.stats['dtcs_found']}<br>
            <strong>Unique DIDs:</strong> {len(unique_dids)}<br>
            <strong>Unique DTCs:</strong> {len(unique_dtcs)}<br>
        """
        
        if unique_dids:
            summary_html += "<br><strong>Detected DIDs:</strong><br>"
            for did_hex, did_name in sorted(unique_dids.items()):
                # Try to get more info from CDD if available
                if self.cdd_parser and self.cdd_parser.is_loaded:
                    did_int = int(did_hex, 16)
                    cdd_info = self.cdd_parser.find_did(did_int)
                    if cdd_info:
                        did_type_str = cdd_info['type'].value if hasattr(cdd_info['type'], 'value') else str(cdd_info['type'])
                        summary_html += f"&nbsp;&nbsp;• 0x{did_hex} - {cdd_info['name']} ({did_type_str})<br>"
                    else:
                        summary_html += f"&nbsp;&nbsp;• 0x{did_hex} - {did_name}<br>"
                else:
                    summary_html += f"&nbsp;&nbsp;• 0x{did_hex} - {did_name}<br>"
        
        if unique_dtcs:
            summary_html += "<br><strong>Detected DTCs:</strong><br>"
            for dtc_hex, dtc_name in sorted(unique_dtcs.items()):
                # Try to get more info from CDD if available
                if self.cdd_parser and self.cdd_parser.is_loaded:
                    dtc_int = int(dtc_hex, 16)
                    cdd_info = self.cdd_parser.find_dtc(dtc_int)
                    if cdd_info:
                        summary_html += f"&nbsp;&nbsp;• 0x{dtc_hex} - {cdd_info['name']} (Severity: {cdd_info['severity']})<br>"
                    else:
                        summary_html += f"&nbsp;&nbsp;• 0x{dtc_hex} - {dtc_name}<br>"
                else:
                    summary_html += f"&nbsp;&nbsp;• 0x{dtc_hex} - {dtc_name}<br>"
        
        summary_html += "</div>"
        return summary_html

    def stop(self):
        self.stop_event.set()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MagnaDebugApp()
    window.show()
    sys.exit(app.exec())