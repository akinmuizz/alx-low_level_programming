#include "main.h"
#include <stdio.h>

/**
 * set_bit - to set value of a bit at given index to 1
 * @n: pointer to the bit
 * @index: index to set valuse at
 * Return: return -1 for errors
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	*n ^= (1 << index);

	return (1);
}
