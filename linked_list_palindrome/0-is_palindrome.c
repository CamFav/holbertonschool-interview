#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * reverse_copy - creates a reversed copy of a singly linked list
 * @head: pointer to the head of the original list
 *
 * Return: pointer to the head of the new reversed list, or NULL if it fails
 */
listint_t *reverse_copy(listint_t *head)
{
    listint_t *new_head = NULL;
    listint_t *current = head;
    listint_t *new_node;

    while (current != NULL)
    {
        new_node = malloc(sizeof(listint_t));
        if (new_node == NULL)
        {
            return (NULL);
        }
        new_node->n = current->n;
        new_node->next = new_head;
        new_head = new_node;
        current = current->next;
    }
    return (new_head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the linked list
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */
int is_palindrome(listint_t **head)
{
    listint_t *reversed_head;
    listint_t *original;
    listint_t *reversed;
    int is_palindrome;

    if (*head == NULL || (*head)->next == NULL)
    {
        return (1);
    }

    /* Create a reversed copy of the original list */
    reversed_head = reverse_copy(*head);
    if (reversed_head == NULL)
    {
        return (0);
    }

    /* Compare the two lists */
    original = *head;
    reversed = reversed_head;
    is_palindrome = 1;

    while (original != NULL && reversed != NULL)
    {
        if (original->n != reversed->n)
        {
            is_palindrome = 0;
            break;
        }
        original = original->next;
        reversed = reversed->next;
    }

    free_listint(reversed_head);

    return (is_palindrome);
}
