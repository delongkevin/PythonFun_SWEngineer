import pyautogui
import json
import time
import os
import tkinter as tk
from tkinter import ttk, messagebox, filedialog, simpledialog
from pynput import mouse, keyboard
from threading import Thread
from PIL import Image, ImageTk

class RealTimeAutomatorGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Magna Real-Time Automator")
        self.root.geometry("1100x750")  
        self.root.minsize(900, 650)     
        
        self.actions = []
        self.recording = False
        self.last_action_time = None
        self.image_folder = "button_images"
        self.playback_active = False
        self.stop_requested = False
        self.current_iteration = 0
        self.total_iterations = 1
        self.batch_status = tk.StringVar()
        self.shortcut_config_file = "shortcuts_config.json"

        if not os.path.exists(self.image_folder):
            os.makedirs(self.image_folder)
        
        pyautogui.FAILSAFE = True
        
        # Professional color scheme
        self.colors = {
            'primary': '#1e3a8a',
            'secondary': '#3b82f6',
            'accent': '#2563eb',
            'light_bg': '#f8fafc',
            'card_bg': '#ffffff',
            'text': '#1e293b',
            'text_light': '#64748b',
            'success': '#10b981',
            'warning': '#f59e0b',
            'danger': '#ef4444',
            'border': '#e2e8f0',
            'hover': '#f1f5f9',
            'movement': '#8b5cf6'
        }
        
        self.root.configure(bg=self.colors['light_bg'])
        
        # Load shortcuts BEFORE setting up menu bar
        self.shortcuts = self.load_shortcuts_config()
        
        self.setup_menu_bar()  # Now this will have access to self.shortcuts
        self.setup_styles()
        self.setup_ui()
        
        self.mouse_listener = None
        self.kb_listener = None
        self.shortcuts_window = None
        self.tooltip = None
        self.notification_win = None
        self.global_stop_listener = None

    
    def load_shortcuts_config(self):
        """Load shortcuts configuration from file or use defaults"""
        default_shortcuts = {
            "Start Recording": "F9",
            "Stop Recording": "S",  # Removed hidden recording
            "Play All Steps": "F5",  # Removed hidden playback
            "Stop Playback": "Q",
            "New Session": "Ctrl+N",
            "Open File": "Ctrl+O",
            "Save File": "Ctrl+S",
            "Delete Selected Step": "Delete",
            "Move Step Up": "Ctrl+Up",
            "Move Step Down": "Ctrl+Down",
        }
        
        try:
            if os.path.exists(self.shortcut_config_file):
                with open(self.shortcut_config_file, 'r') as f:
                    loaded_shortcuts = json.load(f)
                    # Merge with defaults (in case new shortcuts were added)
                    for key, value in default_shortcuts.items():
                        if key not in loaded_shortcuts:
                            loaded_shortcuts[key] = value
                    return loaded_shortcuts
        except Exception as e:
            print(f"Error loading shortcuts config: {e}")
        
        return default_shortcuts.copy()

    def save_shortcuts_config(self):
        """Save shortcuts configuration to file"""
        try:
            with open(self.shortcut_config_file, 'w') as f:
                json.dump(self.shortcuts, f, indent=2)
            return True
        except Exception as e:
            print(f"Error saving shortcuts config: {e}")
            return False

    def setup_menu_bar(self):
        """Create professional menu bar"""
        menubar = tk.Menu(self.root, bg='white', fg=self.colors['text'])
        self.root.config(menu=menubar)
        
        # File Menu
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(label="New Session", command=self.new_session, accelerator="Ctrl+N")
        file_menu.add_separator()
        file_menu.add_command(label="Open...", command=self.load_routine, accelerator="Ctrl+O")
        file_menu.add_command(label="Save", command=self.save_routine, accelerator="Ctrl+S")
        file_menu.add_command(label="Save As...", command=self.save_routine_as, accelerator="Ctrl+Shift+S")
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.root.quit)
        
        # Edit Menu
        edit_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Edit", menu=edit_menu)
        edit_menu.add_command(label="Delete Selected Step", command=self.delete_step, accelerator="Del")
        edit_menu.add_command(label="Clear All Steps", command=self.clear_all_steps)
        edit_menu.add_separator()
        edit_menu.add_command(label="Move Step Up", command=self.move_step_up, accelerator="Ctrl+Up")
        edit_menu.add_command(label="Move Step Down", command=self.move_step_down, accelerator="Ctrl+Down")
        edit_menu.add_separator()
        edit_menu.add_command(label="Add Delay to All Steps", command=self.add_delay_to_all)
        edit_menu.add_command(label="Remove All Move Steps", command=self.remove_all_moves)
        
        # Recording Menu
        record_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Recording", menu=record_menu)
        record_menu.add_command(label="Start Recording", command=self.start_recording, accelerator="F9")
        record_menu.add_command(label="Stop Recording", command=self.stop_recording, accelerator="S")
        record_menu.add_separator()
        record_menu.add_command(label="Add Sleep Step...", command=self.add_sleep_at_position)
        
        # Playback Menu
        playback_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Playback", menu=playback_menu)
        playback_menu.add_command(label="Play All Steps", command=self.replay_routine_hidden, accelerator="F5")  # Always hidden
        playback_menu.add_command(label="Stop Playback", command=self.stop_playback, accelerator="Q")
        
        # Help Menu
        help_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Help", menu=help_menu)
        help_menu.add_command(label="Quick Start Tutorial", command=self.show_tutorial)
        help_menu.add_command(label="Keyboard Shortcuts", command=self.show_shortcuts)
        help_menu.add_separator()
        help_menu.add_command(label="About", command=self.show_about)
        
        # Apply keyboard shortcuts
        self.apply_keyboard_shortcuts()
    
    def apply_keyboard_shortcuts(self):
        """Apply all keyboard shortcuts from config"""
        self.clear_all_key_bindings()
        
        for action, shortcut in self.shortcuts.items():
            tk_shortcut = self.convert_shortcut_to_tk_format(shortcut)
            if not tk_shortcut:
                continue
                
            # Map action to function
            if action == "Start Recording":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.start_recording())
            elif action == "Stop Recording":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.stop_recording())
            elif action == "Play All Steps":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.replay_routine_hidden())
            elif action == "Stop Playback":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.stop_playback())
            elif action == "New Session":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.new_session())
            elif action == "Open File":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.load_routine())
            elif action == "Save File":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.save_routine())
            elif action == "Delete Selected Step":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.delete_step())
            elif action == "Move Step Up":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.move_step_up())
            elif action == "Move Step Down":
                self.root.bind(f'<{tk_shortcut}>', lambda e: self.move_step_down())
    
    def clear_all_key_bindings(self):
        """Clear all keyboard bindings to avoid conflicts"""
        # List of common key sequences to unbind
        common_keys = [
            'F1', 'F2', 'F3', 'F4', 'F5', 'F6', 'F7', 'F8', 'F9', 'F10', 'F11', 'F12',
            'Control-n', 'Control-o', 'Control-s', 'Control-Shift-S',
            'Delete', 'Control-Up', 'Control-Down',
            'q', 'Q', 's', 'S'
        ]
        
        for key in common_keys:
            try:
                self.root.unbind(f'<{key}>')
            except:
                pass
    
    def convert_shortcut_to_tk_format(self, shortcut):
        """Convert shortcut string to Tkinter format"""
        if not shortcut:
            return ""
        
        # Remove any existing angle brackets
        shortcut = shortcut.replace('<', '').replace('>', '')
        
        # Split by '+' to handle modifiers
        parts = shortcut.split('+')
        
        # Convert modifiers to Tkinter format
        tk_parts = []
        for part in parts:
            part = part.strip().lower()
            if part == 'ctrl':
                tk_parts.append('Control')
            elif part == 'shift':
                tk_parts.append('Shift')
            elif part == 'alt':
                tk_parts.append('Alt')
            elif part.startswith('f') and part[1:].isdigit():
                # Function keys
                tk_parts.append(part.upper())
            elif part in ['up', 'down', 'left', 'right']:
                # Arrow keys
                tk_parts.append(part.capitalize())
            elif part == 'delete':
                tk_parts.append('Delete')
            elif part == 'escape':
                tk_parts.append('Escape')
            elif part == 'return':
                tk_parts.append('Return')
            elif part == 'tab':
                tk_parts.append('Tab')
            elif part == 'space':
                tk_parts.append('space')
            elif part == 'backspace':
                tk_parts.append('BackSpace')
            elif len(part) == 1:
                # Single character
                tk_parts.append(part)
            else:
                # Keep as is
                tk_parts.append(part)
        
        # Reconstruct the shortcut
        tk_shortcut = '-'.join(tk_parts)
        
        # Single keys don't need modifiers
        if len(tk_parts) == 1:
            return tk_parts[0]
        
        return tk_shortcut
    
    def setup_styles(self):
        """Configure ttk styles"""
        style = ttk.Style()
        style.theme_use('clam')
        
        style.configure('Main.TFrame', background=self.colors['light_bg'])
        style.configure('Card.TFrame', background=self.colors['card_bg'], relief='flat')
        
        # Button styles
        style.configure('Primary.TButton',
                       background=self.colors['secondary'],
                       foreground='white',
                       borderwidth=0,
                       font=('Segoe UI', 9, 'bold'),
                       padding=(12, 8))
        style.map('Primary.TButton',
                 background=[('active', self.colors['accent'])])
        
        style.configure('Success.TButton',
                       background=self.colors['success'],
                       foreground='white',
                       borderwidth=0,
                       font=('Segoe UI', 9, 'bold'),
                       padding=(12, 8))
        
        style.configure('Danger.TButton',
                       background=self.colors['danger'],
                       foreground='white',
                       borderwidth=0,
                       font=('Segoe UI', 9, 'bold'),
                       padding=(12, 8))
        
        style.configure('Tool.TButton',
                       background=self.colors['card_bg'],
                       foreground=self.colors['text'],
                       borderwidth=1,
                       font=('Segoe UI', 9),
                       padding=(10, 6))
        style.map('Tool.TButton',
                 background=[('active', self.colors['hover'])])
        
        # Treeview
        style.configure('Treeview',
                       background='white',
                       foreground=self.colors['text'],
                       rowheight=28,
                       fieldbackground='white',
                       borderwidth=0)
        style.configure('Treeview.Heading',
                       background=self.colors['primary'],
                       foreground='white',
                       font=('Segoe UI', 9, 'bold'),
                       padding=8)
        style.map('Treeview', background=[('selected', self.colors['secondary'])])
        
        style.configure('TLabelframe',
                       background=self.colors['card_bg'],
                       bordercolor=self.colors['border'],
                       relief='solid',
                       borderwidth=1)
        style.configure('TLabelframe.Label',
                       background=self.colors['card_bg'],
                       foreground=self.colors['primary'],
                       font=('Segoe UI', 10, 'bold'))
    
    def setup_ui(self):
        """Setup main UI layout"""
        # Main container with padding
        main_frame = ttk.Frame(self.root, style='Main.TFrame')
        main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # Top toolbar
        self.create_toolbar(main_frame)
        
        # Content area (2-column layout)
        content_frame = ttk.Frame(main_frame, style='Main.TFrame')
        content_frame.pack(fill=tk.BOTH, expand=True, pady=(10, 0))
        
        # Left: Steps list (70%)
        left_frame = ttk.LabelFrame(content_frame, text="  Recorded Steps  ", padding=15)
        left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 8))
        
        self.create_steps_list(left_frame)
        
        # Right: Controls (30%)
        right_frame = ttk.Frame(content_frame, style='Main.TFrame')
        right_frame.pack(side=tk.RIGHT, fill=tk.BOTH)
        
        self.create_controls(right_frame)
        
        # Bottom status bar
        self.create_status_bar(main_frame)
    
    def create_toolbar(self, parent):
        """Create compact top toolbar with only 4 buttons"""
        toolbar = ttk.Frame(parent, style='Card.TFrame', relief='solid', borderwidth=1)
        toolbar.pack(fill=tk.X, pady=(0, 8))
        
        inner = ttk.Frame(toolbar, style='Card.TFrame')
        inner.pack(fill=tk.X, padx=8, pady=6)
        
        # Only 4 buttons: Record, Stop Record, Play All, Stop Play
        left_actions = ttk.Frame(inner, style='Card.TFrame')
        left_actions.pack(side=tk.LEFT)
        
        # Record button (hides GUI)
        self.record_btn = ttk.Button(left_actions, text="🔴 Record", 
                                    command=self.start_recording, 
                                    style='Primary.TButton', width=10)
        self.record_btn.pack(side=tk.LEFT, padx=2)
        
        # Stop Recording button
        self.stop_btn = ttk.Button(left_actions, text="⏹️ Stop Rec", 
                                  command=self.stop_recording, 
                                  style='Danger.TButton', width=10,
                                  state=tk.DISABLED)
        self.stop_btn.pack(side=tk.LEFT, padx=2)
        
        # Play All button (hides GUI)
        self.replay_btn = ttk.Button(inner, text="▶️ Play All",
                                    command=self.replay_routine_hidden,  # Always hides GUI
                                    style='Success.TButton', width=10)
        self.replay_btn.pack(side=tk.LEFT, padx=2)
        
        # Stop Playback button
        self.stop_playback_btn = ttk.Button(inner, text="⏹️ Stop Play",
                                           command=self.stop_playback,
                                           style='Danger.TButton', width=10,
                                           state=tk.DISABLED)
        self.stop_playback_btn.pack(side=tk.LEFT, padx=2)
        
        # Right side - Stats (compact)
        self.stats_label = tk.Label(inner, 
                                   font=("Segoe UI", 9),
                                   bg=self.colors['card_bg'],
                                   fg=self.colors['text'])
        self.stats_label.pack(side=tk.RIGHT, padx=5)
        self.update_stats()
        
        # Add tooltips for buttons
        tooltips = {
            self.record_btn: "Start Recording (F9) - Hides GUI",
            self.stop_btn: "Stop Recording (S key)",
            self.replay_btn: "Play All Steps (F5) - Hides GUI",
            self.stop_playback_btn: "Stop Playback (Q key)",
        }
        
        self.setup_tooltips(tooltips)
    
    def setup_tooltips(self, tooltips):
        """Setup tooltips for widgets"""
        def show_tooltip(widget, text):
            def enter(event):
                x = widget.winfo_rootx() + 25
                y = widget.winfo_rooty() + 25
                
                # Create tooltip
                self.tooltip = tk.Toplevel(widget)
                self.tooltip.wm_overrideredirect(True)
                self.tooltip.wm_geometry(f"+{x}+{y}")
                
                label = tk.Label(self.tooltip, text=text, 
                               background="#ffffe0", relief="solid", borderwidth=1,
                               font=("Segoe UI", 8))
                label.pack()
            
            def leave(event):
                if hasattr(self, 'tooltip') and self.tooltip:
                    self.tooltip.destroy()
                    self.tooltip = None
            
            widget.bind("<Enter>", enter)
            widget.bind("<Leave>", leave)
        
        # Apply tooltips
        for widget, text in tooltips.items():
            show_tooltip(widget, text)
    
    def create_steps_list(self, parent):
        """Create steps list with treeview"""
        # Treeview
        columns = ('#', 'Name', 'Type', 'Details', 'Delay', 'Confidence')
        self.actions_tree = ttk.Treeview(parent, columns=columns, 
                                        show='headings',
                                        selectmode='browse')
        
        widths = {'#': 40, 'Name': 120, 'Type': 60, 'Details': 200, 'Delay': 60, 'Confidence': 80}
        for col, width in widths.items():
            self.actions_tree.column(col, width=width, 
                                    anchor='center' if col in ['#', 'Type', 'Delay', 'Confidence'] else 'w')
            self.actions_tree.heading(col, text=col)
        
        # Scrollbar
        scrollbar = ttk.Scrollbar(parent, orient=tk.VERTICAL, command=self.actions_tree.yview)
        self.actions_tree.configure(yscrollcommand=scrollbar.set)
        
        self.actions_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Bindings
        self.actions_tree.bind('<<TreeviewSelect>>', self.on_step_select)
        self.actions_tree.bind('<Double-1>', self.rename_step_dialog)
    
    def create_controls(self, parent):
        """Create compact control panels"""
        # Use Notebook for tabs to save space
        control_notebook = ttk.Notebook(parent)
        control_notebook.pack(fill=tk.BOTH, expand=True)
        
        # Tab 1: Step Editor
        editor_frame = ttk.Frame(control_notebook, padding=10)
        control_notebook.add(editor_frame, text="Step")
        
        # Compact delay controls
        ttk.Button(editor_frame, text="✏️ Rename", 
                  command=self.rename_step_dialog,
                  style='Tool.TButton', width=10).pack(fill=tk.X, pady=2)
        
        delay_frame = ttk.Frame(editor_frame)
        delay_frame.pack(fill=tk.X, pady=5)
        tk.Label(delay_frame, text="Delay:", 
                font=("Segoe UI", 8)).pack(side=tk.LEFT)
        self.delay_var = tk.StringVar(value="0.0")
        ttk.Entry(delay_frame, textvariable=self.delay_var, width=6).pack(side=tk.LEFT, padx=5)
        
        # Compact confidence controls
        conf_frame = ttk.Frame(editor_frame)
        conf_frame.pack(fill=tk.X, pady=5)
        tk.Label(conf_frame, text="Conf:", 
                font=("Segoe UI", 8)).pack(side=tk.LEFT)
        self.confidence_var = tk.DoubleVar(value=0.8)
        conf_slider = ttk.Scale(conf_frame, from_=0.5, to=1.0, 
                               variable=self.confidence_var,
                               orient=tk.HORIZONTAL, length=80)
        conf_slider.pack(side=tk.LEFT, padx=5)
        self.conf_display = tk.Label(conf_frame, text="0.80",
                                    font=("Segoe UI", 8, "bold"),
                                    width=4)
        self.conf_display.pack(side=tk.LEFT)
        
        ttk.Button(editor_frame, text="💾 Update",
                  command=self.update_step,
                  style='Primary.TButton').pack(fill=tk.X, pady=(10, 5))
        
        # Tab 2: Iterations
        iter_frame = ttk.Frame(control_notebook, padding=10)
        control_notebook.add(iter_frame, text="Iterate")
        
        tk.Label(iter_frame, text="Repeat:", 
                font=("Segoe UI", 9)).pack(anchor=tk.W)
        
        iter_input_frame = ttk.Frame(iter_frame)
        iter_input_frame.pack(fill=tk.X, pady=5)
        
        self.iterations_var = tk.StringVar(value="1")
        ttk.Spinbox(iter_input_frame, from_=1, to=999, 
                   textvariable=self.iterations_var,
                   width=8).pack(side=tk.LEFT)
        
        tk.Label(iter_input_frame, text="times",
                font=("Segoe UI", 8)).pack(side=tk.LEFT, padx=5)
        
        # Quick iteration buttons in a grid
        iter_grid = ttk.Frame(iter_frame)
        iter_grid.pack(fill=tk.X, pady=5)
        
        iter_buttons = [('1x', 1), ('5x', 5), ('10x', 10), ('∞', 0)]
        for i, (text, val) in enumerate(iter_buttons):
            btn = ttk.Button(iter_grid, text=text,
                            command=lambda v=val: self.iterations_var.set(str(v)),
                            style='Tool.TButton', width=4)
            btn.grid(row=0, column=i, padx=1, sticky='ew')
        
        self.iter_display = tk.Label(iter_frame, text="Iteration: 0/0",
                                    font=("Segoe UI", 9),
                                    fg=self.colors['secondary'])
        self.iter_display.pack(anchor=tk.W, pady=(10, 0))
        
        # Tab 3: Batch Ops
        batch_frame = ttk.Frame(control_notebook, padding=10)
        control_notebook.add(batch_frame, text="Batch")
        
        batch_ops = [
            ("⏱️ Add Delay to All", self.add_delay_to_all),
            ("💤 Add Sleep to All", self.add_sleep_to_all),
            ("🚫 Remove All Moves", self.remove_all_moves),
            ("🗑️ Clear All Steps", self.clear_all_steps),
            ("➕ Add Sleep Step", self.add_sleep_at_position),
            ("🗑️ Delete Step", self.delete_step),
            ("⬆️ Move Up", self.move_step_up),
            ("⬇️ Move Down", self.move_step_down),
        ]
        
        for i, (text, cmd) in enumerate(batch_ops):
            btn = ttk.Button(batch_frame, text=text,
                            command=cmd,
                            style='Tool.TButton')
            btn.pack(fill=tk.X, pady=2)
    
    def create_status_bar(self, parent):
        """Create compact status bar"""
        status_frame = ttk.Frame(parent, style='Card.TFrame', relief='solid', borderwidth=1)
        status_frame.pack(fill=tk.X, pady=(5, 0))  # Reduced pady
        
        inner = ttk.Frame(status_frame, style='Card.TFrame')
        inner.pack(fill=tk.X, padx=8, pady=4)  # Reduced padding
        
        self.status_var = tk.StringVar(value="🟢 Ready")
        tk.Label(inner, textvariable=self.status_var,
                font=("Segoe UI", 9), bg=self.colors['card_bg'],
                fg=self.colors['text'], anchor='w').pack(side=tk.LEFT, fill=tk.X, expand=True)
        
        self.progress_var = tk.StringVar(value="")
        tk.Label(inner, textvariable=self.progress_var,
                font=("Segoe UI", 9), bg=self.colors['card_bg'],
                fg=self.colors['secondary']).pack(side=tk.RIGHT)
    
    # Core functionality methods
    def calculate_delay(self):
        """Calculate delay since last action"""
        current_time = time.time()
        if self.last_action_time is None:
            delay = 0.0
        else:
            delay = round(current_time - self.last_action_time, 2)
        self.last_action_time = current_time
        return delay
    
    def capture_button_image(self, x, y, name):
        """Capture screenshot of button area"""
        left = max(0, x - 50)
        top = max(0, y - 50)
        screenshot = pyautogui.screenshot(region=(left, top, 100, 100))
        filepath = os.path.join(self.image_folder, f"{name}.png")
        screenshot.save(filepath)
        return filepath
    
    def on_click(self, x, y, button, pressed):
        """Handle mouse click events"""
        if not self.recording or not pressed:
            return
        
        click_num = len(self.actions) + 1
        timestamp = int(time.time() * 1000)
        button_name = f"Click {click_num}"
        
        delay = self.calculate_delay()
        image_path = self.capture_button_image(x, y, f"button_{timestamp}")
        
        action = {
            'type': 'click',
            'name': button_name,
            'button_name': f"button_{timestamp}",
            'image_path': image_path,
            'original_x': x,
            'original_y': y,
            'delay_before': delay,
            'confidence': 0.8
        }
        
        self.actions.append(action)
        self.root.after(0, self.update_steps_list)
        self.root.after(0, self.update_stats)
        self.root.after(0, lambda: self.status_var.set(f"✅ Captured {button_name} at ({x}, {y}) [+{delay}s]"))
    
    def on_move(self, x, y):
        """Handle mouse movement events"""
        if not self.recording:
            return
        
        # Only record significant movements (avoid recording every pixel)
        if self.actions:
            last_action = self.actions[-1]
            if last_action['type'] == 'move':
                # Update last move instead of creating new one if within 100ms
                if time.time() - self.last_action_time < 0.1:
                    last_action['x'] = x
                    last_action['y'] = y
                    return
        
        move_num = len([a for a in self.actions if a['type'] == 'move']) + 1
        delay = self.calculate_delay()
        
        action = {
            'type': 'move',
            'name': f"Move {move_num}",
            'x': x,
            'y': y,
            'delay_before': delay
        }
        
        self.actions.append(action)
        self.root.after(0, self.update_steps_list)
        self.root.after(0, self.update_stats)
        self.root.after(0, lambda: self.status_var.set(f"🖱️ Move to ({x}, {y}) [+{delay}s]"))
    
    def on_key_press(self, key):
        """Handle keyboard events"""
        # Change from ESC to 'S' key
        try:
            if hasattr(key, 'char') and key.char and key.char.lower() == 's':
                self.recording = False
                # Update notification before stopping
                if hasattr(self, 'recording_status'):
                    self.recording_status.set("Stopping recording...")
                return False
        except AttributeError:
            pass
        
        if not self.recording:
            return
        
        delay = self.calculate_delay()
        
        try:
            # Handle special keys
            if hasattr(key, 'char') and key.char:
                key_str = key.char
                key_type = 'char'
            else:
                key_str = str(key).replace('Key.', '')
                key_type = 'special'
            
            keystroke_num = len([a for a in self.actions if a['type'] == 'keystroke']) + 1
            
            action = {
                'type': 'keystroke',
                'name': f"Key: {key_str}",
                'key': key_str,
                'key_type': key_type,
                'delay_before': delay
            }
            
            self.actions.append(action)
            self.root.after(0, self.update_steps_list)
            self.root.after(0, self.update_stats)
            
            # Also update the notification if visible
            if hasattr(self, 'recording_status'):
                self.recording_status.set(f"Recording... (S to stop)")
            
        except Exception as e:
            print(f"Error recording keystroke: {e}")
    
    def update_steps_list(self):
        """Update the treeview with all actions"""
        for item in self.actions_tree.get_children():
            self.actions_tree.delete(item)
        
        for i, action in enumerate(self.actions, 1):
            step_name = action.get('name', f"Step {i}")
            
            if action['type'] == 'click':
                details = f"({action['original_x']}, {action['original_y']})"
                values = (i, step_name, 'Click', details, 
                         f"{action['delay_before']:.2f}s", 
                         f"{action['confidence']:.2f}")
                tags = ('click',)
            elif action['type'] == 'move':
                details = f"Move to ({action['x']}, {action['y']})"
                values = (i, step_name, 'Move', details, 
                         f"{action['delay_before']:.2f}s", "-")
                tags = ('move',)
            elif action['type'] == 'sleep':
                details = f"Sleep for {action['duration']}s"
                values = (i, step_name, 'Sleep', details, 
                         f"{action['delay_before']:.2f}s", "-")
                tags = ('sleep',)
            elif action['type'] == 'keystroke':
                details = f"Press: {action['key']}"
                values = (i, step_name, 'Keystroke', details, 
                         f"{action['delay_before']:.2f}s", "-")
                tags = ('keystroke',)
            
            item_id = str(i)
            self.actions_tree.insert('', 'end', iid=item_id, values=values, tags=tags)
            
            if i == len(self.actions):
                self.actions_tree.selection_set(item_id)
                self.actions_tree.see(item_id)
        
        # Color coding
        self.actions_tree.tag_configure('click', foreground=self.colors['secondary'])
        self.actions_tree.tag_configure('move', foreground=self.colors['movement'])
        self.actions_tree.tag_configure('sleep', foreground=self.colors['warning'])
        self.actions_tree.tag_configure('keystroke', foreground=self.colors['success'])
    
    def update_stats(self):
        """Update compact statistics display"""
        total_steps = len(self.actions)
        total_delay = sum(a.get('delay_before', 0) + a.get('duration', 0) for a in self.actions)
        clicks = sum(1 for a in self.actions if a['type'] == 'click')
        moves = sum(1 for a in self.actions if a['type'] == 'move')
        keystrokes = sum(1 for a in self.actions if a['type'] == 'keystroke')
        
        # Compact format
        self.stats_label.config(
            text=f"📊 Steps:{total_steps} | C:{clicks} | M:{moves} | K:{keystrokes} | ⏱️:{total_delay:.1f}s"
        )
    
    def start_recording(self):
        """Start recording all user actions"""
        # Minimize the main window
        self.root.iconify()
        self.root.update()
        
        # Brief pause to let window minimize
        time.sleep(0.3)
        
        # Show recording notification
        self.show_recording_notification()
        
        self.recording = True
        self.last_action_time = None  # Reset timing
        self.record_btn.config(state=tk.DISABLED)
        self.stop_btn.config(state=tk.NORMAL)
        self.status_var.set("🎥 Recording... Window minimized. Press 'S' to stop.") 
        
        def record_thread():
            # Mouse listener for clicks and movement
            self.mouse_listener = mouse.Listener(
                on_click=self.on_click,
                on_move=self.on_move
            )
            self.mouse_listener.start()
            
            # Keyboard listener
            self.kb_listener = keyboard.Listener(on_press=self.on_key_press)
            self.kb_listener.start()
            self.kb_listener.join()
            
            # Stop mouse listener when keyboard listener stops
            self.mouse_listener.stop()
            self.recording = False
            self.root.after(0, self.recording_stopped)
        
        Thread(target=record_thread, daemon=True).start()
    
    def stop_recording(self):
        """Stop recording"""
        self.recording = False
        if self.kb_listener:
            self.kb_listener.stop()
        if self.mouse_listener:
            self.mouse_listener.stop()
    
    def recording_stopped(self):
        """Clean up after recording stops"""
        # Hide recording notification
        self.hide_recording_notification()
        
        # Restore main window
        self.root.deiconify()
        self.root.lift()
        self.root.focus_force()
        
        self.record_btn.config(state=tk.NORMAL)
        self.stop_btn.config(state=tk.DISABLED)
        self.status_var.set(f"⏹️ Recording stopped. {len(self.actions)} steps recorded.")
        self.update_stats()
        
        def replay_thread():
            # Countdown before start
            for countdown in [3, 2, 1]:
                if self.stop_requested:
                    self.root.after(0, self.playback_finished)
                    self.root.after(0, self.stop_global_stop_listener)
                    return
                
                self.root.after(0, lambda c=countdown: self.status_var.set(
                    f"Starting replay in {c} seconds... Press Q to stop"))
                time.sleep(1)
            
            # Main playback loop
            while (self.current_iteration < self.total_iterations and 
                   not self.stop_requested):
                
                self.current_iteration += 1
                if self.total_iterations == float('inf'):
                    self.root.after(0, lambda: self.iter_display.config(
                        text=f"Iteration: {self.current_iteration} (Infinite)",
                        fg=self.colors['warning']))
                else:
                    self.root.after(0, lambda: self.iter_display.config(
                        text=f"Iteration: {self.current_iteration}/{self.total_iterations}",
                        fg=self.colors['secondary']))
                
                self.root.after(0, lambda: self.status_var.set(
                    f"Iteration {self.current_iteration} - Press 'Q' to stop at any time"))
                
                success_count = 0
                total_clicks = sum(1 for a in self.actions if a['type'] == 'click')
                
                for i, action in enumerate(self.actions, 1):
                    # Check for stop request
                    if self.stop_requested:
                        break
                    
                    # Update UI
                    self.root.after(0, lambda i=i: (
                        self.status_var.set(f"Iteration {self.current_iteration}: Step {i}/{len(self.actions)}..."),
                        self.progress_var.set(f"{i}/{len(self.actions)}"),
                        self.actions_tree.selection_set(str(i)),
                        self.actions_tree.see(str(i))
                    ))
                    
                    # Apply delay
                    if action['delay_before'] > 0:
                        # Check for stop during sleep
                        sleep_remaining = action['delay_before']
                        while sleep_remaining > 0 and not self.stop_requested:
                            time.sleep(min(0.05, sleep_remaining))  # Smaller sleep for quicker response
                            sleep_remaining -= 0.05
                    
                    if self.stop_requested:
                        break
                    
                    # Execute action
                    if action['type'] == 'click':
                        success, msg = self.find_and_click(action)
                        if success:
                            success_count += 1
                        self.root.after(0, lambda m=msg: self.status_var.set(m))
                        
                    elif action['type'] == 'move':
                        pyautogui.moveTo(action['x'], action['y'], duration=0.2)
                        self.root.after(0, lambda: self.status_var.set(
                            f"Iteration {self.current_iteration}: Moved to ({action['x']}, {action['y']})"))
                        
                    elif action['type'] == 'sleep':
                        # Check for stop during sleep
                        sleep_remaining = action['duration']
                        while sleep_remaining > 0 and not self.stop_requested:
                            time.sleep(min(0.05, sleep_remaining))  # Smaller sleep for quicker response
                            sleep_remaining -= 0.05
                        
                    elif action['type'] == 'keystroke':
                        if action['key_type'] == 'char':
                            pyautogui.press(action['key'])
                        else:
                            key_map = {
                                'enter': 'enter',
                                'space': 'space',
                                'tab': 'tab',
                                'backspace': 'backspace',
                                'shift': 'shift',
                                'ctrl': 'ctrl',
                                'alt': 'alt'
                            }
                            key = key_map.get(action['key'].lower(), action['key'])
                            pyautogui.press(key)
                        self.root.after(0, lambda: self.status_var.set(
                            f"Iteration {self.current_iteration}: Pressed '{action['key']}'"))
                
                # Check if we should continue
                if self.stop_requested:
                    break
                
                # Brief pause between iterations (unless last iteration)
                if self.current_iteration < self.total_iterations:
                    pause_remaining = 0.5
                    while pause_remaining > 0 and not self.stop_requested:
                        time.sleep(min(0.05, pause_remaining))
                        pause_remaining -= 0.05
            
            # Stop the global listener
            self.root.after(0, self.stop_global_stop_listener)
            
            # Playback finished
            self.root.after(0, self.playback_finished)
            
            if not self.stop_requested:
                self.root.after(0, lambda: self.status_var.set(
                    f"✅ Playback complete! {self.current_iteration} iteration(s) executed."))
            else:
                self.root.after(0, lambda: self.status_var.set(
                    f"⏹️ Playback stopped after {self.current_iteration} iteration(s)."))
            
            self.root.after(0, lambda: self.progress_var.set(""))
        
        Thread(target=replay_thread, daemon=True).start()
    
    def start_global_stop_listener(self):
        """Start global keyboard listener for stopping playback"""
        def on_press(key):
            try:
                if key.char and key.char.lower() == 'q':
                    self.stop_playback()
                    return False  # Stop listener
            except AttributeError:
                pass
            return True  # Continue listening
        
        # Start listener in a thread
        self.global_stop_listener = keyboard.Listener(on_press=on_press)
        self.global_stop_listener.start()

    def stop_global_stop_listener(self):
        """Stop the global keyboard listener"""
        if hasattr(self, 'global_stop_listener') and self.global_stop_listener:
            self.global_stop_listener.stop()
    
    def playback_finished(self):
        """Clean up after playback finishes"""
        self.playback_active = False
        self.replay_btn.config(state=tk.NORMAL)
        self.record_btn.config(state=tk.NORMAL)
        self.stop_playback_btn.config(state=tk.DISABLED)
        self.iter_display.config(text="Iteration: 0/0", fg=self.colors['text_light'])
        # Ensure global listener is stopped
        self.stop_global_stop_listener()
    
    def stop_playback(self):
        """Stop the current playback"""
        if self.playback_active:
            self.stop_requested = True
            self.status_var.set("⏹️ Stopping playback...")
            # Also stop the global listener immediately
            self.stop_global_stop_listener()
    
    def replay_routine_hidden(self):
        """Replay all recorded actions with GUI hidden by default"""
        if not self.actions:
            messagebox.showwarning("No Steps", "Please record steps first.")
            return
        
        # Get iteration count
        try:
            iter_val = int(self.iterations_var.get())
            if iter_val == 0:
                self.total_iterations = float('inf')  # Infinite
            elif iter_val > 0:
                self.total_iterations = iter_val
            else:
                messagebox.showerror("Invalid", "Iterations must be >= 0 (0 for infinite)")
                return
        except ValueError:
            messagebox.showerror("Invalid", "Please enter a valid number for iterations")
            return
        
        # Hide the GUI before starting
        self.root.iconify()
        time.sleep(0.5)
        
        # Start global keyboard listener for stop
        self.start_global_stop_listener()
        
        # Reset playback state
        self.playback_active = True
        self.stop_requested = False
        self.current_iteration = 0
        self.replay_btn.config(state=tk.DISABLED)
        self.record_btn.config(state=tk.DISABLED)
        self.stop_playback_btn.config(state=tk.NORMAL)
        
        def replay_thread():
            # Countdown before start
            for countdown in [3, 2, 1]:
                if self.stop_requested:
                    self.root.after(0, self.playback_finished)
                    self.root.after(0, self.stop_global_stop_listener)
                    self.root.after(0, self.root.deiconify)  # Restore GUI if stopped
                    return
                
                time.sleep(1)
            
            # Main playback loop
            while (self.current_iteration < self.total_iterations and 
                   not self.stop_requested):
                
                self.current_iteration += 1
                
                success_count = 0
                total_clicks = sum(1 for a in self.actions if a['type'] == 'click')
                
                for i, action in enumerate(self.actions, 1):
                    # Check for stop request
                    if self.stop_requested:
                        break
                    
                    # Apply delay
                    if action['delay_before'] > 0:
                        # Check for stop during sleep
                        sleep_remaining = action['delay_before']
                        while sleep_remaining > 0 and not self.stop_requested:
                            time.sleep(min(0.05, sleep_remaining))
                            sleep_remaining -= 0.05
                    
                    if self.stop_requested:
                        break
                    
                    # Execute action
                    if action['type'] == 'click':
                        success, msg = self.find_and_click(action)
                        if success:
                            success_count += 1
                        
                    elif action['type'] == 'move':
                        pyautogui.moveTo(action['x'], action['y'], duration=0.2)
                        
                    elif action['type'] == 'sleep':
                        # Check for stop during sleep
                        sleep_remaining = action['duration']
                        while sleep_remaining > 0 and not self.stop_requested:
                            time.sleep(min(0.05, sleep_remaining))
                            sleep_remaining -= 0.05
                        
                    elif action['type'] == 'keystroke':
                        if action['key_type'] == 'char':
                            pyautogui.press(action['key'])
                        else:
                            key_map = {
                                'enter': 'enter',
                                'space': 'space',
                                'tab': 'tab',
                                'backspace': 'backspace',
                                'shift': 'shift',
                                'ctrl': 'ctrl',
                                'alt': 'alt'
                            }
                            key = key_map.get(action['key'].lower(), action['key'])
                            pyautogui.press(key)
                
                # Check if we should continue
                if self.stop_requested:
                    break
                
                # Brief pause between iterations (unless last iteration)
                if self.current_iteration < self.total_iterations:
                    pause_remaining = 0.5
                    while pause_remaining > 0 and not self.stop_requested:
                        time.sleep(min(0.05, pause_remaining))
                        pause_remaining -= 0.05
            
            # Stop the global listener
            self.stop_global_stop_listener()
            
            # Restore GUI
            self.root.after(0, self.root.deiconify)
            self.root.after(0, self.root.lift)
            self.root.after(0, self.root.focus_force)
            
            # Playback finished
            self.root.after(0, self.playback_finished)
            
            if not self.stop_requested:
                self.root.after(0, lambda: self.status_var.set(
                    f"✅ Playback complete! {self.current_iteration} iteration(s) executed."))
            else:
                self.root.after(0, lambda: self.status_var.set(
                    f"⏹️ Playback stopped after {self.current_iteration} iteration(s)."))
            
            self.root.after(0, lambda: self.progress_var.set(""))
        
        Thread(target=replay_thread, daemon=True).start()
    
    def find_and_click(self, action):
        """Find and click a button using image recognition"""
        if self.stop_requested:
            return False, "Playback stopped"
        
        try:
            location = pyautogui.locateOnScreen(action['image_path'], 
                                               confidence=action['confidence'])
            if location:
                center_x = location.left + location.width // 2
                center_y = location.top + location.height // 2
                pyautogui.click(center_x, center_y)
                return True, f"✅ Clicked at ({center_x}, {center_y})"
            else:
                return False, "❌ Button not found on screen"
        except Exception as e:
            return False, f"⚠️ Error: {str(e)}"
    
    # Step management methods
    def on_step_select(self, event):
        """Handle step selection"""
        selection = self.actions_tree.selection()
        if selection:
            idx = int(selection[0]) - 1
            if 0 <= idx < len(self.actions):
                action = self.actions[idx]
                self.delay_var.set(f"{action['delay_before']:.2f}")
                if action['type'] == 'click':
                    self.confidence_var.set(action['confidence'])
    
    def rename_step_dialog(self, event=None):
        """Rename selected step"""
        selection = self.actions_tree.selection()
        if not selection:
            messagebox.showwarning("No Selection", "Please select a step to rename.")
            return
        
        idx = int(selection[0]) - 1
        current_name = self.actions[idx].get('name', f"Step {idx + 1}")
        
        new_name = simpledialog.askstring("Rename Step", 
                                         "Enter new name for step:",
                                         initialvalue=current_name,
                                         parent=self.root)
        
        if new_name and new_name.strip():
            self.actions[idx]['name'] = new_name.strip()
            self.update_steps_list()
            self.status_var.set(f"✅ Step renamed to '{new_name}'")
    
    def update_step(self):
        """Update selected step with current settings"""
        selection = self.actions_tree.selection()
        if not selection:
            messagebox.showwarning("No Selection", "Please select a step to update.")
            return
        
        idx = int(selection[0]) - 1
        if 0 <= idx < len(self.actions):
            action = self.actions[idx]
            
            try:
                action['delay_before'] = float(self.delay_var.get())
                if action['type'] == 'click':
                    conf = self.confidence_var.get()
                    if 0.5 <= conf <= 1.0:
                        action['confidence'] = conf
                    else:
                        messagebox.showerror("Invalid Value", "Confidence must be between 0.5 and 1.0")
                        return
                
                self.update_steps_list()
                self.update_stats()
                self.status_var.set(f"✅ Step updated successfully!")
            except ValueError:
                messagebox.showerror("Invalid Input", "Please enter valid numbers.")
    
    def delete_step(self):
        """Delete selected step"""
        selection = self.actions_tree.selection()
        if not selection:
            messagebox.showwarning("No Selection", "Please select a step to delete.")
            return
        
        idx = int(selection[0]) - 1
        if messagebox.askyesno("Confirm Delete", f"Delete step {idx + 1}?"):
            self.actions.pop(idx)
            self.update_steps_list()
            self.update_stats()
            self.status_var.set(f"🗑️ Step deleted.")
    
    def add_sleep_at_position(self):
        """Add a sleep step"""
        selection = self.actions_tree.selection()
        idx = int(selection[0]) if selection else len(self.actions)
        
        duration = simpledialog.askfloat("Add Sleep Step", 
                                        "Sleep duration in seconds:",
                                        minvalue=0.1, maxvalue=300.0,
                                        initialvalue=1.0,
                                        parent=self.root)
        if duration:
            sleep_action = {
                'type': 'sleep',
                'name': f"Sleep {duration}s",
                'duration': duration,
                'delay_before': 0.0
            }
            self.actions.insert(idx, sleep_action)
            self.update_steps_list()
            self.update_stats()
            self.status_var.set(f"⏱️ Added {duration}s sleep")
    
    def add_delay_to_all(self):
        """Add a fixed delay to all steps"""
        delay = simpledialog.askfloat("Add Delay to All Steps",
                                     "Enter delay to add to ALL steps (seconds):",
                                     minvalue=0.0, maxvalue=60.0,
                                     initialvalue=0.5,
                                     parent=self.root)
        
        if delay is not None:
            count = 0
            for action in self.actions:
                action['delay_before'] = max(0, action.get('delay_before', 0) + delay)
                count += 1
            
            self.update_steps_list()
            self.update_stats()
            self.status_var.set(f"✅ Added {delay}s delay to {count} steps") 
            self.root.after(3000, lambda: self.status_var.set("🟢 Ready"))

    def add_sleep_to_all(self):
        """Add sleep step after each existing step"""
        duration = simpledialog.askfloat("Add Sleep After Each Step",
                                        "Enter sleep duration to add AFTER each step (seconds):",
                                        minvalue=0.1, maxvalue=10.0,
                                        initialvalue=1.0,
                                        parent=self.root)
        
        if duration is not None:
            # Create new list with sleep steps inserted
            new_actions = []
            count = 0
            
            for i, action in enumerate(self.actions):
                # Add the original action
                new_actions.append(action)
                
                # Add sleep step after (except after the last step)
                if i < len(self.actions) - 1:
                    sleep_action = {
                        'type': 'sleep',
                        'name': f"Sleep {duration}s",
                        'duration': duration,
                        'delay_before': 0.0
                    }
                    new_actions.append(sleep_action)
                    count += 1
            
            self.actions = new_actions
            self.update_steps_list()
            self.update_stats()
            self.status_var.set(f"✅ Added {count} sleep steps ({duration}s each)") 
            self.root.after(3000, lambda: self.status_var.set("🟢 Ready"))

    def remove_all_moves(self):
        """Remove all mouse movement steps"""
        move_count = sum(1 for a in self.actions if a['type'] == 'move')
        
        if move_count == 0:
            self.status_var.set("⚠️ No move steps to remove")  
            self.root.after(2000, lambda: self.status_var.set("🟢 Ready"))
            return
        
        if messagebox.askyesno("Remove All Moves",
                              f"Remove all {move_count} mouse movement steps?\n"
                              f"This will only keep clicks, keystrokes, and sleep steps."):
            # Keep only non-move actions
            self.actions = [a for a in self.actions if a['type'] != 'move']
            
            self.update_steps_list()
            self.update_stats()
            self.status_var.set(f"✅ Removed {move_count} move steps")  
            self.root.after(3000, lambda: self.status_var.set("🟢 Ready"))
    
    def clear_all_steps(self):
        """Clear all recorded steps"""
        if not self.actions:
            return
        
        if messagebox.askyesno("Clear All Steps", 
                             f"Delete all {len(self.actions)} steps?\nThis cannot be undone."):
            self.actions = []
            self.update_steps_list()
            self.update_stats()
            self.status_var.set("🗑️ All steps cleared.")
    
    def new_session(self):
        """Start a new session"""
        if self.actions and messagebox.askyesno("New Session", 
                                               "Start new session? Unsaved changes will be lost."):
            self.actions = []
            self.last_action_time = None
            self.update_steps_list()
            self.update_stats()
            self.status_var.set("🟢 New session started")
    
    def move_step_up(self):
        """Move selected step up"""
        selection = self.actions_tree.selection()
        if not selection:
            return
        
        idx = int(selection[0]) - 1
        if idx > 0:
            self.actions[idx], self.actions[idx-1] = self.actions[idx-1], self.actions[idx]
            self.update_steps_list()
            self.actions_tree.selection_set(str(idx))
            self.status_var.set("🔼 Moved step up")
    
    def move_step_down(self):
        """Move selected step down"""
        selection = self.actions_tree.selection()
        if not selection:
            return
        
        idx = int(selection[0]) - 1
        if idx < len(self.actions) - 1:
            self.actions[idx], self.actions[idx+1] = self.actions[idx+1], self.actions[idx]
            self.update_steps_list()
            self.actions_tree.selection_set(str(idx + 2))
            self.status_var.set("🔽 Moved step down")
    
    def test_detection(self):
        """Test if selected click can be detected"""
        selection = self.actions_tree.selection()
        if not selection:
            messagebox.showwarning("No Selection", "Please select a step to test.")
            return
        
        idx = int(selection[0]) - 1
        action = self.actions[idx]
        
        if action['type'] != 'click':
            messagebox.showinfo("Not a Click", "This step is not a button click.")
            return
        
        self.status_var.set("🔍 Testing detection in 2 seconds...")
        
        def test_thread():
            time.sleep(2)
            try:
                location = pyautogui.locateOnScreen(action['image_path'], 
                                                   confidence=action['confidence'])
                if location:
                    msg = f"✅ Detection Success!\n\nFound at: ({location.left}, {location.top})\nSize: {location.width}x{location.height}"
                    self.root.after(0, lambda: messagebox.showinfo("Success", msg))
                else:
                    msg = "❌ Button not found.\n\nTry:\n• Lower confidence threshold\n• Ensure button is visible\n• Re-record the button"
                    self.root.after(0, lambda: messagebox.showwarning("Not Found", msg))
            except Exception as e:
                self.root.after(0, lambda: messagebox.showerror("Error", str(e)))
            
            self.root.after(0, lambda: self.status_var.set("Test complete."))
        
        Thread(target=test_thread, daemon=True).start()
    
    # File operations
    def save_routine(self):
        """Save automation routine to file"""
        if not self.actions:
            messagebox.showwarning("No Steps", "No steps to save.")
            return
        
        filename = filedialog.asksaveasfilename(
            defaultextension=".json",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            title="Save Automation"
        )
        
        if filename:
            with open(filename, 'w') as f:
                json.dump(self.actions, f, indent=2)
            self.status_var.set(f"💾 Saved {len(self.actions)} steps")
            messagebox.showinfo("Saved", f"Successfully saved {len(self.actions)} steps!")
    
    def save_routine_as(self):
        """Save as (same as save)"""
        self.save_routine()
    
    def load_routine(self):
        """Load automation routine from file"""
        filename = filedialog.askopenfilename(
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            title="Load Automation"
        )
        
        if filename:
            try:
                with open(filename, 'r') as f:
                    self.actions = json.load(f)
                self.update_steps_list()
                self.update_stats()
                self.status_var.set(f"📂 Loaded {len(self.actions)} steps")
                messagebox.showinfo("Loaded", f"Successfully loaded {len(self.actions)} steps!")
            except Exception as e:
                messagebox.showerror("Error", f"Failed to load:\n{str(e)}")
    
    # Notification methods
    def show_recording_notification(self):
        """Show a floating notification that recording is active"""
        self.notification_win = tk.Toplevel(self.root)
        self.notification_win.overrideredirect(True)  # Remove window decorations
        self.notification_win.attributes('-topmost', True)  # Always on top
        self.notification_win.attributes('-alpha', 0.9)  # Slightly transparent
        
        # Make it a small fixed size
        self.notification_win.geometry("300x100")
        
        # Position at bottom right of screen
        screen_width = self.notification_win.winfo_screenwidth()
        screen_height = self.notification_win.winfo_screenheight()
        x = screen_width - 320  # 20px margin from right
        y = screen_height - 120  # 20px margin from bottom
        self.notification_win.geometry(f"+{x}+{y}")
        
        # Red background for recording
        bg_color = '#ff4444'  # Bright red
        fg_color = 'white'
        
        self.notification_win.configure(bg=bg_color)
        
        # Add recording indicator
        tk.Label(self.notification_win, text="🔴 RECORDING", 
                 font=("Segoe UI", 14, "bold"), 
                 bg=bg_color, fg=fg_color).pack(pady=(15, 5))
        
        # Status text
        self.recording_status = tk.StringVar(value="Press 'S' to stop recording") 
        tk.Label(self.notification_win, textvariable=self.recording_status,
                 font=("Segoe UI", 10), 
                 bg=bg_color, fg=fg_color).pack()
        
        # Stats
        self.recording_stats = tk.StringVar(value="Steps: 0")
        tk.Label(self.notification_win, textvariable=self.recording_stats,
                 font=("Segoe UI", 9), 
                 bg=bg_color, fg=fg_color).pack(pady=(5, 0))
        
        # Make it semi-transparent and click-through
        self.notification_win.attributes('-transparentcolor', bg_color)
        self.notification_win.attributes('-alpha', 0.85)
        
        # Update notification window periodically
        self.update_recording_notification()

    def update_recording_notification(self):
        """Update the recording notification with current stats"""
        if hasattr(self, 'notification_win') and self.notification_win.winfo_exists():
            total_steps = len(self.actions)
            clicks = sum(1 for a in self.actions if a['type'] == 'click')
            moves = sum(1 for a in self.actions if a['type'] == 'move')
            keystrokes = sum(1 for a in self.actions if a['type'] == 'keystroke')
            
            stats_text = f"Steps: {total_steps} | Clicks: {clicks} | Moves: {moves} | Keys: {keystrokes}"
            self.recording_stats.set(stats_text)
            
            # Update every 500ms
            self.root.after(500, self.update_recording_notification)

    def hide_recording_notification(self):
        """Hide the recording notification"""
        if hasattr(self, 'notification_win') and self.notification_win.winfo_exists():
            self.notification_win.destroy()
    
    # Help dialogs
    def show_tutorial(self):
        """Show tutorial dialog"""
        tutorial = tk.Toplevel(self.root)
        tutorial.title("Quick Start Tutorial")
        tutorial.geometry("650x750")
        tutorial.configure(bg='white')
        tutorial.transient(self.root)
        tutorial.resizable(False, False)
        
        # Center window
        tutorial.update_idletasks()
        x = self.root.winfo_x() + (self.root.winfo_width() - 650) // 2
        y = self.root.winfo_y() + (self.root.winfo_height() - 550) // 2
        tutorial.geometry(f"+{x}+{y}")
        
        # Header
        header = tk.Frame(tutorial, bg=self.colors['primary'], height=80)
        header.pack(fill=tk.X)
        header.pack_propagate(False)
        
        tk.Label(header, text="Real-Time Automation Tutorial",
                font=("Segoe UI", 18, "bold"),
                bg=self.colors['primary'],
                fg='white').pack(pady=20)
        
        # Content
        content = tk.Frame(tutorial, bg='white')
        content.pack(fill=tk.BOTH, expand=True, padx=30, pady=20)
        
        steps = [
            ("1. Start Recording", 
             "Click '🔴 Start Recording' or press F9. The app will now record ALL your actions in real-time."),
            ("2. Perform Actions", 
             "Click buttons, move your mouse, and type - everything is recorded with automatic timing!"),
            ("3. Auto Delays", 
             "Delays between actions are calculated automatically based on your actual timing."),
            ("4. Stop Recording", 
             "Press 's' key when done. All your clicks, movements, and keystrokes are saved."),
            ("5. Edit & Customize", 
             "Rename steps, adjust delays, change confidence, or delete unwanted actions."),
            ("6. Play & Save", 
             "Use '▶️ Play All' to replay your automation, then save it for later!"),
        ]
        
        for title, desc in steps:
            frame = tk.Frame(content, bg='white')
            frame.pack(fill=tk.X, pady=6)
            
            tk.Label(frame, text=title,
                    font=("Segoe UI", 11, "bold"),
                    bg='white',
                    fg=self.colors['primary'],
                    anchor='w').pack(fill=tk.X)
            
            tk.Label(frame, text=desc,
                    font=("Segoe UI", 9),
                    bg='white',
                    fg=self.colors['text'],
                    anchor='w',
                    wraplength=570,
                    justify=tk.LEFT).pack(fill=tk.X, padx=(10, 0))
        
        ttk.Button(tutorial, text="Got It!", 
                  command=tutorial.destroy,
                  style='Primary.TButton').pack(pady=20)
    
    def show_shortcuts(self):
        """Show keyboard shortcuts with editing capability"""
        shortcuts_win = tk.Toplevel(self.root)
        shortcuts_win.title("Keyboard Shortcuts Editor")
        shortcuts_win.geometry("900x1000")
        shortcuts_win.configure(bg='white')
        shortcuts_win.transient(self.root)
        shortcuts_win.resizable(False, False)
        
        # Store reference to window
        self.shortcuts_window = shortcuts_win
        
        # Center
        shortcuts_win.update_idletasks()
        x = self.root.winfo_x() + (self.root.winfo_width() - 600) // 2
        y = self.root.winfo_y() + (self.root.winfo_height() - 700) // 2
        shortcuts_win.geometry(f"+{x}+{y}")
        
        # Header
        header = tk.Frame(shortcuts_win, bg=self.colors['primary'], height=80)
        header.pack(fill=tk.X)
        header.pack_propagate(False)
        
        tk.Label(header, text="Keyboard Shortcuts Editor",
                font=("Segoe UI", 16, "bold"),
                bg=self.colors['primary'],
                fg='white').pack(pady=20)
        
        tk.Label(header, text="Click 'Edit' to customize any shortcut",
                font=("Segoe UI", 10),
                bg=self.colors['primary'],
                fg='white').pack()
        
        # Content area with scrollbar
        canvas = tk.Canvas(shortcuts_win, bg='white', highlightthickness=0)
        scrollbar = ttk.Scrollbar(shortcuts_win, orient="vertical", command=canvas.yview)
        scrollable_frame = tk.Frame(canvas, bg='white')
        
        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )
        
        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        
        # Instructions
        instructions = tk.Frame(scrollable_frame, bg='white', padx=20, pady=10)
        instructions.pack(fill=tk.X)
        
        tk.Label(instructions, 
                text="Instructions:\n"
                     "1. Click 'Edit' next to any shortcut\n"
                     "2. Press your desired key combination\n"
                     "3. Click 'Save' to apply the change\n"
                     "4. Use 'Reset to Default' to restore original shortcut",
                font=("Segoe UI", 9),
                bg='white',
                fg=self.colors['text_light'],
                justify=tk.LEFT,
                wraplength=560).pack(anchor='w')
        
        # Column headers
        headers = tk.Frame(scrollable_frame, bg='white', padx=20, pady=10)
        headers.pack(fill=tk.X)
        
        tk.Label(headers, text="Action",
                font=("Segoe UI", 10, "bold"),
                bg='white',
                fg=self.colors['primary'],
                width=25,
                anchor='w').pack(side=tk.LEFT)
        
        tk.Label(headers, text="Current Shortcut",
                font=("Segoe UI", 10, "bold"),
                bg='white',
                fg=self.colors['primary'],
                width=15,
                anchor='center').pack(side=tk.LEFT, padx=(0, 10))
        
        tk.Label(headers, text="Edit",
                font=("Segoe UI", 10, "bold"),
                bg='white',
                fg=self.colors['primary'],
                width=8,
                anchor='center').pack(side=tk.LEFT)
        
        # Shortcuts list frame
        list_frame = tk.Frame(scrollable_frame, bg='white', padx=20)
        list_frame.pack(fill=tk.X)
        
        # Create the shortcuts UI inside the list_frame
        self.create_shortcut_editor_ui(list_frame)
        
        # Pack canvas and scrollbar
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")
        
        # Make window scrollable with mouse wheel
        def _on_mousewheel(event):
            canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        
        canvas.bind_all("<MouseWheel>", _on_mousewheel)
        
        # Set focus to the window
        shortcuts_win.focus_set()
        
        # Ensure window is closed properly
        def on_closing():
            self.shortcuts_window = None
        
        shortcuts_win.protocol("WM_DELETE_WINDOW", on_closing)

    def create_shortcut_editor_ui(self, parent):
        """Create UI for editing shortcuts"""
        for action in self.shortcuts.keys():
            frame = tk.Frame(parent, bg='white')
            frame.pack(fill=tk.X, pady=4)
            
            # Action label
            tk.Label(frame, text=action,
                    font=("Segoe UI", 10),
                    bg='white',
                    fg=self.colors['text'],
                    width=25,
                    anchor='w').pack(side=tk.LEFT)
            
            # Current shortcut display
            current_key = self.shortcuts[action]
            key_label = tk.Label(frame, text=current_key,
                               font=("Segoe UI", 10, "bold"),
                               bg=self.colors['light_bg'],
                               fg=self.colors['primary'],
                               width=15,
                               anchor='center',
                               relief='solid',
                               borderwidth=1)
            key_label.pack(side=tk.LEFT, padx=(0, 10))
            
            # Edit button - FIXED lambda scope issue
            # Create local variables to capture current values
            action_var = action
            label_var = key_label
            
            edit_btn = ttk.Button(frame, text="Edit",
                                 command=lambda a=action_var, lbl=label_var: self.edit_shortcut_dialog(a, lbl),
                                 style='Tool.TButton',
                                 width=8)
            edit_btn.pack(side=tk.LEFT)
            
    def edit_shortcut_dialog(self, action, key_label):
        """Show dialog to edit a keyboard shortcut - simplified version"""
        dialog = tk.Toplevel(self.root)
        dialog.title(f"Edit Shortcut: {action}")
        dialog.geometry("600x200")  # Smaller size
        dialog.configure(bg='white')
        dialog.transient(self.root)
        dialog.resizable(False, False)
        dialog.grab_set()  # Make dialog modal
        
        # Center dialog
        dialog.update_idletasks()
        x = self.root.winfo_x() + (self.root.winfo_width() - 400) // 2
        y = self.root.winfo_y() + (self.root.winfo_height() - 200) // 2
        dialog.geometry(f"+{x}+{y}")
        
        # Header
        header = tk.Frame(dialog, bg=self.colors['primary'], height=60)
        header.pack(fill=tk.X)
        header.pack_propagate(False)
        
        tk.Label(header, text=f"Edit Shortcut: {action}",
                font=("Segoe UI", 13, "bold"),
                bg=self.colors['primary'],
                fg='white').pack(pady=15)
        
        # Content area
        content = tk.Frame(dialog, bg='white')
        content.pack(fill=tk.BOTH, expand=True, padx=25, pady=20)
        
        current_key = self.shortcuts[action]
        tk.Label(content, text=f"Current: {current_key}",
                font=("Segoe UI", 9),
                bg='white',
                fg=self.colors['text_light']).pack(anchor='w', pady=(0, 10))
        
        # Key capture area
        capture_frame = tk.Frame(content, bg=self.colors['light_bg'], 
                               relief='solid', borderwidth=1, height=50)
        capture_frame.pack(fill=tk.X, pady=10)
        capture_frame.pack_propagate(False)
        
        key_display = tk.StringVar(value="Click here and press new key...")
        display_label = tk.Label(capture_frame, 
                               textvariable=key_display,
                               font=("Segoe UI", 11, "bold"),
                               bg=self.colors['light_bg'],
                               fg=self.colors['primary'])
        display_label.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # Info label
        info_label = tk.Label(content, 
                             text="Press any key or combination. Dialog will auto-close.",
                             font=("Segoe UI", 8),
                             bg='white',
                             fg=self.colors['text_light'])
        info_label.pack(anchor='w', pady=(5, 0))
        
        captured_key = []
        key_listener = None
        
        def on_key_press(key):
            """Capture keyboard shortcut and automatically save it"""
            try:
                # Clear previous capture
                captured_key.clear()
                
                # Get modifiers
                modifiers = []
                key_name = None
                
                # Check for special keys
                if hasattr(key, 'name'):
                    # Handle special keys
                    if key.name.startswith('f') and key.name[1:].isdigit():
                        key_name = key.name.upper()  # F1, F2, etc.
                    elif key.name in ['up', 'down', 'left', 'right']:
                        key_name = key.name.capitalize()
                    elif key.name == 'space':
                        key_name = 'Space'
                    elif key.name == 'enter' or key.name == 'return':
                        key_name = 'Return'
                    elif key.name == 'tab':
                        key_name = 'Tab'
                    elif key.name == 'delete':
                        key_name = 'Delete'
                    elif key.name == 'backspace':
                        key_name = 'Backspace'
                    elif key.name == 'escape':
                        key_name = 'Escape'
                    elif key.name == 'ctrl_l' or key.name == 'ctrl_r':
                        modifiers.append("Ctrl")
                        return  # Wait for another key
                    elif key.name == 'shift_l' or key.name == 'shift_r':
                        modifiers.append("Shift")
                        return  # Wait for another key
                    elif key.name == 'alt_l' or key.name == 'alt_r':
                        modifiers.append("Alt")
                        return  # Wait for another key
                    else:
                        key_name = str(key).replace("'", "")
                
                # Handle character keys
                elif hasattr(key, 'char') and key.char:
                    key_name = key.char.upper()
                
                if key_name:
                    # Build shortcut string
                    if modifiers:
                        new_shortcut = '+'.join(modifiers) + '+' + key_name
                    else:
                        new_shortcut = key_name
                    
                    # Check for conflicts (but allow anyway)
                    conflict_action = None
                    for act, shortcut in self.shortcuts.items():
                        if shortcut == new_shortcut and act != action:
                            conflict_action = act
                            break
                    
                    if conflict_action:
                        # Unbind from conflicting action
                        self.shortcuts[conflict_action] = ""  # Clear conflicting shortcut
                        self.unbind_old_shortcut(conflict_action)
                    
                    # Stop the listener
                    if key_listener:
                        key_listener.stop()
                    
                    # Update the shortcut
                    self.update_key_binding(action, new_shortcut)
                    
                    # Update the label in the shortcuts window
                    key_label.config(text=new_shortcut)
                    
                    # Close dialog
                    dialog.destroy()
                    
                    # Show brief notification
                    self.status_var.set(f"✅ Shortcut for '{action}' updated to: {new_shortcut}")
                    
                    # Refresh shortcuts display if window is still open
                    self.refresh_shortcuts_display()
                    
                    return False  # Stop listener
                    
            except Exception as e:
                print(f"Error capturing key: {e}")
        
        def start_key_listener():
            """Start listening for key presses"""
            nonlocal key_listener
            if key_listener is None:
                key_listener = keyboard.Listener(on_press=on_key_press)
                key_listener.start()
        
        def stop_key_listener():
            """Stop the key listener"""
            nonlocal key_listener
            if key_listener:
                key_listener.stop()
                key_listener = None
        
        def on_capture_click(event):
            """When capture area is clicked, start listening"""
            key_display.set("Listening... Press any key")
            start_key_listener()
        
        def cancel_edit():
            """Cancel editing - just close"""
            stop_key_listener()
            dialog.destroy()
        
        # Bind click event to capture area
        display_label.bind('<Button-1>', on_capture_click)
        capture_frame.bind('<Button-1>', on_capture_click)
        
        # Make it look clickable
        display_label.config(cursor='hand2')
        capture_frame.config(cursor='hand2')
        
        # Single close button (optional, can also just click away)
        btn_frame = tk.Frame(content, bg='white')
        btn_frame.pack(fill=tk.X, pady=(10, 0))
        
        ttk.Button(btn_frame, text="Close", 
                  command=cancel_edit,
                  style='Tool.TButton',
                  width=10).pack()
        
        # Handle dialog closing
        def on_closing():
            stop_key_listener()
            dialog.destroy()
        
        dialog.protocol("WM_DELETE_WINDOW", on_closing)
        
        # Set initial focus to the capture frame
        capture_frame.focus_set()

    def show_shortcuts(self):
        """Show keyboard shortcuts with editing capability - simplified"""
        shortcuts_win = tk.Toplevel(self.root)
        shortcuts_win.title("Keyboard Shortcuts")
        shortcuts_win.geometry("900x600")  
        shortcuts_win.configure(bg='white')
        shortcuts_win.transient(self.root)
        shortcuts_win.resizable(False, False)
        
        # Store reference to window
        self.shortcuts_window = shortcuts_win
        
        # Center
        shortcuts_win.update_idletasks()
        x = self.root.winfo_x() + (self.root.winfo_width() - 700) // 2
        y = self.root.winfo_y() + (self.root.winfo_height() - 500) // 2
        shortcuts_win.geometry(f"+{x}+{y}")
        
        # Header
        header = tk.Frame(shortcuts_win, bg=self.colors['primary'], height=70)
        header.pack(fill=tk.X)
        header.pack_propagate(False)
        
        tk.Label(header, text="Keyboard Shortcuts",
                font=("Segoe UI", 16, "bold"),
                bg=self.colors['primary'],
                fg='white').pack(pady=15)
        
        tk.Label(header, text="Click any shortcut to edit it",
                font=("Segoe UI", 10),
                bg=self.colors['primary'],
                fg='white').pack()
        
        # Content area with scrollbar
        canvas = tk.Canvas(shortcuts_win, bg='white', highlightthickness=0)
        scrollbar = ttk.Scrollbar(shortcuts_win, orient="vertical", command=canvas.yview)
        scrollable_frame = tk.Frame(canvas, bg='white')
        
        scrollable_frame.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )
        
        canvas.create_window((0, 0), window=scrollable_frame, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        
        # Instructions
        instructions = tk.Frame(scrollable_frame, bg='white', padx=20, pady=10)
        instructions.pack(fill=tk.X)
        
        tk.Label(instructions, 
                text="Instructions: Click any shortcut below, then press your new key combination.\n"
                     "The dialog will automatically close and save your change.",
                font=("Segoe UI", 9),
                bg='white',
                fg=self.colors['text_light'],
                justify=tk.LEFT,
                wraplength=560).pack(anchor='w')
        
        # Column headers
        headers = tk.Frame(scrollable_frame, bg='white', padx=20, pady=10)
        headers.pack(fill=tk.X)
        
        tk.Label(headers, text="Action",
                font=("Segoe UI", 10, "bold"),
                bg='white',
                fg=self.colors['primary'],
                width=30,
                anchor='w').pack(side=tk.LEFT)
        
        tk.Label(headers, text="Shortcut",
                font=("Segoe UI", 10, "bold"),
                bg='white',
                fg=self.colors['primary'],
                width=20,
                anchor='center').pack(side=tk.LEFT)
        
        # Shortcuts list - simpler version
        list_frame = tk.Frame(scrollable_frame, bg='white', padx=20)
        list_frame.pack(fill=tk.X)
        
        for action in self.shortcuts.keys():
            frame = tk.Frame(list_frame, bg='white')
            frame.pack(fill=tk.X, pady=4)
            
            # Action label
            tk.Label(frame, text=action,
                    font=("Segoe UI", 10),
                    bg='white',
                    fg=self.colors['text'],
                    width=30,
                    anchor='w').pack(side=tk.LEFT)
            
            # Current shortcut display - clickable
            current_key = self.shortcuts[action]
            key_label = tk.Label(frame, text=current_key,
                               font=("Segoe UI", 10, "bold"),
                               bg=self.colors['light_bg'],
                               fg=self.colors['primary'],
                               width=20,
                               anchor='center',
                               relief='solid',
                               borderwidth=1,
                               cursor='hand2')  # Make it look clickable
            
            # Bind click event
            key_label.bind('<Button-1>', 
                          lambda e, a=action, lbl=key_label: self.edit_shortcut_dialog(a, lbl))
            key_label.pack(side=tk.LEFT)
        
        # Pack canvas and scrollbar
        canvas.pack(side="left", fill="both", expand=True, padx=20, pady=10)
        scrollbar.pack(side="right", fill="y", pady=10)
        
        # Close button
        ttk.Button(shortcuts_win, text="Close", 
                  command=shortcuts_win.destroy,
                  style='Primary.TButton',
                  width=15).pack(pady=10)
        
        # Make window scrollable with mouse wheel
        def _on_mousewheel(event):
            canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        
        canvas.bind_all("<MouseWheel>", _on_mousewheel)
        
        # Ensure window is closed properly
        def on_closing():
            self.shortcuts_window = None
        
        shortcuts_win.protocol("WM_DELETE_WINDOW", on_closing)
    
    def refresh_shortcuts_display(self):
        """Refresh the shortcuts display window if it's open"""
        if hasattr(self, 'shortcuts_window') and self.shortcuts_window and self.shortcuts_window.winfo_exists():
            # Destroy and recreate the window
            self.shortcuts_window.destroy()
            self.show_shortcuts()   
 
    
    def unbind_old_shortcut(self, action):
        """Unbind the old shortcut for an action"""
        if action in self.shortcuts:
            old_shortcut = self.shortcuts[action]
            try:
                # Convert to Tkinter format
                tk_shortcut = self.convert_shortcut_to_tk_format(old_shortcut)
                if tk_shortcut:
                    # Unbind using the Tkinter format
                    self.root.unbind(f'<{tk_shortcut}>')
            except:
                pass

    def update_key_binding(self, action, new_shortcut):
        """Update a specific key binding"""
        # Map action names to binding methods
        binding_map = {
            "Start Recording": self.bind_start_recording,
            "Stop Recording": self.bind_stop_recording,
            "Play All Steps": self.bind_play_all,  # Changed from bind_play_hidden
            "Stop Playback": self.bind_stop_playback,
            "New Session": self.bind_new_session,
            "Open File": self.bind_open_file,
            "Save File": self.bind_save_file,
            "Delete Selected Step": self.bind_delete_step,
            "Move Step Up": self.bind_move_up,
            "Move Step Down": self.bind_move_down,
        }
        
        if action in binding_map:
            # Unbind old shortcut
            self.unbind_old_shortcut(action)
            
            # Update shortcut in config
            self.shortcuts[action] = new_shortcut
            
            # Apply new binding using converter
            tk_shortcut = self.convert_shortcut_to_tk_format(new_shortcut)
            if tk_shortcut:
                binding_map[action](tk_shortcut)
            
            # Save configuration
            self.save_shortcuts_config()
    
    def bind_start_recording(self, shortcut):
        """Bind start recording shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.start_recording())
        
    def bind_stop_recording(self, shortcut):
        """Bind stop recording shortcut"""
        # Note: Stop recording is handled by the 's' key in on_key_press method
        # This binding is primarily for the menu item
        pass
    
    def bind_play_all(self, shortcut):
        """Bind play all shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.replay_routine_hidden())
    
    def bind_stop_playback(self, shortcut):
        """Bind stop playback shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.stop_playback())
    
    def bind_new_session(self, shortcut):
        """Bind new session shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.new_session())
    
    def bind_open_file(self, shortcut):
        """Bind open file shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.load_routine())
    
    def bind_save_file(self, shortcut):
        """Bind save file shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.save_routine())
    
    def bind_delete_step(self, shortcut):
        """Bind delete step shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.delete_step())
    
    def bind_move_up(self, shortcut):
        """Bind move up shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.move_step_up())
    
    def bind_move_down(self, shortcut):
        """Bind move down shortcut"""
        self.root.bind(f'<{shortcut}>', lambda e: self.move_step_down())
    
    def show_about(self):
        """Show about dialog"""
        about = tk.Toplevel(self.root)
        about.title("About")
        about.geometry("450x300")
        about.configure(bg='white')
        about.transient(self.root)
        about.resizable(False, False)
        
        # Center
        about.update_idletasks()
        x = self.root.winfo_x() + (self.root.winfo_width() - 450) // 2
        y = self.root.winfo_y() + (self.root.winfo_height() - 300) // 2
        about.geometry(f"+{x}+{y}")
        
        header = tk.Frame(about, bg=self.colors['primary'], height=100)
        header.pack(fill=tk.X)
        header.pack_propagate(False)
        
        tk.Label(header, text="Magna Real-Time Automator",
                font=("Segoe UI", 18, "bold"),
                bg=self.colors['primary'],
                fg='white').pack(pady=15)
        
        tk.Label(header, text="Professional Real-Time Automation",
                font=("Segoe UI", 10),
                bg=self.colors['primary'],
                fg='white').pack()
        
        content = tk.Frame(about, bg='white')
        content.pack(fill=tk.BOTH, expand=True, padx=40, pady=30)
        
        tk.Label(content, text="Version 3.0",
                font=("Segoe UI", 11),
                bg='white',
                fg=self.colors['text']).pack(pady=5)
        
        tk.Label(content, text="Records clicks, movements, and keystrokes\nin real-time with automatic delay calculation.\nCreated by Kevin.Delong@magna.com",
                font=("Segoe UI", 9),
                bg='white',
                fg=self.colors['text_light'],
                justify=tk.CENTER).pack(pady=10)
    
    def close_notification(self):
        """Ensure notification window is closed"""
        if hasattr(self, 'notification_win') and self.notification_win and self.notification_win.winfo_exists():
            self.notification_win.destroy()

def main():
    root = tk.Tk()
    app = RealTimeAutomatorGUI(root)
    
    # Ensure notification is closed when main window closes
    def on_closing():
        app.close_notification()
        root.destroy()
    
    root.protocol("WM_DELETE_WINDOW", on_closing)
    root.after(500, app.show_tutorial)
    root.mainloop()

if __name__ == "__main__":
    main()