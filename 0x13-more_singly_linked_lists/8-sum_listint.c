#include "lists.h"

/**
 * sum_listint - a function
 * @head: this points to the head node, as a pointer
 *
 * Return: always 0 if empty list
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *mains = head;

	while (mains)
	{
		sum += mains->n;
		mains = mains->next;
	}

	return  (sum);
}
