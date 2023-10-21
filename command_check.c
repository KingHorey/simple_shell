#include "main.h"

/**
 * check_command - check the command is a built-in command
 * @env: environmental variable
 * @args: array of pointers
 * Return: 1 if successful
 */

int check_command(char **args, char **env)
{
	int i = 0;

	if (__strcmp(args[0], "env") == 0)
	{
		while (env[i])
		{
			if (env[i])
				printf("%s\n", env[i]);
			i++;
		}
		cleanup(args);
		return (1);
	}
	else if (__strcmp(args[0], "exit") == 0)
	{
		cleanup(args);
		exit(0);
	}

	return (-1);
}
