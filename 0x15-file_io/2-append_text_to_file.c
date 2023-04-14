#include "main.h"
#include <string.h>

/**
 * append_text_to_file - Appends text to an existing file
 *
 * @filename: The name of the file to append to
 * @text_content: The content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, by, len = 0;

	if (!filename)
	while (text_content[len])
		len++;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return (-1);
	if (!text_content)
	{
	by = write(fd, text_content, len);
	close(fd);

	if (by == len)
		return(1);
	return (-1);
	}
	close(fd);
	return (1);
}
