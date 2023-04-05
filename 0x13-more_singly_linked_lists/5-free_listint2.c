#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list
 * @head: the pointer to the headnode
 *
 * Description: this will set the head pointer to NULL
 */

void free_listint2(listint_t **head)
{
	listint_t *main, *next;

	if (head == NULL)
		return;

	main = *head;

	while (main != NULL)
	{
		next = main->next;
		free(main);
		main = next;
	}

	*head = NULL;
}
