#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Creates a new node with the given value and parent.
 * @parent: Pointer to the parent node.
 * @value: The value to be stored in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
binary_tree_t *create_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @start: The starting index of the array/subarray.
 * @end: The ending index of the array/subarray.
 * @parent: Pointer to the parent node.
 *
 * Return: Pointer to the root node of the created AVL subtree.
 */
binary_tree_t *build_avl_tree
(int *array, int start, int end, binary_tree_t *parent)
{
	int mid;
	binary_tree_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = create_node(parent, array[mid]);

	if (node == NULL)
		return (NULL);

	node->left = build_avl_tree(array, start, mid - 1, node);
	node->right = build_avl_tree(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return ((avl_t *)build_avl_tree(array, 0, size - 1, NULL));
}
