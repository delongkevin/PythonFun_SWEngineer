import pyautogui
import json
import time
import argparse
import sys
import os
from pynput import keyboard

class AutomationRunner:
    """Command-line runner for saved automation sequences"""
    
    def __init__(self):
        self.stop_requested = False
        self.current_iteration = 0
        self.total_iterations = 1
        self.playback_active = False
        self.global_stop_listener = None
        pyautogui.FAILSAFE = True
    
    def load_sequence(self, filepath):
        """Load automation sequence from JSON file"""
        try:
            if not os.path.exists(filepath):
                print(f"❌ Error: File '{filepath}' not found")
                return None
            
            with open(filepath, 'r') as f:
                actions = json.load(f)
            
            if not actions:
                print("⚠️ Warning: The sequence file is empty")
                return None
            
            print(f"✅ Loaded {len(actions)} steps from '{filepath}'")
            return actions
        
        except json.JSONDecodeError as e:
            print(f"❌ Error: Invalid JSON format - {str(e)}")
            return None
        except Exception as e:
            print(f"❌ Error loading file: {str(e)}")
            return None
    
    def start_global_stop_listener(self):
        """Start global keyboard listener for stopping playback"""
        def on_press(key):
            try:
                if key.char and key.char.lower() == 'q':
                    print("\n⚠️ Stop requested (Q key pressed)...")
                    self.stop_requested = True
                    return False  # Stop listener
            except AttributeError:
                pass
            return True  # Continue listening
        
        self.global_stop_listener = keyboard.Listener(on_press=on_press)
        self.global_stop_listener.start()
    
    def stop_global_stop_listener(self):
        """Stop the global keyboard listener"""
        if self.global_stop_listener:
            self.global_stop_listener.stop()
    
    def find_and_click(self, action):
        """Find and click a button using image recognition"""
        if self.stop_requested:
            return False, "Playback stopped"
        
        try:
            if not os.path.exists(action['image_path']):
                return False, f"❌ Image file not found: {action['image_path']}"
            
            location = pyautogui.locateOnScreen(
                action['image_path'], 
                confidence=action.get('confidence', 0.8)
            )
            
            if location:
                center_x = location.left + location.width // 2
                center_y = location.top + location.height // 2
                pyautogui.click(center_x, center_y)
                return True, f"✅ Clicked at ({center_x}, {center_y})"
            else:
                return False, f"❌ Button not found on screen (confidence: {action.get('confidence', 0.8)})"
        
        except Exception as e:
            return False, f"⚠️ Error: {str(e)}"
    
    def execute_action(self, action, step_num, total_steps):
        """Execute a single action"""
        action_type = action.get('type', 'unknown')
        action_name = action.get('name', f'Step {step_num}')
        
        # Apply delay before action
        if action.get('delay_before', 0) > 0:
            delay = action['delay_before']
            if self.stop_requested:
                return False
            
            # Sleep with stop checking
            sleep_remaining = delay
            while sleep_remaining > 0 and not self.stop_requested:
                time.sleep(min(0.05, sleep_remaining))
                sleep_remaining -= 0.05
        
        if self.stop_requested:
            return False
        
        # Execute based on action type
        if action_type == 'click':
            success, msg = self.find_and_click(action)
            print(f"  [{step_num}/{total_steps}] {action_name}: {msg}")
            return success
        
        elif action_type == 'move':
            try:
                x, y = action['x'], action['y']
                pyautogui.moveTo(x, y, duration=0.2)
                print(f"  [{step_num}/{total_steps}] {action_name}: Moved to ({x}, {y})")
                return True
            except Exception as e:
                print(f"  [{step_num}/{total_steps}] {action_name}: ❌ Error - {str(e)}")
                return False
        
        elif action_type == 'sleep':
            duration = action.get('duration', 1.0)
            print(f"  [{step_num}/{total_steps}] {action_name}: Sleeping for {duration}s...")
            
            # Sleep with stop checking
            sleep_remaining = duration
            while sleep_remaining > 0 and not self.stop_requested:
                time.sleep(min(0.05, sleep_remaining))
                sleep_remaining -= 0.05
            
            return True
        
        elif action_type == 'keystroke':
            try:
                key = action.get('key', '')
                key_type = action.get('key_type', 'char')
                
                if key_type == 'char':
                    pyautogui.press(key)
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
                    mapped_key = key_map.get(key.lower(), key)
                    pyautogui.press(mapped_key)
                
                print(f"  [{step_num}/{total_steps}] {action_name}: Pressed '{key}'")
                return True
            except Exception as e:
                print(f"  [{step_num}/{total_steps}] {action_name}: ❌ Error - {str(e)}")
                return False
        
        else:
            print(f"  [{step_num}/{total_steps}] {action_name}: ⚠️ Unknown action type '{action_type}'")
            return False
    
    def run_sequence(self, actions, iterations=1, delay_multiplier=1.0, skip_on_error=False):
        """Run the automation sequence"""
        self.total_iterations = iterations if iterations > 0 else float('inf')
        self.current_iteration = 0
        self.stop_requested = False
        self.playback_active = True
        
        # Start global stop listener
        self.start_global_stop_listener()
        
        print(f"\n🎬 Starting playback...")
        print(f"   Iterations: {'Infinite (until Q pressed)' if iterations == 0 else iterations}")
        print(f"   Total steps: {len(actions)}")
        print(f"   Delay multiplier: {delay_multiplier}x")
        print(f"   Skip on error: {'Yes' if skip_on_error else 'No'}")
        print(f"   Press 'Q' at any time to stop\n")
        
        # Countdown
        for countdown in [3, 2, 1]:
            if self.stop_requested:
                self.cleanup()
                return
            print(f"Starting in {countdown}...")
            time.sleep(1)
        
        print("\n▶️  Playback started!\n")
        
        # Apply delay multiplier to all actions
        if delay_multiplier != 1.0:
            for action in actions:
                if 'delay_before' in action:
                    action['delay_before'] *= delay_multiplier
                if 'duration' in action:
                    action['duration'] *= delay_multiplier
        
        # Main playback loop
        total_successes = 0
        total_failures = 0
        
        while self.current_iteration < self.total_iterations and not self.stop_requested:
            self.current_iteration += 1
            
            if self.total_iterations == float('inf'):
                print(f"{'='*60}")
                print(f"🔄 Iteration {self.current_iteration} (Infinite loop)")
                print(f"{'='*60}")
            else:
                print(f"{'='*60}")
                print(f"🔄 Iteration {self.current_iteration}/{self.total_iterations}")
                print(f"{'='*60}")
            
            iteration_successes = 0
            iteration_failures = 0
            
            for i, action in enumerate(actions, 1):
                if self.stop_requested:
                    break
                
                success = self.execute_action(action, i, len(actions))
                
                if success:
                    iteration_successes += 1
                else:
                    iteration_failures += 1
                    if not skip_on_error and action.get('type') == 'click':
                        print(f"\n⚠️ Critical error on step {i}. Stopping iteration.")
                        if self.current_iteration < self.total_iterations:
                            print("   Moving to next iteration...\n")
                        break
            
            total_successes += iteration_successes
            total_failures += iteration_failures
            
            print(f"\n📊 Iteration {self.current_iteration} Summary:")
            print(f"   ✅ Successful: {iteration_successes}")
            print(f"   ❌ Failed: {iteration_failures}")
            print()
            
            if self.stop_requested:
                break
            
            # Brief pause between iterations
            if self.current_iteration < self.total_iterations:
                pause_remaining = 0.5
                while pause_remaining > 0 and not self.stop_requested:
                    time.sleep(min(0.05, pause_remaining))
                    pause_remaining -= 0.05
        
        # Final summary
        self.cleanup()
        
        print(f"\n{'='*60}")
        if self.stop_requested:
            print(f"⏹️  Playback STOPPED by user")
        else:
            print(f"✅ Playback COMPLETED")
        print(f"{'='*60}")
        print(f"📊 Final Statistics:")
        print(f"   Total iterations: {self.current_iteration}")
        print(f"   Total successes: {total_successes}")
        print(f"   Total failures: {total_failures}")
        print(f"{'='*60}\n")
    
    def cleanup(self):
        """Cleanup resources"""
        self.playback_active = False
        self.stop_global_stop_listener()


