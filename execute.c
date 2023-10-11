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
	int check, check_child = 0;

	check = check_command(argv);
	if (check == 1)
		return;

	child_pid = fork();
	if (child_pid == 0)
		check_child = execve(argv[0], argv, env);
	if (check_child == -1)
		puts("No such file or directory");
	cleanup(argv);
	wait(&child_pid);
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
