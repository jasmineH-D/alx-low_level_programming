#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 *
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Number of letters read and printed, or 0 if an error occurred
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t numb;
	char *buf;
	int fd;

	if (!filename)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	numb = read(fd, buf, letters);
	if (numb < 0)
		free(buf);
		return (0);

	numb = write(STDOUT_FILENO, buf, numb);
	if (numb == -1 || numb != letters)
		free(buf);
		return (0);

	free(buf);
	close(fd);
	return (numb);
}
