#include "lists.h"

/**
 * free_dlistint - Frees the memory allocated for a doubly linked list
 * @head: Pointer to the head of the list
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
