#include "main.h"
/**
 * _abs -function define the vali=ue of a number
 * @e: function parameter
 * Return: -e or e;
 */

int _abs(int e)
{
	if (e < 0)
		return (-e);
	else if (e >= 0)
	{
		return (e);
	}
	return (0);
}
