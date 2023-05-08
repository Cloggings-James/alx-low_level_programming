#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints
 * @filename: A pointer to a string containing the name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: On success, returns the actual number of letters read and printed.
 *         On failure, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));

	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	close(fd);

	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	buffer[bytes_read] = '\0';

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	free(buffer);

	if (bytes_written == -1 || bytes_read != bytes_written)
		return (0);

	return (bytes_written);
}
