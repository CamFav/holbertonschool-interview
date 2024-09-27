#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Restores the Max Heap property by shifting the root node down.
 * @node: Pointer to the root of the heap to heapify down.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;
    heap_t *left = node->left;
    heap_t *right = node->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != node)
    {
        int temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
    }
}

/**
 * get_last_node - Gets the last node in a level-order traversal of the heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node in level-order.
 */
heap_t *get_last_node(heap_t *root)
{
    /* Implement a queue for level-order traversal */
    /* You can create a helper function to handle this */
    /* Pseudo code example using a queue can be added here */
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value of the extracted root node or 0 if it fails.
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    heap_t *root_node = *root;
    int extracted_value = root_node->n;

    if (!root_node->left && !root_node->right)
    {
        free(root_node);
        *root = NULL;
        return (extracted_value);
    }

    /* Get the last node in level-order */
    heap_t *last_node = get_last_node(root_node);

    /* Swap the root node with the last node */
    root_node->n = last_node->n;

    /* Remove the last node from the tree */
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;
    free(last_node);

    /* Restore the heap property */
    heapify_down(*root);

    return (extracted_value);
}
