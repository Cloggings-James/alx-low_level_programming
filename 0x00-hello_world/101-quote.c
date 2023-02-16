#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 1 (Failure)
 */
int main(void)
{
	int len;
	char *quote = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	len = write(2, quote, 59);
	if (len != 59)
	{
		return (1);
	}
	return (1);
}
