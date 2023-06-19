#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success, return the number of characters written.
 * On error, return -1 and set errno appropriately.
 */
int _putchar(char c)
{
	return putchar(c);
}

/**
 * _strlen - Computes the length of a string
 * @s: The input string
 *
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;

	return len;
}

