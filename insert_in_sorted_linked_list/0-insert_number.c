#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts a new node into a sorted singly linked list.
 * @head: Double pointer to the head of the list.
 * @number: The number to be inserted into the list.
 *
 * Return: New node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Traverse the list to find the insertion position */
    current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    /* Insert the new node at the correct position */
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
