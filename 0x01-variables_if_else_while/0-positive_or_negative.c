#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Where the program starts
 *
 * Return: 0
 */
int main(void)
{
    int n;

    srand(time(0));
    n = rand() - RAND_MAX / 2;
    /* my code */
    if (n > 0)
    {
        printf("%d is positive\n", n);
    }
    else if (n < 0)
    {
        printf("%d is negative\n", n);
    }
    else
    {
        printf("%d is zero\n", n);
    }
    /* end of my code */
    return (0);
}
