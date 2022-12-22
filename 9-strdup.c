#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: pointer to string to duplicate
 *
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	int i;
	char *dest_str;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	dest_str = malloc(sizeof(char) * (i + 1));
	if (dest_str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		dest_str[i] = str[i];
	}
	dest_str[i] = '\0';
	return (dest_str);
}
