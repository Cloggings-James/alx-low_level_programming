#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Error: missing condition to check if n is a positive integer
    if(n < 0) {
        printf("Error: Entered number is not a positive integer\n");
        return 0;
    }

    for (i = 1; i <= n; ++i) {
        sum += i;
    }

    printf("Sum = %d\n", sum);

    return 0;
}

