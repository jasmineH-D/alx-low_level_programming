#include "main.h"
/**
 * puts_half - a function that prints half of a string
 *
 * @str: input
 * Return: half of input
 */
void puts_half(char *str)
{
	int u, f, y;

	longi = 0;

	for (u = 0; str[a] != '\0'; u++)
		y++;

	f = (y / 2);

	if ((y % 2) == 1)
		f = ((y + 1) / 2);

	for (u = f; str[u] != '\0'; u++)
		_putchar(str[u]);
	_putchar('\n');
}
