#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a circular doubly linked list
 * @list: Pointer to the head of the list
 * @str: String to be duplicated and stored in the new node
 * 
 * Return: Adress of the new node, otherwise NULL
 */
List *add_node_end(List **list, char *str) {
    List *new_node, *tail;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(List));

    if (!new_node)
        return NULL;

    /* Duplicate the string */
    new_node->str = strdup(str);

    if (!new_node->str)
    {
        free(new_node);
        return NULL;
    }

    /* If list is empty, set prev and next pointers of the node to itsef. */
    if (!*list)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *list = new_node;
    }

    /* Else, if list is not empty, set the pointers to insert it at the end */
    else
    {
        tail = (*list)->prev;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = *list;
        (*list)->prev = new_node;
    }

    return new_node;
}
