#include "main.h"
/**
 * _strchr- print occurence of a char
 * @s: arrayto be scanned
 * @c: character to look for
 * Return: the array
 */

char *_strchr(char *s, char c)
{

	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);

	return (NULL);
}
