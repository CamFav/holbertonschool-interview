#!/usr/bin/python3
"""Pascal Triangle"""


def pascal_triangle(n):
    """Function that returns a list of lists of integers
    representing the Pascal's triangle of n

    Args:
        n (int): number of rows
    """
    if n < 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        prev_row = triangle[-1]
        new_row = [1]

        for j in range(len(prev_row) - 1):
            new_row.append(prev_row[j] + prev_row[j + 1])

        new_row.append(1)
        triangle.append(new_row)

    return triangle
