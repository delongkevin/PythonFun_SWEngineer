# Basic usage with ASC file
python CAN_log_parser.py logfile.asc --plot

# Generate report and CSV export
python CAN_log_parser.py logfile.blf --report --csv --output-dir ./results

# Compare specific messages
python CAN_log_parser.py logfile.txt --compare 0 5 --verbose

# All options together
python CAN_log_parser.py logfile.blf --plot --report --csv --max-messages 100 --output-prefix MAGNA