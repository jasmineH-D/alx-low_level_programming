#include "main.h"
#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: a string
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int y = 0;

	while (*s != '\0')
	{
	y++;
	s++;
	}
	return (y);
}
