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

	if ((!args[i]) || strcmp(args[i], "~") == 0)
	{
		retrn_checker = go_to_home(args);
		return (1);
	}
	else if (strcmp(args[i], "-") == 0)
	{
		retrn_checker = prev_dirs();
	}
	else
	{
		getcwd(current_dir, sizeof(current_dir));
		retrn_checker = chdir(args[i]);
		if (!retrn_checker)
		{
			setenv("OLDPWD", current_dir, 1);
			setenv("PWD", args[i], 1);
		}
		else
			perror("chdir");
	}
	cleanup(args);
	return (1);
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
	char current_dir[400];

	home = getenv("HOME");
	if (home)
	{
		getcwd(current_dir, sizeof(current_dir));
		setenv("OLDPWD", current_dir, 1);
		setenv("PWD", home, 1);
		cleanup(arg);
		chdir(home);
		return (1);
	}
	else
		perror("chdir: No home directory");
	cleanup(arg);
	return (0);
}


/**
 * prev_dirs - changes the directory to HOME
 *
 * Return: 1 on success
 */

int prev_dirs(void)
{
	char *oldpwd, *nxtpwd, *tmp_dir;

	oldpwd = getenv("OLDPWD");
	nxtpwd = getenv("PWD");

	if (strcmp(oldpwd, nxtpwd) == 0)
		chdir(nxtpwd);
	else
	{
		tmp_dir = nxtpwd;
		setenv("PWD", oldpwd, 1);
		setenv("OLDPWD", tmp_dir, 1);
		chdir(oldpwd);
	}
	return (1);
}
