#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to convert to binary and print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
        unsigned long int mask = 1;
        int i;

        /* Find the most significant bit */
        for (i = 0; i < (sizeof(unsigned long int) * 8) - 1; i++)
                mask = (mask << 1);

        /* Print each bit starting with the most significant */
        for (; i >= 0; i--)
        {
                if ((n & mask) == 0)
                        putchar('0');
                else
                        putchar('1');
                mask = (mask >> 1);
        }
}

