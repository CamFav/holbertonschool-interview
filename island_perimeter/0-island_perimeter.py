#!/usr/bin/python3
"""
island_perimeter - Calculate the amount of rainwater trapped between walls.

Parameters:
    grid (list of int): A list of integers representing an island.

Returns:
    int: The perimeter of the island.
"""
def island_perimeter(grid):
    """
    Calculate the amount of rainwater trapped between walls.

    Args:
        grid (list of int): A list of integers representing an island.
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
