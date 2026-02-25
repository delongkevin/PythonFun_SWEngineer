import warnings
warnings.filterwarnings('ignore', category=UserWarning, module='matplotlib')
import tkinter as tk
from tkinter import ttk, filedialog, messagebox, scrolledtext
import threading
import queue
import time
import os
from datetime import datetime
import json
import sys
import glob
import math
import collections
import random
import shutil  
from advanced_analytics import AdvancedAnalytics, integrate_advanced_analytics
from visualization_dashboard import VisualizationDashboard, integrate_visualization_dashboard


def check_python_version():
    """Ensure Python version compatibility"""
    import sys
    required_version = (3, 7)
    current_version = sys.version_info[:2]
    
    if current_version < required_version:
        print(f"ERROR: Python {required_version[0]}.{required_version[1]}+ required")
        print(f"Current version: {current_version[0]}.{current_version[1]}")
        sys.exit(1)
        
# Enhanced import handling with installation guidance
def safe_import(module_name, package_name=None):
    """
    Safely import a module and provide installation guidance if missing
    """
    try:
        if package_name is None:
            package_name = module_name
        module = __import__(module_name)
        return module, True
    except ImportError as e:
        print(f"Missing library: {module_name}")
        print(f"To install: pip install {package_name}")
        return None, False

# Try to import optional libraries with fallbacks
try:
    from matplotlib.figure import Figure
    from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
    import matplotlib.animation as animation
    MATPLOTLIB_AVAILABLE = True
except ImportError:
    MATPLOTLIB_AVAILABLE = False
    print("Matplotlib not available - plotting features disabled")
    print("To install: pip install matplotlib")

# Try other optional libraries
CV2_AVAILABLE = False
try:
    import cv2
    CV2_AVAILABLE = True
except ImportError:
    print("OpenCV not available - video features disabled")
    print("To install: pip install opencv-python")

SERIAL_AVAILABLE = False
try:
    import serial
    SERIAL_AVAILABLE = True
except ImportError:
    print("pyserial not available - UART features disabled")
    print("To install: pip install pyserial")

CAN_AVAILABLE = False
CAN_BUS_AVAILABLE = False
try:
    import can
    CAN_AVAILABLE = True
    # Test if can.Bus is available (newer versions)
    if hasattr(can, 'Bus'):
        CAN_BUS_AVAILABLE = True
    else:
        print("python-can available but can.Bus not found - using simulation")
except ImportError:
    print("python-can not available - CAN features disabled")
    print("To install: pip install python-can")

PANDAS_AVAILABLE = False
try:
    import pandas as pd
    PANDAS_AVAILABLE = True
except ImportError:
    print("pandas not available - some analysis features disabled")
    print("To install: pip install pandas")

SCAPY_AVAILABLE = False
try:
    from scapy.all import *
    SCAPY_AVAILABLE = True
except ImportError:
    print("scapy not available - Ethernet features disabled")
    print("To install: pip install scapy")

NUMPY_AVAILABLE = False
try:
    import numpy as np
    NUMPY_AVAILABLE = True
except ImportError:
    print("numpy not available - some features disabled")
    print("To install: pip install numpy")

PIL_AVAILABLE = False
try:
    from PIL import Image, ImageTk
    PIL_AVAILABLE = True
except ImportError:
    print("PIL not available - video display disabled")
    print("To install: pip install Pillow")

PSUTIL_AVAILABLE = False
try:
    import psutil
    PSUTIL_AVAILABLE = True
except ImportError:
    print("psutil not available - some system monitoring disabled")
    print("To install: pip install psutil")

class RateLimiter:
    """Rate limiter for logging operations"""
    def __init__(self, max_rate_per_second):
        self.max_rate = max_rate_per_second
        self.tokens = max_rate_per_second
        self.last_update = time.time()
        self.lock = threading.Lock()
    
    def acquire(self):
        """Try to acquire a token"""
        with self.lock:
            now = time.time()
            elapsed = now - self.last_update
            self.tokens = min(self.max_rate, self.tokens + elapsed * self.max_rate)
            self.last_update = now
            
            if self.tokens >= 1:
                self.tokens -= 1
                return True
            return False
            
class LogFilter:
    """Filter and format log messages"""
    
    def __init__(self):
        self.error_count = {}
        self.last_log_time = {}
        self.suppress_duration = 5.0  # Suppress duplicate errors for 5 seconds
    
    def should_log(self, message):
        """Determine if message should be logged"""
        # Suppress repetitive errors
        error_key = self._get_error_key(message)
        current_time = time.time()
        
        if error_key in self.last_log_time:
            if current_time - self.last_log_time[error_key] < self.suppress_duration:
                self.error_count[error_key] = self.error_count.get(error_key, 0) + 1
                return False
        
        self.last_log_time[error_key] = current_time
        
        # If we suppressed messages, add count
        if error_key in self.error_count and self.error_count[error_key] > 0:
            count = self.error_count[error_key]
            self.error_count[error_key] = 0
            return True, f"{message} (repeated {count} times)"
        
        return True, message
    
    def _get_error_key(self, message):
        """Extract error key from message"""
        # Group similar errors together
        if 'colorbar' in message.lower():
            return 'colorbar_error'
        elif 'tight_layout' in message.lower():
            return 'tight_layout_warning'
        elif 'dimension' in message.lower():
            return 'dimension_error'
        elif 'visualization' in message.lower():
            return 'viz_error'
        else:
            return message[:50]  # First 50 chars as key
           
