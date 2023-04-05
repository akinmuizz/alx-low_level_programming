#include "main.h"

/**
 * pop_listint -Deletes head notes, amazing
 * @head: the pointer that points to the head node
 *
 * Return: Always 0 if linked list is empty
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *tmp;

	if (*head == NULL)
	{
		return (0);
	}

	n = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return (n);
}
