#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str = "Hello, Dynamic Libraries!";

	_puts(str);
	printf("Length: %d\n", _strlen(str));

	return (0);
}

