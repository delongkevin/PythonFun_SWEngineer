"""
Enhanced Analytics Module for ADAS Data Logger
Advanced analysis capabilities with ML-inspired techniques
"""

import json
import os
from datetime import datetime
from collections import defaultdict, Counter
import math
import statistics

class AdvancedAnalytics:
    """Advanced analytics engine for ADAS data"""
    
    def __init__(self, logger_app):
        self.app = logger_app
        self.analysis_cache = {}
        self.pattern_library = {}
        self.baseline_metrics = {}
        
    def perform_comprehensive_analysis(self, log_directory):
        """Perform comprehensive multi-dimensional analysis"""
        results = {
            'summary': {},
            'can_analysis': {},
            'ethernet_analysis': {},
            'uart_analysis': {},
            'video_analysis': {},
            'correlations': {},
            'anomalies': [],
            'insights': [],
            'recommendations': []
        }
        
        try:
            # Load all data files
            can_data = self.load_can_data(log_directory)
            eth_data = self.load_ethernet_data(log_directory)
            uart_data = self.load_uart_data(log_directory)
            
            # Generate summary statistics
            results['summary'] = self.generate_summary_stats(can_data, eth_data, uart_data)
            
            # CAN bus analysis
            if can_data:
                results['can_analysis'] = self.analyze_can_bus(can_data)
                
            # Ethernet analysis
            if eth_data:
                results['ethernet_analysis'] = self.analyze_ethernet(eth_data)
                
            # UART analysis
            if uart_data:
                results['uart_analysis'] = self.analyze_uart(uart_data)
                
            # Cross-interface correlation
            results['correlations'] = self.analyze_correlations(can_data, eth_data, uart_data)
            
            # Pattern detection
            results['patterns'] = self.detect_patterns(can_data, eth_data)
            
            # Generate insights
            results['insights'] = self.generate_insights(results)
            
            # Generate recommendations
            results['recommendations'] = self.generate_recommendations(results)
            
        except Exception as e:
            results['error'] = str(e)
            
        return results
    
    def load_can_data(self, log_directory):
        """Load CAN data from CSV"""
        data = []
        can_file = os.path.join(log_directory, 'CAN', 'can_messages.csv')
        
        if os.path.exists(can_file):
            try:
                with open(can_file, 'r') as f:
                    lines = f.readlines()[1:]  # Skip header
                    for line in lines:
                        parts = line.strip().split(',')
                        if len(parts) >= 4:
                            data.append({
                                'timestamp': float(parts[0]),
                                'id': parts[1],
                                'data': parts[2],
                                'dlc': int(parts[3])
                            })
            except Exception as e:
                print(f"Error loading CAN data: {e}")
                
        return data
    
    def load_ethernet_data(self, log_directory):
        """Load Ethernet data from CSV"""
        data = []
        eth_file = os.path.join(log_directory, 'Ethernet', 'ethernet_packets.csv')
        
        if os.path.exists(eth_file):
            try:
                with open(eth_file, 'r') as f:
                    lines = f.readlines()[1:]  # Skip header
                    for line in lines:
                        parts = line.strip().split(',')
                        if len(parts) >= 5:
                            data.append({
                                'timestamp': float(parts[0]),
                                'src_ip': parts[1],
                                'dst_ip': parts[2],
                                'protocol': parts[3],
                                'size': int(parts[4])
                            })
            except Exception as e:
                print(f"Error loading Ethernet data: {e}")
                
        return data
    
    def load_uart_data(self, log_directory):
        """Load UART data from CSV files"""
        data = []
        uart_dir = os.path.join(log_directory, 'UART')
        
        if os.path.exists(uart_dir):
            for filename in os.listdir(uart_dir):
                if filename.endswith('.csv'):
                    try:
                        with open(os.path.join(uart_dir, filename), 'r') as f:
                            lines = f.readlines()[1:]  # Skip header
                            for line in lines:
                                parts = line.strip().split(',')
                                if len(parts) >= 3:
                                    data.append({
                                        'timestamp': float(parts[0]),
                                        'port': parts[1],
                                        'data': parts[2]
                                    })
                    except Exception as e:
                        print(f"Error loading UART data from {filename}: {e}")
                        
        return data
    
    def generate_summary_stats(self, can_data, eth_data, uart_data):
        """Generate comprehensive summary statistics"""
        summary = {
            'total_messages': len(can_data) + len(eth_data) + len(uart_data),
            'can_messages': len(can_data),
            'ethernet_packets': len(eth_data),
            'uart_messages': len(uart_data),
            'duration': 0,
            'data_rates': {}
        }
        
        # Calculate duration
        all_timestamps = []
        if can_data:
            all_timestamps.extend([d['timestamp'] for d in can_data])
        if eth_data:
            all_timestamps.extend([d['timestamp'] for d in eth_data])
        if uart_data:
            all_timestamps.extend([d['timestamp'] for d in uart_data])
            
        if all_timestamps:
            summary['duration'] = max(all_timestamps) - min(all_timestamps)
            
            # Calculate data rates
            if summary['duration'] > 0:
                summary['data_rates']['can'] = len(can_data) / summary['duration']
                summary['data_rates']['ethernet'] = len(eth_data) / summary['duration']
                summary['data_rates']['uart'] = len(uart_data) / summary['duration']
        
        return summary
    
    def analyze_can_bus(self, can_data):
        """Detailed CAN bus analysis"""
        if not can_data:
            return {}
            
        analysis = {
            'message_distribution': {},
            'timing_analysis': {},
            'id_statistics': {},
            'bus_load': {},
            'patterns': []
        }
        
        # Message ID distribution
        id_counts = Counter([msg['id'] for msg in can_data])
        analysis['message_distribution'] = dict(id_counts.most_common(20))
        
        # Timing analysis
        timestamps = [msg['timestamp'] for msg in can_data]
        if len(timestamps) > 1:
            intervals = [timestamps[i+1] - timestamps[i] for i in range(len(timestamps)-1)]
            analysis['timing_analysis'] = {
                'min_interval': min(intervals),
                'max_interval': max(intervals),
                'avg_interval': statistics.mean(intervals),
                'std_interval': statistics.stdev(intervals) if len(intervals) > 1 else 0
            }
        
        # ID statistics
        unique_ids = set([msg['id'] for msg in can_data])
        analysis['id_statistics'] = {
            'unique_ids': len(unique_ids),
            'total_messages': len(can_data),
            'messages_per_id': len(can_data) / len(unique_ids) if unique_ids else 0
        }
        
        # Bus load estimation (assuming 500kbps CAN)
        total_bits = sum([(msg['dlc'] * 8 + 44) for msg in can_data])  # 44 bits overhead per message
        duration = timestamps[-1] - timestamps[0] if len(timestamps) > 1 else 1
        analysis['bus_load'] = {
            'total_bits': total_bits,
            'duration': duration,
            'avg_bitrate': total_bits / duration if duration > 0 else 0,
            'utilization_percent': (total_bits / duration / 500000 * 100) if duration > 0 else 0
        }
        
        # Detect periodic patterns
        analysis['patterns'] = self.detect_can_patterns(can_data)
        
        return analysis
    
    def detect_can_patterns(self, can_data):
        """Detect periodic message patterns in CAN data"""
        patterns = []
        
        # Group by message ID
        id_groups = defaultdict(list)
        for msg in can_data:
            id_groups[msg['id']].append(msg['timestamp'])
        
        # Analyze periodicity for each ID
        for msg_id, timestamps in id_groups.items():
            if len(timestamps) >= 3:
                intervals = [timestamps[i+1] - timestamps[i] for i in range(len(timestamps)-1)]
                avg_interval = statistics.mean(intervals)
                std_interval = statistics.stdev(intervals) if len(intervals) > 1 else 0
                
                # Consider it periodic if std deviation is low
                if std_interval < avg_interval * 0.1 and avg_interval > 0:
                    frequency = 1000 / avg_interval  # Hz
                    patterns.append({
                        'id': msg_id,
                        'type': 'periodic',
                        'frequency': frequency,
                        'interval': avg_interval,
                        'stability': 1 - (std_interval / avg_interval) if avg_interval > 0 else 0,
                        'count': len(timestamps)
                    })
        
        return sorted(patterns, key=lambda x: x['count'], reverse=True)
    
    def analyze_ethernet(self, eth_data):
        """Detailed Ethernet analysis"""
        if not eth_data:
            return {}
            
        analysis = {
            'protocol_distribution': {},
            'traffic_analysis': {},
            'ip_statistics': {},
            'bandwidth': {}
        }
        
        # Protocol distribution
        protocol_counts = Counter([pkt['protocol'] for pkt in eth_data])
        analysis['protocol_distribution'] = dict(protocol_counts)
        
        # Traffic analysis
        timestamps = [pkt['timestamp'] for pkt in eth_data]
        sizes = [pkt['size'] for pkt in eth_data]
        
        analysis['traffic_analysis'] = {
            'total_packets': len(eth_data),
            'total_bytes': sum(sizes),
            'avg_packet_size': statistics.mean(sizes),
            'max_packet_size': max(sizes),
            'min_packet_size': min(sizes)
        }
        
        # IP statistics
        src_ips = Counter([pkt['src_ip'] for pkt in eth_data])
        dst_ips = Counter([pkt['dst_ip'] for pkt in eth_data])
        
        analysis['ip_statistics'] = {
            'unique_sources': len(src_ips),
            'unique_destinations': len(dst_ips),
            'top_sources': dict(src_ips.most_common(5)),
            'top_destinations': dict(dst_ips.most_common(5))
        }
        
        # Bandwidth calculation
        duration = timestamps[-1] - timestamps[0] if len(timestamps) > 1 else 1
        analysis['bandwidth'] = {
            'avg_throughput_mbps': (sum(sizes) * 8 / duration / 1_000_000) if duration > 0 else 0,
            'peak_rate': self.calculate_peak_bandwidth(eth_data)
        }
        
        return analysis
    
    def calculate_peak_bandwidth(self, eth_data):
        """Calculate peak bandwidth in sliding window"""
        if not eth_data:
            return 0
            
        window_size = 1.0  # 1 second window
        max_throughput = 0
        
        for i in range(len(eth_data)):
            window_start = eth_data[i]['timestamp']
            window_end = window_start + window_size
            
            window_bytes = sum([pkt['size'] for pkt in eth_data 
                              if window_start <= pkt['timestamp'] < window_end])
            
            throughput = window_bytes * 8 / window_size / 1_000_000  # Mbps
            max_throughput = max(max_throughput, throughput)
        
        return max_throughput
    
    def analyze_uart(self, uart_data):
        """Detailed UART analysis"""
        if not uart_data:
            return {}
            
        analysis = {
            'port_distribution': {},
            'data_rate': {},
            'character_distribution': {}
        }
        
        # Port distribution
        port_counts = Counter([msg['port'] for msg in uart_data])
        analysis['port_distribution'] = dict(port_counts)
        
        # Data rate per port
        port_groups = defaultdict(list)
        for msg in uart_data:
            port_groups[msg['port']].append(msg)
        
        for port, messages in port_groups.items():
            timestamps = [msg['timestamp'] for msg in messages]
            duration = timestamps[-1] - timestamps[0] if len(timestamps) > 1 else 1
            total_chars = sum([len(msg['data']) for msg in messages])
            
            analysis['data_rate'][port] = {
                'messages': len(messages),
                'characters': total_chars,
                'chars_per_second': total_chars / duration if duration > 0 else 0
            }
        
        return analysis
    
    def analyze_correlations(self, can_data, eth_data, uart_data):
        """Analyze correlations between different interfaces"""
        correlations = {
            'temporal_correlation': {},
            'event_correlation': [],
            'synchronized_events': []
        }
        
        # Temporal correlation - look for events happening close in time
        time_window = 0.1  # 100ms window
        
        if can_data and eth_data:
            can_times = [msg['timestamp'] for msg in can_data]
            eth_times = [pkt['timestamp'] for pkt in eth_data]
            
            # Count events within time window
            close_events = 0
            for can_time in can_times[:100]:  # Sample first 100 for performance
                close_eth = [t for t in eth_times if abs(t - can_time) < time_window]
                if close_eth:
                    close_events += 1
            
            correlations['temporal_correlation']['can_ethernet'] = {
                'close_events': close_events,
                'correlation_strength': close_events / min(100, len(can_times)) if can_times else 0
            }
        
        return correlations
    
    def detect_patterns(self, can_data, eth_data):
        """Detect interesting patterns in the data"""
        patterns = {
            'burst_events': [],
            'quiet_periods': [],
            'cyclical_patterns': []
        }
        
        # Detect burst events in CAN data
        if can_data:
            timestamps = [msg['timestamp'] for msg in can_data]
            
            # Find bursts (many messages in short time)
            for i in range(len(timestamps) - 10):
                window_duration = timestamps[i+10] - timestamps[i]
                if window_duration < 0.01:  # 10 messages in less than 10ms
                    patterns['burst_events'].append({
                        'timestamp': timestamps[i],
                        'messages': 10,
                        'duration': window_duration,
                        'rate': 10 / window_duration
                    })
        
        # Detect quiet periods
        if can_data:
            timestamps = [msg['timestamp'] for msg in can_data]
            for i in range(len(timestamps) - 1):
                gap = timestamps[i+1] - timestamps[i]
                if gap > 1.0:  # More than 1 second gap
                    patterns['quiet_periods'].append({
                        'start': timestamps[i],
                        'end': timestamps[i+1],
                        'duration': gap
                    })
        
        return patterns
    
    def generate_insights(self, results):
        """Generate actionable insights from analysis"""
        insights = []
        
        # CAN bus insights
        if 'can_analysis' in results and results['can_analysis']:
            can_analysis = results['can_analysis']
            
            # Bus utilization insight
            if 'bus_load' in can_analysis:
                utilization = can_analysis['bus_load'].get('utilization_percent', 0)
                if utilization > 70:
                    insights.append({
                        'type': 'warning',
                        'category': 'CAN Bus',
                        'message': f'High bus utilization detected: {utilization:.1f}%',
                        'recommendation': 'Consider reducing message frequency or optimizing message scheduling'
                    })
                elif utilization < 10:
                    insights.append({
                        'type': 'info',
                        'category': 'CAN Bus',
                        'message': f'Low bus utilization: {utilization:.1f}%',
                        'recommendation': 'Bus capacity is well within limits'
                    })
            
            # Pattern insights
            if 'patterns' in can_analysis and can_analysis['patterns']:
                periodic_count = len(can_analysis['patterns'])
                insights.append({
                    'type': 'success',
                    'category': 'CAN Patterns',
                    'message': f'Detected {periodic_count} periodic message patterns',
                    'recommendation': 'Message timing appears stable and predictable'
                })
        
        # Ethernet insights
        if 'ethernet_analysis' in results and results['ethernet_analysis']:
            eth_analysis = results['ethernet_analysis']
            
            if 'bandwidth' in eth_analysis:
                avg_throughput = eth_analysis['bandwidth'].get('avg_throughput_mbps', 0)
                peak_throughput = eth_analysis['bandwidth'].get('peak_rate', 0)
                
                if peak_throughput > avg_throughput * 5:
                    insights.append({
                        'type': 'warning',
                        'category': 'Ethernet',
                        'message': f'High bandwidth variability detected (Peak: {peak_throughput:.2f} Mbps, Avg: {avg_throughput:.2f} Mbps)',
                        'recommendation': 'Consider traffic shaping or QoS policies'
                    })
        
        # Pattern insights
        if 'patterns' in results:
            burst_count = len(results['patterns'].get('burst_events', []))
            if burst_count > 10:
                insights.append({
                    'type': 'info',
                    'category': 'Traffic Patterns',
                    'message': f'Detected {burst_count} burst events',
                    'recommendation': 'Review event triggers for possible optimization'
                })
        
        return insights
    
    def generate_recommendations(self, results):
        """Generate system recommendations"""
        recommendations = []
        
        summary = results.get('summary', {})
        
        # Data rate recommendations
        if summary.get('can_messages', 0) > 10000:
            recommendations.append({
                'priority': 'medium',
                'category': 'Performance',
                'title': 'Consider Data Sampling',
                'description': 'High message volume detected. Consider implementing selective logging or data sampling to reduce storage requirements.'
            })
        
        # Duration recommendations
        duration = summary.get('duration', 0)
        if duration < 60:
            recommendations.append({
                'priority': 'low',
                'category': 'Data Quality',
                'title': 'Extend Logging Duration',
                'description': f'Current session duration: {duration:.1f}s. Longer sessions provide better statistical analysis.'
            })
        
        # Interface recommendations
        can_count = summary.get('can_messages', 0)
        eth_count = summary.get('ethernet_packets', 0)
        
        if can_count > 0 and eth_count == 0:
            recommendations.append({
                'priority': 'info',
                'category': 'Configuration',
                'title': 'Enable Additional Interfaces',
                'description': 'Only CAN logging is active. Consider enabling Ethernet capture for comprehensive system monitoring.'
            })
        
        return recommendations
    
    def format_analysis_report(self, results):
        """Format analysis results as readable report"""
        report = []
        report.append("=" * 80)
        report.append("ADAS ECU DATA LOGGER - COMPREHENSIVE ANALYSIS REPORT")
        report.append("=" * 80)
        report.append(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        report.append("")
        
        # Summary Section
        report.append("─" * 80)
        report.append("SESSION SUMMARY")
        report.append("─" * 80)
        summary = results.get('summary', {})
        report.append(f"Total Messages:     {summary.get('total_messages', 0):,}")
        report.append(f"  CAN Messages:     {summary.get('can_messages', 0):,}")
        report.append(f"  Ethernet Packets: {summary.get('ethernet_packets', 0):,}")
        report.append(f"  UART Messages:    {summary.get('uart_messages', 0):,}")
        report.append(f"Session Duration:   {summary.get('duration', 0):.2f} seconds")
        report.append("")
        
        # Data Rates
        if 'data_rates' in summary:
            report.append("Data Rates:")
            rates = summary['data_rates']
            report.append(f"  CAN:      {rates.get('can', 0):.2f} msg/s")
            report.append(f"  Ethernet: {rates.get('ethernet', 0):.2f} pkt/s")
            report.append(f"  UART:     {rates.get('uart', 0):.2f} msg/s")
        report.append("")
        
        # CAN Analysis
        if results.get('can_analysis'):
            report.append("─" * 80)
            report.append("CAN BUS ANALYSIS")
            report.append("─" * 80)
            can_analysis = results['can_analysis']
            
            if 'id_statistics' in can_analysis:
                stats = can_analysis['id_statistics']
                report.append(f"Unique Message IDs:     {stats.get('unique_ids', 0)}")
                report.append(f"Messages per ID (avg):  {stats.get('messages_per_id', 0):.1f}")
            
            if 'bus_load' in can_analysis:
                load = can_analysis['bus_load']
                report.append(f"Bus Utilization:        {load.get('utilization_percent', 0):.2f}%")
                report.append(f"Average Bitrate:        {load.get('avg_bitrate', 0)/1000:.2f} kbps")
            
            if 'patterns' in can_analysis and can_analysis['patterns']:
                report.append("")
                report.append("Periodic Message Patterns:")
                for i, pattern in enumerate(can_analysis['patterns'][:5], 1):
                    report.append(f"  {i}. ID: {pattern['id']}")
                    report.append(f"     Frequency: {pattern['frequency']:.2f} Hz")
                    report.append(f"     Stability: {pattern['stability']*100:.1f}%")
                    report.append(f"     Count: {pattern['count']}")
            report.append("")
        
        # Ethernet Analysis
        if results.get('ethernet_analysis'):
            report.append("─" * 80)
            report.append("ETHERNET ANALYSIS")
            report.append("─" * 80)
            eth_analysis = results['ethernet_analysis']
            
            if 'traffic_analysis' in eth_analysis:
                traffic = eth_analysis['traffic_analysis']
                report.append(f"Total Packets:         {traffic.get('total_packets', 0):,}")
                report.append(f"Total Bytes:           {traffic.get('total_bytes', 0):,}")
                report.append(f"Average Packet Size:   {traffic.get('avg_packet_size', 0):.1f} bytes")
            
            if 'bandwidth' in eth_analysis:
                bw = eth_analysis['bandwidth']
                report.append(f"Average Throughput:    {bw.get('avg_throughput_mbps', 0):.2f} Mbps")
                report.append(f"Peak Throughput:       {bw.get('peak_rate', 0):.2f} Mbps")
            
            if 'protocol_distribution' in eth_analysis:
                report.append("")
                report.append("Protocol Distribution:")
                for proto, count in eth_analysis['protocol_distribution'].items():
                    report.append(f"  {proto}: {count:,} packets")
            report.append("")
        
        # Insights Section
        if results.get('insights'):
            report.append("─" * 80)
            report.append("KEY INSIGHTS")
            report.append("─" * 80)
            for i, insight in enumerate(results['insights'], 1):
                icon = {"warning": "⚠️", "info": "ℹ️", "success": "✓"}.get(insight['type'], "•")
                report.append(f"{i}. [{icon}] {insight['category']}: {insight['message']}")
                report.append(f"   → {insight['recommendation']}")
                report.append("")
        
        # Recommendations Section
        if results.get('recommendations'):
            report.append("─" * 80)
            report.append("RECOMMENDATIONS")
            report.append("─" * 80)
            for i, rec in enumerate(results['recommendations'], 1):
                priority_icon = {"high": "🔴", "medium": "🟡", "low": "🟢", "info": "ℹ️"}.get(rec['priority'], "•")
                report.append(f"{i}. [{priority_icon}] {rec['title']}")
                report.append(f"   Category: {rec['category']}")
                report.append(f"   {rec['description']}")
                report.append("")
        
        report.append("=" * 80)
        report.append("END OF REPORT")
        report.append("=" * 80)
        
        return "\n".join(report)


# Integration functions for the main application
def integrate_advanced_analytics(logger_app):
    """Integrate advanced analytics into the logger application"""
    
    # Create analytics instance
    analytics = AdvancedAnalytics(logger_app)
    
    # Replace the load_analysis_data method
    def enhanced_load_analysis_data():
        if not hasattr(logger_app, 'current_log_dir') or not logger_app.current_log_dir:
            from tkinter import filedialog, messagebox
            log_dir = filedialog.askdirectory(title="Select Log Directory to Analyze")
            if not log_dir:
                return
            logger_app.current_log_dir = log_dir
        
        logger_app.analysis_text.delete(1.0, 'end')
        logger_app.analysis_text.insert('end', "Performing comprehensive analysis...\n\n")
        logger_app.root.update()
        
        # Perform analysis
        results = analytics.perform_comprehensive_analysis(logger_app.current_log_dir)
        
        # Format and display report
        report = analytics.format_analysis_report(results)
        
        logger_app.analysis_text.delete(1.0, 'end')
        logger_app.analysis_text.insert('end', report)
        
        logger_app.log_message("Advanced analysis completed")
    
    # Replace method
    logger_app.load_analysis_data = enhanced_load_analysis_data
    
    return analytics