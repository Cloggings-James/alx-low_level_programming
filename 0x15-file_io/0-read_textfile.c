#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters it could read and print, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t fd, num_read, num_written;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (!buf)
        return (0);

    num_read = read(fd, buf, letters);
    if (num_read == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    num_written = write(STDOUT_FILENO, buf, num_read);
    if (num_written == -1 || (size_t)num_written != num_read)
    {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);

    return (num_written);
}

