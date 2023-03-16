#include <stdio.h>

int main() {
    int num, i, isPrime=1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("The number %d is not a prime number.", num);
        return 0;
    }

    for (i = 2; i <= num/2; ++i) {
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime) {
        printf("The number %d is a prime number.", num);
    }
    else {
        printf("The number %d is not a prime number.", num);
    }
    return 0;
}

