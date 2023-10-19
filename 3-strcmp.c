#include "main.h"

/**
 * __strcmp- string comparison
 * @s1: First array
 * @s2: second array
 * Return: The result of comparison
 */

int __strcmp(char *s1, char *s2)
{
	int counter, result;

	result = 0;

	for (counter = 0; s1[counter] != '\0'; counter++)
	{
		if (*(s1 + counter) > *(s2 + counter))
		{
			result = *(s1 + counter) - *(s2 + counter);
			break;
		}
		else if (*(s1 + counter) < *(s2 + counter))
		{
			result = *(s1 + counter) - *(s2 + counter);
			break;
		}
		else if (*(s1 + counter) == *(s2 + counter))
		{
			result = 0;
		}
	}
	return (result);
}
