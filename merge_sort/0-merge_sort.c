#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays of array[].
 * First subarray is array[left..middle]
 * Second subarray is array[middle+1..right]
 * @array: The array to be sorted
 * @temp: Temporary array used for merging
 * @left: Starting index of the left subarray
 * @middle: Middle index, separating the two subarrays
 * @right: Ending index of the right subarray
 */
void merge(int *array, int *temp, size_t left, size_t middle, size_t right)
{
	size_t i = left, j = middle + 1, k = left;

	while (i <= middle && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= middle)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];
}

/**
 * merge_sort_recursive - Recursively divides the array
 * and merges the subarrays
 * @array: The array to be sorted
 * @temp: Temporary array used for merging
 * @left: Left index
 * @right: Right index
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (left < right)
	{
		size_t middle = left + (right - left) / 2;

		merge_sort_recursive(array, temp, left, middle);
		merge_sort_recursive(array, temp, middle + 1, right);
		merge(array, temp, left, middle, right);
	}
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size - 1);

	free(temp);
}
