#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
        return (c >= '0' && c <= '9');
}

/**
 * _strlen - calculates the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
        int len = 0;

        while (*s++)
                len++;

        return (len);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 if successful, 1 otherwise
 */
int main(int argc, char *argv[])
{
        int i, j, len1, len2, lenres, carry, n1, n2, *res;
        char *s1, *s2;

        if (argc != 3)
        {
                printf("Error\n");
                return (1);
        }

        s1 = argv[1];
        s2 = argv[2];
        len1 = _strlen(s1);
        len2 = _strlen(s2);
        lenres = len1 + len2;
        res = calloc(lenres, sizeof(int));

        if (res == NULL)
                return (1);

        for (i = len1 - 1; i >= 0; i--)
        {
                if (!_isdigit(s1[i]))
                {
                        printf("Error\n");
                        free(res);
                        return (1);
                }
                carry = 0;
                n1 = s1[i] - '0';

                for (j = len2 - 1; j >= 0; j--)
                {
                        if (!_isdigit(s2[j]))
                        {
                                printf("Error\n");
                                free(res);
                                return (1);
                        }
                        n2 = s2[j] - '0';
                        carry += res[i + j + 1] + (n1 * n2);
                        res[i + j + 1] = carry % 10;
                        carry /= 10;
                }
                if (carry)
                        res[i + j + 1] += carry;
        }
        if (*res == 0)
                res++;

        for (i = 0; i < lenres; i++)
                printf("%d", res[i]);
        printf("\n");

        free(res);
        return (0);
}

