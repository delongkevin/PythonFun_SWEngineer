#!/usr/bin/env python3
"""
Jenkins Pipeline Dashboard Script - Specific Job Version with HTML Report
"""

import requests
import json
import time
import datetime
from typing import Dict, List, Optional, Tuple
import os
from dataclasses import dataclass, asdict
import argparse
import urllib3
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry
import html

# Disable SSL warnings
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

@dataclass
class BuildInfo:
    """Data class to store build information"""
    job_name: str
    build_number: int
    status: str
    timestamp: datetime.datetime
    duration: int
    url: str
    commit_message: str = ""
    commit_author: str = ""
    tests_total: int = 0
    tests_failed: int = 0
    tests_passed: int = 0

class JenkinsDashboard:
    def __init__(self, jenkins_url: str, username: str = None, password: str = None, verify_ssl: bool = False):
        self.jenkins_url = jenkins_url.rstrip('/')
        self.session = requests.Session()
        self.verify_ssl = verify_ssl
        
        # Disable SSL verification
        self.session.verify = verify_ssl
        
        if username and password:
            self.session.auth = (username, password)
        
        # Add retry strategy
        retry_strategy = Retry(
            total=3,
            backoff_factor=1,
            status_forcelist=[429, 500, 502, 503, 504],
        )
        adapter = HTTPAdapter(max_retries=retry_strategy)
        self.session.mount("http://", adapter)
        self.session.mount("https://", adapter)
        
    def extract_job_name_from_url(self, url: str) -> str:
        """Extract job name from Jenkins URL"""
        # Remove the base URL and split by '/job/'
        base_url = "https://eahubjenkins02.magna.global:8443"
        if url.startswith(base_url):
            path = url.replace(base_url, "")
            # Extract the last part as job name
            parts = [part for part in path.split('/') if part and part != 'view']
            job_parts = [part.replace('job/', '') for part in parts if part != 'job']
            return job_parts[-1] if job_parts else "unknown"
        return "unknown"
    
    def get_specific_job_builds(self, limit: int = 10) -> List[BuildInfo]:
        """Get builds for the specific job URL provided"""
        builds = []
        try:
            # Use the provided URL directly
            api_url = f"{self.jenkins_url}/api/json"
            print(f"Fetching from: {api_url}")
            
            response = self.session.get(api_url, verify=self.verify_ssl)
            response.raise_for_status()
            job_data = response.json()
            
            print(f"Job data keys: {list(job_data.keys())}")
            
            # Extract job name from URL
            job_name = self.extract_job_name_from_url(self.jenkins_url)
            
            # Get builds from the job data
            builds_data = job_data.get('builds', [])
            print(f"Found {len(builds_data)} builds")
            
            for build in builds_data[:limit]:
                build_info = self.get_build_details_from_data(build, job_name)
                if build_info:
                    builds.append(build_info)
                    
        except requests.RequestException as e:
            print(f"Error fetching builds: {e}")
            print(f"Response content: {e.response.content if hasattr(e, 'response') else 'No response'}")
        
        return builds
    
    def get_build_details_from_data(self, build_data: Dict, job_name: str) -> Optional[BuildInfo]:
        """Get detailed information about a specific build"""
        try:
            build_number = build_data['number']
            build_url = build_data['url']
            
            # Get detailed build information
            build_detail_url = f"{build_url}api/json"
            response = self.session.get(build_detail_url, verify=self.verify_ssl)
            response.raise_for_status()
            build_detail = response.json()
            
            # Extract build information
            status = "UNKNOWN"
            if build_detail.get('result'):
                status = "SUCCESS" if build_detail['result'] == 'SUCCESS' else "FAILED"
            elif build_detail.get('building'):
                status = "RUNNING"
            else:
                status = "UNKNOWN"
            
            timestamp = datetime.datetime.fromtimestamp(build_detail['timestamp'] / 1000)
            duration = build_detail.get('duration', 0) / 1000  # Convert to seconds
            
            build_info = BuildInfo(
                job_name=job_name,
                build_number=build_number,
                status=status,
                timestamp=timestamp,
                duration=duration,
                url=build_url
            )
            
            # Try to get additional information
            self._add_additional_info(build_info, build_url)
            
            return build_info
            
        except requests.RequestException as e:
            print(f"Error fetching build details for #{build_data.get('number', 'unknown')}: {e}")
            return None
    
    def _add_additional_info(self, build_info: BuildInfo, build_url: str):
        """Add test results and Git information"""
        # Test results
        try:
            test_url = f"{build_url}testReport/api/json"
            response = self.session.get(test_url, verify=self.verify_ssl)
            if response.status_code == 200:
                test_data = response.json()
                build_info.tests_total = test_data.get('totalCount', 0)
                build_info.tests_failed = test_data.get('failCount', 0)
                build_info.tests_passed = build_info.tests_total - build_info.tests_failed
        except:
            pass
        
        # Git information
        try:
            build_detail_url = f"{build_url}api/json"
            response = self.session.get(build_detail_url, verify=self.verify_ssl)
            if response.status_code == 200:
                build_data = response.json()
                actions = build_data.get('actions', [])
                
                # Look for Git information in actions
                for action in actions:
                    # Method 1: Last built revision
                    if 'lastBuiltRevision' in action:
                        revision = action['lastBuiltRevision']
                        if 'branch' in revision and revision['branch']:
                            branch_info = revision['branch'][0]
                            build_info.commit_message = branch_info.get('msg', '')
                            build_info.commit_author = branch_info.get('author', {}).get('fullName', '')
                            break
                    
                    # Method 2: Build causes
                    if 'causes' in action:
                        for cause in action.get('causes', []):
                            if 'shortDescription' in cause:
                                desc = cause['shortDescription']
                                if 'Git' in desc or 'git' in desc:
                                    build_info.commit_message = desc
                                    break
        except:
            pass

    def generate_dashboard(self, builds_per_job: int = 5) -> Dict:
        """Generate dashboard data for the specific job"""
        dashboard_data = {
            'timestamp': datetime.datetime.now().isoformat(),
            'job_url': self.jenkins_url,
            'jobs': {}
        }
        
        job_name = self.extract_job_name_from_url(self.jenkins_url)
        print(f"Fetching data for job: {job_name}")
        
        builds = self.get_specific_job_builds(builds_per_job)
        
        # Calculate test statistics
        total_tests = sum(b.tests_total for b in builds)
        passed_tests = sum(b.tests_passed for b in builds)
        failed_tests = sum(b.tests_failed for b in builds)
        avg_duration = sum(b.duration for b in builds) / len(builds) if builds else 0
        
        dashboard_data['jobs'][job_name] = {
            'builds': [asdict(build) for build in builds],
            'success_count': len([b for b in builds if b.status == 'SUCCESS']),
            'failed_count': len([b for b in builds if b.status == 'FAILED']),
            'running_count': len([b for b in builds if b.status == 'RUNNING']),
            'unknown_count': len([b for b in builds if b.status == 'UNKNOWN']),
            'total_builds': len(builds),
            'total_tests': total_tests,
            'passed_tests': passed_tests,
            'failed_tests': failed_tests,
            'avg_duration': avg_duration
        }
        
        # Calculate success rate
        completed_builds = [b for b in builds if b.status in ['SUCCESS', 'FAILED']]
        if completed_builds:
            success_rate = (len([b for b in completed_builds if b.status == 'SUCCESS']) / len(completed_builds)) * 100
            dashboard_data['jobs'][job_name]['success_rate'] = round(success_rate, 2)
        else:
            dashboard_data['jobs'][job_name]['success_rate'] = 0
        
        return dashboard_data

