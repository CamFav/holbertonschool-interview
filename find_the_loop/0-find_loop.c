#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a singly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Address of the node where the loop starts,
 * or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next; /* Move slow pointer by 1 */
		fast = fast->next->next; /* Move fast pointer by 2 */

		if (slow == fast)
		{
			slow = head; /* Move slow to head */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow); /* Loop start */
		}
	}
	return (NULL);
}
