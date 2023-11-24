#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * inion - A union to interp
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
	u.i = 1;
	return (u.c == 1);
}
