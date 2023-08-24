#include "main.h"
#include <stdbool.h>

/**
 * is_separator - checks if a character is a word separator
 * @c: the character to check
 * Return: true if the character is a separator, false otherwise
 */
bool is_separator(char c)
{
    char separators[] = " \t\n,;.!?\"(){}";

    for (int i = 0; separators[i] != '\0'; i++)
    {
	    if (c == separators[i])
		    return true;
    }
    return false;
}

/**
 * cap_string - capitalizes all words in a string
 * @str: input string
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
    bool new_word = true;
    char *ptr = str;

    while (*ptr != '\0')
    {
        if (new_word && (*ptr >= 'a' && *ptr <= 'z'))
        {
            *ptr = *ptr - 'a' + 'A';
            new_word = false;
        }
        else if (is_separator(*ptr))
        {
            new_word = true;
        }
        ptr++; // Move to the next character
    }
    return str;
}
