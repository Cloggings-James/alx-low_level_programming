#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

int is_valid_char(char c) {
    return isalnum(c);
}

char **strtow(char *str) {
    int len = strlen(str);
    int word_count = 0;
    int in_word = 0;
    int i, j;

    char **words = (char **)malloc(sizeof(char *) * (len + 1));
    if (words == NULL) {
        return NULL;
    }

    for (i = 0, j = 0; i <= len; i++) {
        if (is_valid_char(str[i])) {
            if (!in_word) {
                words[word_count] = (char *)malloc(sizeof(char) * MAX_WORD_LEN);
                if (words[word_count] == NULL) {
                    return NULL;
                }
                in_word = 1;
                j = 0;
            }
            words[word_count][j] = str[i];
            j++;
        } else {
            if (in_word) {
                words[word_count][j] = '\0';
                word_count++;
                in_word = 0;
            }
        }
    }

    words[word_count] = NULL;

    return words;
}

int main() {
    char str[] = "This is a test string";
    char **words = strtow(str);

    if (words == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    int i;
    for (i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}

