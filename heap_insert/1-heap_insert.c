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
 * find_insertion_point - Finds the insertion point for the new node recursively
 * @node: The current node in the traversal
 * @height: The height of the current node
 * @depth: The current depth of the traversal
 * @value: The value to be inserted
 *
 * Return: A pointer to the newly inserted node
 */
heap_t *find_insertion_point(heap_t *node, int height, int depth, int value)
{
    heap_t *new_node;

    if (!node->left)
    {
        new_node = binary_tree_node(node, value);
        node->left = new_node;
        return (new_node);
    }
    else if (!node->right)
    {
        new_node = binary_tree_node(node, value);
        node->right = new_node;
        return (new_node);
    }
    else if (depth < height - 1)
    {
        new_node = find_insertion_point(node->left, height, depth + 1, value);
        if (!new_node)
            new_node = find_insertion_point(node->right, height, depth + 1, value);
        return (new_node);
    }
    return (NULL);
}

/**
 * tree_height - Computes the height of the tree
 * @tree: A pointer to the root of the tree
 *
 * Return: The height of the tree
 */
int tree_height(heap_t *tree)
{
    int left_height;
    int right_height;

    if (!tree)
        return (0);

    left_height = tree_height(tree->left);
    right_height = tree_height(tree->right);
    return (left_height > right_height ? left_height + 1 : right_height + 1);
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
    heap_t *new_node;
    int height;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    height = tree_height(*root);
    new_node = find_insertion_point(*root, height, 0, value);
    if (!new_node)
        return (NULL);

    return (heapify_up(new_node));
}
