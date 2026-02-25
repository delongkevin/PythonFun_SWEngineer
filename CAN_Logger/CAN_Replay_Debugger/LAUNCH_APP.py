import sys
import os
import subprocess
import traceback

def main():
    try:
        # Check dependencies
        from PySide6.QtWidgets import QApplication
        import can
        import cantools
        
        # Import main app
        from can_replay_monitor import MagnaDebugApp
        
        # Launch app
        app = QApplication(sys.argv)
        window = MagnaDebugApp()
        window.show()
        sys.exit(app.exec())
        
    except ImportError as e:
        print(f"ERROR: {e}")
        print("\nPlease install dependencies first:")
        print("pip install PySide6 python-can cantools")
        
        # Try to run installer
        if os.path.exists("Install_Dependencies.bat"):
            subprocess.run(["Install_Dependencies.bat"], shell=True)
        else:
            input("\nPress Enter to exit...")
        sys.exit(1)

if __name__ == "__main__":
    main()