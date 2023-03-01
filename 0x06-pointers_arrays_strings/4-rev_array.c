#include "main.h"
/**
 * reverse_array - reverse array of integers
 * @a: array
 * @n: number of elements
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int y;
	int q;

	for (y = 0; y < n--; y++)
	{
		q = a[y];
		a[y] = a[n];
		a[n] = q;
	}
}
