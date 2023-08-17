#include "main.h"
#include <stdio.h>
void times_table(void)
{
	int i, e, r;

	for (i = 0 ; i < 10 ; i++)
	{
		for (e = 0 ; e < 10 ; e++)
		{
		r = i * e;
		if (e == 0)
			printf("%d, ", r);
		else
		{
			printf("%2d", r);
			if (e != 9)
				printf(", ");
		}
	}
	printf("\n");
}
}