def display_console_dashboard(dashboard_data: Dict):
    """Display dashboard in console format"""
    print("\n" + "="*80)
    print("JENKINS PIPELINE DASHBOARD")
    print("="*80)
    print(f"Job URL: {dashboard_data['job_url']}")
    print(f"Last Updated: {dashboard_data['timestamp']}")
    print("-"*80)
    
    for job_name, job_data in dashboard_data['jobs'].items():
        print(f"\n📊 JOB: {job_name}")
        print(f"   📈 Success Rate: {job_data.get('success_rate', 0)}%")
        print(f"   ✅ Successful: {job_data['success_count']} | ❌ Failed: {job_data['failed_count']} | 🔄 Running: {job_data['running_count']} | ❓ Unknown: {job_data['unknown_count']}")
        print("   Recent Builds:")
        
        if not job_data['builds']:
            print("     No builds found or unable to fetch build data")
            continue
            
        for build_dict in job_data['builds']:
            build = BuildInfo(**build_dict)
            
            # Status icons
            status_icons = {
                "SUCCESS": "✅",
                "FAILED": "❌", 
                "RUNNING": "🔄",
                "UNKNOWN": "❓"
            }
            status_icon = status_icons.get(build.status, "❓")
            
            duration_str = f"{build.duration:.1f}s" if build.duration > 0 else "N/A"
            
            print(f"     {status_icon} Build #{build.build_number:>3} | {build.status:<8} | {duration_str:>8} | {build.timestamp.strftime('%Y-%m-%d %H:%M')}")
            print(f"          🔗 {build.url}")
            
            if build.tests_total > 0:
                test_status = f"Tests: {build.tests_passed}/{build.tests_total} passed"
                if build.tests_failed > 0:
                    test_status += f" ({build.tests_failed} failed)"
                print(f"          📊 {test_status}")
            
            if build.commit_message:
                commit_preview = build.commit_message[:80] + "..." if len(build.commit_message) > 80 else build.commit_message
                print(f"          📝 {commit_preview}")
            
            if build.commit_author:
                print(f"          👤 {build.commit_author}")


