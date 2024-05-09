#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
  * linear_search - use linear algo
  * @array: ptr to first element
  * @size: no of eles in array
  * @value: value to search for
  *
  * Return: -1, 0, NULL
  */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
