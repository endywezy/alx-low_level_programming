#include "hash_tables.h"

/**
 * hash_table_print - This prints a hash table.
 * @hash_table: A pointer to the hash table to print.
 *
 * Description: Key/value pairs are printed in the order
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *hash_table)
{
	/*Declaration*/
	hash_node_t *current_node;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (hash_table == NULL)
		return;

	printf("{");
	for (i = 0; i < hash_table->size; i++)
	{
		if (hash_table->array[i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

		current_node = hash_table->array[i];
		while (current_node != NULL)
		{
			printf("'%s': '%s'", current_node->key, current_node->value);
			current_node = current_node->next;
			if (current_node != NULL)
			printf(", ");
		}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
