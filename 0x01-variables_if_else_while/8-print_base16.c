#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	for (ch = '0'; ch <= '9'; ch++)
		write(1, &ch, 1);

	for (ch = 'a'; ch <= 'f'; ch++)
		write(1, &ch, 1);

	write(1, "\n", 1);

	return (0);
}

