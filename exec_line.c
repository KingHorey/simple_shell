#include "main.h"

/**
 * exec_line - executes arguments from strtok function
 * @args: pointer to character array holding command and argument
 */
void exec_line(char *args[])
{
	pid_t pid;
	int stat, status;

	pid = fork();

	if (!pid)
	{
		stat = execve(args[0], args, NULL);
		if (stat == -1)
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

