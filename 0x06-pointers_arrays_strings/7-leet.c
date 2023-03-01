#include "main.h"
/**
 * leet - encode into 1337speak
 * @n: input value
 * Return: n value
 */
char *leet(char *n)
{
	int a, y;
	char t1[] = "aAeEoOtTlL";
	char t2[] = "4433007711";

	for (a = 0; n[a] != '\0'; a++)
	{
		for (y = 0; y < 10; y++)
		{
			if (n[a] == t1[y])
			{
				n[a] = t2[y];
			}
		}
	}
	return (n);
}
