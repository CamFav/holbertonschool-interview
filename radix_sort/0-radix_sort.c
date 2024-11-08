#include "sort.h"

/**
 * counting_sort_by_digit - Sorts array elements by a specific digit place
 * @array: The array to be sorted
 * @size: The size of the array
 * @digit_place: The current digit place to sort by (1, 10, 100, ...)
 */

void counting_sort_by_digit(int *array, size_t size, int digit_place)
{
    int count[10] = {0};
    int sorted[size];

    /* Calculate count of elements */
    for (int i = 0; i < size; i++)
    {
        int index = (array[i] / digit_place) % 10;
        count[index]++;
    }

    /* Calculate cumulative count */
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    /* Place the elements in sorted order */
    for (int i = size - 1; i >= 0; i--)
    {
        /* Find the current digit based on diigt_place */
        int current_digit = (array[i] / digit_place) % 10;
        sorted[count[current_digit] - 1] = array[i - 1];
        count[current_digit]--;
    }

    /* Copy the sorted elements into original array */
    for (int i = 0; i < size; i++) {
        array[i] = sorted[i];

    free(sorted);
    }
}


/**
 * radic_sort - sorts an array of integers in ascending order using the Radix sort algorithm
 * @array: array that contain only nymbers >=0
 * 
 * Return: Print the array each time you increase your significant digit
 */

void radix_sort(int *array, size_t size)
{
    int max_num = array[0];
    size_t i;
    int digit_place;

    /* Find the maximum number to determine the number of digits */
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_num)
            max_num = array[i];
    }

    /* Sort by each digit place */
    for (digit_place = 1; max_num / digit_place > 0; digit_place *= 10)
    {
        counting_sort_by_digit(array, size, digit_place);

        /* Print the array after each digit place sort */
        for (i = 0; i < size; i++)
        {
            printf("%d", array[i]);
            if (i < size - 1)
                printf(", ");
        }
        printf("\n");
    }
}
