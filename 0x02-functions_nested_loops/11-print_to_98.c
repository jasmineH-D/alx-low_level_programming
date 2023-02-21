#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - prints all natural numbers
 * @y: the number to start printing
 * Return: Always 0.
 */
void print_to_98(int y)
{
	if (y <= 98)
	{
	for (; y <= 98; y++)
	{
	if (y == 98)
	{
	printf("%d", y);
	printf("\n");
	break;
	}
	else
	{
	printf("%d, ", y);
	}
	}
	}
	else
	{
	for (; y >= 98; y--)
	{
	if (y == 98)
	{
	printf("%d", y);
	printf("\n");
	break;
	}
	else
	{
	printf("%d, ", y);
	}
	}
	}
}
