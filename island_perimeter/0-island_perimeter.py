#!/usr/bin/python3
"""
This module provides a function to calculate the perimeter of an island in a grid.
"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): A 2D grid representing the map of the island and water.

    Returns:
        int: The perimeter of the island.
    """
    # Perimeter of the island
    perimeter = 0
    
    # Iterate over the grid
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            
            # If the current cell is an island cell
            if grid[i][j] == 1:
                
                # Check the top cell
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                    
                # Check the bottom cell    
                if i == len(grid)-1 or grid[i+1][j] == 0:
                    perimeter += 1
                    
                # Check the left cell
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                    
                # Check the right cell
                if j == len(grid[0])-1 or grid[i][j+1] == 0:
                    perimeter += 1
                    
    return perimeter
