#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - Concatenates two strings.
 *
 * @s1: The first string to be concatenated.
 * @s2: The second string to be concatenated.
 *
 * Return: A pointer to the concatenated string, or NULL if it fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	unsigned int len1, len2, len_total, i, ci;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);
	len_total = len1 + len2;

	result = malloc(len_total + 1);
	if (result == NULL)
		return (NULL);

	for (i = 0, ci = 0; i < len_total; i++)
	{
		if (i < len1)
			result[i] = s1[i];
		else
			result[i] = s2[ci++];
	}

	result[len_total] = '\0';

	return (result);
}

