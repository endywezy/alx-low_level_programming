#include "main.h"
/**
 * print_last_digit - print the last digit of a number
 * @e: the number who last digit needs to be printed
 * Return: the value of the last digit
 */

int print_last_digit(int e)
{
	int a;

	a = e % 10;
	if (e < 0)
		a = -a;
	_putchar(a + '0');
	return (a);
}
