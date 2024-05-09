#!/usr/bin/python3
def canUnlockAll(boxes):
    # Visited boxes
    visited = set()

    # DFS Algo
    def dfs(box_index):

        visited.add(box_index)

        for key in boxes[box_index]:
            if key not in visited:
                dfs(key)

    # Start DFS from box 0
    dfs(0)

    return len(visited) == len(boxes)
