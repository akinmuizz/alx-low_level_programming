#include <stdio.h>
#include "main.h"

/**
 * flip_bits - function to count number bits flipped
 * @n: the number in the function
 * @m: number wo be flipped
 * Return: returns bits for success
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, bit = 0;

	while (xor > 0)
	{
		bit += (xor & 1);
		xor >>= 1;
	}

	return (bit);
}
