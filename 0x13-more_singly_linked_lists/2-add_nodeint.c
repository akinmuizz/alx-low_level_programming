#include "lists.h"

/**
 * add_nodeint - name of function
 * @head: pointer to address of head of our list
 * @n: the integer
 *
 * Return: always NULL if function fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint *newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
	{
		return (NULL);
	}

	newnode->n = n;
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}