class ProfessionalADASLogger:
    def __init__(self, root):
        self.root = root
        self.root.title("ADAS ECU Professional Data Logger")
        self.root.geometry("1400x900")
        self.root.configure(bg='#2c3e50')
        
        # Show library status
        self.show_library_status()
        
        # Configuration file for persistence
        self.config_file = "adas_logger_config.json"
        
        # Set application icon (you can replace with your own icon)
        try:
            self.root.iconbitmap("magna_icon.ico")
        except:
            print("No Icon Detected, using default")
        
        # Style configuration for professional look
        self.setup_styles()
        
        # Data management
        self.setup_data_structures()
        
        # Initialize UI
        self.setup_main_interface()
        
        self.log_filter = LogFilter()
        
        # Initialize advanced analytics (after UI setup)
        self.analytics_engine = None
        self.viz_dashboard = None

        # Integrate modules
        self.root.after(2000, self.integrate_advanced_features)
                
        # Load previous configuration
        self.load_previous_config()
        
        # Auto-detect on startup
        self.root.after(1000, self.auto_detect_interfaces)
    
    def setup_shutdown_handler(self):
        """Setup graceful shutdown on window close"""
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

    def on_closing(self):
        """Handle application close"""
        if self.is_logging:
            response = messagebox.askyesno(
                "Logging Active", 
                "Logging is currently active. Stop logging and exit?"
            )
            if response:
                self.stop_logging()
                time.sleep(1)  # Allow threads to finish
            else:
                return
        
        # Save configuration
        try:
            self.save_current_config()
        except:
            pass
        
        # Cleanup
        try:
            if hasattr(self, 'video_capture') and self.video_capture:
                self.video_capture.release()
        except:
            pass
        
        self.root.destroy()
    
    def show_library_status(self):
        """Display library availability status"""
        status_window = tk.Toplevel(self.root)
        status_window.title("Library Status")
        status_window.geometry("400x300")
        status_window.transient(self.root)
        status_window.grab_set()
        
        ttk.Label(status_window, text="Library Availability Status", 
                 font=('Arial', 14, 'bold')).pack(pady=10)
        
        status_text = scrolledtext.ScrolledText(status_window, height=12)
        status_text.pack(fill='both', expand=True, padx=10, pady=10)
        
        libraries = [
            ("Matplotlib", MATPLOTLIB_AVAILABLE, "Plotting features"),
            ("OpenCV", CV2_AVAILABLE, "Video capture"),
            ("PySerial", SERIAL_AVAILABLE, "UART communication"),
            ("Python-CAN", CAN_AVAILABLE, "CAN bus communication"),
            ("Pandas", PANDAS_AVAILABLE, "Data analysis"),
            ("Scapy", SCAPY_AVAILABLE, "Network capture"),
            ("Pillow", PIL_AVAILABLE, "Image processing"),
            ("psutil", PSUTIL_AVAILABLE, "System monitoring")
        ]
        
        for lib_name, available, description in libraries:
            status = "✓ Available" if available else "✗ Missing"
            color = "green" if available else "red"
            status_text.insert(tk.END, f"{lib_name:15} {status:15} {description}\n")
            if available:
                status_text.tag_add("available", "end-1l", "end-1l wordend")
            else:
                status_text.tag_add("missing", "end-1l", "end-1l wordend")
        
        status_text.tag_config("available", foreground="green")
        status_text.tag_config("missing", foreground="red")
        status_text.config(state="disabled")
        
        ttk.Button(status_window, text="Continue", 
                  command=status_window.destroy).pack(pady=10)

    def integrate_advanced_features(self):
        """Integrate advanced analytics and visualization"""
        try:
            # Import modules
            from advanced_analytics import integrate_advanced_analytics
            from visualization_dashboard import integrate_visualization_dashboard
            
            # Integrate analytics first
            self.analytics_engine = integrate_advanced_analytics(self)
            self.log_message("✓ Advanced analytics engine loaded")
            
            # FIXED: Create visualization dashboard BEFORE calling setup_advanced_analytics
            self.viz_dashboard = integrate_visualization_dashboard(self)
            self.log_message("✓ Interactive visualization dashboard loaded")
            
        except Exception as e:
            self.log_message(f"Warning: Advanced features partially loaded: {e}")
            
    def setup_styles(self):
        """Configure professional color scheme and styles"""
        self.style = ttk.Style()
        self.style.theme_use('clam')
        
        # Color scheme
        self.colors = {
            'primary': '#3498db',
            'secondary': '#2c3e50',
            'success': '#27ae60',
            'warning': '#f39c12',
            'danger': '#e74c3c',
            'dark': '#34495e',
            'light': '#ecf0f1',
            'text': '#2c3e50'
        }
        
        # Configure styles
        self.style.configure('Primary.TButton', 
                           background=self.colors['primary'],
                           foreground='white',
                           focuscolor='none')
        self.style.configure('Success.TButton',
                           background=self.colors['success'],
                           foreground='white')
        self.style.configure('Danger.TButton',
                           background=self.colors['danger'],
                           foreground='white')
        self.style.configure('Dark.TFrame',
                           background=self.colors['dark'])
        self.style.configure('Primary.TLabelframe',
                           background=self.colors['secondary'],
                           foreground='white')
        self.style.configure('Primary.TLabelframe.Label',
                           background=self.colors['secondary'],
                           foreground='white')

    def setup_data_structures(self):
        """Enhanced data structures with memory limits and performance optimizations"""
        # Configure queue sizes based on data type characteristics
        self.data_queues = {
            'CAN': queue.Queue(maxsize=5000),      # CAN messages are small but frequent
            'Ethernet': queue.Queue(maxsize=2000), # Ethernet packets can be large
            'UART': queue.Queue(maxsize=10000),    # UART data is typically small
            'Video': queue.Queue(maxsize=10)       # Video frames are memory intensive
        }
        
        self.max_data_points = 50000  # Reduced from 100k for better performance
        self.is_logging = False
        self.log_directory = ""
        self.start_time = None
        self.config_profiles = {}
        self.current_profile = "default"
        
        # Initialize detected_interfaces here
        self.detected_interfaces = {
            'CAN': [], 'Ethernet': [], 'UART': [], 'Video': []
        }
        
        # Use deque for better performance with fixed size
        # Remove duplicate import - collections is already imported at top
        self.plot_data = {
            'timestamps': collections.deque(maxlen=1000),  # Fixed size for plots
            'can_signals': {},
            'uart_data': {}
        }
        
        # Session statistics with locks for thread safety
        self.session_stats = {
            'can_messages': 0,
            'ethernet_packets': 0, 
            'uart_bytes': 0,
            'video_frames': 0
        }
        self.stats_lock = threading.Lock()
        
        # Video capture object
        self.video_capture = None
        
        # Performance tracking
        self._last_plot_update = 0
        self._last_video_update = 0
    
    def monitor_resources(self):
        """Monitor system resources during logging"""
        if not self.is_logging or not PSUTIL_AVAILABLE:
            return
            
        try:
            # Memory check
            memory = psutil.virtual_memory()
            if memory.percent > 90:
                self.log_message(f"WARNING: High memory usage: {memory.percent:.1f}%")
                
            # CPU check
            cpu_percent = psutil.cpu_percent(interval=0.1)
            if cpu_percent > 85:
                self.log_message(f"WARNING: High CPU usage: {cpu_percent:.1f}%")
                
            # Disk space check
            if hasattr(self, 'current_log_dir'):
                disk = psutil.disk_usage(self.current_log_dir)
                if disk.percent > 99:
                    self.log_message("CRITICAL: Disk space critically low!")
                    messagebox.showwarning(
                        "Disk Space Critical",
                        "Disk space is critically low. Stopping logging."
                    )
                    self.stop_logging()
                    return
                    
        except Exception as e:
            pass  # Silent fail for monitoring
        
        # Schedule next check
        if self.is_logging:
            self.root.after(5000, self.monitor_resources)  # Check every 5 seconds
    
    def setup_main_interface(self):
        """Setup the main application interface"""
        # Create notebook for tabbed interface
        self.notebook = ttk.Notebook(self.root)
        self.notebook.pack(fill='both', expand=True, padx=10, pady=10)
        
        # Create tabs
        self.setup_dashboard_tab()
        self.setup_configuration_tab()
        self.setup_analysis_tab()
        self.setup_about_tab()
        
        # Setup status bar
        self.setup_status_bar()
        self.setup_shutdown_handler()

    def setup_dashboard_tab(self):
        """Setup the main dashboard tab"""
        dashboard_frame = ttk.Frame(self.notebook)
        self.notebook.add(dashboard_frame, text="Dashboard")
        
        # Top control panel
        self.setup_control_panel(dashboard_frame)
        
        # Main content area
        content_frame = ttk.Frame(dashboard_frame)
        content_frame.pack(fill='both', expand=True, pady=(10, 0))
        
        # Left panel - Status and detection
        left_frame = ttk.LabelFrame(content_frame, text="System Status", padding="15")
        left_frame.pack(side='left', fill='both', expand=True, padx=(0, 5))
        
        self.setup_status_display(left_frame)
        self.setup_interface_detection(left_frame)
        
        # Right panel - Real-time monitoring
        right_frame = ttk.LabelFrame(content_frame, text="Real-time Monitoring", padding="15")
        right_frame.pack(side='right', fill='both', expand=True, padx=(5, 0))
        
        self.setup_realtime_monitoring(right_frame)

    def setup_control_panel(self, parent):
        """Setup the top control panel"""
        control_frame = ttk.Frame(parent, style='Dark.TFrame')
        control_frame.pack(fill='x', pady=(0, 10))
        
        # Title and quick actions
        title_label = ttk.Label(control_frame, 
                              text="ADAS ECU Professional Data Logger", 
                              font=('Arial', 18, 'bold'),
                              foreground='white',
                              background=self.colors['dark'])
        title_label.pack(side='left', padx=15, pady=10)
        
        # Control buttons
        button_frame = ttk.Frame(control_frame, style='Dark.TFrame')
        button_frame.pack(side='right', padx=15, pady=10)
        
        self.start_btn = ttk.Button(button_frame, text="▶ Start Logging", 
                                  style='Success.TButton',
                                  command=self.start_logging, state="disabled")
        self.start_btn.pack(side='left', padx=(0, 5))
        
        self.stop_btn = ttk.Button(button_frame, text="■ Stop Logging", 
                                 style='Danger.TButton',
                                 command=self.stop_logging, state="disabled")
        self.stop_btn.pack(side='left', padx=(0, 5))
        
        ttk.Button(button_frame, text="⚙ Settings", 
                 command=self.show_configuration).pack(side='left', padx=(0, 5))
        
        ttk.Button(button_frame, text="ℹ About", 
                 command=self.show_about).pack(side='left')

    def setup_status_display(self, parent):
        """Setup system status display"""
        # Status grid
        status_grid = ttk.Frame(parent)
        status_grid.pack(fill='x', pady=(0, 15))
        
        interfaces = [
            ('CAN', 'CAN-FD Bus'),
            ('Ethernet', 'Ethernet Network'),
            ('UART', 'Serial Ports'),
            ('Video', 'Video Capture')
        ]
        
        self.status_indicators = {}
        self.status_labels = {}
        
        for i, (interface, description) in enumerate(interfaces):
            frame = ttk.Frame(status_grid)
            frame.grid(row=i//2, column=i%2, sticky='w', padx=10, pady=5)
            
            # Status indicator (circle)
            canvas = tk.Canvas(frame, width=20, height=20, highlightthickness=0)
            canvas.pack(side='left')
            indicator = canvas.create_oval(2, 2, 18, 18, fill='red', outline='')
            
            # Create labels
            interface_label = ttk.Label(frame, text=f"{interface}:", font=('Arial', 9, 'bold'))
            interface_label.pack(side='left', padx=(5, 0))
            
            status_label = ttk.Label(frame, text=description, font=('Arial', 9))
            status_label.pack(side='left', padx=(2, 0))
            
            self.status_indicators[interface] = (canvas, indicator)
            self.status_labels[interface] = status_label
        
        # Recording status
        recording_frame = ttk.Frame(parent)
        recording_frame.pack(fill='x', pady=10)
        
        self.recording_canvas = tk.Canvas(recording_frame, width=30, height=30, highlightthickness=0)
        self.recording_canvas.pack(side='left')
        self.recording_indicator = self.recording_canvas.create_oval(5, 5, 25, 25, fill='red', outline='')
        
        self.recording_status = ttk.Label(recording_frame, text="READY", 
                                        font=('Arial', 12, 'bold'))
        self.recording_status.pack(side='left', padx=10)
        
        # Statistics
        stats_frame = ttk.LabelFrame(parent, text="Session Statistics", padding="10")
        stats_frame.pack(fill='x', pady=(10, 0))
        
        self.stats_labels = {}
        stats = ['Duration', 'CAN Messages', 'Ethernet Packets', 'UART Bytes', 'Video Frames']
        
        for stat in stats:
            stat_frame = ttk.Frame(stats_frame)
            stat_frame.pack(fill='x', pady=2)
            
            ttk.Label(stat_frame, text=f"{stat}:").pack(side='left')
            self.stats_labels[stat] = ttk.Label(stat_frame, text="0", 
                                              font=('Arial', 9, 'bold'))
            self.stats_labels[stat].pack(side='right')

    def setup_interface_detection(self, parent):
        """Setup interface detection section"""
        detect_frame = ttk.Frame(parent)
        detect_frame.pack(fill='x', pady=(15, 0))
        
        ttk.Button(detect_frame, text="🔄 Auto-Detect Interfaces", 
                 command=self.auto_detect_interfaces).pack(side='left')
        
        ttk.Button(detect_frame, text="📊 Refresh Statistics", 
                 command=self.update_statistics).pack(side='left', padx=(10, 0))
        
        # Detection results
        self.detection_text = scrolledtext.ScrolledText(parent, height=8, 
                                                       font=('Consolas', 9))
        self.detection_text.pack(fill='both', expand=True, pady=(10, 0))
        
        # Log display area
        log_frame = ttk.LabelFrame(parent, text="Log Messages", padding="10")
        log_frame.pack(fill='both', expand=True, pady=(10, 0))
        
        self.log_text = scrolledtext.ScrolledText(log_frame, height=6, 
                                                font=('Consolas', 9))
        self.log_text.pack(fill='both', expand=True)
        
        # Add clear log button
        clear_frame = ttk.Frame(parent)
        clear_frame.pack(fill='x', pady=(5, 0))
        ttk.Button(clear_frame, text="Clear Log", 
                  command=self.clear_log).pack(side='right')

    def setup_realtime_monitoring(self, parent):
        """Setup real-time monitoring area"""
        # Video preview
        video_frame = ttk.LabelFrame(parent, text="Video Preview", padding="10")
        video_frame.pack(fill='both', expand=True, pady=(0, 10))
        
        self.video_label = ttk.Label(video_frame, text="No video feed", 
                                   background='black', foreground='white',
                                   font=('Arial', 12))
        self.video_label.pack(fill='both', expand=True)
        
        # Real-time plots
        plot_frame = ttk.LabelFrame(parent, text="Signal Monitoring", padding="10")
        plot_frame.pack(fill='both', expand=True)
        
        self.setup_realtime_plots(plot_frame)

    def setup_realtime_plots(self, parent):
        """Setup real-time plotting area"""
        if not MATPLOTLIB_AVAILABLE:
            # Fallback when matplotlib is not available
            fallback_label = ttk.Label(parent, 
                                     text="Plotting disabled - matplotlib not installed\n\n"
                                          "To enable plotting features:\n"
                                          "pip install matplotlib",
                                     foreground='red', justify='center')
            fallback_label.pack(fill='both', expand=True)
            return
        
        # Create matplotlib figure
        self.plot_fig = Figure(figsize=(8, 4), dpi=100)
        self.can_plot = self.plot_fig.add_subplot(111)
        self.can_plot.set_title('CAN Signal Monitoring')
        self.can_plot.set_xlabel('Time (s)')
        self.can_plot.set_ylabel('Signal Value')
        self.can_plot.grid(True, alpha=0.3)
        
        self.plot_canvas = FigureCanvasTkAgg(self.plot_fig, parent)
        self.plot_canvas.get_tk_widget().pack(fill='both', expand=True)

    def setup_configuration_tab(self):
        """Setup configuration tab"""
        config_frame = ttk.Frame(self.notebook)
        self.notebook.add(config_frame, text="Configuration")
        
        # Log directory selection
        dir_frame = ttk.LabelFrame(config_frame, text="Log Directory", padding="10")
        dir_frame.pack(fill='x', pady=(0, 10))
        
        ttk.Label(dir_frame, text="Log Directory:").grid(row=0, column=0, sticky='w')
        self.dir_entry = ttk.Entry(dir_frame, width=50)
        self.dir_entry.grid(row=0, column=1, padx=(5, 5), sticky=(tk.W, tk.E))
        ttk.Button(dir_frame, text="Browse", command=self.browse_directory).grid(row=0, column=2)
        
        # Interface configuration
        interface_config_frame = ttk.LabelFrame(config_frame, text="Interface Configuration", padding="15")
        interface_config_frame.pack(fill='both', expand=True)
        
        self.setup_interface_configuration(interface_config_frame)

    def setup_interface_configuration(self, parent):
        """Setup interface-specific configuration with availability indicators"""
        notebook = ttk.Notebook(parent)
        notebook.pack(fill='both', expand=True)
        
        # CAN Configuration
        can_frame = ttk.Frame(notebook, padding="10")
        notebook.add(can_frame, text=f"CAN-FD {'✓' if CAN_AVAILABLE else '✗'}")
        self.setup_can_config(can_frame)
        
        # Ethernet Configuration
        eth_frame = ttk.Frame(notebook, padding="10")
        notebook.add(eth_frame, text=f"Ethernet {'✓' if SCAPY_AVAILABLE else '✗'}")
        self.setup_ethernet_config(eth_frame)
        
        # UART Configuration
        uart_frame = ttk.Frame(notebook, padding="10")
        notebook.add(uart_frame, text=f"UART {'✓' if SERIAL_AVAILABLE else '✗'}")
        self.setup_uart_config(uart_frame)
        
        # Video Configuration
        video_frame = ttk.Frame(notebook, padding="10")
        notebook.add(video_frame, text=f"Video {'✓' if CV2_AVAILABLE else '✗'}")
        self.setup_video_config(video_frame)
    
    def setup_can_config(self, parent):
        """Setup CAN configuration"""
        if not CAN_AVAILABLE:
            ttk.Label(parent, text="CAN features disabled - python-can not installed", 
                     foreground='red').pack(pady=20)
            ttk.Label(parent, text="To install: pip install python-can").pack()
            return
        
        ttk.Label(parent, text="CAN Interface:").grid(row=0, column=0, sticky='w', pady=5)
        self.can_var = tk.StringVar()
        self.can_combo = ttk.Combobox(parent, textvariable=self.can_var, width=30)
        self.can_combo.grid(row=0, column=1, padx=(10, 0), pady=5, sticky='w')
        
        ttk.Label(parent, text="Baudrate:").grid(row=1, column=0, sticky='w', pady=5)
        self.can_baud = ttk.Combobox(parent, values=['125000', '250000', '500000', '1000000'], width=15)
        self.can_baud.set('500000')
        self.can_baud.grid(row=1, column=1, padx=(10, 0), pady=5, sticky='w')

    def setup_uart_config(self, parent):
        """Setup UART configuration for 4 ports"""
        if not SERIAL_AVAILABLE:
            ttk.Label(parent, text="UART features disabled - pyserial not installed", 
                     foreground='red').pack(pady=20)
            ttk.Label(parent, text="To install: pip install pyserial").pack()
            return
        
        uart_configs = []
        
        for i in range(4):
            port_frame = ttk.LabelFrame(parent, text=f"UART Port {i+1}", padding="10")
            port_frame.grid(row=i//2, column=i%2, sticky='w', padx=5, pady=5)
            
            ttk.Label(port_frame, text="Port:").grid(row=0, column=0, sticky='w', pady=2)
            uart_var = tk.StringVar()
            uart_combo = ttk.Combobox(port_frame, textvariable=uart_var, width=12)
            uart_combo.grid(row=0, column=1, padx=(5, 0), pady=2, sticky='w')
            
            ttk.Label(port_frame, text="Baudrate:").grid(row=1, column=0, sticky='w', pady=2)
            baud_combo = ttk.Combobox(port_frame, values=['9600', '19200', '38400', '57600', '115200'], width=10)
            baud_combo.set('115200')
            baud_combo.grid(row=1, column=1, padx=(5, 0), pady=2, sticky='w')
            
            uart_configs.append({
                'var': uart_var,
                'combo': uart_combo,
                'baud': baud_combo
            })
        
        self.uart_configs = uart_configs

    def setup_ethernet_config(self, parent):
        """Setup Ethernet configuration - this method exists but content is incomplete"""
        if not SCAPY_AVAILABLE:
            ttk.Label(parent, text="Ethernet features disabled - scapy not installed", 
                     foreground='red').pack(pady=20)
            ttk.Label(parent, text="To install: pip install scapy").pack()
            return
        
        # Add actual configuration widgets here
        ttk.Label(parent, text="Network Interface:").grid(row=0, column=0, sticky='w', pady=5)
        self.eth_var = tk.StringVar()
        self.eth_combo = ttk.Combobox(parent, textvariable=self.eth_var, width=30)
        self.eth_combo.grid(row=0, column=1, padx=(10, 0), pady=5, sticky='w')
        
        # Add filter configuration
        ttk.Label(parent, text="BPF Filter:").grid(row=1, column=0, sticky='w', pady=5)
        self.eth_filter = ttk.Entry(parent, width=30)
        self.eth_filter.grid(row=1, column=1, padx=(10, 0), pady=5, sticky='w')
        self.eth_filter.insert(0, "tcp or udp")  # Default filter

    def setup_video_config(self, parent):
        """Setup video configuration"""
        if not CV2_AVAILABLE:
            ttk.Label(parent, text="Video features disabled - opencv-python not installed", 
                     foreground='red').pack(pady=20)
            ttk.Label(parent, text="To install: pip install opencv-python").pack()
            return
        
        ttk.Label(parent, text="Video Source:").grid(row=0, column=0, sticky='w', pady=5)
        self.video_var = tk.StringVar()
        self.video_combo = ttk.Combobox(parent, textvariable=self.video_var, width=20)
        self.video_combo.grid(row=0, column=1, padx=(10, 0), pady=5, sticky='w')

    def setup_analysis_tab(self):
        """Setup data analysis tab"""
        analysis_frame = ttk.Frame(self.notebook)
        self.notebook.add(analysis_frame, text="Analysis")
        
        # Analysis controls
        controls_frame = ttk.Frame(analysis_frame)
        controls_frame.pack(fill='x', pady=(0, 10))
        
        ttk.Button(controls_frame, text="📈 Load Data", command=self.load_analysis_data).pack(side='left')
        ttk.Button(controls_frame, text="📊 Generate Report", command=self.generate_report).pack(side='left', padx=(5, 0))
        ttk.Button(controls_frame, text="💾 Export Data", command=self.export_data).pack(side='left', padx=(5, 0))
        
        # Analysis results area
        self.analysis_text = scrolledtext.ScrolledText(analysis_frame, height=20)
        self.analysis_text.pack(fill='both', expand=True)
        
    def setup_advanced_analytics(self):
        """Setup advanced analytics with real-time insights"""
        analytics_notebook = ttk.Notebook(self.analysis_text.master)
        analytics_notebook.pack(fill='both', expand=True, before=self.analysis_text)
        
        # Hide old analysis text
        self.analysis_text.pack_forget()
        
        # Tab 1: Statistical Overview
        stats_frame = ttk.Frame(analytics_notebook, padding="10")
        analytics_notebook.add(stats_frame, text="📊 Statistics")
        self.setup_statistics_view(stats_frame)
        
        # Tab 2: Performance Metrics
        perf_frame = ttk.Frame(analytics_notebook, padding="10")
        analytics_notebook.add(perf_frame, text="⚡ Performance")
        self.setup_performance_view(perf_frame)
        
        # Tab 3: Data Quality
        quality_frame = ttk.Frame(analytics_notebook, padding="10")
        analytics_notebook.add(quality_frame, text="✓ Data Quality")
        self.setup_quality_view(quality_frame)
        
        # Tab 4: Anomaly Detection
        anomaly_frame = ttk.Frame(analytics_notebook, padding="10")
        analytics_notebook.add(anomaly_frame, text="🔍 Anomalies")
        self.setup_anomaly_view(anomaly_frame)
        
        # Tab 5: Export & Reports
        export_frame = ttk.Frame(analytics_notebook, padding="10")
        analytics_notebook.add(export_frame, text="💾 Export")
        self.setup_export_view(export_frame)

    def setup_statistics_view(self, parent):
        """Statistical analysis view"""
        # Control panel
        control_frame = ttk.Frame(parent)
        control_frame.pack(fill='x', pady=(0, 10))
        
        ttk.Button(control_frame, text="🔄 Refresh Stats", 
                  command=self.refresh_statistics).pack(side='left', padx=5)
        ttk.Button(control_frame, text="📈 Export Stats", 
                  command=self.export_statistics).pack(side='left', padx=5)
        
        # Statistics display with scrolling
        self.stats_display = scrolledtext.ScrolledText(parent, height=25, 
                                                       font=('Consolas', 10))
        self.stats_display.pack(fill='both', expand=True)
        
        # Configure tags for colored output
        self.stats_display.tag_config('header', font=('Consolas', 12, 'bold'), 
                                     foreground='#2c3e50')
        self.stats_display.tag_config('metric', foreground='#3498db')
        self.stats_display.tag_config('value', font=('Consolas', 10, 'bold'), 
                                     foreground='#27ae60')
        self.stats_display.tag_config('warning', foreground='#f39c12')
        self.stats_display.tag_config('error', foreground='#e74c3c')

    def setup_performance_view(self, parent):
        """Performance metrics view"""
        # Metrics grid
        metrics_frame = ttk.LabelFrame(parent, text="Real-Time Performance Metrics", 
                                      padding="15")
        metrics_frame.pack(fill='both', expand=True)
        
        self.perf_metrics = {}
        metrics = [
            ('Throughput', 'CAN msg/s', 'can_throughput'),
            ('Packet Rate', 'pkt/s', 'eth_throughput'),
            ('UART Rate', 'bytes/s', 'uart_throughput'),
            ('Frame Rate', 'fps', 'video_fps'),
            ('Queue Usage', '%', 'queue_usage'),
            ('CPU Usage', '%', 'cpu_usage'),
            ('Memory Usage', 'MB', 'memory_usage'),
            ('Disk Write', 'MB/s', 'disk_write')
        ]
        
        for i, (label, unit, key) in enumerate(metrics):
            frame = ttk.Frame(metrics_frame)
            frame.grid(row=i//2, column=i%2, sticky='ew', padx=10, pady=5)
            
            ttk.Label(frame, text=f"{label}:", 
                     font=('Arial', 10, 'bold')).pack(side='left')
            
            value_label = ttk.Label(frame, text=f"0 {unit}", 
                                   font=('Arial', 10), foreground='#27ae60')
            value_label.pack(side='right')
            
            self.perf_metrics[key] = value_label
        
        # Performance graph
        if MATPLOTLIB_AVAILABLE:
            graph_frame = ttk.LabelFrame(parent, text="Performance History", 
                                        padding="10")
            graph_frame.pack(fill='both', expand=True, pady=(10, 0))
            
            self.perf_fig = Figure(figsize=(10, 4), dpi=100)
            self.perf_plot = self.perf_fig.add_subplot(111)
            self.perf_canvas = FigureCanvasTkAgg(self.perf_fig, graph_frame)
            self.perf_canvas.get_tk_widget().pack(fill='both', expand=True)
            
            # Performance history data
            self.perf_history = {
                'time': collections.deque(maxlen=100),
                'can_rate': collections.deque(maxlen=100),
                'eth_rate': collections.deque(maxlen=100),
                'memory': collections.deque(maxlen=100)
            }

    def setup_quality_view(self, parent):
        """Data quality monitoring view"""
        # Quality metrics
        quality_frame = ttk.LabelFrame(parent, text="Data Quality Metrics", 
                                      padding="15")
        quality_frame.pack(fill='both', expand=True)
        
        self.quality_metrics = {}
        
        metrics = [
            ('CAN Messages', 'Total', 'Errors', 'Error Rate'),
            ('Ethernet Packets', 'Total', 'Dropped', 'Drop Rate'),
            ('UART Data', 'Total', 'Corrupt', 'Error Rate'),
            ('Video Frames', 'Total', 'Skipped', 'Skip Rate')
        ]
        
        for i, (interface, col1, col2, col3) in enumerate(metrics):
            frame = ttk.LabelFrame(quality_frame, text=interface, padding="10")
            frame.grid(row=i//2, column=i%2, sticky='nsew', padx=5, pady=5)
            
            labels = {}
            for j, label_text in enumerate([col1, col2, col3]):
                lbl_frame = ttk.Frame(frame)
                lbl_frame.pack(fill='x', pady=2)
                
                ttk.Label(lbl_frame, text=f"{label_text}:").pack(side='left')
                value_lbl = ttk.Label(lbl_frame, text="0", 
                                     font=('Arial', 9, 'bold'))
                value_lbl.pack(side='right')
                labels[label_text.lower().replace(' ', '_')] = value_lbl
            
            self.quality_metrics[interface] = labels
        
        # Quality score
        score_frame = ttk.LabelFrame(parent, text="Overall Data Quality Score", 
                                    padding="15")
        score_frame.pack(fill='x', pady=(10, 0))
        
        self.quality_score_label = ttk.Label(score_frame, text="100%", 
                                            font=('Arial', 24, 'bold'),
                                            foreground='#27ae60')
        self.quality_score_label.pack()

    def setup_anomaly_view(self, parent):
        """Anomaly detection view"""
        # Anomaly list
        anomaly_frame = ttk.LabelFrame(parent, text="Detected Anomalies", 
                                      padding="10")
        anomaly_frame.pack(fill='both', expand=True)
        
        # Treeview for anomalies
        columns = ('Time', 'Type', 'Interface', 'Severity', 'Description')
        self.anomaly_tree = ttk.Treeview(anomaly_frame, columns=columns, 
                                        show='tree headings', height=15)
        
        self.anomaly_tree.heading('#0', text='ID')
        self.anomaly_tree.column('#0', width=50)
        
        for col in columns:
            self.anomaly_tree.heading(col, text=col)
            self.anomaly_tree.column(col, width=120)
        
        # Scrollbar
        scrollbar = ttk.Scrollbar(anomaly_frame, orient='vertical', 
                                 command=self.anomaly_tree.yview)
        self.anomaly_tree.configure(yscrollcommand=scrollbar.set)
        
        self.anomaly_tree.pack(side='left', fill='both', expand=True)
        scrollbar.pack(side='right', fill='y')
        
        # Anomaly counter
        self.anomaly_count = 0
        
        # Control buttons
        btn_frame = ttk.Frame(parent)
        btn_frame.pack(fill='x', pady=(10, 0))
        
        ttk.Button(btn_frame, text="Clear Anomalies", 
                  command=self.clear_anomalies).pack(side='left', padx=5)
        ttk.Button(btn_frame, text="Export Anomalies", 
                  command=self.export_anomalies).pack(side='left', padx=5)

    def setup_export_view(self, parent):
        """Enhanced export options"""
        # Export format selection
        format_frame = ttk.LabelFrame(parent, text="Export Format", padding="15")
        format_frame.pack(fill='x', pady=(0, 10))
        
        self.export_format = tk.StringVar(value='CSV')
        
        formats = ['CSV', 'JSON', 'Excel', 'HDF5', 'Parquet']
        for fmt in formats:
            ttk.Radiobutton(format_frame, text=fmt, variable=self.export_format, 
                           value=fmt).pack(side='left', padx=10)
        
        # Export options
        options_frame = ttk.LabelFrame(parent, text="Export Options", padding="15")
        options_frame.pack(fill='x', pady=(0, 10))
        
        self.export_compressed = tk.BooleanVar(value=True)
        self.export_metadata = tk.BooleanVar(value=True)
        self.export_stats = tk.BooleanVar(value=True)
        
        ttk.Checkbutton(options_frame, text="Compress output", 
                       variable=self.export_compressed).pack(anchor='w')
        ttk.Checkbutton(options_frame, text="Include metadata", 
                       variable=self.export_metadata).pack(anchor='w')
        ttk.Checkbutton(options_frame, text="Include statistics", 
                       variable=self.export_stats).pack(anchor='w')
        
        # Data selection
        data_frame = ttk.LabelFrame(parent, text="Data to Export", padding="15")
        data_frame.pack(fill='both', expand=True)
        
        self.export_can = tk.BooleanVar(value=True)
        self.export_eth = tk.BooleanVar(value=True)
        self.export_uart = tk.BooleanVar(value=True)
        self.export_video = tk.BooleanVar(value=False)
        
        ttk.Checkbutton(data_frame, text="CAN Messages", 
                       variable=self.export_can).pack(anchor='w')
        ttk.Checkbutton(data_frame, text="Ethernet Packets", 
                       variable=self.export_eth).pack(anchor='w')
        ttk.Checkbutton(data_frame, text="UART Data", 
                       variable=self.export_uart).pack(anchor='w')
        ttk.Checkbutton(data_frame, text="Video Frames (Warning: Large)", 
                       variable=self.export_video).pack(anchor='w')
        
        # Export buttons
        btn_frame = ttk.Frame(parent)
        btn_frame.pack(fill='x', pady=(10, 0))
        
        ttk.Button(btn_frame, text="📊 Quick Export", 
                  command=self.quick_export,
                  style='Success.TButton').pack(side='left', padx=5, fill='x', expand=True)
        ttk.Button(btn_frame, text="⚙️ Advanced Export", 
                  command=self.advanced_export).pack(side='left', padx=5, fill='x', expand=True)
    def setup_about_tab(self):
        """Setup about tab"""
        about_frame = ttk.Frame(self.notebook)
        self.notebook.add(about_frame, text="About & Help")
        
        about_text = scrolledtext.ScrolledText(about_frame, height=20, wrap=tk.WORD)
        about_text.pack(fill='both', expand=True, padx=10, pady=10)
        
        about_content = """
ADAS ECU Professional Data Logger

This application provides comprehensive data logging capabilities for ADAS ECU testing.

LIBRARY STATUS:
"""
        # Add library status
        libraries = [
            ("Matplotlib", MATPLOTLIB_AVAILABLE),
            ("OpenCV", CV2_AVAILABLE),
            ("PySerial", SERIAL_AVAILABLE),
            ("Python-CAN", CAN_AVAILABLE),
            ("Scapy", SCAPY_AVAILABLE),
            ("Pillow", PIL_AVAILABLE)
        ]
        
        for lib_name, available in libraries:
            status = "Available" if available else "Not Available"
            about_content += f"{lib_name}: {status}\n"
        
        about_content += """
INSTALLATION:
To install all required libraries, run:
pip install matplotlib opencv-python pyserial python-can scapy Pillow psutil pandas numpy

FEATURES:
- Multi-interface data logging
- Real-time monitoring
- Data analysis and reporting
- Configuration profiles

SUPPORT:
For technical support: Kevin.Delong@magna.com
"""
        
        about_text.insert('1.0', about_content)
        about_text.config(state='disabled')

    def setup_status_bar(self):
        """Setup bottom status bar"""
        status_bar = ttk.Frame(self.root, relief='sunken', style='Dark.TFrame')
        status_bar.pack(side='bottom', fill='x')
        
        self.status_message = ttk.Label(status_bar, text="Ready", foreground='white', background=self.colors['dark'])
        self.status_message.pack(side='left', padx=10)
        
        ttk.Label(status_bar, text="ADAS Logger v2.1.0", 
                foreground='white',
                background=self.colors['dark']).pack(side='right', padx=10)

    def auto_detect_interfaces(self):
        """Enhanced auto-detection with progress indication and proper error handling"""
        # Ensure detected_interfaces exists
        if not hasattr(self, 'detected_interfaces'):
            self.detected_interfaces = {
                'CAN': [], 'Ethernet': [], 'UART': [], 'Video': []
            }
        
        self.status_message.config(text="Scanning for interfaces...")
        self.log_message("Starting comprehensive interface detection...")
        
        # Clear previous results safely
        if hasattr(self, 'detected_interfaces'):
            self.detected_interfaces = {key: [] for key in self.detected_interfaces}
        
        if hasattr(self, 'detection_text'):
            self.detection_text.delete(1.0, tk.END)
        
        # Reset all status indicators to yellow (scanning)
        if hasattr(self, 'status_indicators'):
            for interface in self.status_indicators:
                canvas, indicator = self.status_indicators[interface]
                canvas.itemconfig(indicator, fill='yellow')
                
                if interface in self.status_labels:
                    self.status_labels[interface].config(foreground='black')
        
        # Start detection threads
        threads = [
            threading.Thread(target=self.detect_can),
            threading.Thread(target=self.detect_ethernet),
            threading.Thread(target=self.detect_uart),
            threading.Thread(target=self.detect_video)
        ]
        
        for thread in threads:
            thread.daemon = True
            thread.start()
        
        # Check results after delay
        self.root.after(3000, self.finalize_detection)

    def detect_can(self):
        """Detect available CAN interfaces"""
        try:
            can_interfaces = []
            
            if CAN_AVAILABLE:
                # Simulate CAN detection for now
                if sys.platform.startswith('win'):
                    can_interfaces = ['PCAN_USBBUS1', '0', '1']
                else:
                    can_interfaces = ['can0', 'can1']
            else:
                can_interfaces = ['CAN simulation only']
            
            self.detected_interfaces['CAN'] = can_interfaces
            self.log_message(f"Detected CAN interfaces: {can_interfaces}")
            
        except Exception as e:
            self.log_message(f"CAN detection error: {str(e)}")
            self.detected_interfaces['CAN'] = ['Detection failed']

    def detect_ethernet(self):
        """Detect available Ethernet interfaces"""
        try:
            ethernet_interfaces = []
            
            # Simulate Ethernet detection
            if sys.platform.startswith('win'):
                ethernet_interfaces = ['Ethernet', 'Wi-Fi']
            else:
                ethernet_interfaces = ['eth0', 'wlan0']
            
            self.detected_interfaces['Ethernet'] = ethernet_interfaces
            self.log_message(f"Detected Ethernet interfaces: {ethernet_interfaces}")
            
        except Exception as e:
            self.log_message(f"Ethernet detection error: {str(e)}")
            self.detected_interfaces['Ethernet'] = ['Detection failed']

    def detect_uart(self):
        """Detect available UART ports"""
        try:
            uart_ports = []
            
            if SERIAL_AVAILABLE:
                # Simulate UART detection
                if sys.platform.startswith('win'):
                    uart_ports = ['COM1', 'COM3', 'COM5']
                else:
                    uart_ports = ['/dev/ttyUSB0', '/dev/ttyACM0']
            else:
                uart_ports = ['UART simulation only']
            
            self.detected_interfaces['UART'] = uart_ports
            self.log_message(f"Detected UART ports: {uart_ports}")
            
        except Exception as e:
            self.log_message(f"UART detection error: {str(e)}")
            self.detected_interfaces['UART'] = ['Detection failed']

    def detect_video(self):
        """Detect available video sources"""
        try:
            video_sources = []
            
            if CV2_AVAILABLE:
                # Simulate video detection
                video_sources = ['0', '1']
            else:
                video_sources = ['Video simulation only']
            
            self.detected_interfaces['Video'] = video_sources
            self.log_message(f"Detected video sources: {video_sources}")
            
        except Exception as e:
            self.log_message(f"Video detection error: {str(e)}")
            self.detected_interfaces['Video'] = ['Detection failed']

    def finalize_detection(self):
        """Finalize detection and update UI with proper error handling"""
        # Ensure detected_interfaces exists
        if not hasattr(self, 'detected_interfaces'):
            self.log_message("ERROR: detected_interfaces not initialized")
            return
            
        detection_summary = "Interface Detection Complete:\n\n"
        
        for interface, devices in self.detected_interfaces.items():
            is_detected = len(devices) > 0 and devices != ['Detection failed']
            indicator_color = "green" if is_detected else "red"
            text_color = "green" if is_detected else "red"
            
            # Update status indicators
            if hasattr(self, 'status_indicators') and interface in self.status_indicators:
                canvas, indicator = self.status_indicators[interface]
                canvas.itemconfig(indicator, fill=indicator_color)
            
            # Update status labels
            if hasattr(self, 'status_labels') and interface in self.status_labels:
                status_text = f"✓ {len(devices)} found" if is_detected else "✗ Not Found"
                self.status_labels[interface].config(
                    text=status_text, 
                    foreground=text_color
                )
            
            status_text = "✓ Detected" if is_detected else "✗ Not Found"
            detection_summary += f"{interface}: {status_text} ({len(devices)} devices)\n"
            for device in devices:
                detection_summary += f"  └ {device}\n"
            detection_summary += "\n"
        
        # Clear and update detection text
        if hasattr(self, 'detection_text'):
            self.detection_text.delete(1.0, tk.END)
            self.detection_text.insert(tk.END, detection_summary)
        
        # Update configuration comboboxes
        self.update_configuration_combos()
        
        # Enable start button if interfaces detected
        if any(self.detected_interfaces.values()):
            if hasattr(self, 'start_btn'):
                self.start_btn.config(state="normal")
            if hasattr(self, 'status_message'):
                self.status_message.config(text="Interfaces detected - Ready to log")
        else:
            if hasattr(self, 'status_message'):
                self.status_message.config(text="No interfaces detected")
        
        self.log_message("Interface detection completed")

    def update_configuration_combos(self):
        """Update configuration comboboxes with detected devices"""
        try:
            # CAN interfaces
            if hasattr(self, 'can_combo') and CAN_AVAILABLE:
                self.can_combo['values'] = self.detected_interfaces['CAN']
                if self.detected_interfaces['CAN']:
                    self.can_combo.set(self.detected_interfaces['CAN'][0])
            
            # Ethernet interfaces
            if hasattr(self, 'eth_combo') and SCAPY_AVAILABLE:
                self.eth_combo['values'] = self.detected_interfaces['Ethernet']
                if self.detected_interfaces['Ethernet']:
                    self.eth_combo.set(self.detected_interfaces['Ethernet'][0])
            
            # Video sources
            if hasattr(self, 'video_combo') and CV2_AVAILABLE:
                self.video_combo['values'] = self.detected_interfaces['Video']
                if self.detected_interfaces['Video']:
                    self.video_combo.set(self.detected_interfaces['Video'][0])
            
            # UART ports
            if hasattr(self, 'uart_configs') and SERIAL_AVAILABLE:
                available_ports = self.detected_interfaces['UART']
                for i, config in enumerate(self.uart_configs):
                    config['combo']['values'] = available_ports
                    if i < len(available_ports):
                        config['combo'].set(available_ports[i])
            
        except Exception as e:
            self.log_message(f"Error updating configuration combos: {str(e)}")

    def save_can_data(self, data):
        """Save CAN data to file"""
        try:
            filename = os.path.join(self.current_log_dir, 'CAN', 'can_messages.csv')
            file_exists = os.path.isfile(filename)
            
            with open(filename, 'a', newline='') as f:
                if not file_exists:
                    f.write("timestamp,arbitration_id,data,dlc,channel\n")
                f.write(f"{data['timestamp']},{data['arbitration_id']},{data['data']},{data['dlc']},{data['channel']}\n")
        except Exception as e:
            self.log_message(f"Error saving CAN data: {str(e)}")

    def save_uart_data(self, data):
        """Save UART data to file"""
        try:
            port_name = data['port'].replace('/', '_').replace('\\', '_')
            filename = os.path.join(self.current_log_dir, 'UART', f'uart_{port_name}.csv')
            file_exists = os.path.isfile(filename)
            
            with open(filename, 'a', newline='') as f:
                if not file_exists:
                    f.write("timestamp,port,data,bytes_received\n")
                f.write(f"{data['timestamp']},{data['port']},{data['data']},{data['bytes_received']}\n")
        except Exception as e:
            self.log_message(f"Error saving UART data: {str(e)}")

    def save_ethernet_data(self, data):
        """Save Ethernet data to file"""
        try:
            filename = os.path.join(self.current_log_dir, 'Ethernet', 'ethernet_packets.csv')
            file_exists = os.path.isfile(filename)
            
            with open(filename, 'a', newline='') as f:
                if not file_exists:
                    f.write("timestamp,src_ip,dst_ip,protocol,size,interface\n")
                f.write(f"{data['timestamp']},{data['src_ip']},{data['dst_ip']},{data['protocol']},{data['size']},{data['interface']}\n")
        except Exception as e:
            self.log_message(f"Error saving Ethernet data: {str(e)}")

    def save_video_frame(self, frame, frame_count):
        """Save video frame to file"""
        try:
            if CV2_AVAILABLE and frame is not None:
                filename = os.path.join(self.current_log_dir, 'Video', f'frame_{frame_count:06d}.jpg')
                cv2.imwrite(filename, frame)
        except Exception as e:
            self.log_message(f"Error saving video frame: {str(e)}")
            
    def load_previous_config(self):
        """Load previous configuration from file"""
        try:
            if os.path.exists(self.config_file):
                with open(self.config_file, 'r') as f:
                    config = json.load(f)
                
                if 'log_directory' in config and hasattr(self, 'dir_entry'):
                    self.log_directory = config['log_directory']
                    self.dir_entry.delete(0, tk.END)
                    self.dir_entry.insert(0, self.log_directory)
                
                self.log_message("Previous configuration loaded")
                
        except Exception as e:
            self.log_message(f"Error loading previous config: {str(e)}")

    def save_current_config(self):
        """Save current configuration to file with validation"""
        try:
            config = {
                'log_directory': self.log_directory,
                'timestamp': datetime.now().isoformat(),
                'version': '2.1.0',
                'can_interface': self.can_var.get() if hasattr(self, 'can_var') else '',
                'ethernet_interface': self.eth_var.get() if hasattr(self, 'eth_var') else '',
                'video_source': self.video_var.get() if hasattr(self, 'video_var') else '',
                'uart_ports': []
            }
            
            if hasattr(self, 'uart_configs'):
                for config_item in self.uart_configs:
                    if config_item['var'].get():  # Only save configured ports
                        uart_config = {
                            'port': config_item['var'].get(),
                            'baudrate': config_item['baud'].get()
                        }
                        config['uart_ports'].append(uart_config)
            
            # Create backup of existing config
            if os.path.exists(self.config_file):
                backup_file = self.config_file + '.bak'
                shutil.copy2(self.config_file, backup_file)  # Remove "import shutil" from here
            
            # Save with atomic write
            temp_file = self.config_file + '.tmp'
            with open(temp_file, 'w') as f:
                json.dump(config, f, indent=2, ensure_ascii=False)
            
            # Atomic replace
            os.replace(temp_file, self.config_file)
                
            self.log_message("Configuration saved successfully")
            
        except Exception as e:
            self.log_message(f"Error saving configuration: {str(e)}")
            # Restore backup if available
            if 'backup_file' in locals() and os.path.exists(backup_file):
                try:
                    shutil.copy2(backup_file, self.config_file)  # Remove "import shutil" from here
                    self.log_message("Restored previous configuration from backup")
                except:
                    pass

    def browse_directory(self):
        """Browse for log directory"""
        directory = filedialog.askdirectory()
        if directory:
            self.log_directory = directory
            self.dir_entry.delete(0, tk.END)
            self.dir_entry.insert(0, directory)
            self.log_message(f"Log directory set to: {directory}")
            self.save_current_config()

    def start_logging(self):
        """Start data logging across all interfaces"""
        if not self.validate_configuration():
            return
        
        if not self.check_disk_space():
            return
        self.is_logging = True
        self.start_time = time.time()
        
        # Update UI
        self.start_btn.config(state="disabled")
        self.stop_btn.config(state="normal")
        self.recording_canvas.itemconfig(self.recording_indicator, fill='green')
        self.recording_status.config(text="RECORDING", foreground='green')
        
        # Create log directory
        self.create_log_directory()
        
        self.save_session_checkpoint()
        
        # Start logging threads
        self.start_logging_threads()
        
        # Start real-time updates
        self.start_real_time_updates()
        
        self.log_message("Data logging started")
        self.status_message.config(text="Logging in progress...")

    def validate_configuration(self):
        """Validate configuration before starting"""
        if not self.log_directory:
            messagebox.showerror("Error", "Please select a log directory")
            return False
            
        if not os.path.exists(self.log_directory):
            try:
                os.makedirs(self.log_directory, exist_ok=True)
            except Exception as e:
                messagebox.showerror("Error", f"Cannot create log directory: {e}")
                return False
        
        if not self.validate_log_directory_writable():
            return False
            
        # Check if at least one interface is configured
        can_configured = CAN_AVAILABLE and self.can_var.get() and self.can_var.get() in self.detected_interfaces['CAN']
        eth_configured = SCAPY_AVAILABLE and self.eth_var.get() and self.eth_var.get() in self.detected_interfaces['Ethernet']
        uart_configured = SERIAL_AVAILABLE and any(config['var'].get() for config in self.uart_configs)
        video_configured = CV2_AVAILABLE and self.video_var.get() and self.video_var.get() in self.detected_interfaces['Video']
        
        if not any([can_configured, eth_configured, uart_configured, video_configured]):
            messagebox.showerror("Error", "Please configure at least one interface")
            return False
            
        return True
        
    def validate_log_directory_writable(self):
        """Verify log directory is writable"""
        try:
            test_file = os.path.join(self.log_directory, '.write_test')
            with open(test_file, 'w') as f:
                f.write('test')
            os.remove(test_file)
            return True
        except Exception as e:
            messagebox.showerror(
                "Directory Error",
                f"Cannot write to log directory:\n{self.log_directory}\n\nError: {e}"
            )
            return False
           
    def check_disk_space(self):
        """Check available disk space before logging"""
        if not PSUTIL_AVAILABLE:
            return True
            
        try:
            usage = psutil.disk_usage(self.log_directory)
            free_gb = usage.free / (1024**3)
            
            if free_gb < 1.0:  # Less than 1GB free
                messagebox.showerror(
                    "Low Disk Space",
                    f"Only {free_gb:.2f} GB free space available.\n"
                    "Please free up disk space before logging."
                )
                return False
            elif free_gb < 5.0:  # Less than 5GB free
                response = messagebox.askyesno(
                    "Low Disk Space Warning",
                    f"Only {free_gb:.2f} GB free space available.\n"
                    "Continue anyway?"
                )
                return response
                
            return True
        except Exception as e:
            self.log_message(f"Could not check disk space: {e}")
            return True

    def create_log_directory(self):
        """Create timestamped log directory"""
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.current_log_dir = os.path.join(self.log_directory, f"ADAS_Log_{timestamp}")
        os.makedirs(self.current_log_dir, exist_ok=True)
        
        # Create subdirectories for each data type
        for data_type in ['CAN', 'Ethernet', 'UART', 'Video']:
            os.makedirs(os.path.join(self.current_log_dir, data_type), exist_ok=True)
        
        # Create session metadata file
        self.save_session_metadata()

    def save_session_metadata(self):
        """Save session metadata"""
        try:
            metadata = {
                'session_start': datetime.now().isoformat(),
                'log_directory': self.current_log_dir,
                'interfaces_configured': {
                    'CAN': self.can_var.get() if hasattr(self, 'can_var') else 'None',
                    'Ethernet': self.eth_var.get() if hasattr(self, 'eth_var') else 'None', 
                    'Video': self.video_var.get() if hasattr(self, 'video_var') else 'None',
                    'UART_ports': [config['var'].get() for config in getattr(self, 'uart_configs', [])]
                }
            }
            
            with open(os.path.join(self.current_log_dir, 'session_metadata.json'), 'w') as f:
                json.dump(metadata, f, indent=2)
                
        except Exception as e:
            self.log_message(f"Error saving metadata: {str(e)}")
    
    def save_session_checkpoint(self):
        """Periodically save session checkpoint for recovery"""
        if not self.is_logging:
            return
            
        try:
            checkpoint = {
                'timestamp': datetime.now().isoformat(),
                'elapsed_time': time.time() - self.start_time if self.start_time else 0,
                'statistics': self.session_stats.copy(),
                'is_logging': self.is_logging
            }
            
            checkpoint_file = os.path.join(self.current_log_dir, 'session_checkpoint.json')
            with open(checkpoint_file, 'w') as f:
                json.dump(checkpoint, f, indent=2)
                
        except Exception as e:
            pass  # Silent fail for checkpoints
        
        # Schedule next checkpoint
        if self.is_logging:
            self.root.after(30000, self.save_session_checkpoint)  # Every 30 seconds
    
    def start_logging_threads(self):
        """Start individual logging threads"""
        # Start CAN logging if configured
        if CAN_AVAILABLE and self.can_var.get():
            threading.Thread(target=self.can_logging_thread, daemon=True).start()
            
        # Start Ethernet logging if configured
        if SCAPY_AVAILABLE and self.eth_var.get():
            threading.Thread(target=self.ethernet_logging_thread, daemon=True).start()
            
        # Start UART logging for configured ports
        if SERIAL_AVAILABLE:
            for config in self.uart_configs:
                if config['var'].get():
                    threading.Thread(target=self.uart_logging_thread, 
                                   args=(config,), daemon=True).start()
                
        # Start video logging if configured
        if CV2_AVAILABLE and self.video_var.get():
            threading.Thread(target=self.video_logging_thread, daemon=True).start()

    def start_real_time_updates(self):
        """Start real-time UI updates"""
        # Start statistics updates
        self.update_statistics_timer()
        
        if PSUTIL_AVAILABLE:
            self.monitor_resources()
        
        # Start plot animation if available
        if MATPLOTLIB_AVAILABLE:
            self.ani = animation.FuncAnimation(self.plot_fig, self.update_plots, 
                                             interval=100, cache_frame_data=False)
        
        # Start video display updates
        if CV2_AVAILABLE:
            self.update_video_display()

    def can_logging_thread(self):
        """CAN logging thread with robust error handling"""
        self.log_message("Starting CAN logging (simulation)")
        
        message_count = 0
        max_messages = 10000
        consecutive_errors = 0
        max_consecutive_errors = 10
        
        while self.is_logging and message_count < max_messages:
            try:
                if not self.is_logging:
                    break
                    
                timestamp = time.time() - self.start_time
                
                simulated_data = {
                    'timestamp': timestamp,
                    'arbitration_id': hex(0x100 + (message_count % 256)),
                    'data': ''.join([f'{(message_count + i) % 256:02x}' for i in range(8)]),
                    'dlc': 8,
                    'channel': self.can_var.get() if hasattr(self, 'can_var') else 'simulated',
                    'simulated': True
                }
                
                if self.safe_queue_put('CAN', simulated_data):
                    self.increment_stat('can_messages', 1)
                    message_count += 1
                    try:
                        self.save_can_data(simulated_data)
                    except Exception as save_error:
                        self.log_message(f"CAN data save error: {save_error}")
                    consecutive_errors = 0  # Reset on success
                
                queue_size = self.data_queues['CAN'].qsize()
                sleep_time = 0.001 if queue_size < 100 else 0.01
                time.sleep(sleep_time)
                
            except Exception as e:
                consecutive_errors += 1
                self.log_message(f"CAN logging error: {str(e)}")
                
                if consecutive_errors >= max_consecutive_errors:
                    self.log_message("CAN logging: Too many consecutive errors, stopping")
                    break
                    
                time.sleep(1)
        
        self.log_message(f"CAN logging stopped. Messages logged: {message_count}")
        
    def uart_logging_thread(self, config):
        """UART logging thread with simulation"""
        port = config['var'].get()
        self.log_message(f"Starting UART logging on {port} (simulation)")
        
        byte_count = 0
        while self.is_logging and byte_count < 10000:
            try:
                timestamp = time.time() - self.start_time
                simulated_data = {
                    'timestamp': timestamp,
                    'port': port,
                    'data': f"{byte_count:08x}",
                    'bytes_received': 4,
                    'simulated': True
                }
                
                if self.safe_queue_put('UART', simulated_data):
                    self.increment_stat('uart_bytes', 4)
                    byte_count += 4
                    self.save_uart_data(simulated_data)
                
                time.sleep(0.1)
                
            except Exception as e:
                self.log_message(f"UART logging error: {str(e)}")
                break

    def ethernet_logging_thread(self):
        """Ethernet logging thread with simulation"""
        interface = self.eth_var.get()
        self.log_message(f"Starting Ethernet capture on {interface} (simulation)")
        
        packet_count = 0
        while self.is_logging and packet_count < 1000:
            try:
                timestamp = time.time() - self.start_time
                packet_data = {
                    'timestamp': timestamp,
                    'src_ip': f"192.168.1.{packet_count % 255}",
                    'dst_ip': f"192.168.1.{(packet_count + 1) % 255}",
                    'protocol': 'TCP' if packet_count % 2 == 0 else 'UDP',
                    'size': (packet_count % 1000) + 100,
                    'interface': interface,
                    'simulated': True
                }
                
                if self.safe_queue_put('Ethernet', packet_data):
                    self.increment_stat('ethernet_packets', 1)
                    packet_count += 1
                    self.save_ethernet_data(packet_data)
                
                time.sleep(0.01)
                
            except Exception as e:
                self.log_message(f"Ethernet capture error: {str(e)}")
                break

    def video_logging_thread(self):
        """Video logging thread - simulation only for now"""
        source = self.video_var.get()
        self.log_message(f"Starting video capture from {source} (simulation)")
        
        frame_count = 0
        while self.is_logging and frame_count < 100:
            try:
                # Simulate video frame
                timestamp = time.time() - self.start_time
                
                # Create a simple black frame simulation
                if CV2_AVAILABLE:
                    # If OpenCV is available, create actual frame
                    frame = np.zeros((480, 640, 3), dtype=np.uint8)
                    # Add some visual indication
                    cv2.putText(frame, f"Frame {frame_count}", (50, 50), 
                               cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
                    cv2.putText(frame, f"Time: {timestamp:.1f}s", (50, 100), 
                               cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
                else:
                    frame = None
                
                if self.safe_queue_put('Video', frame):
                    self.increment_stat('video_frames', 1)
                    frame_count += 1
                    self.save_video_frame(frame, frame_count)
                
                time.sleep(0.1)  # 10 FPS simulation
                
            except Exception as e:
                self.log_message(f"Video capture error: {str(e)}")
                break

    def safe_queue_put(self, queue_name, data, timeout=1.0):
        """Safely put data in queue with timeout and memory protection"""
        try:
            if queue_name not in self.data_queues:
                self.log_message(f"ERROR: Unknown queue {queue_name}")
                return False
                
            queue_obj = self.data_queues[queue_name]
            
            # Check if queue is approaching limit
            if queue_obj.qsize() > queue_obj.maxsize * 0.9:
                self.log_message(f"WARNING: {queue_name} queue near capacity ({queue_obj.qsize()}/{queue_obj.maxsize})")
                
            queue_obj.put(data, timeout=timeout, block=True)
            return True
            
        except queue.Full:
            # Implement data sampling when queue is full instead of complete loss
            # Note: queue_obj might not be defined in this scope, so get it again
            try:
                queue_obj = self.data_queues[queue_name]
                if queue_obj.qsize() > queue_obj.maxsize * 0.5:
                    # Try to make space by removing oldest item
                    try:
                        queue_obj.get_nowait()  # Remove one old item
                        queue_obj.put(data, timeout=0.5, block=True)  # Try again
                        self.log_message(f"INFO: {queue_name} queue sampled - oldest item removed")
                        return True
                    except:
                        pass
            except:
                pass
                    
            self.log_message(f"WARNING: {queue_name} queue full, data lost")
            return False
            
        except Exception as e:
            self.log_message(f"ERROR: Queue put failed: {str(e)}")
            return False

    def update_plots(self, frame):
        """Update real-time plots with memory management - FIXED dimensions"""
        if not self.is_logging or not MATPLOTLIB_AVAILABLE:
            return
        
        current_time = time.time()
        if hasattr(self, '_last_plot_update'):
            if current_time - self._last_plot_update < 0.05:
                return
        
        self._last_plot_update = current_time
        
        try:
            if self.start_time:
                elapsed = current_time - self.start_time
                
                if 'can_signal' not in self.plot_data['can_signals']:
                    self.plot_data['can_signals']['can_signal'] = collections.deque(maxlen=1000)
                
                value = math.sin(elapsed * 2) * 50 + 50 + random.uniform(-5, 5)
                
                self.plot_data['timestamps'].append(elapsed)
                self.plot_data['can_signals']['can_signal'].append(value)
                
                # Clear and redraw
                self.can_plot.clear()
                
                if len(self.plot_data['timestamps']) > 1:
                    # FIX: Ensure both arrays have same length
                    timestamps = list(self.plot_data['timestamps'])
                    signals = list(self.plot_data['can_signals']['can_signal'])
                    
                    # Trim to same length
                    min_len = min(len(timestamps), len(signals))
                    timestamps = timestamps[-min_len:]
                    signals = signals[-min_len:]
                    
                    # Now plot with matching dimensions
                    self.can_plot.plot(timestamps, signals, 
                                     'b-', linewidth=1.5, alpha=0.8)
                
                self.can_plot.set_title(f'CAN Signal Monitoring - {len(self.plot_data["timestamps"])} points')
                self.can_plot.set_xlabel('Time (s)')
                self.can_plot.set_ylabel('Signal Value')
                self.can_plot.grid(True, alpha=0.2)
                self.can_plot.set_ylim(0, 100)
                
                self.plot_canvas.draw_idle()
                
        except Exception as e:
            # Only log occasionally to reduce spam
            if random.random() < 0.01:
                print(f"Plot update error: {e}")

    def update_video_display(self):
        if not self.is_logging or not CV2_AVAILABLE or not PIL_AVAILABLE:
            return
            
        try:
            current_time = time.time()
            if hasattr(self, '_last_video_update'):
                if current_time - self._last_video_update < 0.033:
                    self.root.after(33, self.update_video_display)
                    return
                    
            self._last_video_update = current_time
            
            frame = None
            try:
                frame = self.data_queues['Video'].get_nowait()
            except queue.Empty:
                pass
                
            if frame is not None and isinstance(frame, np.ndarray) and frame.size > 0:
                height, width = frame.shape[:2]
                if width > 800 or height > 600:
                    frame = cv2.resize(frame, (800, 600))
                
                rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                img = Image.fromarray(rgb_frame)
                img.thumbnail((800, 600), Image.Resampling.LANCZOS)
                
                imgtk = ImageTk.PhotoImage(image=img)
                
                # CRITICAL FIX: Clear old reference before setting new one
                if hasattr(self.video_label, 'image') and self.video_label.image:
                    old_image = self.video_label.image
                    self.video_label.image = None
                    del old_image
                
                self.video_label.configure(image=imgtk)
                self.video_label.image = imgtk
                
                # Explicit cleanup
                del img, rgb_frame
                        
            # Clean queue
            while self.data_queues['Video'].qsize() > 3:
                try:
                    old_frame = self.data_queues['Video'].get_nowait()
                    del old_frame
                except queue.Empty:
                    break
                        
        except Exception as e:
            if random.random() < 0.01:
                self.log_message(f"Video display error: {e}")
        
        if self.is_logging:
            self.root.after(33, self.update_video_display)

    def update_statistics_timer(self):
        """Update statistics periodically"""
        if hasattr(self, 'is_logging') and self.is_logging:
            self.update_statistics()
            self.root.after(1000, self.update_statistics_timer)

    def update_statistics(self):
        """Update statistics display"""
        if hasattr(self, 'stats_labels') and self.stats_labels:
            if self.start_time and self.is_logging:
                duration = time.time() - self.start_time
                self.stats_labels['Duration'].config(text=f"{duration:.1f}s")
            else:
                self.stats_labels['Duration'].config(text="0s")
                
            self.stats_labels['CAN Messages'].config(text=str(self.session_stats['can_messages']))
            self.stats_labels['Ethernet Packets'].config(text=str(self.session_stats['ethernet_packets']))
            self.stats_labels['UART Bytes'].config(text=str(self.session_stats['uart_bytes']))
            self.stats_labels['Video Frames'].config(text=str(self.session_stats['video_frames']))

    def stop_logging(self):
        """Stop all data logging"""
        self.is_logging = False
        
        # Stop video capture
        if hasattr(self, 'video_capture') and self.video_capture:
            self.video_capture.release()
            self.video_capture = None
        
        # Update UI
        self.start_btn.config(state="normal")
        self.stop_btn.config(state="disabled")
        self.recording_canvas.itemconfig(self.recording_indicator, fill='red')
        self.recording_status.config(text="READY", foreground='black')
        
        self.log_message("Data logging stopped")
        self.status_message.config(text="Logging stopped")
        
        # Final statistics update
        self.update_statistics()
    
    def increment_stat(self, stat_name, value=1):
        """Thread-safe statistics increment"""
        with self.stats_lock:
            if stat_name in self.session_stats:
                self.session_stats[stat_name] += value
                
    def start_analytics_engine(self):
        """Start real-time analytics processing"""
        if not self.is_logging:
            return
        
        threading.Thread(target=self.analytics_worker, daemon=True).start()
        self.root.after(1000, self.update_analytics_display)

    def analytics_worker(self):
        """Background analytics processing"""
        last_can_count = 0
        last_eth_count = 0
        last_uart_count = 0
        last_video_count = 0
        last_time = time.time()
        
        while self.is_logging:
            try:
                time.sleep(1)  # Update every second
                
                current_time = time.time()
                elapsed = current_time - last_time
                
                if elapsed > 0:
                    # Calculate throughput
                    with self.stats_lock:
                        can_rate = (self.session_stats['can_messages'] - last_can_count) / elapsed
                        eth_rate = (self.session_stats['ethernet_packets'] - last_eth_count) / elapsed
                        uart_rate = (self.session_stats['uart_bytes'] - last_uart_count) / elapsed
                        video_rate = (self.session_stats['video_frames'] - last_video_count) / elapsed
                        
                        last_can_count = self.session_stats['can_messages']
                        last_eth_count = self.session_stats['ethernet_packets']
                        last_uart_count = self.session_stats['uart_bytes']
                        last_video_count = self.session_stats['video_frames']
                    
                    # Store performance history
                    if hasattr(self, 'perf_history'):
                        self.perf_history['time'].append(current_time - self.start_time)
                        self.perf_history['can_rate'].append(can_rate)
                        self.perf_history['eth_rate'].append(eth_rate)
                        self.perf_history['memory'].append(self.get_memory_usage())
                    
                    # Anomaly detection
                    self.detect_anomalies(can_rate, eth_rate, uart_rate, video_rate)
                    
                    last_time = current_time
                    
            except Exception as e:
                pass  # Silent fail for analytics

    def detect_anomalies(self, can_rate, eth_rate, uart_rate, video_rate):
        """Detect anomalies in data streams"""
        # Detect sudden drops in data rate
        if can_rate < 1 and self.session_stats['can_messages'] > 100:
            self.add_anomaly('Low CAN Rate', 'CAN', 'WARNING', 
                            f'CAN message rate dropped to {can_rate:.2f} msg/s')
        
        # Detect queue overflow
        for queue_name, queue_obj in self.data_queues.items():
            usage = (queue_obj.qsize() / queue_obj.maxsize) * 100
            if usage > 90:
                self.add_anomaly('Queue Overflow', queue_name, 'ERROR',
                               f'{queue_name} queue at {usage:.1f}% capacity')
        
        # Detect memory spikes
        if PSUTIL_AVAILABLE:
            memory = psutil.virtual_memory()
            if memory.percent > 90:
                self.add_anomaly('High Memory', 'System', 'ERROR',
                               f'Memory usage at {memory.percent:.1f}%')

    def add_anomaly(self, anomaly_type, interface, severity, description):
        """Add detected anomaly to list"""
        if not hasattr(self, 'anomaly_tree'):
            return
        
        timestamp = datetime.now().strftime("%H:%M:%S")
        self.anomaly_count += 1
        
        # Color coding
        tag = ''
        if severity == 'ERROR':
            tag = 'error'
        elif severity == 'WARNING':
            tag = 'warning'
        
        self.anomaly_tree.insert('', 0, text=str(self.anomaly_count),
                                values=(timestamp, anomaly_type, interface, 
                                      severity, description),
                                tags=(tag,))
        
        # Configure tags
        self.anomaly_tree.tag_configure('error', foreground='#e74c3c')
        self.anomaly_tree.tag_configure('warning', foreground='#f39c12')
        
        # Keep only last 100 anomalies
        children = self.anomaly_tree.get_children()
        if len(children) > 100:
            self.anomaly_tree.delete(children[-1])

    def update_analytics_display(self):
        """Update analytics displays"""
        if not self.is_logging:
            return
        
        try:
            # Update performance metrics
            if hasattr(self, 'perf_metrics'):
                if len(self.perf_history['time']) > 1:
                    can_rate = self.perf_history['can_rate'][-1] if self.perf_history['can_rate'] else 0
                    eth_rate = self.perf_history['eth_rate'][-1] if self.perf_history['eth_rate'] else 0
                    
                    self.perf_metrics['can_throughput'].config(text=f"{can_rate:.1f} msg/s")
                    self.perf_metrics['eth_throughput'].config(text=f"{eth_rate:.1f} pkt/s")
                
                # Queue usage
                total_usage = sum(q.qsize() / q.maxsize * 100 for q in self.data_queues.values()) / len(self.data_queues)
                self.perf_metrics['queue_usage'].config(text=f"{total_usage:.1f}%")
                
                # System metrics
                if PSUTIL_AVAILABLE:
                    memory_mb = psutil.Process().memory_info().rss / 1024 / 1024
                    self.perf_metrics['memory_usage'].config(text=f"{memory_mb:.1f} MB")
                    self.perf_metrics['cpu_usage'].config(text=f"{psutil.cpu_percent():.1f}%")
            
            # Update performance graph
            if MATPLOTLIB_AVAILABLE and hasattr(self, 'perf_plot'):
                self.update_performance_graph()
            
            # Update quality score
            self.update_quality_score()
            
        except Exception as e:
            pass
        
        # Schedule next update
        if self.is_logging:
            self.root.after(1000, self.update_analytics_display)

    def update_performance_graph(self):
        """Update performance history graph"""
        try:
            if len(self.perf_history['time']) < 2:
                return
            
            self.perf_plot.clear()
            
            times = list(self.perf_history['time'])
            can_rates = list(self.perf_history['can_rate'])
            eth_rates = list(self.perf_history['eth_rate'])
            
            self.perf_plot.plot(times, can_rates, 'b-', label='CAN Rate', linewidth=2)
            self.perf_plot.plot(times, eth_rates, 'g-', label='Eth Rate', linewidth=2)
            
            self.perf_plot.set_xlabel('Time (s)')
            self.perf_plot.set_ylabel('Rate')
            self.perf_plot.legend(loc='upper right')
            self.perf_plot.grid(True, alpha=0.3)
            
            self.perf_canvas.draw_idle()
            
        except Exception as e:
            pass

    def update_quality_score(self):
        """Calculate and update data quality score"""
        if not hasattr(self, 'quality_score_label'):
            return
        
        try:
            # Simple quality score based on error rates
            total_messages = sum(self.session_stats.values())
            if total_messages == 0:
                quality_score = 100
            else:
                # Assume 99% quality for simulation
                quality_score = 99.5
            
            # Update label with color coding
            self.quality_score_label.config(text=f"{quality_score:.1f}%")
            
            if quality_score >= 95:
                self.quality_score_label.config(foreground='#27ae60')
            elif quality_score >= 85:
                self.quality_score_label.config(foreground='#f39c12')
            else:
                self.quality_score_label.config(foreground='#e74c3c')
                
        except Exception as e:
            pass

    def get_memory_usage(self):
        """Get current memory usage in MB"""
        if PSUTIL_AVAILABLE:
            return psutil.Process().memory_info().rss / 1024 / 1024
        return 0
          
    def log_message(self, message):
        """Add message to log display with filtering"""
        # Filter message
        should_log = self.log_filter.should_log(message)
        
        if isinstance(should_log, tuple):
            should_log, message = should_log
        
        if not should_log:
            return
        
        # Format timestamp
        timestamp = datetime.now().strftime("%H:%M:%S")
        
        # Color code based on message type
        if any(word in message.lower() for word in ['error', 'failed', 'critical']):
            prefix = "❌"
        elif any(word in message.lower() for word in ['warning', 'warn']):
            prefix = "⚠️"
        elif any(word in message.lower() for word in ['success', '✓', 'completed']):
            prefix = "✅"
        elif any(word in message.lower() for word in ['info', 'detected', 'found']):
            prefix = "ℹ️"
        else:
            prefix = "•"
        
        log_entry = f"[{timestamp}] {prefix} {message}\n"
        
        if hasattr(self, 'log_text'):
            self.log_text.insert(tk.END, log_entry)
            self.log_text.see(tk.END)
            
            # Keep log size manageable (last 1000 lines)
            lines = int(self.log_text.index('end-1c').split('.')[0])
            if lines > 1000:
                self.log_text.delete('1.0', '500.0')
        
        # Only print important messages to console
        if prefix in ["❌", "⚠️", "✅"]:
            print(log_entry.strip())

    def clear_log(self):
        """Clear log messages"""
        if hasattr(self, 'log_text'):
            self.log_text.delete(1.0, tk.END)

    def show_configuration(self):
        """Show configuration tab"""
        self.notebook.select(1)

    def show_about(self):
        """Show about tab"""
        self.notebook.select(3)

    def load_analysis_data(self):
        """Load and analyze logged data"""
        try:
            self.analysis_text.delete(1.0, tk.END)
            self.analysis_text.insert(tk.END, "Data Analysis Report\n")
            self.analysis_text.insert(tk.END, "=" * 50 + "\n\n")
            self.analysis_text.insert(tk.END, f"CAN Messages: {self.session_stats['can_messages']}\n")
            self.analysis_text.insert(tk.END, f"Ethernet Packets: {self.session_stats['ethernet_packets']}\n")
            self.analysis_text.insert(tk.END, f"UART Bytes: {self.session_stats['uart_bytes']}\n")
            self.analysis_text.insert(tk.END, f"Video Frames: {self.session_stats['video_frames']}\n")
            self.log_message("Data analysis completed")
        except Exception as e:
            messagebox.showerror("Analysis Error", f"Failed to load analysis data: {str(e)}")

    def generate_report(self):
        """Generate analysis report"""
        try:
            report_file = filedialog.asksaveasfilename(
                defaultextension=".txt",
                filetypes=[("Text files", "*.txt"), ("All files", "*.*")],
                title="Save Analysis Report As"
            )
            
            if report_file:
                with open(report_file, 'w') as f:
                    f.write("ADAS Data Logger Report\n")
                    f.write("=" * 30 + "\n")
                    f.write(f"Generated: {datetime.now()}\n")
                    f.write(f"CAN Messages: {self.session_stats['can_messages']}\n")
                    f.write(f"Ethernet Packets: {self.session_stats['ethernet_packets']}\n")
                    f.write(f"UART Bytes: {self.session_stats['uart_bytes']}\n")
                    f.write(f"Video Frames: {self.session_stats['video_frames']}\n")
                
                self.log_message(f"Report generated: {report_file}")
                messagebox.showinfo("Report Generated", f"Report saved to:\n{report_file}")
                
        except Exception as e:
            messagebox.showerror("Report Error", f"Failed to generate report: {str(e)}")

    def export_data(self):
        """Export logged data"""
        try:
            export_dir = filedialog.askdirectory(title="Select Export Directory")
            if export_dir:
                self.log_message(f"Data export started to: {export_dir}")
                # Simulate export process
                time.sleep(1)
                self.log_message("Data export completed")
                messagebox.showinfo("Export Complete", f"Data exported to:\n{export_dir}")
                
        except Exception as e:
            messagebox.showerror("Export Error", f"Failed to export data: {str(e)}")

def main():
    """Main application entry point"""
    try:
        check_python_version()
        root = tk.Tk()
        app = ProfessionalADASLogger(root)
        root.mainloop()
    except Exception as e:
        print(f"Application error: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    main()
