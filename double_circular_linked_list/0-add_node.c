#include "list.h"

/**
 * add_node_end - Adds a new node to the end of
 * a circular doubly linked list
 * @list: Pointer to the head of the list
 * @str: String to be duplicated and stored in the new node
 *
 * Return: Address of the new node, otherwise NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tail;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* If list is empty, set prev and next pointers of the node to itself */
	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else /* List is not empty, insert at the end */
	{
		tail = (*list)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of
 * a circular doubly linked list
 * @list: Pointer to the head of the list
 * @str: String to be duplicated and stored in the new node
 *
 * Return: Address of the new node, otherwise NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *tail;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	/* If list is empty, set prev and next pointers of the node to itself */
	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else /* List is not empty, insert at the beginning */
	{
		tail = (*list)->prev;
		new_node->next = *list;
		new_node->prev = tail;
		tail->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	return (new_node);
}
