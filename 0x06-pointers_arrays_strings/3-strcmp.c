#include "main.h"

/**
 * _strcmp - string compare
 * @s1: parameter 1
 * @s2: parameter 2
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int e;

	    for (e = 0 ; s1[e] != '\0' || s2[e] != '\0' ; e++)
	    {
		    if (s1[e] != s2[e])
		    {
			    if (s1[e] < s2[e])
				    return (s1[e] - s2[e]);
			    else if (s2[e] < s1[e])
				    return (s1[e] - s2[e]);
		    }
	    }
	    return (0);
}
