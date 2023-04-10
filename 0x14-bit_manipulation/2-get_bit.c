#include "main.h"
#include <stdio.h>

/**
 * get_bit - retrieves value of bit in an index
 * @n: bit to be retrieved
 * @index: index to get the value at
 *
 * Return: retutn -1 if error occurs
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
