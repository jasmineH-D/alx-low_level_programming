#include "main.h"

/**
 * print_rev -  prints a string
 * @s: string
 * Return: Always 0.
 */
void print_rev(char *s)
{
	int y = 0;
	int u;

	while (*s != '\0')
	{
		y++;
		s++;
	}
	s--;
	for (u = y; u > 0; u--)
	{
		_putchar(*s);