def generate_html_report(dashboard_data: Dict, filename: str = "jenkins_dashboard.html") -> str:
    """Generate professional HTML report with charts and styling"""
    
    job_name = list(dashboard_data['jobs'].keys())[0]
    job_data = dashboard_data['jobs'][job_name]
    
    # Calculate chart data
    build_status_data = [
        job_data['success_count'],
        job_data['failed_count'],
        job_data['running_count'],
        job_data['unknown_count']
    ]
    
    # Handle test data properly - ensure non-negative values
    test_data = [
        max(0, job_data['passed_tests']),
        max(0, job_data['failed_tests'])
    ]
    
    # Build timeline data
    timeline_data = []
    for build_dict in job_data['builds']:
        build = BuildInfo(**build_dict)
        timeline_data.append({
            'number': build.build_number,
            'status': build.status,
            'duration': build.duration,
            'timestamp': build.timestamp.strftime('%Y-%m-%d %H:%M'),
            'tests_passed': build.tests_passed,
            'tests_total': build.tests_total
        })
    
    # Status colors
    status_colors = {
        "SUCCESS": "#28a745",
        "FAILED": "#dc3545",
        "RUNNING": "#ffc107",
        "UNKNOWN": "#6c757d"
    }
    
    # Check if we have any test data at all
    has_test_data = job_data['total_tests'] > 0
    
    # Generate HTML
    html_content = f"""
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Jenkins Dashboard - {job_name}</title>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css">
        <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
        <style>
            :root {{
                --success-color: #28a745;
                --failed-color: #dc3545;
                --running-color: #ffc107;
                --unknown-color: #6c757d;
            }}
            
            body {{
                background-color: #f8f9fa;
                font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            }}
            
            .dashboard-header {{
                background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
                color: white;
                padding: 2rem 0;
                margin-bottom: 2rem;
                border-radius: 0 0 20px 20px;
                box-shadow: 0 4px 6px rgba(0,0,0,0.1);
            }}
            
            .card {{
                border: none;
                border-radius: 15px;
                box-shadow: 0 4px 6px rgba(0,0,0,0.05);
                transition: transform 0.3s ease;
                margin-bottom: 1.5rem;
            }}
            
            .card:hover {{
                transform: translateY(-5px);
                box-shadow: 0 6px 12px rgba(0,0,0,0.1);
            }}
            
            .stat-card {{
                text-align: center;
                padding: 1.5rem;
            }}
            
            .stat-icon {{
                font-size: 2.5rem;
                margin-bottom: 1rem;
            }}
            
            .success-card {{ border-left: 4px solid var(--success-color); }}
            .failed-card {{ border-left: 4px solid var(--failed-color); }}
            .running-card {{ border-left: 4px solid var(--running-color); }}
            .tests-card {{ border-left: 4px solid #17a2b8; }}
            
            .build-badge {{
                padding: 0.5rem 1rem;
                border-radius: 20px;
                font-weight: bold;
            }}
            
            .build-success {{ background-color: var(--success-color); color: white; }}
            .build-failed {{ background-color: var(--failed-color); color: white; }}
            .build-running {{ background-color: var(--running-color); color: #212529; }}
            .build-unknown {{ background-color: var(--unknown-color); color: white; }}
            
            .chart-container {{
                position: relative;
                height: 300px;
                margin-bottom: 2rem;
            }}
            
            .no-data-message {{
                display: flex;
                align-items: center;
                justify-content: center;
                height: 100%;
                color: #6c757d;
                font-style: italic;
            }}
            
            .timeline-item {{
                padding: 1rem;
                margin-bottom: 1rem;
                border-radius: 10px;
                border-left: 4px solid;
            }}
            
            .timeline-success {{ border-color: var(--success-color); background-color: rgba(40, 167, 69, 0.1); }}
            .timeline-failed {{ border-color: var(--failed-color); background-color: rgba(220, 53, 69, 0.1); }}
            .timeline-running {{ border-color: var(--running-color); background-color: rgba(255, 193, 7, 0.1); }}
            
            .test-progress {{
                height: 8px;
                border-radius: 4px;
                margin-top: 5px;
            }}
            
            .commit-message {{
                background-color: #f8f9fa;
                border-left: 3px solid #007bff;
                padding: 0.75rem;
                margin-top: 0.5rem;
                border-radius: 0 5px 5px 0;
                font-family: 'Courier New', monospace;
                font-size: 0.9rem;
            }}
            
            .refresh-info {{
                font-size: 0.9rem;
                color: #6c757d;
            }}
        </style>
    </head>
    <body>
        <div class="dashboard-header">
            <div class="container">
                <div class="row align-items-center">
                    <div class="col-md-8">
                        <h1 class="display-5"><i class="fas fa-tachometer-alt me-3"></i>Jenkins Pipeline Dashboard</h1>
                        <p class="lead mb-0">{job_name}</p>
                        <p class="mb-0">{dashboard_data['job_url']}</p>
                    </div>
                    <div class="col-md-4 text-end">
                        <div class="refresh-info">
                            <i class="fas fa-sync-alt me-1"></i>
                            Last updated: {dashboard_data['timestamp']}
                        </div>
                    </div>
                </div>
            </div>
        </div>
        
        <div class="container">
            <!-- Statistics Cards -->
            <div class="row mb-4">
                <div class="col-md-3">
                    <div class="card success-card">
                        <div class="card-body stat-card">
                            <div class="stat-icon text-success">
                                <i class="fas fa-check-circle"></i>
                            </div>
                            <h3 class="card-title">{job_data['success_count']}</h3>
                            <p class="card-text">Successful Builds</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card failed-card">
                        <div class="card-body stat-card">
                            <div class="stat-icon text-danger">
                                <i class="fas fa-times-circle"></i>
                            </div>
                            <h3 class="card-title">{job_data['failed_count']}</h3>
                            <p class="card-text">Failed Builds</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card running-card">
                        <div class="card-body stat-card">
                            <div class="stat-icon text-warning">
                                <i class="fas fa-sync-alt"></i>
                            </div>
                            <h3 class="card-title">{job_data['running_count']}</h3>
                            <p class="card-text">Running Builds</p>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="card tests-card">
                        <div class="card-body stat-card">
                            <div class="stat-icon text-info">
                                <i class="fas fa-vial"></i>
                            </div>
                            <h3 class="card-title">{job_data['total_tests']}</h3>
                            <p class="card-text">Total Tests</p>
                        </div>
                    </div>
                </div>
            </div>
            
            <!-- Success Rate and Average Duration -->
            <div class="row mb-4">
                <div class="col-md-6">
                    <div class="card">
                        <div class="card-body">
                            <h5 class="card-title"><i class="fas fa-chart-line me-2"></i>Success Rate</h5>
                            <div class="progress" style="height: 30px;">
                                <div class="progress-bar bg-success" role="progressbar" 
                                     style="width: {job_data['success_rate']}%"
                                     aria-valuenow="{job_data['success_rate']}" aria-valuemin="0" aria-valuemax="100">
                                    {job_data['success_rate']}%
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-md-6">
                    <div class="card">
                        <div class="card-body">
                            <h5 class="card-title"><i class="fas fa-clock me-2"></i>Average Build Duration</h5>
                            <h2 class="display-6">{job_data['avg_duration']:.1f}s</h2>
                            <p class="text-muted">Average time per build</p>
                        </div>
                    </div>
                </div>
            </div>
            
            <!-- Charts -->
            <div class="row mb-4">
                <div class="col-md-6">
                    <div class="card">
                        <div class="card-body">
                            <h5 class="card-title"><i class="fas fa-chart-pie me-2"></i>Build Status Distribution</h5>
                            <div class="chart-container">
                                <canvas id="buildStatusChart"></canvas>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-md-6">
                    <div class="card">
                        <div class="card-body">
                            <h5 class="card-title"><i class="fas fa-chart-bar me-2"></i>Test Results</h5>
                            <div class="chart-container">
                                {"<canvas id='testResultsChart'></canvas>" if has_test_data else """
                                <div class="no-data-message">
                                    <div class="text-center">
                                        <i class="fas fa-chart-bar fa-3x mb-3 text-muted"></i>
                                        <p class="h5">No test data available</p>
                                        <p class="text-muted">No tests were executed in these builds</p>
                                    </div>
                                </div>
                                """}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            
            <!-- Recent Builds -->
            <div class="card">
                <div class="card-body">
                    <h5 class="card-title"><i class="fas fa-history me-2"></i>Recent Builds</h5>
                    
                    {"".join([f"""
                    <div class="timeline-item timeline-{build_dict['status'].lower()}">
                        <div class="row">
                            <div class="col-md-1">
                                <span class="build-badge build-{build_dict['status'].lower()}">
                                    #{build_dict['build_number']}
                                </span>
                            </div>
                            <div class="col-md-3">
                                <strong>Status:</strong> {build_dict['status']}<br>
                                <strong>Time:</strong> {build_dict['timestamp']}
                            </div>
                            <div class="col-md-2">
                                <strong>Duration:</strong> {build_dict['duration']:.1f}s
                            </div>
                            <div class="col-md-3">
                                {f"<strong>Tests:</strong> {build_dict['tests_passed']}/{build_dict['tests_total']} passed" if build_dict['tests_total'] > 0 else "No test data"}
                                {f'''
                                <div class="test-progress bg-light">
                                    <div class="test-progress bg-success" style="width: {build_dict['tests_passed']/build_dict['tests_total']*100 if build_dict['tests_total'] > 0 else 0}%"></div>
                                </div>
                                ''' if build_dict['tests_total'] > 0 else ""}
                            </div>
                            <div class="col-md-3 text-end">
                                <a href="{build_dict['url']}" target="_blank" class="btn btn-sm btn-outline-primary">
                                    <i class="fas fa-external-link-alt me-1"></i>View Details
                                </a>
                            </div>
                        </div>
                        {f'''
                        <div class="row mt-2">
                            <div class="col-12">
                                <div class="commit-message">
                                    <small><strong>Commit by {build_dict['commit_author']}:</strong></small><br>
                                    {html.escape(build_dict['commit_message'][:200])}{"..." if len(build_dict['commit_message']) > 200 else ""}
                                </div>
                            </div>
                        </div>
                        ''' if build_dict['commit_message'] else ""}
                    </div>
                    """ for build_dict in job_data['builds']])}
                </div>
            </div>
            
            <!-- Footer -->
            <div class="text-center mt-4 mb-4 text-muted">
                <p>Generated by Jenkins Dashboard Script • {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}</p>
            </div>
        </div>
        
        <script>
            // Build Status Chart
            const buildStatusCtx = document.getElementById('buildStatusChart').getContext('2d');
            const buildStatusChart = new Chart(buildStatusCtx, {{
                type: 'doughnut',
                data: {{
                    labels: ['Success', 'Failed', 'Running', 'Unknown'],
                    datasets: [{{
                        data: {build_status_data},
                        backgroundColor: [
                            '#28a745',
                            '#dc3545',
                            '#ffc107',
                            '#6c757d'
                        ],
                        borderWidth: 2,
                        borderColor: '#fff'
                    }}]
                }},
                options: {{
                    responsive: true,
                    maintainAspectRatio: false,
                    plugins: {{
                        legend: {{
                            position: 'bottom'
                        }}
                    }}
                }}
            }});
            
            // Test Results Chart (only if we have test data)
            {f"""
            const testResultsCtx = document.getElementById('testResultsChart').getContext('2d');
            const testResultsChart = new Chart(testResultsCtx, {{
                type: 'bar',
                data: {{
                    labels: ['Passed', 'Failed'],
                    datasets: [{{
                        label: 'Test Count',
                        data: {test_data},
                        backgroundColor: [
                            '#28a745',
                            '#dc3545'
                        ],
                        borderWidth: 1,
                        borderRadius: 5
                    }}]
                }},
                options: {{
                    responsive: true,
                    maintainAspectRatio: false,
                    scales: {{
                        y: {{
                            beginAtZero: true,
                            ticks: {{
                                stepSize: 1,
                                precision: 0
                            }},
                            grid: {{
                                drawBorder: false
                            }}
                        }},
                        x: {{
                            grid: {{
                                display: false
                            }}
                        }}
                    }},
                    plugins: {{
                        legend: {{
                            display: false
                        }},
                        tooltip: {{
                            callbacks: {{
                                label: function(context) {{
                                    return `${{context.dataset.label}}: ${{context.raw}}`;
                                }}
                            }}
                        }}
                    }}
                }}
            }};
            """ if has_test_data else ""}
        </script>
        
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js"></script>
    </body>
    </html>
    """
    
    # Save HTML file
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(html_content)
    
    print(f"\n✅ HTML report generated: {filename}")
    print(f"📊 Open {filename} in your browser to view the dashboard")
    
    return filename



def save_dashboard_json(dashboard_data: Dict, filename: str = "jenkins_dashboard.json"):
    """Save dashboard data to JSON file"""
    with open(filename, 'w') as f:
        json.dump(dashboard_data, f, indent=2, default=str)
    print(f"\n📁 Dashboard data saved to {filename}")

def main():
    parser = argparse.ArgumentParser(description='Jenkins Pipeline Dashboard - Specific Job')
    parser.add_argument('--url', required=True, help='Jenkins job URL (full path to the job)')
    parser.add_argument('--username', help='Jenkins username')
    parser.add_argument('--password', help='Jenkins password')
    parser.add_argument('--builds', type=int, default=10, help='Number of builds to display')
    parser.add_argument('--output', help='Output HTML file (default: Report.html)')
    parser.add_argument('--interval', type=int, help='Refresh interval in seconds')
    parser.add_argument('--no-ssl-verify', action='store_true', default=True, help='Disable SSL verification')
    parser.add_argument('--json', action='store_true', help='Also save JSON data file')
    
    args = parser.parse_args()
    
    # Create dashboard instance
    dashboard = JenkinsDashboard(
        args.url, 
        args.username, 
        args.password, 
        verify_ssl=not args.no_ssl_verify
    )
    
    def refresh_dashboard():
        # Generate dashboard data
        dashboard_data = dashboard.generate_dashboard(args.builds)
        
        # Display in console
        display_console_dashboard(dashboard_data)
        
        # Save to HTML file
        html_filename = args.output if args.output else "Report.html"
        generate_html_report(dashboard_data, html_filename)
        
        # Save JSON if requested
        if args.json:
            json_filename = html_filename.replace('.html', '.json') if html_filename.endswith('.html') else "dashboard.json"
            save_dashboard_json(dashboard_data, json_filename)
    
    # Initial run
    refresh_dashboard()
    
    # Continuous refresh if interval specified
    if args.interval:
        print(f"\n🔄 Refreshing every {args.interval} seconds... (Press Ctrl+C to stop)")
        try:
            while True:
                time.sleep(args.interval)
                print(f"\n{'='*80}")
                print(f"🔄 Refreshing dashboard...")
                refresh_dashboard()
        except KeyboardInterrupt:
            print("\n🛑 Dashboard stopped.")

if __name__ == "__main__":
    main()