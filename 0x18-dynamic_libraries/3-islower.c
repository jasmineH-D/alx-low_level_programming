#include "main.h"
/**
 * _islower - checks for lowercase
 * @c: The character to be checked
 * Return: 1 to lowercase or 0 for otherwise
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')

		return (1);
	else
		return (0);
}
