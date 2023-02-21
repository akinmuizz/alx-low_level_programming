#include "main.h"

/**
 * print_sign - prints the signs of numbers
 * @n: The number that will be checked
 * Return: 0 always
 */

int print_sign(int n)

{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n < 0)
	{
		_putchar(45);
		return (-1);
	}
	else
	{
		_putchar(48);
	return (0);
	}
}
