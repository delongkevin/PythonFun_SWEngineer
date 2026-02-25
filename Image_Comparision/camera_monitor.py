import cv2
import numpy as np
import os
import json
import logging
import sys
import time
from datetime import datetime
import argparse

class CameraMonitor:
    """Smart camera monitoring system to detect anomalies."""
    
    def __init__(self, config_path=None):
        self.config = self._load_config(config_path)
        self.setup_logging()
        self.camera = None
        self.master_frame = None
        self.detection_count = 0
        
    def _load_config(self, config_path):
        """Load configuration from file or use defaults."""
        default_config = {
            'camera_index': 0,
            'output_dir': 'camera_monitor_output',
            'detection_threshold': 15.0,
            'check_interval': 1.0,
            'max_runtime': 3600,
            'fps': 30,
            'roi': None,
            'min_contour_area': 100,
            'quality_checks': {
                'enable_lighting_check': True,
                'enable_distortion_check': True,
                'brightness_dark_thresh': 60,
                'brightness_bright_thresh': 200,
                'black_screen_std_dev': 5
            }
        }
        
        if config_path and os.path.exists(config_path):
            try:
                with open(config_path, 'r') as f:
                    user_config = json.load(f)
                    default_config.update(user_config)
            except Exception as e:
                logging.warning(f"Could not load config file: {e}")
        
        return default_config
    
    def setup_logging(self):
        """Setup logging configuration."""
        os.makedirs(self.config['output_dir'], exist_ok=True)
        log_file = os.path.join(self.config['output_dir'], 'camera_monitor.log')
        
        logging.basicConfig(
            level=logging.INFO,
            format='%(asctime)s - %(levelname)s - %(message)s',
            handlers=[
                logging.FileHandler(log_file),
                logging.StreamHandler(sys.stdout)
            ]
        )
    
    def setup_directories(self):
        """Create necessary output directories."""
        dirs = [
            'detected_anomalies',
            'quality_issues/black_screen',
            'quality_issues/too_dark',
            'quality_issues/too_bright',
            'quality_issues/distortion',
            'master_frames'
        ]
        
        for dir_name in dirs:
            os.makedirs(os.path.join(self.config['output_dir'], dir_name), exist_ok=True)
    
    def initialize_camera(self):
        """Initialize camera with fallback detection."""
        camera_idx = self.config['camera_index']
        
        # Try to find available camera if specified one fails
        for i in range(max(3, camera_idx + 2)):
            self.camera = cv2.VideoCapture(i)
            if self.camera.isOpened():
                if i != camera_idx:
                    logging.info(f"Camera at index {camera_idx} not available. Using index {i}")
                    self.config['camera_index'] = i
                break
        
        if not self.camera or not self.camera.isOpened():
            raise RuntimeError("No camera available")
        
        # Set camera properties
        self.camera.set(cv2.CAP_PROP_FPS, self.config['fps'])
        self.camera.set(cv2.CAP_PROP_BUFFERSIZE, 1)  # Reduce latency
        
        width = int(self.camera.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(self.camera.get(cv2.CAP_PROP_FRAME_HEIGHT))
        
        logging.info(f"Camera initialized: {width}x{height} @ {self.config['fps']} FPS")
        return width, height
    
    def set_master_frame(self):
        """Set initial master frame for comparison."""
        ret, frame = self.camera.read()
        if not ret:
            raise RuntimeError("Failed to capture master frame")
        
        frame = self.apply_roi(frame)
        
        self.master_frame = frame
        master_path = os.path.join(self.config['output_dir'], 'master_frames', 
                                  f'master_{datetime.now().strftime("%Y%m%d_%H%M%S")}.jpg')
        cv2.imwrite(master_path, frame)
        logging.info(f"Master frame set: {master_path}")
        
        return frame
    
    def apply_roi(self, frame):
        """Apply Region of Interest cropping if configured."""
        roi = self.config.get('roi')
        if roi:
            try:
                x, y, w, h = map(int, roi.split(','))
                # Validate ROI coordinates
                frame_height, frame_width = frame.shape[:2]
                if (x >= 0 and y >= 0 and w > 0 and h > 0 and 
                    x + w <= frame_width and y + h <= frame_height):
                    return frame[y:y+h, x:x+w]
                else:
                    logging.warning(f"Invalid ROI coordinates: {roi}. Using full frame.")
            except Exception as e:
                logging.warning(f"Invalid ROI format: {e}. Using full frame.")
        return frame
    
    def calculate_difference(self, frame1, frame2):
        """Calculate percentage difference between two frames."""
        if frame1 is None or frame2 is None:
            return 0
        
        # Ensure same dimensions
        if frame1.shape != frame2.shape:
            frame2 = cv2.resize(frame2, (frame1.shape[1], frame1.shape[0]))
        
        # Use multiple methods for robust detection
        diff = cv2.absdiff(frame1, frame2)
        gray_diff = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
        _, thresh = cv2.threshold(gray_diff, 30, 255, cv2.THRESH_BINARY)
        
        non_zero = np.count_nonzero(thresh)
        total_pixels = thresh.shape[0] * thresh.shape[1]
        
        return (non_zero / total_pixels) * 100 if total_pixels > 0 else 0
    
    def check_quality_issues(self, frame):
        """Check for various quality issues in the frame."""
        issues = []
        
        if frame is None:
            return ['empty_frame']
        
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        mean_brightness = np.mean(gray)
        std_brightness = np.std(gray)
        
        # Check for black screen
        if mean_brightness < 20 and std_brightness < self.config['quality_checks']['black_screen_std_dev']:
            issues.append('black_screen')
        
        # Check for dark frame
        elif mean_brightness < self.config['quality_checks']['brightness_dark_thresh']:
            issues.append('too_dark')
        
        # Check for bright frame
        elif mean_brightness > self.config['quality_checks']['brightness_bright_thresh']:
            issues.append('too_bright')
        
        # Check for distortion (solid color bars)
        if self.config['quality_checks']['enable_distortion_check']:
            if self.detect_distortion(frame):
                issues.append('distortion')
        
        return issues
    
    def detect_distortion(self, frame):
        """Detect distortion like solid color bars at edges."""
        h, w = frame.shape[:2]
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        
        # Check edges (15% of frame)
        margin_h, margin_w = int(h * 0.15), int(w * 0.15)
        
        regions = [
            ("top", gray[0:margin_h, :]),
            ("bottom", gray[h-margin_h:h, :]),
            ("left", gray[:, 0:margin_w]),
            ("right", gray[:, w-margin_w:w])
        ]
        
        for name, region in regions:
            if region.size == 0:
                continue
            
            # Check for solid color areas
            if np.std(region) < 10 and (np.mean(region) < 30 or np.mean(region) > 220):
                return True
        
        return False
    
    def save_detection(self, frame, diff_percent, issues=None):
        """Save detected anomaly with metadata."""
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.detection_count += 1
        
        # Save the frame
        filename = f"anomaly_{timestamp}_diff_{diff_percent:.1f}.jpg"
        save_path = os.path.join(self.config['output_dir'], 'detected_anomalies', filename)
        cv2.imwrite(save_path, frame)
        
        # Save metadata
        meta = {
            'timestamp': timestamp,
            'detection_number': self.detection_count,
            'difference_percent': float(diff_percent),
            'quality_issues': issues or [],
            'file_path': save_path
        }
        
        meta_path = save_path.replace('.jpg', '.json')
        with open(meta_path, 'w') as f:
            json.dump(meta, f, indent=2)
        
        # Save to quality issue folders if applicable
        if issues:
            for issue in issues:
                if issue in ['black_screen', 'too_dark', 'too_bright', 'distortion']:
                    issue_path = os.path.join(self.config['output_dir'], 'quality_issues', issue, filename)
                    cv2.imwrite(issue_path, frame)
        
        logging.info(f"Detection #{self.detection_count}: {filename} (Diff: {diff_percent:.1f}%, Issues: {issues})")
        return save_path
    
    def create_comparison_image(self, master, current, diff_percent):
        """Create side-by-side comparison image."""
        # Resize to same height for comparison
        target_height = 400
        h1, w1 = master.shape[:2]
        h2, w2 = current.shape[:2]
        
        if h1 == 0 or h2 == 0:
            return current
        
        master_scaled = cv2.resize(master, (int(w1 * target_height / h1), target_height))
        current_scaled = cv2.resize(current, (int(w2 * target_height / h2), target_height))
        
        # Add labels
        cv2.putText(master_scaled, "Master", (10, 30), 
                   cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 255), 2)
        cv2.putText(current_scaled, "Current", (10, 30), 
                   cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 255), 2)
        
        # Combine
        comparison = cv2.hconcat([master_scaled, current_scaled])
        
        # Add difference text
        diff_text = f"Difference: {diff_percent:.1f}%"
        cv2.putText(comparison, diff_text, (10, comparison.shape[0] - 20),
                   cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
        
        return comparison
    
    def run_monitoring(self):
        """Main monitoring loop."""
        try:
            self.setup_directories()
            self.initialize_camera()
            master_frame = self.set_master_frame()
            
            logging.info(f"Starting camera monitoring...")
            logging.info(f"Detection threshold: {self.config['detection_threshold']}%")
            logging.info(f"Max runtime: {self.config['max_runtime']} seconds")
            logging.info(f"ROI: {self.config['roi'] if self.config['roi'] else 'Full frame'}")
            
            start_time = time.time()
            last_check_time = time.time()
            last_frame_time = start_time
            
            while True:
                # Check runtime limit
                elapsed = time.time() - start_time
                if elapsed > self.config['max_runtime']:
                    logging.info(f"Maximum runtime ({self.config['max_runtime']}s) reached.")
                    break
                
                # Check at specified interval
                current_time = time.time()
                if current_time - last_check_time < self.config['check_interval']:
                    time.sleep(0.01)  # Small sleep to prevent CPU hogging
                    continue
                
                # Capture frame
                ret, frame = self.camera.read()
                if not ret:
                    logging.warning("Failed to capture frame. Retrying...")
                    time.sleep(0.5)
                    continue
                
                # Calculate actual FPS
                current_frame_time = time.time()
                actual_fps = 1.0 / (current_frame_time - last_frame_time)
                last_frame_time = current_frame_time
                
                # Apply ROI if configured
                current_frame = self.apply_roi(frame.copy())
                
                # Calculate difference from master
                diff_percent = self.calculate_difference(master_frame, current_frame)
                
                # Check for quality issues
                quality_issues = self.check_quality_issues(current_frame)
                
                # Detect anomalies
                if diff_percent > self.config['detection_threshold'] or quality_issues:
                    # Save detection
                    self.save_detection(frame, diff_percent, quality_issues)
                    
                    # Create comparison image
                    comparison = self.create_comparison_image(master_frame, current_frame, diff_percent)
                    comp_path = os.path.join(
                        self.config['output_dir'], 
                        'detected_anomalies',
                        f"comparison_{datetime.now().strftime('%Y%m%d_%H%M%S')}.jpg"
                    )
                    cv2.imwrite(comp_path, comparison)
                
                last_check_time = current_time
                
                # Log FPS periodically
                if int(current_time) % 10 == 0 and int(last_check_time) != int(current_time):
                    logging.debug(f"Current FPS: {actual_fps:.1f}, Diff: {diff_percent:.1f}%")
                
        except KeyboardInterrupt:
            logging.info("Monitoring stopped by user.")
        except Exception as e:
            logging.error(f"Monitoring error: {e}")
            raise
        finally:
            self.cleanup()
    
    def cleanup(self):
        """Clean up resources."""
        if self.camera and self.camera.isOpened():
            self.camera.release()
        
        logging.info(f"Monitoring complete. Detected {self.detection_count} anomalies.")
        logging.info(f"Output directory: {self.config['output_dir']}")


def main():
    parser = argparse.ArgumentParser(description="Smart Camera Monitor for Anomaly Detection")
    
    parser.add_argument('--config', type=str, help='Path to configuration JSON file')
    parser.add_argument('--camera', type=int, help='Camera index (default: 0)')
    parser.add_argument('--output', type=str, help='Output directory')
    parser.add_argument('--threshold', type=float, help='Detection threshold percentage (default: 15)')
    parser.add_argument('--interval', type=float, help='Check interval in seconds (default: 1)')
    parser.add_argument('--runtime', type=int, help='Maximum runtime in seconds (default: 3600)')
    parser.add_argument('--roi', type=str, help='ROI as x,y,width,height (e.g., 100,100,400,300)')
    
    args = parser.parse_args()
    
    # Create monitor instance
    monitor = CameraMonitor(args.config)
    
    # Override config with command line arguments
    if args.camera is not None:
        monitor.config['camera_index'] = args.camera
    if args.output:
        monitor.config['output_dir'] = args.output
    if args.threshold:
        monitor.config['detection_threshold'] = args.threshold
    if args.interval:
        monitor.config['check_interval'] = args.interval
    if args.runtime:
        monitor.config['max_runtime'] = args.runtime
    if args.roi:
        monitor.config['roi'] = args.roi
    
    # Run monitoring
    monitor.run_monitoring()


if __name__ == "__main__":
    main()