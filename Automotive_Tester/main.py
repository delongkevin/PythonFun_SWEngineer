#!/usr/bin/env python3
"""
Automotive ECU Tester - Main Entry Point
Interfaces: Trace32/Lauterbach, BK Precision 1687B Power Supply, USB Camera, Serial COM Ports
"""

import sys
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from ui.app import AutomotiveTesterApp

if __name__ == "__main__":
    app = AutomotiveTesterApp()
    app.run()
