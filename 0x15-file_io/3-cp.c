#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
char *buffer;

buffer = calloc(1024, sizeof(char));

if (buffer == NULL)
{
perror(file);
exit(EXIT_FAILURE);
}

return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
if (close(fd) == -1)
{
perror("close");
exit(EXIT_FAILURE);
}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
int from, to;
ssize_t r, w;
char *buffer;

if (argc != 3)
{
fprintf(stderr, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);

if (from == -1)
{
perror(argv[1]);
free(buffer);
exit(98);
}

to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

if (to == -1)
{
perror(argv[2]);
free(buffer);
exit(99);
}

for (;;)
{
r = read(from, buffer, 1024);

if (r == -1)
{
perror(argv[1]);
free(buffer);
exit(98);
}

if (r == 0) /* end of file */
break;

w = write(to, buffer, r);

if (w == -1)
{
perror(argv[2]);
free(buffer);
exit(99);
}
}

if (fsync(to

