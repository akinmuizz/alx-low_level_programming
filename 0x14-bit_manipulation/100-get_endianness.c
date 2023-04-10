#include <stdio.h>
#include "main.h"

/**
 * get_endianness - function to check tendianess
 *
 * Return: 0 for big endianess and 1 for little endianness
 */

int get_endianness(void)
{
	int numba = 1;
	char *endiann = (char *)&numba;

	if (*endiann == 1)
	{
		return (1);
	}

	return (0);
}
