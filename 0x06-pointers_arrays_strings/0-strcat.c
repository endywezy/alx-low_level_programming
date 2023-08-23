#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: dest;
 */

char *_strcat(char *dest, char *src)
{
	int destendy = 0;
	int srcendy = 0;
	int e;

	for (e = 0 ; dest[e] != '\0' ; e++)
		destendy++;
	for (e = 0 ; src[e] != '\0' ; e++)
		srcendy++;

	for (e = 0 ; e <= srcendy ; e++)
		dest[destendy + e] = src[e];
	return (dest);
}
