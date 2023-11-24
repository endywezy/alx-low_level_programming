#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * @void: no parameters
 * @union: the interp
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	union
	{
		int i;
		char c;
	}
	u;
	u . i = 1;
	/* Unused variables are causing warnings, ignore them using (void) */
	(void)u.i;
	(void)u.c;
	return (u . c == 1);
}
