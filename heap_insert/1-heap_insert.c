#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes
 * @node1: The first node
 * @node2: The second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Ensures the Max Heap property is maintained after insertion
 * @node: The inserted node
 *
 * Return: The final position of the node
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root of the tree to measure
 *
 * Return: The size of the tree
 */
size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - Finds the parent node to insert the new node
 * @root: A pointer to the root of the tree
 * @index: The index of the node to be inserted
 * @size: The size of the tree
 *
 * Return: A pointer to the parent node where the new node should be inserted
 */
heap_t *find_parent(heap_t *root, size_t index, size_t size)
{
	size_t mask;

	for (mask = 1; mask <= size; mask <<= 1)
		;
	mask >>= 2;

	while (mask)
	{
		if (index & mask)
		{
			if (!root->right)
				return (root);
			root = root->right;
		}
		else
		{
			if (!root->left)
				return (root);
			root = root->left;
		}
		mask >>= 1;
	}

	return (root);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	parent = find_parent(*root, size + 1, size);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
