#include "main.h"

/**
 *
 *
 */

char **environ(char **argmnt)
{
	char **space, *token;
	space = malloc(sizeof(char *) * 1024);

	token = strtok(environ[42], ".:");
	int i = 0;
	while(token)
	{
		token = strtok(NULL, ".:");
		space[i++] = token;
	}
	space[i] = NULL;



	return (space);
}
