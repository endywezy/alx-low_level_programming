#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	/**
	 *  union - A union to inthe same memory 
	 *  @i: An integer.
	 *  @c: A character.
	 */
	union
	{
		int i;
		char c;
	}
	u;
	u . i = 1;
	return (u . c == 1);
}
