#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located, or NULL
 * if value is not present or head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express = NULL, *prev = NULL;

	if (!list)
		return (NULL);

	express = list->express;
	prev = list;

	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n >= value)
			break;
		prev = express;
		express = express->express;
	}

	if (!express)
	{
		while (list->next)
			list = list->next;
		express = list;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, express->index);

	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
