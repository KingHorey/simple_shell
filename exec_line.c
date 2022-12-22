#include "main.h"

/**
 * exec_line - executes the command s
 * @args: already tokenized commans
 * Return: processed command
 */

void *exec_line(char **args)
{
	char *path, *command;
	struct stat buffer;
	int i;

	command = args[0];
	path = getenv("PATH");

	if (path)
	{
		if (_strcmp(args[0], "env") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
				_puts(environ[i]);
		}

		if (_strcmp(args[0], "exit") == 0)
			_exit(i);

		else if (stat(command, &buffer) == 0)
			act(args);
		else
		{
			create_child(args);
		}
	}
	return (NULL);
}

/**
 * act - creates a child process
 * @arg: pointer pointer
 * Return: NULL
 */

void *act(char **arg)
{
	int stat, status;
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		stat = execve(arg[0], arg, environ);
		if (stat == -1)
			perror("failed");
	}
	else if (pid < 0)
		perror("failed to start process");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFSIGNALED(status) && !WIFEXITED(status));
	}
	return (NULL);
}


/**
 * create_child - searche env
 * @args: pointer pointer
 * Return: Null
 */

void *create_child(char **args)
{
	char *path, *token, *command;
	char *home_token, home_dir[1000], *path_cpy;
	struct stat buffer;

	command = args[0];
	path = getenv("PATH");
	home_token = getcwd(home_dir, 1000);

	path_cpy = _strdup(path);
	token = strtok(path_cpy, ":");
	while (token)
	{
		chdir(token);
		if (stat(args[0], &buffer) == 0)
		{
			_strcat(token, "/");
			_strcat(token, args[0]);
			_strcat(token, "\0");
			args[0] = token;
			chdir(home_token);
			free(path_cpy);
			act(args);
			return (command);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}