def main():
    """Main entry point for CLI"""
    parser = argparse.ArgumentParser(
        description='Magna Real-Time Automator - Command Line Runner',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Examples:
  # Run sequence once
  python automator_cli.py sequence.json
  
  # Run sequence 5 times
  python automator_cli.py sequence.json -i 5
  
  # Run infinite loop (until Q pressed)
  python automator_cli.py sequence.json -i 0
  
  # Run with 2x speed (half delays)
  python automator_cli.py sequence.json -d 0.5
  
  # Continue on errors
  python automator_cli.py sequence.json --skip-errors
        """
    )
    
    parser.add_argument('sequence_file', 
                       help='Path to the JSON sequence file')
    
    parser.add_argument('-i', '--iterations', 
                       type=int, 
                       default=1,
                       help='Number of iterations (0 for infinite loop, default: 1)')
    
    parser.add_argument('-d', '--delay-multiplier', 
                       type=float, 
                       default=1.0,
                       help='Delay multiplier (e.g., 0.5 for 2x speed, 2.0 for half speed, default: 1.0)')
    
    parser.add_argument('--skip-errors', 
                       action='store_true',
                       help='Continue execution even if steps fail')
    
    parser.add_argument('-v', '--verbose', 
                       action='store_true',
                       help='Verbose output')
    
    args = parser.parse_args()
    
    # Validate inputs
    if args.iterations < 0:
        print("❌ Error: Iterations must be >= 0 (0 for infinite)")
        sys.exit(1)
    
    if args.delay_multiplier <= 0:
        print("❌ Error: Delay multiplier must be > 0")
        sys.exit(1)
    
    # Create runner
    runner = AutomationRunner()
    
    # Load sequence
    actions = runner.load_sequence(args.sequence_file)
    if actions is None:
        sys.exit(1)
    
    # Run sequence
    try:
        runner.run_sequence(
            actions,
            iterations=args.iterations,
            delay_multiplier=args.delay_multiplier,
            skip_on_error=args.skip_errors
        )
    except KeyboardInterrupt:
        print("\n\n⚠️ Interrupted by user (Ctrl+C)")
        runner.cleanup()
        sys.exit(130)
    except Exception as e:
        print(f"\n❌ Fatal error: {str(e)}")
        runner.cleanup()
        sys.exit(1)


if __name__ == "__main__":
    main()