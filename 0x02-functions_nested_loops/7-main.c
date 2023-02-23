#include "main.h"

/**
 * main - Entry point
 *
 * Description: This program calls the function print_last_digit
 *              to print the last digit of given numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int r;

    print_last_digit(98);
    print_last_digit(0);
    r = print_last_digit(-1024);
    _putchar('0' + r);
    _putchar('\n');
    return (0);
}

