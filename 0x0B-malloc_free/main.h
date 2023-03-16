#ifndef HOLBERTON_H
#define HOLBERTON_H

/*
 * File: holberton.h
 * Author: Your Name
 * Desc: Header file containing function prototypes for all functions
 *       used in the 0x0B-malloc_free directory.
 */

#include <stdlib.h>

/* function to create an array of chars and initialize it with a specific char */
char *create_array(unsigned int size, char c);

/* function to print a character */
int _putchar(char c);

/* function to duplicate a string */
char *_strdup(char *str);

/* function to concatenate two strings */
char *str_concat(char *s1, char *s2);

/* function to allocate a 2D array of integers */
int **alloc_grid(int width, int height);

/* function to free a 2D array of integers */
void free_grid(int **grid, int height);

/* function to concatenate all command line arguments into a single string */
char *argstostr(int ac, char **av);

/* function to split a string into words and return an array of strings */
char **strtow(char *str);

#endif /* HOLBERTON_H */

