#include "lists.h"

/**
 * print_dlistint - Prints all the nodes of a doubly linked list
 * @h: Pointer to the head of the list
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{

	size_t node_count = 0;
/*Declaration*/
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_count++;
	}

	/*returbs Node Count*/
	return (node_count);
}
