#include "main.h"

/**
 * check_command - check the command is a built-in command
 *
 * @args: array of pointers
 * Return: 1 if successful
 */

int  check_command(char **args, char **env)
{
	int i = 0;

	if (strcmp(args[0], "env") == 0)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
		return (1);
	}
	return (-1);
}
