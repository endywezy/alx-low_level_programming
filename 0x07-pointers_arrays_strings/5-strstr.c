#include "main.h"
#include <stddef.h>

/**
 * _strstr - function finds the first occurrence of the substring
 * @haystack: The terminating null bytes
 * @needle: in the string haystack
 * Return: NuLL or a pointer to the beginning of the located substring
 */

char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*haystack !=  '\0')
	{
		char *haystackptr = haystack;

		char *needleptr = needle;

		while (*needleptr != '\0' && *haystackptr == *needleptr)
		{
			haystackptr++;
			needleptr++;
		}
		if (*needleptr == '\0')
		{
			return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
