#!/usr/bin/python3
"""
Log parsing script that reads logs from stdin and computes metrics.
"""
import sys
import re
from signal import signal, SIGINT

# Initialize metrics
total_file_size = 0
status_code_counts = {}
VALID_STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]
line_count = 0


def print_stats():
    """
    Print the current metrics: total file size and count of status codes.
    """
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        print(f"{code}: {status_code_counts[code]}")


def signal_handler(signal_received, frame):
    """
    Handle keyboard interruption (CTRL+C) and print final statistics.
    """
    print_stats()
    sys.exit(0)


# Register the signal handler
signal(SIGINT, signal_handler)

# Read input line by line
try:
    for line in sys.stdin:
        line_count += 1
        try:
            # Match the input format using regex
            pattern = (
                r'.+ - \[.+\] "GET /projects/260 HTTP/1.1" (\d{3}) (\d+)'
            )
            match = re.match(pattern, line.strip())
            if match:
                global total_file_size
                status_code = int(match.group(1))
                file_size = int(match.group(2))
                total_file_size += file_size

                if status_code in VALID_STATUS_CODES:
                    if status_code not in status_code_counts:
                        status_code_counts[status_code] = 0
                    status_code_counts[status_code] += 1
        except Exception:
            # Ignore malformed lines
            continue

        # Print stats every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    # Print stats and exit gracefully on keyboard interrupt
    print_stats()
    sys.exit(0)
