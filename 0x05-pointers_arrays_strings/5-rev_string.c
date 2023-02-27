#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Input string
 * Return: String in reverse
 */

void rev_string(char *s)
{
	char y= s[0];
	int a = 0;
	int b;

	while (s[a] != '\0')
	a++;
	for (b = 0; b < a; b++)
	{
		a--;
		y = s[b];
		s[b] = s[a];
		s[a] = y;
	}
}
