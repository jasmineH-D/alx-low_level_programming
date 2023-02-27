#include "main.h"
/**
 * swap_int - swaps the values of two integers
 * @a: integers
 * @b: integers
 * Return: m
 */
void swap_int(int *a, int *b)
{
	int y;

	y = *a;
	*a = *b;
	*b = y;
}
