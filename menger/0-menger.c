#include <stdio.h>
#include "menger.h"

/**
 * is_hole - Checks if a cell at (row, col) should be a hole.
 * @row: The row index.
 * @col: The column index.
 *
 * Return: 1 if the cell is a hole, 0 otherwise.
 */
static int is_hole(int row, int col)
{
    while (row > 0 || col > 0)
    {
        if (row % 3 == 1 && col % 3 == 1)
            return (1);
        row /= 3;
        col /= 3;
    }
    return (0);
}

/**
 * menger - Draws a 2D Menger sponge of a given level.
 * @level: The level of the sponge.
 */
void menger(int level)
{
    int size, row, col;

    if (level < 0)
        return;

    size = 1;
    for (row = 0; row < level; row++)
        size *= 3;

    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (is_hole(row, col))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}
