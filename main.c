#include "main.h"

/**
* main - main function that runs all other functions
* @argc: number of command line arguments
* @argv: array of pointers holding the commands passed to terminal
* @env: array of pointers for environmental variable
* Return: 1 if successful
*/
int main(int argc, char **argv, char **env)
{
	/* gets the env path */
	for (;;)
	{
		char *lineptr = NULL, **splits;
		size_t n = 0;
		ssize_t count;
		(void) argc;
		(void) argv;

		env = environ;

		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
		}
		count = getline(&lineptr, &n, stdin);

		if (count == -1)
		{
			free(lineptr);
			exit(0);
		}
		splits = split_commands(lineptr);
		execute(splits, env);
		free(lineptr);
		if (!isatty(STDIN_FILENO))
		{
			cleanup(splits);
		}
	}
	return (0);
}
