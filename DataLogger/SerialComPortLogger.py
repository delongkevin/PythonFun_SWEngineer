#!/usr/bin/env python3
"""
Serial Port Communication Tool
Connects to COM ports by name, sends/receives data, and auto-logs to file.
"""

import serial
import serial.tools.list_ports
import sys
import os
import time
import argparse
from datetime import datetime
import threading
import queue
import re

class SerialCommunicator:
    def __init__(self, port_name, baudrate=115200, timeout=1):
        self.port_name = port_name
        self.baudrate = baudrate
        self.timeout = timeout
        self.serial_port = None
        self.running = False
        self.receive_queue = queue.Queue()
        self.log_file = None
        self.script_dir = os.path.dirname(os.path.abspath(__file__))
        
    def find_port_by_name(self):
        """Find actual COM port from partial/full name"""
        ports = serial.tools.list_ports.comports()
        
        # Try exact match first
        for port in ports:
            if port.description == self.port_name:
                return port.device
        
        # Try partial match (case-insensitive)
        for port in ports:
            if self.port_name.lower() in port.description.lower():
                print(f"Found partial match: '{port.description}' -> {port.device}")
                return port.device
        
        # Try if port_name is already a device name (COM16, etc.)
        if re.match(r'COM\d+', self.port_name, re.IGNORECASE):
            return self.port_name
        
        return None
    
    def connect(self):
        """Connect to the serial port"""
        actual_port = self.find_port_by_name()
        
        if not actual_port:
            print(f"Error: No port found with name containing '{self.port_name}'")
            print("\nAvailable ports:")
            ports = serial.tools.list_ports.comports()
            for port in ports:
                print(f"  - {port.description} ({port.device})")
            return False
        
        try:
            print(f"Connecting to {actual_port} (from: '{self.port_name}') at {self.baudrate} baud...")
            self.serial_port = serial.Serial(
                port=actual_port,
                baudrate=self.baudrate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=self.timeout,
                xonxoff=False,
                rtscts=False,
                dsrdtr=False
            )
            
            # Create log file
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
            log_filename = f"serial_log_{actual_port.replace(':', '_')}_{timestamp}.txt"
            log_path = os.path.join(self.script_dir, log_filename)
            self.log_file = open(log_path, 'a', encoding='utf-8')
            
            print(f"Connected successfully!")
            print(f"Logging to: {log_path}")
            return True
            
        except serial.SerialException as e:
            print(f"Error connecting to {actual_port}: {e}")
            return False
        except Exception as e:
            print(f"Unexpected error: {e}")
            return False
    
    def start_receiving(self):
        """Start the receive thread"""
        if not self.serial_port or not self.serial_port.is_open:
            print("Error: Port not connected")
            return False
        
        self.running = True
        self.receive_thread = threading.Thread(target=self._receive_loop, daemon=True)
        self.receive_thread.start()
        return True
    
    def _receive_loop(self):
        """Background thread for receiving data"""
        buffer = ""
        
        while self.running and self.serial_port and self.serial_port.is_open:
            try:
                if self.serial_port.in_waiting > 0:
                    # Read available data
                    data = self.serial_port.read(self.serial_port.in_waiting)
                    
                    # Decode and process
                    try:
                        text = data.decode('utf-8', errors='replace')
                        buffer += text
                        
                        # Process complete lines
                        while '\n' in buffer:
                            line, buffer = buffer.split('\n', 1)
                            line = line.rstrip('\r')
                            self._process_received_line(line)
                    except UnicodeDecodeError:
                        # Log raw hex if can't decode
                        hex_data = data.hex()
                        self._process_received_line(f"[HEX DATA]: {hex_data}")
                
                # Small sleep to prevent CPU hogging
                time.sleep(0.01)
                
            except Exception as e:
                if self.running:  # Only print if we're supposed to be running
                    print(f"Error in receive loop: {e}")
                time.sleep(0.1)
    
    def _process_received_line(self, line):
        """Process and log a received line"""
        timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]
        formatted_line = f"[{timestamp}] RX: {line}"
        
        # Print to console
        print(formatted_line)
        
        # Log to file
        if self.log_file:
            self.log_file.write(formatted_line + '\n')
            self.log_file.flush()
        
        # Add to queue (if needed for other processing)
        self.receive_queue.put(line)
    
    def send_data(self, data, add_newline=True):
        """Send data to the serial port"""
        if not self.serial_port or not self.serial_port.is_open:
            print("Error: Port not connected")
            return False
        
        try:
            # Ensure data ends with newline if requested
            if add_newline and not data.endswith('\n'):
                data_to_send = data + '\n'
            else:
                data_to_send = data
            
            # Send the data
            self.serial_port.write(data_to_send.encode('utf-8'))
            self.serial_port.flush()
            
            # Log the sent data
            timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]
            log_line = f"[{timestamp}] TX: {data.strip()}"
            print(log_line)
            
            if self.log_file:
                self.log_file.write(log_line + '\n')
                self.log_file.flush()
            
            return True
            
        except Exception as e:
            print(f"Error sending data: {e}")
            return False
    
    def wait_for_prompt(self, prompt=">", timeout=5):
        """Wait for a specific prompt/response"""
        if not self.serial_port or not self.serial_port.is_open:
            return False
        
        start_time = time.time()
        buffer = ""
        
        while time.time() - start_time < timeout:
            if self.serial_port.in_waiting > 0:
                data = self.serial_port.read(self.serial_port.in_waiting)
                try:
                    buffer += data.decode('utf-8', errors='replace')
                    
                    # Check for prompt
                    if prompt in buffer:
                        return True
                except:
                    pass
            
            time.sleep(0.01)
        
        return False
    
    def disconnect(self):
        """Disconnect from serial port"""
        self.running = False
        
        if self.receive_thread and self.receive_thread.is_alive():
            self.receive_thread.join(timeout=2)
        
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()
            print(f"Disconnected from port")
        
        if self.log_file:
            self.log_file.close()
            print(f"Log file closed")

