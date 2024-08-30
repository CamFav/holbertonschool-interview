#!/usr/bin/python3
"""
rain - Calculate the amount of rainwater trapped between walls.

Given a list of non-negative integers representing the heights of walls with unit width 1,
this function calculates the total amount of water retained after it rains.

Parameters:
    walls (list of int): A list of non-negative integers representing the heights of the walls.

Returns:
    int: The total amount of water trapped between the walls.
"""

def rain(walls):
    """
    Calculate the total amount of water trapped between walls after it rains.

    Args:
        walls (list of int): A list of non-negative integers representing wall heights.

    Returns:
        int: The total amount of water trapped.
    """
    if not walls:
        return 0
    
    n = len(walls)
    if n < 3:
        return 0
    
    # Initialize arrays for left and right max heights
    left_max = [0] * n
    right_max = [0] * n
    
    # Fill left_max array
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])
    
    # Fill right_max array
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])
    
    # Calculate the total water trapped
    total_water = 0
    for i in range(n):
        water_at_i = min(left_max[i], right_max[i]) - walls[i]
        if water_at_i > 0:
            total_water += water_at_i
    
    return total_water
