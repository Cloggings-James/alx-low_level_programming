#include <stdio.h>
#include <string.h>

/**
 * generate_key - Generates a valid key for the given username.
 * @username: The username.
 */
void generate_key(const char *username)
{
    int i, len;
    char key[7];

    if (username == NULL)
        return;

    len = strlen(username);

    for (i = 0; i < len; i++)
        key[i] = username[i] + i;

    key[i] = '\0';

    printf("%s\n", key);
}

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        return 1;
    }

    generate_key(argv[1]);

    return 0;
}

