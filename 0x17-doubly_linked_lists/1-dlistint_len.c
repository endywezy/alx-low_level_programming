#include "lists.h"

/**
 * dlistint_len - Return number of elements in dll
 * @h: Pointer to struct of ddl
 * Return: The amount of elements in dll
 */
size_t dlistint_len(const dlistint_t *h)
{
	/*Declaration*/
	size_t count_nodes = 0;

	while (h)
	{
		h = h->next;
		count_nodes++;
	}

	return (count_nodes);
}
