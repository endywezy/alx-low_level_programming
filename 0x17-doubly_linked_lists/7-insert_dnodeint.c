#include "lists.h"

/**
 * insert_dnodeint_at_index - Insert a node at a specific position in list
 * @h: Pointer to the head of the list
 * @idx: Position to insert the new node
 * @n: The data integer for the new node
 * Return: Pointer to the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	/*declaration*/
	dlistint_t *current = *h;

	if (!h)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 0 && current; idx--)
	{
	if (idx == 1)
		{
		/*Declaration*/
		dlistint_t *new_node = malloc(sizeof(dlistint_t));

		if (!new_node)
		return (NULL);

		new_node->n = n;
		new_node->prev = current;
		new_node->next = current->next;

		if (current->next)
			current->next->prev = new_node;

		current->next = new_node;

		return (new_node);
		}

		current = current->next;
	}

	return (NULL);
}
