#include "main.h"

/**
 * exec_line - executes arguments from strtok function
 * @args: pointer to character array holding command and argument
 */

char *get_env(void)
{
	int i = 0;

	while (environ[i] && (strncmp("PATH", environ[i], 4) != 0))
		i++;

	return (environ[i]);
}

/**
 * extract - extracts the environmental variables and stores into a "double pointer"
 *
 * Return: The double pointer
 */

char **extract(void)
{
	char **ret_token; /* double pointer, named return token */
	char *len, *token;
	int i = 0;

	ret_token = malloc(sizeof(char *) * _strlen(len = get_env()));
	token = strtok(len, ":");
	while (token)
		ret_token[i++] = token = strtok(NULL, ":");

	return (ret_token);
}

/**
 * exec_line - executes the command s
 * @args: already tokenized commans
 * Return: processed command
 */

void exec_line(char *args[])
{
	pid_t pid;
	int stats, status;

	pid = fork();

	if (!pid)
	{
		char **size, home[1000], *get_home;
		struct stat buffer;

		size = extract();
		
		get_home = getcwd(home, 1000);
		for (int i = 0; size[i] != NULL; i++)
		{
			chdir(size[i]);
			if (stat(args[0], &buffer) == 0)
			{
				strcat(size[i], "/");
				strcat(size[i], args[0]);
				args[0] = size[i];
				chdir(get_home);
				break;
			}
		}
		stats = execve(args[0], args, NULL);
		free(size);
		if (stats == -1)
		{
			perror("ERROR!\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Error");
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

