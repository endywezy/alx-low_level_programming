#include "hash_tables.h"

/**
 * hash_table_delete - This deletes a hash table.
 * @hash_table: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *hash_table)
{
	/*Declaration*/
	hash_table_t *head = hash_table;
	hash_node_t *current_node, *temp_node;
	unsigned long int i;

	for (i = 0; i < hash_table->size; i++)
	{
		if (hash_table->array[i] != NULL)
		{
			current_node = hash_table->array[i];
			while (current_node != NULL)
			{
				temp_node = current_node->next;
				free(current_node->key);
				free(current_node->value);
				free(current_node);
				current_node = temp_node;
			}
		}
	}
	free(head->array);
	free(head);
}
