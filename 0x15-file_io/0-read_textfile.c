#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the number of letters read and printed,or 0 on error occurred.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t numb = 0;
	char *buf = NULL;
	int fd = 0;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char) * latters);
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	numb = read(fd, buf, letters);
	if (numb < 0)
	{
		free(buf);
		return (0);
	}

	numb = write(STDOUT_FILENO, buf, numb);
	if (numb == -1 || numb != letters)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(fd);
	return (numb);
}

