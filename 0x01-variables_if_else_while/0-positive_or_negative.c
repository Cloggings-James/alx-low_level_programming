#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - assigns a random number to the variable n each time it is executed
 *
 * Description: This program generates a random number and prints whether it is
 * positive, negative, or zero.
 *
 * Return: 0 if the program runs successfully
 */
int main(void)
{
    int n;

    /* Set the seed for the random number generator based on the current time */
    srand(time(0));

    /* Generate a random number between -RAND_MAX/2 and RAND_MAX/2 */
    n = rand() - RAND_MAX / 2;

    /* Determine whether the number is positive, negative, or zero, and print
     * the result to the console */
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

    return (0);
}

