// #include "main.h"

#include <stdio.h>
#include <string.h>


/**
 * _strtok - tokenize a string into smaller parts based on specific
 * delimeter character
 * @str: string to be splited
 * @delim: specified delimeter
 * Return: pointer to next token, otherwise NULL
 */
char *_strtok(char *str, const char delim)
{
	static char *token;
	char *start;

	if (str)
		token = str;

	if (!token)
		return (NULL);

	while (*token && strchr(token, delim))
	{	/*find start of next token*/
		printf("First Loop: %s\n", token);
		token++;
	}
	if (*token == '\0')
		return (NULL);

	start = token;
	printf("%s\n", token);

	while (*token && !strchr(token, delim))
		token++;

	if (*token != '\0')
	{
		*token = '\0';
		token++;
	}
	return (start);
}

int main(void)
{
	char name[] = "Horey is my name";
	const char c = ' ';
	char *data = _strtok(name, c);
	printf("%s\n", data);


	return (0);
}