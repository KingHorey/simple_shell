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
	for (int cmdstatus = 0; cmdstatus == 0;)
	{
		char *lineptr = NULL, **splits;
		char *prompt = "KingO $ ";
		size_t n = 0, output_check = -1, count = 0;
		(void) argc;
		(void) argv;

		env = environ;
		if (cmdstatus == 1)
			break;

		if (isatty(STDIN_FILENO))
		{
			for (int p = 0; p < 8; p++)
				putchar(prompt[p]);
			count = getline(&lineptr, &n, stdin);
			if (count == output_check)
				free(lineptr), free(splits), n = 0, exit(0);
			splits = split_commands(lineptr), free(lineptr);
			cmdstatus = execute(splits, env);
			cleanup(splits);
		/*	free(lineptr);*/
		}
		else
		{
			count = getline(&lineptr, &n, stdin);
			if (count == output_check)
				free(lineptr), exit(0);
			splits = split_commands(lineptr), free(lineptr), execute(splits, env);
			cleanup(splits);
/*			free(lineptr);*/
		}
	}
	return (0);
}
