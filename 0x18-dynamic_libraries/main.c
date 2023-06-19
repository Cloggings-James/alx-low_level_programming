#include <stdio.h>
#include "main.h"

int main() {
    int a = 10;
    int b = 5;

    int result_add = add(a, b);
    printf("Addition: %d + %d = %d\n", a, b, result_add);

    int result_subtract = subtract(a, b);
    printf("Subtraction: %d - %d = %d\n", a, b, result_subtract);

    int result_multiply = multiply(a, b);
    printf("Multiplication: %d * %d = %d\n", a, b, result_multiply);

    int result_divide = divide(a, b);
    printf("Division: %d / %d = %d\n", a, b, result_divide);

    int result_modulus = modulus(a, b);
    printf("Modulus: %d %% %d = %d\n", a, b, result_modulus);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int modulus(int a, int b) {
    return a % b;
}

