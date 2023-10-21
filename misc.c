#include "main.h"

/**
 * path_checker - checks the path
 *
 * @argv: args from cmd
 * Return: struct with file info
 */


retrn_node *path_checker(char **argv)
{
	char **path_ptr;
	retrn_node *result = NULL;
	int i = 0;

	path_ptr = split_path();
	if (!path_ptr)
		return (NULL);
	while (path_ptr[i])
	{
		result = executable_check(path_ptr[i], argv[0]);
		if (result->status == 1)
		{
			cleanup(path_ptr);
			return (result);
		}
		free(result);
		i++;
	}
	cleanup(path_ptr);
	return (NULL);
}

/**
 * show_errors - works on printing errors to stderr
 *
 * @argv: args from cmd
 *
 */
void show_errors(char **argv)
{
	fprintf(stderr, "%s: cannot access '%s': No such file or directory\n",
	argv[0], argv[1]);
	cleanup(argv);
}

/**
 * not_found - works on printing errors to stderr
 *
 * @arg: program name
 * @argv: args from cmd
 *
 */
void not_found(char *arg, char **argv)
{
	fprintf(stderr, "%s: 1: %s: not found\n", arg, argv[0]);
	cleanup(argv);
	exit(127);
}
