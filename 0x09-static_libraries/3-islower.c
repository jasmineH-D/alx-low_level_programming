#include "main.h"
/**
 * _islower - check if an input is lower char or not
 * @c: an integer input
 *
 * Return: 1 if c is lower char, 0 otherwise
 */
int _islower(int c)
{
	int i;

	for (i = 97; i <= 122; i++)
	{
		if (i == c)
			return (1);
	}

	return (0);
}
