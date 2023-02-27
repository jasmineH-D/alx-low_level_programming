#include "main.h"
/**
 * puts2 - function should print only one character out of two
 *
 * @str: input
 * Return: print
 */
void puts2(char *str)
{
	int y = 0;
	int l = 0;
	char *h = str;
	int u;

	while (*h != '\0')
	{
		h++;
		y++;
	}
	l = y - 1;
	for (u = 0 ; u <= l ; u++)
	{
		if (u % 2 == 0)
	{
		_putchar(str[u]);
	}
	}
	_putchar('\n');
}
