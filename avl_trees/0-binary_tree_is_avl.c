#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node of the new node
 * @value: The value to store in the new node
 *
 * Return: Pointer to the new node, or NULL if allocation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * is_bst - Helper function to check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum value that the current node's value should be greater than.
 * @max: Maximum value that the current node's value should be less than.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    int left_bst = is_bst(tree->left, min, tree->n);
    int right_bst = is_bst(tree->right, tree->n, max);

    return (left_bst && right_bst);
}

/**
 * height - Helper function to calculate the height of a binary tree
 * and check if it is balanced.
 * @tree: Pointer to the root node of the tree.
 * @balanced: Pointer to a flag indicating if the tree is balanced.
 *
 * Return: The height of the tree, or -1 if the tree is not balanced.
 */
int height(const binary_tree_t *tree, int *balanced)
{
	if (!tree)
		return (0);

	int left_height = height(tree->left, balanced);
	int right_height = height(tree->right, balanced);

	if (left_height == -1 || right_height == -1 ||
		abs(left_height - right_height) > 1)
	{
		*balanced = 0;
		return (-1);
	}

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int balanced = 1;

	/* Check if it's a valid BST and if it's balanced */
	if (is_bst(tree, INT_MIN, INT_MAX) && height(tree, &balanced) != -1 &&
		balanced)
		return (1);

	return (0);
}
