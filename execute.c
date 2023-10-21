#include "main.h"

/**
* execute - execute the command
*
* @argv: args to be carried out
* @env: environmental variable
* @arg: argument name
*/

void execute(char **argv, char **env, char *arg)
{
	pid_t child_pid;
	int check, check_child = 0, rest = 1, status;
	struct stat buf;
	retrn_node *result = NULL;

	check = check_command(argv, env);
	if (check == 1)
		return;
	if (strstr(argv[0], "/"))
	{
		result = malloc(sizeof(retrn_node));
		result->status = stat(argv[0], &buf);
		result->cmd_path = _strdup(argv[0]);
		rest = 0;
	}
	else
	{
		result = path_checker(argv);
		if (result)
			rest = 0;
	}
	if (rest == 0)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			check_child = execve(result->cmd_path, argv, env);
			if (check_child == -1)
				show_errors(argv);
		}
		clean_resources(argv, result);
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
			exit(2);
	}
	else
		not_found(arg, argv);
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
		if (argv[i])
			free(argv[i]);
		i++;
	}
	free(argv);

}


/**
 * executable_check - checks using stat, if binary file is present
 *
 * @path_ptr: array of paths
 * @argv: command passed
 * Return: struct
 */

retrn_node *executable_check(char *path_ptr, char *argv)
{
	int len_cmd = 0, result;
	char *new_pth;
	struct stat buf;
	retrn_node *retrn_value;

	retrn_value = malloc(sizeof(retrn_node));
	if (!retrn_value)
	{
		perror("malloc");
		return (NULL);
	}
	len_cmd = _strlen(argv) + 2;
	new_pth = malloc((_strlen(path_ptr) + len_cmd));
	_strcpy(new_pth, path_ptr);
	_strcat(new_pth, "/");
	_strcat(new_pth, argv);
	result = stat(new_pth, &buf);
	if (result == 0)
	{
		retrn_value->status = 1;
		retrn_value->cmd_path = _strdup(new_pth);
		free(new_pth);
		return (retrn_value);
	}
	else
	{
		retrn_value->status = 0;
		retrn_value->cmd_path = NULL;
		free(new_pth);
	}
	if (retrn_value->cmd_path != NULL)
		puts("failed");
	return (retrn_value);
}


/**
* clean_resources - clear up memory used
*
* @argv: arguments passes
* @result: struct for status and file path
*
*/

void clean_resources(char **argv, retrn_node *result)
{
	cleanup(argv);
	free(result->cmd_path);
	free(result);
}
