#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string to calculate its length.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
    size_t len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

