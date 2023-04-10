#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int create_file(const char *filename, char *text_content)
{
    int fd, len, res;
    mode_t mode = S_IRUSR | S_IWUSR;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (fd == -1)
        return (-1);

    if (text_content != NULL) {
        len = strlen(text_content);
        res = write(fd, text_content, len);
        if (res == -1) {
            close(fd);
            return (-1);
        }
    }

    close(fd);
    return (1);
}

