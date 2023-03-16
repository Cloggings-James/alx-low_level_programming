#include <stdio.h>

void print_error(void) {
    printf("Error\n");
}

void print_mul(int n1, int n2) {
    int result = n1 * n2;
    if (result < 0) {
        putchar('-');
        result = -result;
    }
    if (result >= 100) {
        putchar(result / 100 + '0');
        result %= 100;
        putchar(result / 10 + '0');
        result %= 10;
    } else if (result >= 10) {
        putchar(result / 10 + '0');
        result %= 10;
    }
    putchar(result + '0');
    putchar('\n');
}

void print_number(char *str) {
    int i;
    if (str[0] == '\0') {
        print_error();
        return;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            print_error();
            return;
        }
    }
    for (i = 0; str[i] == '0' && str[i + 1] != '\0'; i++);
    for (; str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

int main(void) {
    char *str1, *str2;
    int n1, n2;
    if (scanf("%ms %ms", &str1, &str2) != 2) {
        print_error();
        return 1;
    }
    n1 = atoi(str1);
    n2 = atoi(str2);
    if (n1 == 0 || n2 == 0 || (n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0)) {
        print_error();
        return 2;
    }
    print_mul(n1, n2);
    print_number(str1);
    print_number(str2);
    return 0;
}

