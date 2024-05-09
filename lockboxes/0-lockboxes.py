#!/usr/bin/python3
"""
Method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be unlocked.

    Args:
        boxes (list): A list of lists

    Returns:
        bool: True if all boxes can be opened; otherwise, False.

    Description:
        This function utilizes depth-first search (DFS) to explore the boxes
        and their keys. It keeps track of visited boxes to ensure that all
        reachable boxes are visited. It determines what
        boxes can be opened based on the traversal results.
    """
    # Visited boxes
    visited = set()

    # DFS Algo
    def dfs(box_index):
        """Explore boxes recursively using DFS."""

        visited.add(box_index)

        for key in boxes[box_index]:
            if key < len(boxes) and key not in visited:
                dfs(key)

    # Start DFS from box 0
    dfs(0)

    return len(visited) == len(boxes)
