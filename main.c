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
	char current_dir[400];

	env = environ;
	setenv("OLDPWD", getcwd(current_dir, sizeof(current_dir)), 1);
	for (;;)
	{
		char *lineptr = NULL, **splits;
		size_t n = 0, output_check = -1, count = 0;
		(void) argc;
		(void) argv;

		if (isatty(STDIN_FILENO))
			printf("($) ");
		else
			printf("\n");
		count = getline(&lineptr, &n, stdin);
		if (count == output_check)
		{
			free(lineptr);
			n = 0;
			exit(0);
		}
		else if (count == 1 && lineptr[0] == '\n')
		{
			free(lineptr);
			n = 0;
			continue;
		}
		splits = split_commands(lineptr);
		free(lineptr);
		n = 0;
		execute(splits, env);
	}
	return (0);
}
