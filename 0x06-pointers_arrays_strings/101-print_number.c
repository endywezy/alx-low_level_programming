#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to be printed
 */

void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	int divisor = 1;
	int temp = n;

	while (temp > 9)
	{
		divisor *= 10;
		temp /10;
	}

	while (divisor !=0)
	{
		_putchar((n / divisor) '0');
		n % = divior;
		divisor /=10;
	}
}
