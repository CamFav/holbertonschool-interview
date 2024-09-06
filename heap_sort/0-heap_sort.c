#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Sifts down an element in a heap to maintain heap property
 * @array: The array representing the heap
 * @start: The index to start sifting down
 * @end: The last index of the heap
 * @size: The size of the array (for printing purposes)
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;

    while (2 * root + 1 <= end)  // While the root has at least one child
    {
        size_t child = 2 * root + 1;  // Left child
        size_t swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;
        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;
        
        if (swap_idx == root)
            return;

        swap(&array[root], &array[swap_idx]);
        print_array(array, size);
        root = swap_idx;
    }
}

/**
 * heapify - Builds a max heap from the array
 * @array: The array to heapify
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    int start = (int)((size - 2) / 2);  // Start at the last parent node

    while (start >= 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    heapify(array, size);

    size_t end = size - 1;

    while (end > 0)
    {
        swap(&array[end], &array[0]);
        print_array(array, size);
        end--;
        sift_down(array, 0, end, size);
    }
}
