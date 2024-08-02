#!/usr/bin/python3
import sys


def solve_nqueens(n):
    def backtrack(row, queens, xy_diff, xy_sum):
        if row == n:
            result.append([[i, queens[i]] for i in range(n)])
            return
        for col in range(n):
            if (col not in queens and
                    row - col not in xy_diff and
                    row + col not in xy_sum):
                backtrack(row + 1,
                          queens + [col],
                          xy_diff + [row - col],
                          xy_sum + [row + col])

    result = []
    backtrack(0, [], [], [])
    for solution in result:
        print(solution)


def validate_input(args):
    if len(args) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(args[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    return n


if __name__ == "__main__":
    n = validate_input(sys.argv)
    solve_nqueens(n)
