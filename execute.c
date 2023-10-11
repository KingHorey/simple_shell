#include "main.h"

/**
 * execute - execute the command
 *
 * @argv: args to be carried out
 * @env: environmental variable
 */

void execute(char **argv, char **env)
{
	pid_t child_pid;
	int check, check_child = 0, result, i = 0, len_cmd = 0;
	char **path_ptr, *new_pth, *cmd_path;
	struct stat buf;

	path_ptr = split_path(), check = check_command(argv, env);
	if (check == 1)
		return;
	if (strstr(argv[0], "/"))
		result = stat(argv[0], &buf);
	else
	{
		while (path_ptr[i])
		{
			len_cmd = strlen(argv[0]) + 2;
			new_pth = malloc((strlen(path_ptr[i]) + len_cmd));
			strcpy(new_pth, path_ptr[i]), strcat(new_pth, "/");
			strcat(new_pth, argv[0]), result = stat(new_pth, &buf);
			if (result == 0)
			{
				cmd_path = strdup(new_pth), free(new_pth);
				break;
			}
			else
				free(new_pth);
			i++;
		}
	}
	if (result == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
			check_child = execve(cmd_path, argv, env);
		if (check_child == -1)
			puts("No such file or directory");
		cleanup(argv), cleanup(path_ptr), free(cmd_path);
		wait(&child_pid);
	}
	else
		cleanup(argv), cleanup(path_ptr), puts("No such file or directory");
}



/**
 * count_array - coutns the number of words are
 * in an array of pointers
 * @cmd: array of pointers
 * Return: number of arrays
 */

int count_array(char **cmd)
{
	int i = 0;

	while (cmd[i] != NULL)
	{
		i++;
	}
	return (i);
}

/**
 * cleanup - cleans up memory for array of pointers
 * @argv: array of pointers that is to be cleared
 * Return: NULL
 */

void cleanup(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);

}
