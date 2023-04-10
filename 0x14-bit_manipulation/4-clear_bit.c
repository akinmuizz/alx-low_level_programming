#include "main.h"
#include <stdio.h>

/**
 * clear_bit - the function to set value of a bit at a given index
 * @index: where to set the value at
 * @n: the pointer
 * Return: return -1 for error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	*n &= ~(1 << index);


	return (1);
}
