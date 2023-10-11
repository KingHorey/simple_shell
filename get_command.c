#include "main.h"

/**
 * get_commands - gets the command from the stdin
 *
 * Return: Pointer to read line
 *
 */

char *get_commands()
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t count;


	count = getline(&lineptr, &n, stdin);
	if (count == -1)
	{
		perror("getline");
		free(lineptr);
		return (NULL);

	}
	return (lineptr);
}

