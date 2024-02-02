#include "hash_tables.h"

/**
 * hash_table_get - This retrieves the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *hash_table, const char *key)
{
	/*Declaration*/
	hash_node_t *current_node;
	unsigned long int index;

	if (hash_table == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, hash_table->size);
	if (index >= hash_table->size)
		return (NULL);

	current_node = hash_table->array[index];
	while (current_node && strcmp(current_node->key, key) != 0)
		current_node = current_node->next;

	return ((current_node == NULL) ? NULL : current_node->value);
}
