import re
import difflib
import argparse
from datetime import datetime, timedelta
import matplotlib.pyplot as plt
import numpy as np
from collections import Counter, defaultdict
import pandas as pd
from typing import List, Dict, Tuple, Optional
import json
import os
import sys
import struct

class RXMessageParser:
    """Parser to analyze and visualize differences in RX messages"""
    
    def __init__(self, time_format: str = "%H:%M:%S.%f"):
        """
        Initialize the RX message parser
        
        Args:
            time_format: Format string for parsing timestamps
        """
        self.time_format = time_format
        self.messages = []
        self.stats = {}
        
    def parse_file(self, file_path: str) -> List[Dict]:
        """
        Parse RX messages from various file formats
        
        Args:
            file_path: Path to the log file (.asc, .txt, .blf)
        
        Returns:
            List of parsed message dictionaries
        """
        self.messages = []
        
        # Check file extension and use appropriate parser
        file_ext = os.path.splitext(file_path)[1].lower()
        
        try:
            if file_ext == '.asc':
                return self._parse_asc_file(file_path)
            elif file_ext == '.blf':
                return self._parse_blf_file(file_path)
            elif file_ext == '.txt':
                return self._parse_txt_file(file_path)
            else:
                print(f"Unsupported file format: {file_ext}. Trying generic parser...")
                return self._parse_generic_file(file_path)
                
        except FileNotFoundError:
            print(f"File not found: {file_path}")
            return []
        except Exception as e:
            print(f"Error parsing file: {e}")
            import traceback
            traceback.print_exc()
            return []
            
    def _parse_asc_file(self, file_path: str) -> List[Dict]:
        """Parse Vector ASC log format"""
        print(f"Parsing ASC file: {file_path}")
        
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as file:
                lines = file.readlines()
        except UnicodeDecodeError:
            # Try with different encoding if UTF-8 fails
            with open(file_path, 'r', encoding='latin-1', errors='ignore') as file:
                lines = file.readlines()
        
        # Vector ASC format patterns
        patterns = [
            # Vector ASC standard format with timestamp
            r'^(\d+\.\d+)\s+(\d+)\s+([RT]x)\s+(\d+)\s+([0-9A-F]+)\s+(\d+)\s+([0-9A-F\s]+)',
            # Vector ASC format with date/time
            r'^(\d{2}/\d{2}/\d{4})\s+(\d{2}:\d{2}:\d{2}\.\d+)\s+([RT]x)\s+(\d+)\s+([0-9A-F]+)\s+(\d+)\s+([0-9A-F\s]+)',
            # Simple timestamp format
            r'^(\d{2}:\d{2}:\d{2}\.\d+)\s+([RT]x)\s+([0-9A-F\s]+)',
            # Even simpler format
            r'^([RT]x)\s+([0-9A-F\s]+)'
        ]
        
        for line_idx, line in enumerate(lines):
            line = line.strip()
            if not line or line.startswith('//') or line.startswith('#'):
                continue
                
            for pattern_idx, pattern in enumerate(patterns):
                match = re.match(pattern, line, re.IGNORECASE)
                if match:
                    groups = match.groups()
                    
                    # Extract based on pattern type
                    if pattern_idx == 0:
                        # Pattern 1: timestamp channel direction can_id dlc data
                        timestamp, channel, direction, can_id, dlc, data = groups[0], groups[1], groups[2], groups[4], groups[5], groups[6]
                    elif pattern_idx == 1:
                        # Pattern 2: date time channel direction can_id dlc data
                        date_str, time_str, channel, direction, can_id, dlc, data = groups[0], groups[1], groups[2], groups[3], groups[4], groups[5], groups[6]
                        timestamp = f"{date_str} {time_str}"
                    elif pattern_idx == 2:
                        # Pattern 3: timestamp direction data
                        timestamp, direction, data = groups[0], groups[1], groups[2]
                        channel = "1"
                        can_id = "000"
                        dlc = "0"
                    elif pattern_idx == 3:
                        # Pattern 4: direction data
                        direction, data = groups[0], groups[1]
                        timestamp = f"{line_idx:08d}"
                        channel = "1"
                        can_id = "000"
                        dlc = "0"
                    else:
                        continue
                    
                    # Only process RX messages
                    if direction.lower() not in ['rx', 'r']:
                        continue
                    
                    # Clean up the data
                    clean_data = re.sub(r'\s+', '', data.strip())
                    
                    # Skip if no valid hex data
                    if not clean_data or not re.match(r'^[0-9A-F]+$', clean_data, re.IGNORECASE):
                        continue
                    
                    message = {
                        'id': len(self.messages),
                        'timestamp': timestamp,
                        'raw_data': data.strip(),
                        'hex_data': clean_data,
                        'byte_array': self._hex_to_bytes(clean_data),
                        'length': len(clean_data) // 2,
                        'parsed_time': self._parse_timestamp(timestamp),
                        'channel': channel,
                        'can_id': can_id,
                        'dlc': int(dlc) if dlc.isdigit() else 0,
                        'line_number': line_idx + 1
                    }
                    self.messages.append(message)
                    break
        
        print(f"Parsed {len(self.messages)} RX messages from ASC file")
        self._calculate_statistics()
        return self.messages
    
    def _parse_blf_file(self, file_path: str) -> List[Dict]:
        """Parse BLF file format (using canmatrix library if available)"""
        print(f"Parsing BLF file: {file_path}")
        
        try:
            # First try with improved canmatrix parsing
            return self._parse_blf_with_canmatrix(file_path)
        except Exception as e:
            print(f"Error with canmatrix parser: {e}. Trying basic BLF parser...")
            return self._parse_basic_blf(file_path)
    
    def _parse_blf_with_canmatrix(self, file_path: str) -> List[Dict]:
        """Parse BLF using canmatrix with better error handling"""
        try:
            import canmatrix.formats
            
            print("Using canmatrix library for BLF parsing...")
            
            # Try different import types for BLF
            try:
                # For newer canmatrix versions
                db = canmatrix.formats.loadp(file_path)
            except:
                # For older versions
                db = canmatrix.formats.load(file_path)
            
            if not db:
                raise Exception("canmatrix returned empty database")
            
            # Extract messages from the database
            message_idx = 0
            
            # Try to iterate through frames
            for frame in db.frames:
                # Extract data from the frame
                try:
                    # Get frame data as hex string
                    if hasattr(frame, 'data'):
                        if isinstance(frame.data, (bytes, bytearray)):
                            hex_data = frame.data.hex().upper()
                        else:
                            hex_data = str(frame.data)
                    else:
                        # Try to get data from signals
                        hex_data = ''
                        for signal in frame.signals:
                            if hasattr(signal, 'raw_value'):
                                if isinstance(signal.raw_value, (bytes, bytearray)):
                                    hex_data += signal.raw_value.hex().upper()
                                else:
                                    hex_data += format(signal.raw_value, '02X')
                    
                    if not hex_data:
                        continue
                    
                    message = {
                        'id': message_idx,
                        'timestamp': str(getattr(frame, 'timestamp', message_idx)),
                        'raw_data': hex_data,
                        'hex_data': hex_data,
                        'byte_array': self._hex_to_bytes(hex_data),
                        'length': len(hex_data) // 2,
                        'parsed_time': None,
                        'frame': getattr(frame, 'name', f'Frame_{message_idx}'),
                        'can_id': getattr(frame, 'id', '000'),
                        'dlc': getattr(frame, 'dlc', 0),
                        'line_number': message_idx + 1
                    }
                    self.messages.append(message)
                    message_idx += 1
                    
                except Exception as frame_e:
                    print(f"Error processing frame: {frame_e}")
                    continue
            
            print(f"Parsed {len(self.messages)} messages from BLF file using canmatrix")
            self._calculate_statistics()
            return self.messages
            
        except ImportError:
            raise Exception("canmatrix library not available")
        except Exception as e:
            raise Exception(f"canmatrix parsing failed: {str(e)}")
    
    def _parse_basic_blf(self, file_path: str) -> List[Dict]:
        """Basic BLF parser that reads binary files"""
        print("Using basic BLF parser...")
        
        try:
            with open(file_path, 'rb') as file:
                # Read the entire file
                data = file.read()
                
                # Try to parse as plain hex file first
                hex_string = data.hex().upper()
                
                # Look for CAN message patterns in the hex data
                # CAN messages often have ID (4 bytes), DLC (1 byte), Data (0-8 bytes)
                pattern = r'([0-9A-F]{8})([0-9A-F]{2})([0-9A-F]{0,16})'
                matches = re.findall(pattern, hex_string)
                
                for idx, (can_id_hex, dlc_hex, data_hex) in enumerate(matches):
                    try:
                        dlc = int(dlc_hex, 16)
                        if dlc > 8:  # DLC should be 0-8 for CAN
                            continue
                            
                        # Ensure data length matches DLC
                        expected_data_len = dlc * 2  # Each byte = 2 hex chars
                        actual_data_len = len(data_hex)
                        
                        if actual_data_len < expected_data_len:
                            data_hex = data_hex.ljust(expected_data_len, '0')
                        elif actual_data_len > expected_data_len:
                            data_hex = data_hex[:expected_data_len]
                        
                        # Clean up data
                        clean_data = re.sub(r'\s+', '', data_hex.strip())
                        
                        if not clean_data:
                            clean_data = '00' * dlc  # Fill with zeros if no data
                        
                        message = {
                            'id': idx,
                            'timestamp': f"{idx:08d}",
                            'raw_data': f"ID:{can_id_hex} DLC:{dlc_hex} DATA:{data_hex}",
                            'hex_data': clean_data,
                            'byte_array': self._hex_to_bytes(clean_data),
                            'length': len(clean_data) // 2,
                            'parsed_time': None,
                            'can_id': can_id_hex,
                            'dlc': dlc,
                            'line_number': idx + 1
                        }
                        self.messages.append(message)
                        
                    except Exception as e:
                        print(f"Error parsing CAN message {idx}: {e}")
                        continue
                
                # If no CAN patterns found, try to extract any hex data
                if len(self.messages) == 0:
                    print("No CAN patterns found, extracting raw hex data...")
                    
                    # Split hex string into bytes
                    hex_pairs = [hex_string[i:i+2] for i in range(0, min(len(hex_string), 10000), 2)]
                    
                    # Group into messages (assuming 8-byte messages)
                    for i in range(0, len(hex_pairs), 8):
                        if i + 8 > len(hex_pairs):
                            break
                            
                        message_hex = ''.join(hex_pairs[i:i+8])
                        clean_data = re.sub(r'\s+', '', message_hex.strip())
                        
                        message = {
                            'id': i // 8,
                            'timestamp': f"{i//8:08d}",
                            'raw_data': message_hex,
                            'hex_data': clean_data,
                            'byte_array': self._hex_to_bytes(clean_data),
                            'length': len(clean_data) // 2,
                            'parsed_time': None,
                            'line_number': i // 8 + 1
                        }
                        self.messages.append(message)
            
            print(f"Parsed {len(self.messages)} messages from BLF file (basic parser)")
            self._calculate_statistics()
            return self.messages
            
        except Exception as e:
            print(f"Error in basic BLF parser: {e}")
            import traceback
            traceback.print_exc()
            return self.messages
    
    def _parse_txt_file(self, file_path: str) -> List[Dict]:
        """Parse generic text log files"""
        print(f"Parsing TXT file: {file_path}")
        
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as file:
                lines = file.readlines()
        except UnicodeDecodeError:
            with open(file_path, 'r', encoding='latin-1', errors='ignore') as file:
                lines = file.readlines()
        
        # Common patterns for RX messages in text logs
        patterns = [
            # Pattern 1: timestamp RX hex_data (with various timestamp formats)
            r'^(\d{1,2}[:\.]\d{1,2}[:\.]\d{1,2}(?:\.\d+)?)\s+.*?[Rr][Xx]\s+([0-9A-F\s]+)',
            # Pattern 2: timestamp direction data
            r'^(\d+\.\d+)\s+[Rr][Xx]\s+([0-9A-F\s]+)',
            # Pattern 3: RX hex_data at start of line
            r'^[Rr][Xx]\s+([0-9A-F\s]+)',
            # Pattern 4: CAN bus format
            r'^CAN\s+(\d+)\s+[Rr][Xx]\s+([0-9A-F]+)\s+([0-9A-F\s]+)',
            # Pattern 5: Simple hex data (lines that look like hex bytes)
            r'^([0-9A-F]{2}\s+){3,}[0-9A-F]{2}$'
        ]
        
        for line_idx, line in enumerate(lines):
            line = line.strip()
            if not line or line.startswith('#') or line.startswith('//'):
                continue
                
            for pattern_idx, pattern in enumerate(patterns):
                match = re.match(pattern, line, re.IGNORECASE)
                if match:
                    groups = match.groups()
                    
                    if pattern_idx == 0:
                        # Pattern 1: timestamp RX data
                        timestamp, data = groups[0], groups[1]
                    elif pattern_idx == 1:
                        # Pattern 2: simple timestamp RX data
                        timestamp, data = groups[0], groups[1]
                    elif pattern_idx == 2:
                        # Pattern 3: RX data only
                        timestamp = f"{line_idx:06d}"
                        data = groups[0]
                    elif pattern_idx == 3:
                        # Pattern 4: CAN format
                        timestamp = f"{line_idx:06d}"
                        data = groups[2]
                    else:
                        # Pattern 5: Simple hex
                        timestamp = f"{line_idx:06d}"
                        data = line
                    
                    # Clean up the data
                    clean_data = re.sub(r'\s+', '', data.strip())
                    
                    # Skip if no valid hex data
                    if not clean_data or not re.match(r'^[0-9A-F]+$', clean_data, re.IGNORECASE):
                        continue
                    
                    message = {
                        'id': len(self.messages),
                        'timestamp': timestamp,
                        'raw_data': data.strip(),
                        'hex_data': clean_data,
                        'byte_array': self._hex_to_bytes(clean_data),
                        'length': len(clean_data) // 2,
                        'parsed_time': self._parse_timestamp(timestamp),
                        'line_number': line_idx + 1
                    }
                    self.messages.append(message)
                    break
        
        print(f"Parsed {len(self.messages)} messages from TXT file")
        self._calculate_statistics()
        return self.messages
    
    def _parse_generic_file(self, file_path: str) -> List[Dict]:
        """Generic parser for unknown file formats"""
        print(f"Parsing generic file: {file_path}")
        return self._parse_txt_file(file_path)
    
    def _hex_to_bytes(self, hex_str: str) -> List[int]:
        """Convert hex string to list of bytes"""
        if not hex_str:
            return []
        hex_str = hex_str.strip()
        if len(hex_str) % 2 != 0:
            hex_str = '0' + hex_str
        
        bytes_list = []
        for i in range(0, len(hex_str), 2):
            try:
                byte_val = int(hex_str[i:i+2], 16)
                bytes_list.append(byte_val)
            except ValueError:
                continue
        return bytes_list
    
    def _parse_timestamp(self, timestamp_str: str) -> Optional[datetime]:
        """Parse timestamp string to datetime object"""
        if not timestamp_str:
            return None
        
        # Clean the timestamp string
        timestamp_str = timestamp_str.strip()
        
        # Try different timestamp formats
        formats = [
            "%H:%M:%S.%f",
            "%H:%M:%S",
            "%M:%S.%f",
            "%S.%f",
            "%Y/%m/%d %H:%M:%S.%f",
            "%m/%d/%Y %H:%M:%S.%f",
            "%d/%m/%Y %H:%M:%S.%f"
        ]
        
        for fmt in formats:
            try:
                return datetime.strptime(timestamp_str, fmt)
            except ValueError:
                continue
        
        # If it's just a number, try to parse as seconds or milliseconds
        try:
            # Try as seconds with decimal
            seconds = float(timestamp_str)
            return datetime.fromtimestamp(seconds)
        except:
            pass
            
        # Try to parse as sequential number
        try:
            seq_num = int(timestamp_str)
            # Use today's date with the sequence as seconds
            base_date = datetime.now().replace(hour=0, minute=0, second=0, microsecond=0)
            return base_date + timedelta(seconds=seq_num)
        except:
            return None
    
    def _calculate_statistics(self):
        """Calculate basic statistics about messages"""
        if not self.messages:
            self.stats = {
                'total_messages': 0,
                'avg_length': 0,
                'min_length': 0,
                'max_length': 0,
                'unique_messages': 0,
                'time_span': None
            }
            return
        
        try:
            # Fix for the syntax error - use list comprehensions properly
            lengths = [m['length'] for m in self.messages if 'length' in m]
            unique_messages = len(set(m.get('hex_data', '') for m in self.messages))
            
            self.stats = {
                'total_messages': len(self.messages),
                'avg_length': np.mean(lengths) if lengths else 0,
                'min_length': min(lengths) if lengths else 0,
                'max_length': max(lengths) if lengths else 0,
                'unique_messages': unique_messages,
                'time_span': None
            }
            
            # Calculate time span if timestamps are available
            times = [m['parsed_time'] for m in self.messages if m.get('parsed_time')]
            if len(times) >= 2:
                time_diff = max(times) - min(times)
                self.stats['time_span'] = str(time_diff)
                
        except Exception as e:
            print(f"Error calculating statistics: {e}")
            self.stats = {
                'total_messages': len(self.messages),
                'avg_length': 0,
                'min_length': 0,
                'max_length': 0,
                'unique_messages': 0,
                'time_span': None
            }
    
    def find_message_differences(self, index1: int = 0, index2: int = 1) -> Dict:
        """
        Find differences between two messages
        
        Args:
            index1, index2: Indices of messages to compare
        
        Returns:
            Dictionary with comparison results
        """
        if not self.messages or len(self.messages) < max(index1, index2) + 1:
            return {}
            
        try:
            msg1 = self.messages[index1]
            msg2 = self.messages[index2]
            
            hex1 = msg1.get('hex_data', '')
            hex2 = msg2.get('hex_data', '')
            
            diff = difflib.SequenceMatcher(None, hex1, hex2)
            
            differences = []
            for tag, i1, i2, j1, j2 in diff.get_opcodes():
                if tag != 'equal':
                    segment1 = hex1[i1:i2]
                    segment2 = hex2[j1:j2]
                    differences.append({
                        'type': tag,
                        'position1': i1,
                        'position2': i2,
                        'position3': j1,
                        'position4': j2,
                        'segment1': segment1,
                        'segment2': segment2,
                        'size_diff': len(segment2) - len(segment1)
                    })
            
            return {
                'message1': msg1,
                'message2': msg2,
                'similarity': diff.ratio(),
                'differences': differences,
                'total_differences': len(differences)
            }
        except Exception as e:
            print(f"Error comparing messages: {e}")
            return {}
    
    def visualize_message_flow(self, max_messages: int = 50, output_file: str = None):
        """
        Create visualization of message flow and differences
        
        Args:
            max_messages: Maximum number of messages to display
            output_file: Optional file to save the plot
        """
        if not self.messages:
            print("No messages to visualize")
            return
        
        try:
            fig, axes = plt.subplots(2, 2, figsize=(15, 10))
            fig.suptitle(f'RX Messages Analysis - {len(self.messages)} messages', fontsize=16)
            
            # Plot 1: Message Length Over Time
            self._plot_message_lengths(axes[0, 0])
            
            # Plot 2: Message Type Distribution
            self._plot_message_distribution(axes[0, 1])
            
            # Plot 3: Byte Value Heatmap
            self._plot_byte_heatmap(axes[1, 0], max_messages)
            
            # Plot 4: Differences Visualization
            self._plot_differences(axes[1, 1])
            
            plt.tight_layout()
            
            if output_file:
                plt.savefig(output_file, dpi=150, bbox_inches='tight')
                print(f"Plot saved to {output_file}")
            else:
                plt.show()
                
        except Exception as e:
            print(f"Error creating visualization: {e}")
            import traceback
            traceback.print_exc()
    
    def _plot_message_lengths(self, ax):
        """Plot message lengths over sequence"""
        if len(self.messages) < 2:
            ax.text(0.5, 0.5, 'Not enough messages', 
                   ha='center', va='center', transform=ax.transAxes)
            return
        
        try:
            lengths = [m.get('length', 0) for m in self.messages]
            ax.plot(range(len(lengths)), lengths, 'b-', alpha=0.7, linewidth=2)
            ax.set_xlabel('Message Sequence')
            ax.set_ylabel('Length (bytes)')
            ax.set_title('Message Length Over Time')
            ax.grid(True, alpha=0.3)
            
            # Add statistics
            avg_len = np.mean(lengths) if lengths else 0
            ax.axhline(y=avg_len, color='r', linestyle='--', alpha=0.5, 
                      label=f'Average: {avg_len:.1f} bytes')
            ax.legend()
        except Exception as e:
            ax.text(0.5, 0.5, f'Error plotting: {str(e)[:50]}', 
                   ha='center', va='center', transform=ax.transAxes)
    
    def _plot_message_distribution(self, ax):
        """Plot distribution of unique messages"""
        if not self.messages:
            ax.text(0.5, 0.5, 'No messages', 
                   ha='center', va='center', transform=ax.transAxes)
            return
        
        try:
            # Group messages by content
            message_counts = Counter(m.get('hex_data', '') for m in self.messages)
            
            # Get top 10 most common messages
            top_messages = message_counts.most_common(10)
            
            if not top_messages:
                ax.text(0.5, 0.5, 'No unique messages found', 
                       ha='center', va='center', transform=ax.transAxes)
                return
                
            labels = [f'Type {i+1}' for i in range(len(top_messages))]
            counts = [count for _, count in top_messages]
            
            bars = ax.bar(labels, counts, alpha=0.7, color='teal')
            ax.set_xlabel('Message Type')
            ax.set_ylabel('Frequency')
            ax.set_title('Top Message Types Distribution')
            ax.set_xticklabels(labels, rotation=45, ha='right')
            
            # Add count labels on bars
            for bar, count in zip(bars, counts):
                height = bar.get_height()
                ax.text(bar.get_x() + bar.get_width()/2., height,
                       f'{count}', ha='center', va='bottom')
        except Exception as e:
            ax.text(0.5, 0.5, f'Error plotting: {str(e)[:50]}', 
                   ha='center', va='center', transform=ax.transAxes)
    
    def _plot_byte_heatmap(self, ax, max_messages: int):
        """Create heatmap of byte values"""
        if not self.messages:
            ax.text(0.5, 0.5, 'No messages', 
                   ha='center', va='center', transform=ax.transAxes)
            return
        
        try:
            # Limit number of messages for display
            display_messages = self.messages[:max_messages]
            max_len = max(m.get('length', 0) for m in display_messages)
            
            if max_len == 0:
                ax.text(0.5, 0.5, 'No valid byte data', 
                       ha='center', va='center', transform=ax.transAxes)
                return
            
            # Create matrix of byte values
            heatmap_data = np.zeros((len(display_messages), max_len))
            
            for i, msg in enumerate(display_messages):
                byte_array = msg.get('byte_array', [])
                for j, byte in enumerate(byte_array[:max_len]):
                    heatmap_data[i, j] = byte
            
            # Plot heatmap
            im = ax.imshow(heatmap_data, aspect='auto', cmap='viridis', 
                          interpolation='nearest')
            ax.set_xlabel('Byte Position')
            ax.set_ylabel('Message Index')
            ax.set_title('Byte Value Heatmap')
            
            # Add colorbar
            plt.colorbar(im, ax=ax, label='Byte Value (0-255)')
        except Exception as e:
            ax.text(0.5, 0.5, f'Error plotting: {str(e)[:50]}', 
                   ha='center', va='center', transform=ax.transAxes)
    
    def _plot_differences(self, ax):
        """Visualize differences between consecutive messages"""
        if len(self.messages) < 2:
            ax.text(0.5, 0.5, 'Not enough messages for comparison', 
                   ha='center', va='center', transform=ax.transAxes)
            return
        
        try:
            # Compare consecutive messages
            differences_count = []
            similarities = []
            
            for i in range(min(20, len(self.messages) - 1)):
                diff = self.find_message_differences(i, i + 1)
                differences_count.append(diff.get('total_differences', 0))
                similarities.append(diff.get('similarity', 0) * 100)
            
            x = range(len(differences_count))
            
            # Plot differences
            ax.bar(x, differences_count, alpha=0.6, color='red', label='Differences Count')
            ax.set_xlabel('Message Pair Index')
            ax.set_ylabel('Number of Differences', color='red')
            ax.tick_params(axis='y', labelcolor='red')
            
            # Plot similarities on second y-axis
            ax2 = ax.twinx()
            ax2.plot(x, similarities, 'g-', marker='o', linewidth=2, 
                    label='Similarity %')
            ax2.set_ylabel('Similarity (%)', color='green')
            ax2.tick_params(axis='y', labelcolor='green')
            
            ax.set_title('Message-to-Message Differences')
            ax.set_xticks(x)
            
            # Add legends
            lines1, labels1 = ax.get_legend_handles_labels()
            lines2, labels2 = ax2.get_legend_handles_labels()
            ax.legend(lines1 + lines2, labels1 + labels2, loc='upper right')
        except Exception as e:
            ax.text(0.5, 0.5, f'Error plotting: {str(e)[:50]}', 
                   ha='center', va='center', transform=ax.transAxes)
    
    def generate_detailed_report(self, output_file: str = 'rx_analysis_report.txt'):
        """Generate detailed text report of analysis"""
        if not self.messages:
            print("No messages to report")
            return
        
        try:
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write("=" * 80 + "\n")
                f.write("RX MESSAGES ANALYSIS REPORT\n")
                f.write("=" * 80 + "\n\n")
                
                f.write(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
                f.write(f"Total Messages: {len(self.messages)}\n")
                f.write(f"Unique Messages: {self.stats.get('unique_messages', 0)}\n")
                f.write(f"Average Length: {self.stats.get('avg_length', 0):.2f} bytes\n")
                f.write(f"Time Span: {self.stats.get('time_span', 'N/A')}\n\n")
                
                f.write("-" * 80 + "\n")
                f.write("MESSAGE SAMPLES\n")
                f.write("-" * 80 + "\n\n")
                
                # Show first 5 messages
                for i, msg in enumerate(self.messages[:5]):
                    f.write(f"Message {i} (Line {msg.get('line_number', 'N/A')}):\n")
                    f.write(f"  Timestamp: {msg.get('timestamp', 'N/A')}\n")
                    f.write(f"  Length: {msg.get('length', 0)} bytes\n")
                    hex_data = msg.get('hex_data', '')
                    f.write(f"  Hex Data: {hex_data[:64]}")
                    if len(hex_data) > 64:
                        f.write("...")
                    f.write("\n\n")
                
                f.write("-" * 80 + "\n")
                f.write("MESSAGE COMPARISONS\n")
                f.write("-" * 80 + "\n\n")
                
                # Compare first 3 pairs
                for i in range(min(3, len(self.messages) - 1)):
                    diff = self.find_message_differences(i, i + 1)
                    f.write(f"Comparison: Message {i} vs Message {i + 1}\n")
                    f.write(f"  Similarity: {diff.get('similarity', 0):.2%}\n")
                    f.write(f"  Differences found: {diff.get('total_differences', 0)}\n")
                    
                    differences = diff.get('differences', [])
                    for j, d in enumerate(differences[:3]):  # Show first 3 differences
                        d_type = d.get('type', 'unknown')
                        pos1 = d.get('position1', 0)
                        pos2 = d.get('position2', 0)
                        pos3 = d.get('position3', 0)
                        pos4 = d.get('position4', 0)
                        f.write(f"  Diff {j + 1}: {d_type} at pos {pos1}-{pos2} "
                               f"vs pos {pos3}-{pos4}\n")
                    f.write("\n")
            
            print(f"Report saved to {output_file}")
        except Exception as e:
            print(f"Error generating report: {e}")
            import traceback
            traceback.print_exc()

    def export_to_csv(self, output_file: str = 'rx_messages.csv'):
        """Export parsed messages to CSV format"""
        if not self.messages:
            print("No messages to export")
            return
        
        try:
            df_data = []
            for msg in self.messages:
                # Ensure all required fields exist
                df_data.append({
                    'ID': msg.get('id', ''),
                    'Line_Number': msg.get('line_number', ''),
                    'Timestamp': msg.get('timestamp', ''),
                    'Hex_Data': msg.get('hex_data', ''),
                    'Length': msg.get('length', 0),
                    'Byte_Count': len(msg.get('byte_array', [])),
                    'Parsed_Time': msg.get('parsed_time', ''),
                    'Channel': msg.get('channel', ''),
                    'CAN_ID': msg.get('can_id', ''),
                    'DLC': msg.get('dlc', ''),
                    'Frame': msg.get('frame', '')
                })
            
            df = pd.DataFrame(df_data)
            df.to_csv(output_file, index=False, encoding='utf-8')
            print(f"Messages exported to {output_file}")
        except Exception as e:
            print(f"Error exporting to CSV: {e}")
            import traceback
            traceback.print_exc()

def main():
    """Main function to handle command line arguments"""
    parser = argparse.ArgumentParser(
        description='Parse and visualize differences in RX messages from log files',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s logfile.asc --plot
  %(prog)s logfile.blf --report --csv
  %(prog)s logfile.txt --output-dir ./results --max-messages 100
  %(prog)s logfile.asc --compare 0 5 --verbose
        """
    )
    
    parser.add_argument(
        'file',
        help='Input log file (.asc, .txt, .blf)'
    )
    
    parser.add_argument(
        '--plot',
        action='store_true',
        help='Generate visualization plots'
    )
    
    parser.add_argument(
        '--report',
        action='store_true',
        help='Generate detailed text report'
    )
    
    parser.add_argument(
        '--csv',
        action='store_true',
        help='Export messages to CSV'
    )
    
    parser.add_argument(
        '--output-dir',
        type=str,
        default='.',
        help='Output directory for generated files'
    )
    
    parser.add_argument(
        '--max-messages',
        type=int,
        default=50,
        help='Maximum number of messages to display in plots (default: 50)'
    )
    
    parser.add_argument(
        '--compare',
        type=int,
        nargs=2,
        metavar=('IDX1', 'IDX2'),
        help='Compare two specific messages by index'
    )
    
    parser.add_argument(
        '--verbose',
        action='store_true',
        help='Enable verbose output'
    )
    
    parser.add_argument(
        '--output-prefix',
        type=str,
        default='rx_analysis',
        help='Prefix for output files (default: rx_analysis)'
    )
    
    args = parser.parse_args()
    
    # Check if file exists
    if not os.path.exists(args.file):
        print(f"Error: File '{args.file}' not found!")
        sys.exit(1)
    
    # Create output directory if it doesn't exist
    if not os.path.exists(args.output_dir):
        try:
            os.makedirs(args.output_dir)
        except Exception as e:
            print(f"Error creating output directory: {e}")
            sys.exit(1)
    
    # Initialize parser
    rx_parser = RXMessageParser()
    
    # Parse the file
    if args.verbose:
        print(f"Processing file: {args.file}")
        print(f"Output directory: {args.output_dir}")
    
    messages = rx_parser.parse_file(args.file)
    
    if not messages:
        print("No messages were parsed from the file.")
        sys.exit(1)
    
    # Generate outputs based on arguments
    base_output = os.path.join(args.output_dir, args.output_prefix)
    
    if args.report:
        report_file = f"{base_output}_report.txt"
        rx_parser.generate_detailed_report(report_file)
    
    if args.csv:
        csv_file = f"{base_output}_messages.csv"
        rx_parser.export_to_csv(csv_file)
    
    if args.plot:
        plot_file = f"{base_output}_plot.png"
        rx_parser.visualize_message_flow(args.max_messages, plot_file)
    
    if args.compare:
        idx1, idx2 = args.compare
        if 0 <= idx1 < len(messages) and 0 <= idx2 < len(messages):
            diff = rx_parser.find_message_differences(idx1, idx2)
            print(f"\nComparison between message {idx1} and message {idx2}:")
            print(f"  Similarity: {diff.get('similarity', 0):.2%}")
            print(f"  Total differences: {diff.get('total_differences', 0)}")
            hex1 = messages[idx1].get('hex_data', '')
            hex2 = messages[idx2].get('hex_data', '')
            print(f"  Message 1: {hex1[:32]}{'...' if len(hex1) > 32 else ''}")
            print(f"  Message 2: {hex2[:32]}{'...' if len(hex2) > 32 else ''}")
            
            # Show first few differences
            differences = diff.get('differences', [])
            if differences:
                print(f"  First 3 differences:")
                for i, d in enumerate(differences[:3]):
                    d_type = d.get('type', 'unknown')
                    pos1 = d.get('position1', 0)
                    pos2 = d.get('position2', 0)
                    print(f"    {i+1}. {d_type} at positions {pos1}-{pos2}")
        else:
            print(f"Error: Indices out of range. Valid indices: 0-{len(messages)-1}")
    
    # Always print summary if verbose or no other output specified
    if args.verbose or (not args.report and not args.csv and not args.plot and not args.compare):
        print(f"\nSummary:")
        print(f"  Total messages parsed: {len(messages)}")
        print(f"  Unique messages: {rx_parser.stats.get('unique_messages', 0)}")
        avg_len = rx_parser.stats.get('avg_length', 0)
        min_len = rx_parser.stats.get('min_length', 0)
        max_len = rx_parser.stats.get('max_length', 0)
        print(f"  Average message length: {avg_len:.2f} bytes")
        print(f"  Message length range: {min_len}-{max_len} bytes")

if __name__ == "__main__":
    main()