#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Assign random number to variable n each time executed
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;

    /* Print whether n is positive or negative */
    if (n > 0)
        printf("%d is positive\n", n);
    else if (n == 0)
        printf("%d is zero\n", n);
    else
        printf("%d is negative\n", n);

    return (0);
}
