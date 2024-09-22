#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: The pointer to the first element of the subarray
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Helper function to perform recursive binary search
 * @array: The pointer to the first element of the array
 * @left: The leftmost index of the current subarray
 * @right: The rightmost index of the current subarray
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	print_array(array, left, right);

	mid = (left + right) / 2;

	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return (mid);

	if (array[mid] >= value)
		return (advanced_binary_recursive(array, left, mid, value));
	return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Initiates an advanced binary search to find the first occurrence
 * @array: The pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
