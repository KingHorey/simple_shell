#include "main.h"

/**
 * _strtok - tokenize a string into smaller parts based on specific
 * delimeter character
 * @str: string to be splited
 * @delim: specified delimeter
 * Return: pointer to next token, otherwise NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token;
	char *start;

	if (str)
		token = str;

	if (!token)
		return (NULL);
	/*find start of next token*/

	while (*token && strchr(delim, *token))
		token++;

	if (*token == '\0')
		return (NULL);
	/*mark start of token*/
	start = token;
/*find the end token*/

	while (*token && !strchr(delim, *token))
		token++;

	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}
	return (start);
}
