#include "lists.h"

/**
 * add_dnodeint_end - Adds a node at the end of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: The data integer for the new node
 * Return: Pointer to the new node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/*Declaration*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!head)
		return (NULL);

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		dlistint_t *last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
		new_node->prev = last_node;
	}

	/*Returns New Node*/
	return (new_node);
}
