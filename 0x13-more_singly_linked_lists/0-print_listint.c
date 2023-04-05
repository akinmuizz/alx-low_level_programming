#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint - singly linked list
 * @h: integer
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t node = 0;

	while (h != NULL)
	{
		node++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (node);
}