def list_available_ports():
    """List all available serial ports"""
    print("\nAvailable serial ports:")
    print("-" * 50)
    ports = serial.tools.list_ports.comports()
    
    if not ports:
        print("No serial ports found")
        return
    
    for i, port in enumerate(ports, 1):
        print(f"{i}. {port.description}")
        print(f"   Device: {port.device}")
        if port.hwid:
            print(f"   HWID: {port.hwid}")
        if port.manufacturer:
            print(f"   Manufacturer: {port.manufacturer}")
        if port.product:
            print(f"   Product: {port.product}")
        if port.serial_number:
            print(f"   Serial: {port.serial_number}")
        print()

def main():
    parser = argparse.ArgumentParser(
        description='Serial Port Communication Tool',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  %(prog)s --port "USB Serial Port" --send "AT"
  %(prog)s --port "COM16" --send "AT\\r\\n" --no-newline
  %(prog)s --port "USB Serial" --send "help" --wait ">"
  %(prog)s --list-ports
  %(prog)s --port "USB Serial" --interactive
        """
    )
    
    parser.add_argument('--port', '-p', type=str, required=False,
                       help='Port name or description (e.g., "USB Serial Port (COM16)" or "COM16")')
    
    parser.add_argument('--send', '-s', type=str,
                       help='Data to send (use \\r for CR, \\n for LF)')
    
    parser.add_argument('--no-newline', action='store_true',
                       help='Do not add newline to sent data')
    
    parser.add_argument('--wait', '-w', type=str, default=">",
                       help='Prompt to wait for before sending (default: ">")')
    
    parser.add_argument('--wait-timeout', type=int, default=5,
                       help='Timeout for waiting prompt in seconds (default: 5)')
    
    parser.add_argument('--list-ports', '-l', action='store_true',
                       help='List available serial ports')
    
    parser.add_argument('--interactive', '-i', action='store_true',
                       help='Interactive mode after sending')
    
    parser.add_argument('--baud', '-b', type=int, default=115200,
                       help='Baud rate (default: 115200)')
    
    if len(sys.argv) == 1:
        parser.print_help()
        list_available_ports()
        sys.exit(1)
    
    args = parser.parse_args()
    
    if args.list_ports:
        list_available_ports()
        sys.exit(0)
    
    if not args.port:
        print("Error: --port argument is required")
        list_available_ports()
        sys.exit(1)
    
    # Create communicator
    comm = SerialCommunicator(args.port, baudrate=args.baud)
    
    try:
        # Connect to port
        if not comm.connect():
            sys.exit(1)
        
        # Start receiving thread
        comm.start_receiving()
        
        # If send command provided
        if args.send:
            # Wait for prompt if specified
            if args.wait:
                print(f"Waiting for prompt: '{args.wait}'...")
                if not comm.wait_for_prompt(args.wait, args.wait_timeout):
                    print(f"Warning: Prompt '{args.wait}' not found within timeout")
            
            # Process escape sequences
            data_to_send = args.send.encode().decode('unicode_escape')
            
            # Send data
            comm.send_data(data_to_send, add_newline=not args.no_newline)
        
        # Interactive mode
        if args.interactive or (not args.send):
            print("\n" + "="*50)
            print("Interactive Mode")
            print("Type commands to send, 'exit' or 'quit' to end")
            print("'\\r' = CR, '\\n' = LF, '\\r\\n' = CRLF")
            print("="*50)
            
            while True:
                try:
                    user_input = input(">>> ").strip()
                    
                    if user_input.lower() in ['exit', 'quit', 'q']:
                        break
                    
                    if user_input:
                        # Process escape sequences
                        processed_input = user_input.encode().decode('unicode_escape')
                        comm.send_data(processed_input, add_newline=True)
                        
                except KeyboardInterrupt:
                    print("\nInterrupted by user")
                    break
                except EOFError:
                    print("\nEnd of input")
                    break
    
    except KeyboardInterrupt:
        print("\nInterrupted by user")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        comm.disconnect()

if __name__ == "__main__":
    main()