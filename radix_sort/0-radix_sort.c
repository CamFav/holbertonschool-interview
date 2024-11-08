#include "sort.h"

/**
 * counting_sort_by_digit - 
 * @array:
 * @size:
 * @int:
 * 
 * Return: 
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
    }

    /* Copy the sorted elements into original array */
    for (int i = 0; i < size; i++) {
        array[i] = sorted[i];
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

}