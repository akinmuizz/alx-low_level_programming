#include "lists.h"

/**
 * free_listint - frees a listint_t function
 * @head: a pointer to the head of the list
 */

void free_listint(listint_t *head)
{
	listint *project;

	while (head != NULL)
	{
		project = head->next;
		free(head);
		head = project;
	}
}
