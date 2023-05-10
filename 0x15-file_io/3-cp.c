#include "main.h"

/**
 * error_from - print error from fd_from
 * @str: string
 */

void error_from(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	exit(98);
}

/**
 * error_too - print error from fd_too
 * @str: string
 */

void error_too(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	exit(99);
}

/**
 * main - copy content from file to another file
 * @argc: number of argument
 * @argv: content of argument
 * Return: return 0 if success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_too, rd, wt;
	int loop_buff;
	char string[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_from(argv[1]);
	fd_too = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_too == -1)
		error_too(argv[2]);
	loop_buff = 1024;
	while (loop_buff == 1024)
	{
		rd = read(fd_from, string, 1024);
		if (rd == -1)
			error_from(argv[1]);
		loop_buff = rd;
		wt = write(fd_too, string, loop_buff);
		if (wt == -1)
			error_too(argv[2]);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %d\n", fd_from);
		exit(100);
	}
	if (close(fd_too) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %d\n", fd_too);
		exit(100);
	}
	return (0);
}
