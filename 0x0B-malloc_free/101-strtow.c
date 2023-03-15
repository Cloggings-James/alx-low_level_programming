/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: Pointer to an array of strings (words), or NULL if str is NULL or empty.
 */
char **strtow(char *str)
{
        char **words, *word;
        int i, j, k, n, len;

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
                word = malloc(sizeof(char) * (j - i + 1));
                if (word == NULL)
                {
                        for (k = 0; k < n; k++)
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

