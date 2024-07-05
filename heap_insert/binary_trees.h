#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
heap_t *heap_insert(heap_t **root, int value);

/* Helper function prototypes */
heap_t *find_insertion_point(heap_t *node, int height, int depth, int value);
void swap_values(heap_t *node1, heap_t *node2);
heap_t *heapify_up(heap_t *node);
int tree_height(heap_t *tree);

#endif /* BINARY_TREES_H */
