#include "main.h"

/**
 * _strtok - tokenize a string into smaller parts based on specific
 * delimeter character
 * @str: string to be splited
 * @delim: specified delimeter
 * Return: pointer to next token, otherwise NULL
 */
char _strtok(char *str, const char *delim);
{
	char *token = NULL;
	char *start;
	
	if(str)
		token = str;

	if (!token)
		return (NULL);
	/*find start of next token*/
	start = token;

	while (*token && strchr(delim, *token))
		token++;

	if (!*token)
		return(NULL);
	/*mark start of token*/
	while (*token && !strchr(delim, *token))
		token++;

	/*null-terminate the token*/
	if (*token)
	{
		*token = '\0';
		token++;
	}
	return (start);
}
