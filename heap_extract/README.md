# Heap Extract

## Description

This project implements a function that extracts the root node of a Max Binary Heap in C. The root node is freed and replaced with the last level-order node in the heap, and the heap is rebuilt if necessary. The project follows specific guidelines regarding memory management, coding style, and compilation requirements.

## Data Structures

The project uses the following data structures for binary trees:

```c
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
typedef struct binary_tree_s heap_t;```

## Function Prototype

```c
int heap_extract(heap_t **root);```

### Parameters:
- **root**: A double pointer to the root node of the heap.

### Return Value:
- The function returns the value stored in the root node, or 0 if the function fails.

## Compilation

To compile the code, the following command should be used:

```bash
gcc -Wall -Wextra -Werror -pedantic -o heap_extract 0-main.c 0-heap_extract.c binary_tree_print.c -L. -lheap```


### Requirements:
- The project is compiled on **Ubuntu 14.04 LTS** using **gcc 4.8.4**.
- All files are compiled with the following flags: `-Wall -Werror -Wextra -pedantic`.
- The code follows the **Betty** coding style, checked using `betty-style.pl` and `betty-doc.pl`.

## Usage

After compiling, you can run the program with **Valgrind** to check for memory leaks:

```bash
valgrind ./heap_extract

## Example Output

$ ./heap_extract
                  .-----------------(098)-----------------.
            .-------(095)-------.                   .-------(091)-------.
       .--(084)--.         .--(079)--.         .--(087)--.         .--(062)--.
  .--(047)     (034)     (002)     (020)     (022)     (068)     (001)     (021)
(032)

Extracted: 98

                  .-----------------(095)-----------------.
       .-------(084)-------.                   .-------(091)-------.
  .--(047)--.         .--(079)--.         .--(087)--.         .--(062)--.
(032)     (034)     (002)     (020)     (022)     (068)     (001)     (021)

Extracted: 95

## Licence

This project is licensed under the Holberton School license.



