#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - changes a binary number to an unsigned int
 * @b: string contains binary number
 *
 * Return: the number converted
 */

unsigned int binary_to_uint(const char *b)
{
	int c;
	unsigned int value_dec = 0;

	if (!b)
	{
		return (0);
	}
	for (c = 0; b[c]; c++)
	{
		if (b[c] < '0' || b[c] > '1')
		{
			return (0);
		}
		value_dec = 2 * value_dec + (b[c] - '0');
	}
	return (value_dec);
}
