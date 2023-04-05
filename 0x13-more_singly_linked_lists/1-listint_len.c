#include "lists.h"
#include <stdio.h>

/**
 * listint_len - the name of our function
 * @h: a pointer
 *
 * Return: number of elements in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t node = 0;

	while (h != NULL)
	{
		node++;
		h = h->next;
	}

	return (node);
}
