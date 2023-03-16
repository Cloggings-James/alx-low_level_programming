#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DIGITS 10000

/**
 * Checks if a string represents a non-negative integer.
 * Returns 1 if the string contains only digits, 0 otherwise.
 */
int is_nonnegative_integer(char *s) {
    while (*s != '\0') {
        if (*s < '0' || *s > '9') {
            return 0;
        }
        s++;
    }
    return 1;
}

/**
 * Multiplies two non-negative integers represented as strings.
 * Returns the product as a string.
 * Assumes that the input strings are valid non-negative integers.
 * If the product exceeds the maximum value of an int, returns NULL.
 */
char *multiply(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j, carry, digit1, digit2;
    int *product = calloc(len1 + len2, sizeof(int));
    char *result = malloc(MAX_DIGITS + 1);

    if (product == NULL || result == NULL) {
        return NULL; // memory allocation error
    }

    for (i = len1 - 1; i >= 0; i--) {
        digit1 = s1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--) {
            digit2 = s2[j] - '0';
            carry += product[i + j + 1] + (digit1 * digit2);
            product[i + j + 1] = carry % 10;
            carry /= 10;
        }
        if (carry > 0) {
            product[i + j + 1] += carry;
        }
    }

    // convert product to string representation
    int k = 0;
    while (k < len1 + len2 && product[k] == 0) {
        k++; // skip leading zeros
    }
    if (k == len1 + len2) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        for (i = 0; k < len1 + len2; i++, k++) {
            if (i > MAX_DIGITS) {
                free(product);
                free(result);
                return NULL; // product exceeds maximum value of int
            }
            result[i] = product[k] + '0';
        }
        result[i] = '\0';
    }

    free(product);
    return result;
}

/**
 * Prints an error message to standard output and exits with status 98.
 */
void print_error(char *msg) {
    printf("%s\n", msg);
    exit(98);
}

int main(int argc, char **argv) {
    char *

