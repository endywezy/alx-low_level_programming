#include "lists.h"

/**
 * add_dnodeint - Insert a new node at the beginning of a doubly linked list
 * @head: Pointer to the head of the list
 * @n: The data integer for the new node
 * Return: Pointer to the new node, or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	/*Declaration*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (!head)
		return (NULL);

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;

	*head = new_node;

	/*Returns New Node*/
	return (new_node);
}
