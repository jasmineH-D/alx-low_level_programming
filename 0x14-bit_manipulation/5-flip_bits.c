#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * @n: first number
 * @m: second number
 *
 * Return: number og the bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int y = n ^ m;
	unsigned int t = 0;

	while (y != 0)
	{
		t += y & 1;
		t >>= 1;
	}
	return (t);
}
