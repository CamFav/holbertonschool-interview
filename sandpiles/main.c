#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

     int grid3[3][3] = {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };
    int grid4[3][3] = {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };

    // ex grid1 et grid2
    print_grid_sum(grid1, grid2);
    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    // ex grid3 et grid4
    print_grid_sum(grid3, grid4);
    sandpiles_sum(grid3, grid4);

    printf("=\n");
    print_grid(grid3);

    return (EXIT_SUCCESS);
}
