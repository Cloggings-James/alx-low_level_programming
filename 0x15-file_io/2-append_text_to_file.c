#include "main.h"

/**
 * create_file - creates a file with the given text content
 * @filename: the name of the file to create
 * @text_content: the text content to write to the file
 *
 * Return: 1 on success, or -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		size_t len = 0;
		while (text_content[len] != '\0')
			len++;

		ssize_t bytes_written = write(fd, text_content, len);
		if (bytes_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
