#include "main.h"
#include <stdio.h>

/**
 * _strpbrk - function locates the first occurrence in the string s
 * @s: that matches one of the bytes
 * @accept: the bytes in the string
 * Return: 0
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *acceptPtr = accept;

		while (*acceptPtr != '\0')
		{
			if (*s == *acceptPtr)
			{
				return (s);
			}
			acceptPtr++;
		}
		s++;
	}
	return (NULL);
}
