#include <stdio.h>
/**
 * main - prints The sum of these multiples
 *
 * Return: Always 0.
 */
int main(void)
{
	int a, b = 0;

	while (a < 1024)
	{
	if ((a % 3 == 0) || (a % 5 == 0))
	{
	b += a;
	}
	a++;
	}
	printf("%d\n", b);
	return (0);
}
