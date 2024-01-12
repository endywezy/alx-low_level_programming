#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of the data (n)
 * @head: Pointer to the head of the list
 * Return: The sum of the data values
 */
int sum_dlistint(dlistint_t *head)
{
	/*Declaration*/
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
