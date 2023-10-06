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
	for (;;)
	{
		char *lineptr, **splits, *new_line;
		size_t n = 0, output_check = -1, count;
		(void) argc;
		(void) argv;

		lineptr = NULL;

		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
			count = getline(&lineptr, &n, stdin);
			if (count == output_check)
			{
				printf("\n");
				free(lineptr);
				exit(0);
			}
			new_line = remove_new_line(lineptr);
			free(lineptr);
			splits = split_commands(new_line); /* invalid write of size 1*/
			execute(splits, env);
		}
		else
		{
			count = getline(&lineptr, &n, stdin);
			if (count == output_check)
			{
				free(lineptr);
				exit(0);
			}
			new_line = remove_new_line(lineptr);
			free(lineptr);
			splits = split_commands(new_line);
			execute(splits, env);
		}
	}
	return (0);
}
