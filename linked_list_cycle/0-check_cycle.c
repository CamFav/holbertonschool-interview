#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle
 * @list: Pointer to the head of the list
 * Return: 1 if cycle exists, 0 otherwise
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    if (list == NULL || list->next == NULL)
        return (0);

    slow = list;
    fast = list->next;

    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            return (1);
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return (0);
}
