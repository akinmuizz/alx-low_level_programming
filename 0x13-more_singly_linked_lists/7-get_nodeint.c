#include "lists.h"

/**
 * get_nodeint_at_index - a function
 * @head: the pointer to first node
 * @index: index of where to be located
 *
 * Return: return NULL if node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *main = head;
	unsigned int node = 0;

	while (main != NULL)
	{
		if (node == index)
			return (main);
		node++;
		main = main->next;
	}

	return (NULL);
}
