#include "main.h"

/**
 * _strlen- calculates the length of any provided string
 * @s: string to be checked
 * Return: 0
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s)
	{
		s++;
		l++;
	}
	return (l);
}
