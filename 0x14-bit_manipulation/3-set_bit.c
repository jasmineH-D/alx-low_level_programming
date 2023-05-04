#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @index: the index, starting from 0 of the bit you want to set
 * @n: @n: pointer to the unsigned long int to set the bit in
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	while (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
