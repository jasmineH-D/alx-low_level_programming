#include "main.h"
/**
 * more_numbers - numbers fonction
 *
 * Return: no return
 */
void more_numbers(void)
{
int i, j;

for (i = 1; i <= 10; i++)
{
for (i = 0; i < 15; j++)
{
if (j >= 10)
_putchar('1');
_putchar(j % 10 + '0');
}
_putchar('\n');
}
}
