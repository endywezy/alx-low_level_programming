#include "hash_tables.h"

/**
 * shash_table_create - This creates a sorted hash table.
 * @size: The size of the new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	/*Declaration*/
	shash_table_t *sht;
	unsigned long int i;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);

	sht->size = size;
	sht->array = malloc(sizeof(shash_node_t *) * size);
	if (sht->array == NULL)
		return (NULL);
    
	for (i = 0; i < size; i++)
		sht->array[i] = NULL;

	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @sorted_hash_table: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *sorted_hash_table, const char *key, const char *value)
{
	shash_node_t *new_node, *temp_node;
	char *value_copy;
	unsigned long int index;

	if (sorted_hash_table == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, sorted_hash_table->size);
	temp_node = sorted_hash_table->shead;

	while (temp_node)
	{
	if (strcmp(temp_node->key, key) == 0)
		{
		free(temp_node->value);
		temp_node->value = value_copy;
		return (1);
		}
		temp_node = temp_node->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
	free(value_copy);
	free(new_node);
		return (0);
	}

	new_node->value = value_copy;
	new_node->next = sorted_hash_table->array[index];
	sorted_hash_table->array[index] = new_node;

	if (sorted_hash_table->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		sorted_hash_table->shead = new_node;
		sorted_hash_table->stail = new_node;
	}
	else if (strcmp(sorted_hash_table->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = sorted_hash_table->shead;
		sorted_hash_table->shead->sprev = new_node;
		sorted_hash_table->shead = new_node;
	}
	else
	{
		temp_node = sorted_hash_table->shead;
		while (temp_node->snext != NULL && strcmp(temp_node->snext->key, key) < 0)
		temp_node = temp_node->snext;

	new_node->sprev = temp_node;
	new_node->snext = temp_node->snext;

	if (temp_node->snext == NULL)
		sorted_hash_table->stail = new_node;
	else
		temp_node->snext->sprev = new_node;

	temp_node->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @sorted_hash_table: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in the sorted hash table.
 */
char *shash_table_get(const shash_table_t *sorted_hash_table, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (sorted_hash_table == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, sorted_hash_table->size);

	if (index >= sorted_hash_table->size)
		return (NULL);

	node = sorted_hash_table->shead;

	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @sorted_hash_table: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *sorted_hash_table)
{
	shash_node_t *node;

	if (sorted_hash_table == NULL)
		return;

	node = sorted_hash_table->shead;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;

		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @sorted_hash_table: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *sorted_hash_table)
{
	shash_node_t *node;

	if (sorted_hash_table == NULL)
		return;

	node = sorted_hash_table->stail;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;

	if (node != NULL)
		printf(", ");
	}
	printf("}\n");
}

