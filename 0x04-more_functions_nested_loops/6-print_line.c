#include "main.h"
/**
 * print_line - drawq a straight line in the terminal
 * @n: input number
 * Return: staight line
 */
void print_line(int n)
{
int y;

if (n <= 0)
{
_putchar('\n');
}
else
{
for (y = 1; y <= n; y++)
{
_putchar('_');
}
_putchar('\n');
}
}
