import json
import time
import threading
from pynput import mouse, keyboard
from pynput.keyboard import Key
import pyautogui

# Disable pyautogui failsafe (optional, use with caution)
pyautogui.FAILSAFE = False

class InputRecorder:
    def __init__(self):
        self.events = []
        self.recording = False
        self.start_time = None
        self.mouse_listener = None
        self.keyboard_listener = None

    def _on_mouse_move(self, x, y):
        if self.recording:
            self.events.append({
                'type': 'mouse_move',
                'x': x,
                'y': y,
                'time': time.time() - self.start_time
            })

    def _on_click(self, x, y, button, pressed):
        if self.recording and pressed:
            self.events.append({
                'type': 'mouse_click',
                'x': x,
                'y': y,
                'button': str(button),
                'time': time.time() - self.start_time
            })

    def _on_key_press(self, key):
        if self.recording:
            try:
                key_char = key.char
            except AttributeError:
                key_char = str(key)
            
            # Stop recording on ESC
            if key == Key.esc:
                self.stop_recording()
                return False
                
            self.events.append({
                'type': 'key_press',
                'key': key_char,
                'time': time.time() - self.start_time
            })

    def start_recording(self):
        self.events = []
        self.start_time = time.time()
        self.recording = True
        
        self.mouse_listener = mouse.Listener(
            on_move=self._on_mouse_move,
            on_click=self._on_click
        )
        self.keyboard_listener = keyboard.Listener(on_press=self._on_key_press)
        
        self.mouse_listener.start()
        self.keyboard_listener.start()
        print("Recording started... Press ESC to stop.")

    def stop_recording(self):
        self.recording = False
        if self.mouse_listener:
            self.mouse_listener.stop()
        if self.keyboard_listener:
            self.keyboard_listener.stop()
        print(f"Recording stopped. {len(self.events)} events captured.")

    def save_recording(self, filename):
        with open(filename, 'w') as f:
            json.dump(self.events, f, indent=2)
        print(f"Recording saved to {filename}")

    def load_recording(self, filename):
        with open(filename, 'r') as f:
            self.events = json.load(f)
        print(f"Recording loaded from {filename}")

    def replay(self, speed_factor=1.0):
        print("Replaying sequence... Press Ctrl+C to stop.")
        try:
            last_time = 0
            for event in self.events:
                # Calculate delay since last event
                delay = (event['time'] - last_time) / speed_factor
                if delay > 0:
                    time.sleep(delay)
                
                # Execute action
                if event['type'] == 'mouse_move':
                    pyautogui.moveTo(event['x'], event['y'])
                elif event['type'] == 'mouse_click':
                    button = 'left' if 'left' in event['button'] else 'right'
                    pyautogui.click(event['x'], event['y'], button=button)
                elif event['type'] == 'key_press':
                    key = event['key']
                    if key.startswith('Key.'):
                        # Handle special keys (e.g., Key.space -> 'space')
                        key = key.split('.')[1]
                        if hasattr(pyautogui, key):
                            pyautogui.press(key)
                        else:
                            # Fallback for unsupported keys
                            pass
                    else:
                        pyautogui.press(key)
                
                last_time = event['time']
        except KeyboardInterrupt:
            print("\nReplay interrupted by user.")

def main():
    recorder = InputRecorder()
    
    while True:
        print("\nOptions:")
        print("1. Record new sequence")
        print("2. Save recording")
        print("3. Load recording")
        print("4. Replay sequence")
        print("5. Exit")
        
        choice = input("Select option: ").strip()
        
        if choice == '1':
            recorder.start_recording()
            # Keep alive until recording stops
            try:
                while recorder.recording:
                    time.sleep(0.1)
            except KeyboardInterrupt:
                recorder.stop_recording()
                
        elif choice == '2':
            filename = input("Enter filename (e.g., sequence.json): ")
            recorder.save_recording(filename)
            
        elif choice == '3':
            filename = input("Enter filename to load: ")
            recorder.load_recording(filename)
            
        elif choice == '4':
            speed = input("Enter speed factor (1.0 = normal, 2.0 = 2x faster): ")
            try:
                speed = float(speed)
            except ValueError:
                speed = 1.0
            recorder.replay(speed_factor=speed)
            
        elif choice == '5':
            break
        else:
            print("Invalid option")

if __name__ == "__main__":
    main()