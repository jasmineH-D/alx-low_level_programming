#include "main.h"
/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: the unsigned long int to retrieve the bit from
 * @index: the index of bit ,starting from 0.
 *
 * Return : the value of the bit at the given index or -1 if an errir occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	while ((n & (1 << index)) == 0)
		return (0);
	return (1);
}
