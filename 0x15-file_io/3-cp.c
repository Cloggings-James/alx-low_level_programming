#include "main.h"

/**
 * cp - copies the content of one file to another file
 * @file_from: the name of the file to copy from
 * @file_to: the name of the file to copy to
 *
 * Return: 0 on success, or a non-zero error code on failure
 */
int cp(const char *file_from, const char *file_to)
{
	if (file_from == NULL || file_to == NULL)
		return (-1);

	int fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (98);
	}

	struct stat st;
	if (fstat(fd_from, &st) == -1)
	{
		perror("fstat");
		close(fd_from);
		return (-1);
	}

	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0777);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		return (99);
	}

	ssize_t bytes_read;
	ssize_t bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);

		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		perror("read");
		close(fd_from);
		close(fd_to);
		return (-1);
	}

	if (close(fd_from) == -1)
	{
		perror("close");
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		perror("close");
		return (100);
	}

	return (0);
}
