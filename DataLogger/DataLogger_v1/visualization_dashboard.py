"""
Interactive Visualization Dashboard for ADAS Logger
Advanced plotting and visualization capabilities
"""

import tkinter as tk
from tkinter import ttk
from collections import deque
import time
import math

try:
    from matplotlib.figure import Figure
    from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
    import matplotlib.pyplot as plt
    from matplotlib.animation import FuncAnimation
    MATPLOTLIB_AVAILABLE = True
except ImportError:
    MATPLOTLIB_AVAILABLE = False

try:
    import numpy as np
    NUMPY_AVAILABLE = True
except ImportError:
    NUMPY_AVAILABLE = False


class VisualizationDashboard:
    """Advanced visualization dashboard for real-time data"""
    
    def __init__(self, parent, logger_app):
        self.parent = parent
        self.app = logger_app
        self.fig = None
        self.canvas = None
        self.axes = {}
        self.animations = []
        
        # Data buffers
        self.can_buffer = deque(maxlen=500)
        self.eth_buffer = deque(maxlen=500)
        self.uart_buffer = deque(maxlen=500)
        self.time_buffer = deque(maxlen=500)
        
        # Heatmap data
        self.can_id_matrix = {}
        self.heatmap_time_window = 60  # seconds
        self.can_id_activity = {}  # Track activity per CAN ID
        self.heatmap_history = {}  # Store history for top IDs only
        self.heatmap_window = 50   # Number of time slots to show
        self.update_counter = 0     # Counter for time slots
        
        self.setup_dashboard()
    
    def track_can_activity(self):
        """Track CAN message activity per ID - FIXED"""
        if not hasattr(self.app, 'data_queues'):
            return
        
        if 'CAN' not in self.app.data_queues:
            return
        
        try:
            messages_this_cycle = 0
            
            # Process up to 100 messages per cycle
            while messages_this_cycle < 100:
                try:
                    # Non-blocking get
                    msg = self.app.data_queues['CAN'].get_nowait()
                    
                    if msg is None:
                        break
                    
                    msg_id = msg.get('arbitration_id', 'unknown')
                    
                    # Initialize counter if needed
                    if msg_id not in self.can_id_activity:
                        self.can_id_activity[msg_id] = 0
                    
                    self.can_id_activity[msg_id] += 1
                    messages_this_cycle += 1
                    
                except queue.Empty:
                    # Queue is empty, normal exit
                    break
                except Exception as e:
                    # Skip this message and continue
                    break
                    
        except Exception as e:
            # Silent fail for tracking errors
            pass

    
    
    def setup_dashboard(self):
        """Setup the visualization dashboard with proper spacing"""
        if not MATPLOTLIB_AVAILABLE:
            ttk.Label(self.parent, text="Matplotlib not available - visualizations disabled",
                     foreground='red').pack(pady=20)
            return
        
        # Create figure with better DPI and size for clarity
        self.fig = Figure(figsize=(15, 9), dpi=90, facecolor='#f0f0f0')
        
        # Add main title with more top padding
        self.fig.suptitle(' ', 
                         fontsize=16, fontweight='bold', y=0.98)
        
        # Create grid with MORE spacing to prevent overlap
        # Key parameters: hspace (vertical spacing), wspace (horizontal spacing)
        gs = self.fig.add_gridspec(3, 3, 
                                   hspace=0.45,    # Increased from 0.3
                                   wspace=0.35,     # Keep horizontal spacing
                                   left=0.08,       # More left margin
                                   right=0.95,      # More right margin
                                   top=0.94,        # More space below title
                                   bottom=0.06)     # More bottom margin
        
        # Top row - Main time series (spans all columns)
        self.axes['timeseries'] = self.fig.add_subplot(gs[0, :])
        self.setup_timeseries_plot()
        
        # Middle row - Three panels
        self.axes['can_dist'] = self.fig.add_subplot(gs[1, 0])
        self.setup_distribution_plot(self.axes['can_dist'], 'CAN Rate')
        
        self.axes['eth_dist'] = self.fig.add_subplot(gs[1, 1])
        self.setup_distribution_plot(self.axes['eth_dist'], 'Ethernet Rate')
        
        self.axes['bus_util'] = self.fig.add_subplot(gs[1, 2])
        self.setup_gauge_plot(self.axes['bus_util'], 'Bus Utilization')
        
        # Bottom row - Two panels (give more space to heatmap)
        self.axes['heatmap'] = self.fig.add_subplot(gs[2, 0:2])
        self.setup_heatmap()
        
        self.axes['scatter'] = self.fig.add_subplot(gs[2, 2])
        self.setup_scatter_plot()
        
        # Create canvas
        self.canvas = FigureCanvasTkAgg(self.fig, self.parent)
        self.canvas.get_tk_widget().pack(fill='both', expand=True)
        
        # Control panel
        self.setup_control_panel()
    
    def setup_control_panel(self):
        """Setup visualization control panel"""
        control_frame = ttk.Frame(self.parent)
        control_frame.pack(fill='x', pady=5)
        
        ttk.Button(control_frame, text="📊 Refresh", 
                  command=self.manual_refresh).pack(side='left', padx=5)
        
        ttk.Button(control_frame, text="📸 Save Snapshot", 
                  command=self.save_snapshot).pack(side='left', padx=5)
        
        ttk.Button(control_frame, text="🔄 Reset Buffers", 
                  command=self.reset_buffers).pack(side='left', padx=5)
        
        # Auto-refresh toggle
        self.auto_refresh_var = tk.BooleanVar(value=True)
        ttk.Checkbutton(control_frame, text="Auto-refresh", 
                       variable=self.auto_refresh_var).pack(side='left', padx=5)
        
        # Time window selector
        ttk.Label(control_frame, text="Time Window:").pack(side='left', padx=5)
        self.time_window_var = tk.StringVar(value="30s")
        time_combo = ttk.Combobox(control_frame, textvariable=self.time_window_var,
                                 values=['10s', '30s', '60s', '5min', '10min'], 
                                 width=10, state='readonly')
        time_combo.pack(side='left', padx=5)
        time_combo.bind('<<ComboboxSelected>>', self.on_time_window_change)
    
    def setup_timeseries_plot(self):
        """Setup main time series plot with proper spacing"""
        ax = self.axes['timeseries']
        ax.set_title('Multi-Interface Data Rate Monitor', 
                    fontsize=12, fontweight='bold', pad=10)
        ax.set_xlabel('Time (seconds)', fontsize=9)
        ax.set_ylabel('Rate (msg/pkt per second)', fontsize=9)
        ax.grid(True, alpha=0.3, linestyle='--')
        ax.set_facecolor('#ffffff')
        ax.tick_params(labelsize=8)  # Smaller tick labels


    def setup_distribution_plot(self, ax, title):
        """Setup distribution histogram with proper spacing"""
        ax.set_title(title, fontweight='bold', fontsize=10, pad=8)
        ax.set_xlabel('Value', fontsize=8)
        ax.set_ylabel('Frequency', fontsize=8)
        ax.grid(True, alpha=0.3, axis='y')
        ax.set_facecolor('#ffffff')
        ax.tick_params(labelsize=7)  # Smaller tick labels


    def setup_gauge_plot(self, ax, title):
        """Setup gauge/dial plot with proper spacing"""
        ax.set_title(title, fontweight='bold', fontsize=10, pad=8)
        ax.set_xlim(-1.5, 1.5)
        ax.set_ylim(-0.5, 1.5)
        ax.axis('off')


    def setup_heatmap(self):
        """Setup CAN ID activity heatmap with proper spacing"""
        ax = self.axes['heatmap']
        ax.set_title('CAN Message ID Activity', 
                    fontweight='bold', fontsize=10, pad=8)
        ax.set_xlabel('Time Window', fontsize=8)
        ax.set_ylabel('Message ID', fontsize=8)
        ax.set_facecolor('#ffffff')
        ax.tick_params(labelsize=7)


    def setup_scatter_plot(self):
        """Setup correlation scatter plot with proper spacing"""
        ax = self.axes['scatter']
        ax.set_title('CAN vs Ethernet', fontweight='bold', fontsize=10, pad=8)
        ax.set_xlabel('CAN Rate', fontsize=8)
        ax.set_ylabel('Eth Rate', fontsize=8)
        ax.grid(True, alpha=0.3)
        ax.set_facecolor('#ffffff')
        ax.tick_params(labelsize=7)
     
    def update_visualization(self):
        if not hasattr(self, 'auto_refresh_var') or not self.auto_refresh_var.get():
            return
        
        if not hasattr(self.app, 'is_logging') or not self.app.is_logging:
            return
        
        try:
            # Calculate current time
            if hasattr(self.app, 'start_time') and self.app.start_time:
                current_time = time.time() - self.app.start_time
            else:
                current_time = 0
            
            # Track CAN activity (with error handling)
            try:
                self.track_can_activity()
            except:
                pass
            
            # Update data buffers
            try:
                self.update_data_buffers(current_time)
            except:
                pass
            
            # Update each plot individually with error handling
            try:
                self.update_timeseries()
            except Exception as e:
                if random.random() < 0.01:  # Log only 1% of errors
                    print(f"Timeseries error: {e}")
            
            try:
                self.update_distributions()
            except Exception as e:
                if random.random() < 0.01:
                    print(f"Distribution error: {e}")
            
            try:
                self.update_gauge()
            except Exception as e:
                if random.random() < 0.01:
                    print(f"Gauge error: {e}")
            
            try:
                self.update_heatmap()
            except Exception as e:
                if random.random() < 0.01:
                    print(f"Heatmap error: {e}")
            
            try:
                self.update_scatter()
            except Exception as e:
                if random.random() < 0.01:
                    print(f"Scatter error: {e}")
            
            # Skip tight_layout - causes more problems than it solves
            # with colorbars
            
            # Redraw canvas
            try:
                self.canvas.draw_idle()
            except:
                pass
            
        except Exception as e:
            # Only log major errors
            if random.random() < 0.01:
                print(f"Visualization error: {e}")    
    
    def reset_buffers(self):
        """Reset all data buffers including heatmap"""
        self.can_buffer.clear()
        self.eth_buffer.clear()
        self.uart_buffer.clear()
        self.time_buffer.clear()
        
        # Clear heatmap data
        self.can_id_activity.clear()
        self.heatmap_history.clear()
        self.update_counter = 0
        
        # Remove colorbar if exists
        if hasattr(self, 'heatmap_colorbar'):
            try:
                self.heatmap_colorbar.remove()
                delattr(self, 'heatmap_colorbar')
            except:
                pass
        
        self.manual_refresh()
        
    def set_heatmap_id_count(self, count=5):
        """Change how many top CAN IDs to show in heatmap"""
        self.heatmap_top_n = count
        self.heatmap_history.clear()  # Reset history when changing count
    
    def update_data_buffers(self, current_time):
        """Update data buffers from app statistics"""
        if not hasattr(self.app, 'session_stats'):
            return
        
        # Store current rates
        self.time_buffer.append(current_time)
        
        # Calculate rates (simplified)
        can_rate = self.app.session_stats.get('can_messages', 0) / max(current_time, 1)
        eth_rate = self.app.session_stats.get('ethernet_packets', 0) / max(current_time, 1)
        uart_rate = self.app.session_stats.get('uart_bytes', 0) / max(current_time, 1)
        
        self.can_buffer.append(can_rate)
        self.eth_buffer.append(eth_rate)
        self.uart_buffer.append(uart_rate / 100)  # Scale down for visualization
    
    def update_timeseries(self):
        """Update time series plot - fixed legend position"""
        ax = self.axes['timeseries']
        ax.clear()
        
        if len(self.time_buffer) > 1:
            times = list(self.time_buffer)
            
            # Plot each data stream
            if self.can_buffer:
                ax.plot(times, list(self.can_buffer), 
                       label='CAN', color='#3498db', linewidth=2)
            
            if self.eth_buffer:
                ax.plot(times, list(self.eth_buffer), 
                       label='Ethernet', color='#2ecc71', linewidth=2)
            
            if self.uart_buffer:
                ax.plot(times, list(self.uart_buffer), 
                       label='UART (scaled)', color='#e74c3c', linewidth=2)
            
            ax.set_title('Multi-Interface Data Rate Monitor', 
                        fontsize=12, fontweight='bold', pad=10)
            ax.set_xlabel('Time (seconds)', fontsize=9)
            ax.set_ylabel('Rate (msg/pkt per second)', fontsize=9)
            
            # FIXED: Better legend positioning to avoid overlap
            ax.legend(loc='upper right', fontsize=8, framealpha=0.9, 
                     bbox_to_anchor=(0.99, 0.99))
            
            ax.grid(True, alpha=0.3, linestyle='--')
            ax.set_facecolor('#ffffff')
            ax.tick_params(labelsize=8)
            
            # Set x-axis limits
            if times:
                ax.set_xlim(max(0, times[-1] - self.get_time_window_seconds()), 
                           times[-1] + 1)

    
    def update_distributions(self):
        """Update distribution histograms - fixed mean line labels"""
        # CAN distribution
        if self.can_buffer and len(self.can_buffer) > 10:
            ax = self.axes['can_dist']
            ax.clear()
            
            data = list(self.can_buffer)
            mean_val = sum(data) / len(data)
            
            ax.hist(data, bins=20, color='#3498db', alpha=0.7, edgecolor='black')
            ax.axvline(mean_val, color='red', linestyle='--', linewidth=2)
            
            # FIXED: Better text positioning
            ax.text(0.95, 0.95, f'Mean: {mean_val:.1f}', 
                   transform=ax.transAxes, fontsize=8,
                   verticalalignment='top', horizontalalignment='right',
                   bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))
            
            ax.set_title('CAN Rate', fontweight='bold', fontsize=10, pad=8)
            ax.set_xlabel('Rate (msg/s)', fontsize=8)
            ax.set_ylabel('Frequency', fontsize=8)
            ax.tick_params(labelsize=7)
            ax.grid(True, alpha=0.3, axis='y')
        
        # Ethernet distribution
        if self.eth_buffer and len(self.eth_buffer) > 10:
            ax = self.axes['eth_dist']
            ax.clear()
            
            data = list(self.eth_buffer)
            mean_val = sum(data) / len(data)
            
            ax.hist(data, bins=20, color='#2ecc71', alpha=0.7, edgecolor='black')
            ax.axvline(mean_val, color='red', linestyle='--', linewidth=2)
            
            # FIXED: Better text positioning
            ax.text(0.95, 0.95, f'Mean: {mean_val:.1f}', 
                   transform=ax.transAxes, fontsize=8,
                   verticalalignment='top', horizontalalignment='right',
                   bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))
            
            ax.set_title('Ethernet Rate', fontweight='bold', fontsize=10, pad=8)
            ax.set_xlabel('Rate (pkt/s)', fontsize=8)
            ax.set_ylabel('Frequency', fontsize=8)
            ax.tick_params(labelsize=7)
            ax.grid(True, alpha=0.3, axis='y')
    
    def update_gauge(self):
        """Update gauge/dial visualization"""
        ax = self.axes['bus_util']
        ax.clear()
        
        # Calculate utilization (0-100%)
        utilization = 0
        if self.can_buffer:
            # Assume max rate is 1000 msg/s for 100% utilization
            current_rate = list(self.can_buffer)[-1] if self.can_buffer else 0
            utilization = min((current_rate / 1000) * 100, 100)
        
        # Draw gauge
        self.draw_gauge(ax, utilization)
        
        ax.set_title('Bus Utilization', fontweight='bold', fontsize=10)
        ax.set_xlim(-1.5, 1.5)
        ax.set_ylim(-0.5, 1.5)
        ax.axis('off')
    
    def draw_gauge(self, ax, value):
        """Draw a gauge meter - improved text placement"""
        # Draw arc background
        theta = np.linspace(0, np.pi, 100) if NUMPY_AVAILABLE else [i * math.pi / 99 for i in range(100)]
        
        if NUMPY_AVAILABLE:
            x = np.cos(theta)
            y = np.sin(theta)
        else:
            x = [math.cos(t) for t in theta]
            y = [math.sin(t) for t in theta]
        
        ax.plot(x, y, linewidth=12, color='#ecf0f1', solid_capstyle='round')
        
        # Color segments
        segments = [
            (0, 50, '#2ecc71'),    # Green
            (50, 75, '#f39c12'),   # Yellow
            (75, 100, '#e74c3c')   # Red
        ]
        
        for start, end, color in segments:
            if NUMPY_AVAILABLE:
                segment_theta = np.linspace(start * np.pi / 100, end * np.pi / 100, 30)
                x_seg = np.cos(segment_theta)
                y_seg = np.sin(segment_theta)
            else:
                segment_theta = [start * math.pi / 100 + i * (end - start) * math.pi / 100 / 29 for i in range(30)]
                x_seg = [math.cos(t) for t in segment_theta]
                y_seg = [math.sin(t) for t in segment_theta]
            
            ax.plot(x_seg, y_seg, linewidth=12, color=color, 
                   solid_capstyle='round', alpha=0.4)
        
        # Draw needle
        needle_angle = math.pi * (1 - value / 100)
        needle_x = [0, math.cos(needle_angle) * 0.85]
        needle_y = [0, math.sin(needle_angle) * 0.85]
        ax.plot(needle_x, needle_y, linewidth=3, color='#2c3e50', 
               marker='o', markersize=10, zorder=10)
        
        # Center circle
        circle = plt.Circle((0, 0), 0.08, color='#34495e', zorder=11)
        ax.add_patch(circle)
        
        # FIXED: Value text with better positioning
        ax.text(0, -0.25, f'{value:.1f}%', 
               ha='center', va='center', 
               fontsize=18, fontweight='bold', color='#2c3e50')
        
        # FIXED: Status labels with better positioning
        ax.text(-0.9, 0.05, '0%', fontsize=8, ha='center', color='#7f8c8d')
        ax.text(0, 1.05, '50%', fontsize=8, ha='center', color='#7f8c8d')
        ax.text(0.9, 0.05, '100%', fontsize=8, ha='center', color='#7f8c8d')


    def update_scatter(self):
        """Update correlation scatter plot - fixed legend"""
        ax = self.axes['scatter']
        ax.clear()
        
        if len(self.can_buffer) > 10 and len(self.eth_buffer) > 10:
            can_data = list(self.can_buffer)
            eth_data = list(self.eth_buffer)
            
            # Match lengths
            min_len = min(len(can_data), len(eth_data))
            can_data = can_data[-min_len:]
            eth_data = eth_data[-min_len:]
            
            # Scatter plot
            ax.scatter(can_data, eth_data, alpha=0.5, s=25, 
                      c='#3498db', edgecolors='black', linewidth=0.5)
            
            # Add trend line
            if NUMPY_AVAILABLE and len(can_data) > 2:
                z = np.polyfit(can_data, eth_data, 1)
                p = np.poly1d(z)
                x_line = np.linspace(min(can_data), max(can_data), 100)
                ax.plot(x_line, p(x_line), "r--", linewidth=2)
                
                # FIXED: Better equation placement
                ax.text(0.05, 0.95, f'y={z[0]:.2f}x+{z[1]:.1f}', 
                       transform=ax.transAxes, fontsize=8,
                       verticalalignment='top',
                       bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))
            
            ax.set_title('CAN vs Ethernet', fontweight='bold', fontsize=10, pad=8)
            ax.set_xlabel('CAN Rate (msg/s)', fontsize=8)
            ax.set_ylabel('Eth Rate (pkt/s)', fontsize=8)
            ax.tick_params(labelsize=7)
            ax.grid(True, alpha=0.3)  
    
    def update_heatmap(self):
        """Update CAN ID activity heatmap - FIXED shrinking issue"""
        ax = self.axes['heatmap']
        ax.clear()  # Clear all old data
        
        if not self.can_buffer or len(self.can_buffer) < 5:
            ax.text(0.5, 0.5, 'Waiting for CAN data...', 
                   transform=ax.transAxes, ha='center', va='center',
                   fontsize=12, color='#95a5a6')
            ax.set_title('CAN Message ID Activity Heatmap (Top 5 Active IDs)', 
                        fontweight='bold', fontsize=10, pad=8)
            ax.axis('off')
            return
        
        # Get TOP 5 most active CAN IDs
        if not self.can_id_activity:
            ax.text(0.5, 0.5, 'No CAN activity detected', 
                   transform=ax.transAxes, ha='center', va='center',
                   fontsize=12, color='#95a5a6')
            ax.set_title('CAN Message ID Activity Heatmap (Top 5 Active IDs)', 
                        fontweight='bold', fontsize=10, pad=8)
            ax.axis('off')
            return
        
        # Sort by activity and get top 5
        sorted_ids = sorted(self.can_id_activity.items(), 
                           key=lambda x: x[1], reverse=True)
        top_5_ids = [id_tuple[0] for id_tuple in sorted_ids[:5]]
        
        if not top_5_ids:
            return
        
        # Update activity history for top 5 IDs only
        self.update_counter += 1
        
        for can_id in top_5_ids:
            if can_id not in self.heatmap_history:
                self.heatmap_history[can_id] = deque(maxlen=self.heatmap_window)
            
            # Get activity level (normalize to 0-1 range)
            activity_level = self.can_id_activity.get(can_id, 0)
            max_activity = max(self.can_id_activity.values()) if self.can_id_activity else 1
            normalized = activity_level / max_activity if max_activity > 0 else 0
            
            self.heatmap_history[can_id].append(normalized)
        
        # Clean up history for IDs no longer in top 5
        all_tracked_ids = list(self.heatmap_history.keys())
        for old_id in all_tracked_ids:
            if old_id not in top_5_ids:
                del self.heatmap_history[old_id]
        
        # Reset activity counters for next cycle (only keep top 5)
        self.can_id_activity = {id: 0 for id in top_5_ids}
        
        # Build matrix for heatmap (ONLY top 5 IDs)
        num_ids = len(top_5_ids)
        max_time_points = max([len(self.heatmap_history[id]) for id in top_5_ids])
        
        if NUMPY_AVAILABLE and max_time_points > 0:
            # Create clean matrix
            matrix = np.zeros((num_ids, max_time_points))
            
            for i, can_id in enumerate(top_5_ids):
                history = list(self.heatmap_history[can_id])
                for j, val in enumerate(history):
                    matrix[i, j] = val
            
            # FIX 1: Use 'equal' aspect instead of 'auto' to prevent shrinking
            im = ax.imshow(matrix, aspect='equal', cmap='YlOrRd', 
                          interpolation='nearest', vmin=0, vmax=1,
                          extent=[0, max_time_points, num_ids, 0])  # Set explicit extent
            
            # FIX 2: Set explicit axis limits
            ax.set_xlim(0, max_time_points)
            ax.set_ylim(num_ids, 0)  # Inverted Y-axis (top to bottom)
            
            # Set Y-axis labels (CAN IDs) - positioned at center of each row
            ax.set_yticks(np.arange(num_ids) + 0.5)
            ax.set_yticklabels([f'{id}' for id in top_5_ids], fontsize=9)
            
            # Set X-axis labels - show every 10 time points
            if max_time_points > 10:
                tick_step = max(1, max_time_points // 10)
                tick_positions = np.arange(0, max_time_points, tick_step)
                ax.set_xticks(tick_positions)
                ax.set_xticklabels([f'{int(pos)}' for pos in tick_positions], fontsize=8)
            else:
                ax.set_xticks(np.arange(max_time_points))
                ax.set_xticklabels([f'{int(i)}' for i in range(max_time_points)], fontsize=8)
            
            # FIX 3: Remove old colorbar properly and create new one
            try:
                if hasattr(self, 'heatmap_colorbar') and self.heatmap_colorbar is not None:
                    self.heatmap_colorbar.remove()
                    self.heatmap_colorbar = None
            except:
                self.heatmap_colorbar = None
            
            try:
                # Create colorbar with fixed size
                from mpl_toolkits.axes_grid1 import make_axes_locatable
                divider = make_axes_locatable(ax)
                cax = divider.append_axes("right", size="3%", pad=0.1)
                self.heatmap_colorbar = self.fig.colorbar(im, cax=cax, label='Activity')
                self.heatmap_colorbar.ax.tick_params(labelsize=7)
            except:
                # Fallback if axes_grid1 not available
                try:
                    self.heatmap_colorbar = self.fig.colorbar(im, ax=ax, 
                                                              label='Activity',
                                                              fraction=0.046, pad=0.04)
                    self.heatmap_colorbar.ax.tick_params(labelsize=7)
                except:
                    pass
            
            # Add subtle grid lines for readability
            ax.set_xticks(np.arange(-.5, max_time_points, 1), minor=True)
            ax.set_yticks(np.arange(-.5, num_ids, 1), minor=True)
            ax.grid(which="minor", color="white", linestyle='-', linewidth=1)
            ax.tick_params(which='minor', size=0)  # Hide minor tick marks
            
        else:
            # Fallback without numpy
            ax.text(0.5, 0.5, 'NumPy required for heatmap', 
                   transform=ax.transAxes, ha='center', va='center',
                   fontsize=10, color='#e74c3c')
        
        # Title and labels
        ax.set_title('CAN Message ID Activity Heatmap (Top 5 Active IDs)', 
                    fontweight='bold', fontsize=10, pad=8)
        ax.set_xlabel('Time Samples', fontsize=9)
        ax.set_ylabel('CAN Message ID', fontsize=9)
    
    def apply_tight_layout(self):
        """Apply tight layout to prevent overlaps"""
        try:
            self.fig.tight_layout(rect=[0, 0, 1, 0.96])  # Leave space for suptitle
        except:
            pass  # Sometimes tight_layout can fail, that's okay
    
    def get_time_window_seconds(self):
        """Convert time window string to seconds"""
        window = self.time_window_var.get()
        conversions = {'10s': 10, '30s': 30, '60s': 60, '5min': 300, '10min': 600}
        return conversions.get(window, 30)
    
    def on_time_window_change(self, event):
        """Handle time window change"""
        window_seconds = self.get_time_window_seconds()
        
        # Update buffer sizes
        new_maxlen = int(window_seconds * 10)  # Assuming ~10 samples per second
        
        self.can_buffer = deque(self.can_buffer, maxlen=new_maxlen)
        self.eth_buffer = deque(self.eth_buffer, maxlen=new_maxlen)
        self.uart_buffer = deque(self.uart_buffer, maxlen=new_maxlen)
        self.time_buffer = deque(self.time_buffer, maxlen=new_maxlen)
        
        self.manual_refresh()
    
    def manual_refresh(self):
        """Manually trigger visualization refresh"""
        self.update_visualization()
    
    def reset_buffers(self):
        """Reset all data buffers"""
        self.can_buffer.clear()
        self.eth_buffer.clear()
        self.uart_buffer.clear()
        self.time_buffer.clear()
        self.manual_refresh()
    
    def save_snapshot(self):
        """Save current visualization as image"""
        from tkinter import filedialog
        import datetime
        
        filename = filedialog.asksaveasfilename(
            defaultextension=".png",
            filetypes=[("PNG Image", "*.png"), ("PDF Document", "*.pdf"), ("All Files", "*.*")],
            initialfile=f"adas_dashboard_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.png"
        )
        
        if filename:
            self.fig.savefig(filename, dpi=300, bbox_inches='tight', facecolor='white')
            self.app.log_message(f"Dashboard snapshot saved: {filename}")


def integrate_visualization_dashboard(logger_app):
    """Integrate visualization dashboard into the logger"""
    
    # Create a new tab for the dashboard
    viz_frame = ttk.Frame(logger_app.notebook)
    logger_app.notebook.insert(2, viz_frame, text="📊 Live Dashboard")
    
    # Create dashboard instance
    dashboard = VisualizationDashboard(viz_frame, logger_app)
    
    # Start automatic updates
    def update_loop():
        if hasattr(logger_app, 'is_logging') and logger_app.is_logging:
            dashboard.update_visualization()
        logger_app.root.after(1000, update_loop)  # Update every second
    
    logger_app.root.after(1000, update_loop)
    
    return dashboard
