#include "main.h"

/**
 * _strlen - gets the length of a string
 * @s: string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;

	return (len);
}
