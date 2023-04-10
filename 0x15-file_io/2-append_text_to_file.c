/**
 * append_text_to_file - Appends text at the end of a file.
 *
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, do not add anything to the file.
 *         If the file does not exist or if you do not have the required
 *         permissions to write the file, return -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int file_descriptor, bytes_written, length = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
length = strlen(text_content);

/* Open file in append mode */
file_descriptor = open(filename, O_WRONLY | O_APPEND);
if (file_descriptor == -1)
return (-1);

/* Write text_content to file */
bytes_written = write(file_descriptor, text_content, length);
if (bytes_written == -1)
{
close(file_descriptor);
return (-1);
}

close(file_descriptor);
return (1);
}

