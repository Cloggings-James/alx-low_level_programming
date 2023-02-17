#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0
 * using only the putchar function, without any variables of type char
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int num = 48;

    while (num <= 57)
    {
        putchar(num);
        num++;
    }
    putchar('\n');

    return (0);
}

