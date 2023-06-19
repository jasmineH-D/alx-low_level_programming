#include "main.h"
/**
 * _isalpha - ckaks for alphabetic
 * @c: character to be cheked
 *
 * Return: 1 if she is  is a letter,0 to otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
