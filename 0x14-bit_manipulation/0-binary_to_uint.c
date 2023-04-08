#include "main.h"
/**
 * binary_to_uint - converts abinary.
 * @b: pointing to a string of 0 and 1 chars.
 *
 * Return: the converted number, or 0 if.
 */
unsigned int binary_to_uint(const char *b)
{
if (b == NULL)
return (0);

int len = strlen(b);
unsigned int out_put = 0;
int y = len - 1, h = 0;

while (y >= 0)
{
if (b[y] != '0' && b[y] != '1')
return (0);
out_put += (b[y] - '0') * pow(2, h);
y--;
h++;
}
return (out_put);
}
