#include "main.h"

/**
 * check_command - check the command is a built-in command
 * @env: environmental variable
 * @args: array of pointers
 * Return: 1 if successful
 */

int check_command(char **args, char **env)
{
	int i = 0, cd_check;

	if (strcmp(args[0], "env") == 0)
	{
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
		printf("end");
		return (1);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		cleanup(args);
		exit(0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		cd_check = change_dirs(args);
		if (cd_check == 1)
			return (1);
	}
	return (-1);
}

