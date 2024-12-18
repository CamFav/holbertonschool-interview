#!/usr/bin/python3
"""
Log parsing script that reads logs from stdin and computes metrics.
"""
import sys
import re
import signal

# Initialize metrics
total_file_size = 0
status_code_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0,
}
line_count = 0


def print_statistics():
    """
    Print the current metrics: total file size and count of status codes.
    """
    print("File size: {}".format(total_file_size))
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print("{}: {}".format(code, status_code_counts[code]))


def signal_handler(sig, frame):
    """
    Handle keyboard interruption (CTRL+C) and print final statistics.
    """
    print_statistics()
    sys.exit(0)


# Register the signal handler
signal.signal(signal.SIGINT, signal_handler)

# Read input line by line
try:
    for line in sys.stdin:
        if not line.strip():
            continue
        line_count += 1

        # Split line and validate
        line_parsed = line.split()
        length_line = len(line_parsed)
        if length_line < 2:
            continue

        try:
            # Update total file size
            file_size = int(line_parsed[-1])
            total_file_size += file_size
        except ValueError:
            continue

        # Update status code counts
        status_code = line_parsed[-2]
        if status_code in status_code_counts:
            status_code_counts[status_code] += 1

        # Print stats every 10 lines
        if line_count % 10 == 0:
            print_statistics()

except KeyboardInterrupt:
    print_statistics()
finally:
    print_statistics()
