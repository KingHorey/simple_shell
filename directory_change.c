#include "main.h"

/**
* change_dirs - implements the cd command
*
* @args: cd command and directories
*
* Return: 1 on success
*
*/
int change_dirs(char **args)
{
	int i = 1, retrn_checker;
	char current_dir[400];

	getcwd(current_dir, sizeof(current_dir));

	if ((!args[i]) || (strcmp(args[i], "~") == 0))
	{
		retrn_checker = go_to_home(args);
		if (retrn_checker)
		return (1);
	}

	while (args[i])
	{
		if (chdir(args[i]) != 0)
			perror("chdir() error()");
		else
		{
			chdir(args[i]);
			cleanup(args);
			return (1);
		}
		i++;
	}
	return (0);
}


/**
 * go_to_home - changes the directory to HOME
 *
 * @arg: args passed by command line
 *
 * Return: 1 on success
 */

int go_to_home(char **arg)
{
	char *home;

	home = getenv("HOME");
	cleanup(arg);
	chdir(home);
	return (1);
}
