#include <stdio.h>
#include "operations.h"

int main(void)
{
    int a = 10;
    int b = 5;

    int result_add = add(a, b);
    int result_subtract = subtract(a, b);
    int result_multiply = multiply(a, b);
    int result_divide = divide(a, b);
    int result_modulus = modulus(a, b);

    printf("Addition: %d\n", result_add);
    printf("Subtraction: %d\n", result_subtract);
    printf("Multiplication: %d\n", result_multiply);
    printf("Division: %d\n", result_divide);
    printf("Modulus: %d\n", result_modulus);

    return 0;
}

