#include "hash_tables.h"

/**
 * hash_table_create - creating a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	/* Allocate memory for hash table */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* Allocate memory for array of pointers */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht); /* Free the hash table if array allocation fails */
		return (NULL);
	}

	/* Initialize each element in the array to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	/* Set the size of the hash table */
	ht->size = size;

	return (ht);
}
