#include "main.h"

/**
 * read_textfile - read file
 * @filename: name file
 * @letters: numbers of file
 *
 * Return: nembers letters printd
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd, read_check, write_check;
	char  *string;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	string = malloc(sizeof(char) * letters);
	if (string == NULL)
	{
		close(fd);
		return (0);
	}
	read_check = read(fd, string, letters);
	if (read_check == -1)
	{
		free(string);
		close(fd);
		return (0);
	}
	write_check = write(STDOUT_FILENO, string, read_check);
	if (read_check != write_check)
	{
		free(string);
		close(fd);
		return (0);
	}
	return (read_check);
}
