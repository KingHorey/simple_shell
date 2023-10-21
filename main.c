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
	int space = 0;

	env = environ;
	/* setenv("OLDPWD", getcwd(current_dir, sizeof(current_dir)), 1); */
	for (;;)
	{
		char *lineptr = NULL, **splits, **arg;
		size_t n = 0, output_check = -1, count = 0;
		(void) argc;
		arg = argv;
		if (isatty(STDIN_FILENO))
			printf("($) ");
		count = getline(&lineptr, &n, stdin);
		if (count == output_check)
		{
			free(lineptr);
			n = 0;
			exit(0);
		}
		else if (count <= 1 || count <= 0)
		{
			free(lineptr);
			n = 0;
			continue;
		}
		else
		{
			space = check_and_remove_space(lineptr);
			if (space)
			{
				splits = split_commands(lineptr);
				free(lineptr);
				n = 0;
				execute(splits, env, arg[0]);
			}
			n = 0;
		}
	}
	return (0);
}


/**
 * check_and_remove_space - checks if all data are spaces
 *
 * @data: string from getline
 * Return: 1 if all spaces or 0 if not
 */

int check_and_remove_space(char *data)
{
	int i = 0;

	while (data[i] == ' ' || data[i] == '\n')
		i++;

	if (data[i] == '\0')
	{
		return (0);
	}
	else
	{
		memmove(data, data + i, _strlen(data) - i + 1);
		return (1);
	}
}
