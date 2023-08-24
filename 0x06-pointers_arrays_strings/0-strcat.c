#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: dest;
 */

char *_strcat(char *dest, char *src)
{
	int destlen = 0;
	int srclen = 0;
	int e;

	for (e = 0 ; dest[e] != '\0' ; e++)
		destlen++;
	for (e = 0 ; src[e] != '\0' ; e++)
		srclen++;

	for (e = 0 ; e <= srclen ; e++)
		dest[destlen + e] = src[e];
	return (dest);
}
