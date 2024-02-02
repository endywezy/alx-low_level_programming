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
    /*Calculate the hash value using the hash_djb2 function*/
    unsigned long int hash_value = hash_djb2(key);

    /*Use the hash value to determine the 
     * index within the array size*/
    unsigned long int index = hash_value % size;

    return (index);
}
