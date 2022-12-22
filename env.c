#include "main.h"

/**
 * path - checks for command in environment
 * Return: pointer with relative path added
 */

char *path(void)
{
	for (int i = 0; environ[i] != NULL; i++)
	{
		if (strncmp("PATH", environ[i], 4) == 0)
		{
			return (environ[i]);
		}
	}
	exit(EXIT_FAILURE);
}

/**
 * env - gets environmental path
 * @argmnt: pointer pointer
 * Return: array
 */

char **env(char **argmnt)
{
	struct stat buffer;
	char *space, *token, **output, *home, home_dir[1000];
	int directory, i, counter;

	home = getcwd(home_dir, 1000);

	output = malloc(sizeof(char *) * 100);
	if (!output)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	token = strtok(space, ":");
	i = 0;
	while (token)
	{
		token = strtok(NULL, ":");
		output[i] = token;
		i++;
	}
	output[i] = '\0';
	counter = 0;
	while (output[counter])
	{
		chdir(output[counter]); /*changes to directory in the **space pointer*/
		printf("%s\n", output[counter]);
		if (stat(argmnt[0], &buffer) == 0)
		{
			strcat(output[counter], "/"); /*add / to the file path */
			strcat(output[counter], argmnt[0]);
			argmnt[0] = output[counter];
			chdir(home);
			break;
		}
		counter++;
	}
	free(output);
	return (argmnt);
}
