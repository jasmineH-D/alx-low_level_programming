#include <stddef.h>

#include <math.h>

#include "main.h"
/**
 * binary_to_uint - converts abinary.
 * @b: pointing to a string of 0 and 1 chars.
 *
 * Return: the converted number, or 0 if.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0')
		{
			n = n * 2;
		}
		else if (b[i] == '1')
		{
			n = n * 2 + 1;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (n);
}
