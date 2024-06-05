#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid to be printed
 *
 * Description: Prints the current state of a 3x3 grid
 */
void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * stabilize - Stabilizes a 3x3 grid of sandpiles
 * @grid: 3x3 grid to be stabilized
 *
 * Description: Stabilizes a grid by toppling cells with more than 3 grains
 */
void stabilize(int grid[3][3]) {
    // 0 for not stable, 1 for stable
    int stable = 0;
    while (!stable) {
        stable = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If a cell contains more than 3
                if (grid[i][j] > 3) {
                    stable = 0; // Becomes instable
                    grid[i][j] -= 4;
                    // Add a grain to each neightboors (if possible)
                    if (i > 0) grid[i - 1][j]++; // Top
                    if (i < 2) grid[i + 1][j]++; // Bottom
                    if (j > 0) grid[i][j - 1]++; // Left
                    if (j < 2) grid[i][j + 1]++; // Right
                }
            }
        }
    }
}

/**
 * sandpiles_sum - Adds and stabilizes two 3x3 grids of sandpiles
 * @grid1: First 3x3 grid and also the resulting grid after stabilization
 * @grid2: Second 3x3 grid to be added to the first grid
 *
 * Description: Adds two sandpiles and stabilizes the resulting grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Add two sandpiles
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Stabilize the resulting sandpile
    int stable = 0;
    while (!stable) {
        stable = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    stable = 0;
                    printf("=\n");
                    print_grid(grid1);
                    stabilize(grid1);
                    break;
                }
            }
            if (!stable)
                break;
        }
    }
}
