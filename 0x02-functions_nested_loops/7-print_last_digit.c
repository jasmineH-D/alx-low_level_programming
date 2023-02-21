#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @n: the number
 * Return: Value to  the last digit of a number
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;
	if (last < 0)
	{
	last = last * -2;
	}
	_putchar(last + '0');
	return (last);
}
