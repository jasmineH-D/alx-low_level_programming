#include "main.h"
#include <stdio.h>
/**
 * create_file - creates a new file or truncates an existing file
 * @filename: The name of the file to create
 * @text_content: a NULL terminated string to the file
 *
 * Return: 1 on sucess, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len, y;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
	len = strlen(text_content);
	y = write(fd, text_content, len);
	if (y < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
	}
