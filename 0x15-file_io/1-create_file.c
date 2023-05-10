#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: name of the file
 * @text_content: terminal string to write
 * Return: 1 on sucess, -1 failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t  i = 0, w;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[i])
			i++;
		w = write(fd, text_content, i);
		if (w == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
