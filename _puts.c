#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 */

void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}

