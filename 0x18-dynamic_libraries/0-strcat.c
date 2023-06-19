#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: string @dest
 */
char *_strcat(char *dest, char *src)
{
	int y;
	int a;

	y = 0;
	while (dest[y] != '\0')
	{
		y++;
	}
	a = 0;
	while (src[a] != '\0')
	{
		dest[y] = src[a];
		y++;
		a++;
	}

	dest[y] = '\0';
	return (dest);
}
