#include "main.h"

/**
 * exec_line - executes the command s
 * @args: already tokenized commans
 * Return: processed command
 */

char *exec_line(char **args)
{
	char *path, *token, *command, *file_path;
	char *home_token, home_dir[1000], *path_cpy;
	struct stat buffer;
	int i = 0;

	command = args[0];
	path = getenv("PATH");
	home_token = getcwd(home_dir, 1000);

	if (path)
	{
		if (_strcmp(args[0], "env") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
				_puts(environ[i]);
		}

		if (_strcmp( args[0], "exit") == 0)
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

void *act(char **arg)
{
	int stat, status;
	pid_t pid, wpid;

	pid = fork();
	if (!pid)
	{
		stat = execve(arg[0], arg, NULL);
		if (stat == -1)
			perror("failed");
	}
	else if (pid < 0)
		perror("failed to start process");
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFSIGNALED(status) && !WIFEXITED(status));
	}
}

void *create_child(char **args)
{
	char *path, *token, *command, *file_path;
	char *home_token, home_dir[1000], *path_cpy;
	struct stat buffer;
	int i = 0;

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
}

