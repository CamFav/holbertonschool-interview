#include "slide_line.h"

/**
 * slide_and_merge_left - Slides and merges an array of integers to the left
 * @line: Pointer to the array of integers
 * @size: Size of the array
 */
static void slide_and_merge_left(int *line, size_t size)
{
    size_t i, j, k;

    /* Move all non-zero elements to the front of the array */
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
            line[j++] = line[i];
    }

    /* Fill the rest with zeros */
    for (k = j; k < size; k++)
        line[k] = 0;

    /* Merge contiguous same numbers */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    /* Move all non-zero elements to the front again */
    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
            line[j++] = line[i];
    }

    /* Fill the rest with zeros */
    for (k = j; k < size; k++)
        line[k] = 0;
}

/**
 * slide_and_merge_right - Slides and merges an array of integers to the right
 * @line: Pointer to the array of integers
 * @size: Size of the array
 */
static void slide_and_merge_right(int *line, size_t size)
{
    size_t i, j, k;

    /* Move all non-zero elements to the back of the array */
    for (i = size - 1, j = size - 1; (int)i >= 0; i--)
    {
        if (line[i] != 0)
            line[j--] = line[i];
    }

    /* Fill the rest with zeros */
    for (k = j; (int)k >= 0; k--)
        line[k] = 0;

    /* Merge contiguous same numbers */
    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }

    /* Move all non-zero elements to the back again */
    for (i = size - 1, j = size - 1; (int)i >= 0; i--)
    {
        if (line[i] != 0)
            line[j--] = line[i];
    }

    /* Fill the rest with zeros */
    for (k = j; (int)k >= 0; k--)
        line[k] = 0;
}

/**
 * slide_line - Slides and merges an array of integers in the given direction
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
    {
        slide_and_merge_left(line, size);
    }
    else if (direction == SLIDE_RIGHT)
    {
        slide_and_merge_right(line, size);
    }
    else
    {
        return (0);
    }

    return (1);
}
