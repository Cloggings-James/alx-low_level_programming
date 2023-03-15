#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char **strtow(char *str)
{
    char **words, *word;
    size_t i, j, k, n, len;

    if (str == NULL || *str == '\0')
        return (NULL);

    len = strlen(str);
    words = malloc(sizeof(char *) * (len + 1));
    if (words == NULL)
        return (NULL);

    for (i = 0, n = 0; i < len; i = j + 1)
    {
        while (i < len && isspace(str[i]))
            i++;
        if (i == len)
            break;

        j = i;
        while (j < len && !isspace(str[j]))
            j++;
        word = (char *)malloc(sizeof(char) * (j - i + 1));
        if (word == NULL)
        {
            for (k = 0; k < i; k++)
                free(words[k]);
            free(words);
            return (NULL);
        }

        for (k = 0; i < j; k++, i++)
            word[k] = str[i];
        word[k] = '\0';

        words[n++] = word;
    }
    words[n] = NULL;

    return (words);
}

