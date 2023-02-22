#include "main.h"
/**
 * print_times_table - prints the times table,
 *@y: the vale of the times table.
 * Return: Always 0.
 */
void print_times_table(int y)
{
	int a, b, c;

	if (y >= 0 && y <= 15)
	{
	for (a = 0; a <= y; a++)
	{
	_putchar('0');
	for (b = 1; b <= y; b++)
	{
	_putchar(',');
	_putchar(' ');
	c = a * b;
	if (c <= 99)
	_putchar(' ');
	if (c <= 9)
	_putchar(' ');
	if (c >= 100)
	{
	_putchar((c / 100) + '0');
	_putchar(((c / 10)) % 10 + '0');
	}
	else if (c <= 99 && c >= 10)
	{
	_putchar((c / 10) + '0');
	}
	_putchar((c % 10) + '0');
	}
	_putchar('\n');
	}
	}
}
