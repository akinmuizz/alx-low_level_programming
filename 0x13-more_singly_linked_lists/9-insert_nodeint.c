#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at given position
 * @head: pointer to head of node
 * @idx: index of listint
 * @n: the integer
 * Return: if function fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *main = *head;
	unsigned int i = 0;

	if (idx == 0)
	{
		return (add_nodeint(head, n));
	}

	while (main != NULL && i < idx - 1)
	{
		main = main->next;
		i++;
	}

	if (main == NULL)
	{
		return (NULL);
	}

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->n = n;
	newnode->next = main->next;
	main->next = newnode;

	return (newnode);
}
