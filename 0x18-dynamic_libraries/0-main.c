#include "dynamic.h"
#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main(void)
{
    int a = 10;
    int b = 5;

    printf("Sum: %d\n", add(a, b));
    printf("Difference: %d\n", subtract(a, b));
    printf("Product: %d\n", multiply(a, b));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

