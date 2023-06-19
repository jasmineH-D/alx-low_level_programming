#include "main.h"
/**
 * _strncat - concatenate two strings
 * @dest: input
 * @src: input
 * @n: input
 *
 * Return: string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int y;
	int a;

	y = 0;
	while (dest[y] != '\0')
	{
		y++;
	}
	a = 0;
	while (a < n && src[a] != '\0')
	{
	dest[y] = src[a];
	y++;
	a++;
	}
	dest[y] = '\0';
	return (dest);
}
