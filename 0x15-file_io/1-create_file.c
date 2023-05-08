#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

int create_file(const char *filename, char *text_content) {
    int fd, write_status;
    int permissions = S_IRUSR | S_IWUSR; /* rw------- */

    if (filename == NULL)
        return -1;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (fd == -1)
        return -1;

    if (text_content != NULL) {
        write_status = write(fd, text_content, strlen(text_content));
        if (write_status == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}

int main(void) {
    /* Test the create_file function */
    int result = create_file("example.txt", "Hello, World!");
    printf("create_file result: %d\n", result);

    return 0;
}

