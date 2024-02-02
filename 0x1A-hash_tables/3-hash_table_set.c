#include "hash_tables.h"

/**
 * hash_table_set - This adds or updates an element in a hash table.
 * @hash_table: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *hash_t, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_copy;
	unsigned long int index, i;

	if (hash_t == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, hash_t->size);

	for (i = index; hash_t->array[i]; i++)
	{
		if (strcmp(hash_t->array[i]->key, key) == 0)
		{
			free(hash_t->array[i]->value);
			hash_t->array[i]->value = value_copy;
			return (1);
		}
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = value_copy;
	new_node->next = hash_t->array[index];
	hash_t->array[index] = new_node;

	return (1);
}
