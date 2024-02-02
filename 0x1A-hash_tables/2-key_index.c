#include "hash_tables.h"

/**
 * key_index - This gets the index at which a key/value pair should
 *             be stored in array of a hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 *
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* Use the hash_djb2 function to calculate the hash */
	unsigned long int hash_value = hash_djb2(key);

	/* Return the index by taking the remainder of the hash with the size */
	return (hash_value % size);
}
