#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int i;
    char *str;

    str = "Holberton";
    i = _strlen(str);
    _putchar(i + '0');
    return (0);
}

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to be written
 *
 * Return: On success 1
 * On error, -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
    /* Your implementation of _putchar function */
}

/**
 * _strlen - Computes the length of a string
 * @s: The string to be measured
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
    /* Your implementation of _strlen function */
}

