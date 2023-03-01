#include "main.h"
#include <stdio.h>

/**
 * rot13 - encoder rot13
 * @s: pointer
 *
 * Return: s
 */

char *rot13(char *s)
{
	int a;
	int t;
	char rot1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (a = 0; s[a] != '\0'; a++)
	{
		for (t = 0; t < 52; t++)
		{
			if (s[a] == rot1[t])
			{
				s[a] = rot2[t];
				break;
			}
		}
	}
	return (s);
}
