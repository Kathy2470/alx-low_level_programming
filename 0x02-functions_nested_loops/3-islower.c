#include "main.h"

int int_putchar(int c);

/**
 * _islower - Checks for lowercase alphabet
 * @c: Character to be checked
 * Return: 1 if character is lowercase, otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
