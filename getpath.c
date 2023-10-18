#include "main.h"

/**
 * get_path - gets the environmental path variable
 *
 * Description: Gets the environ path
 *
 * Return: Returns the path
 */
char *get_path(void)
{
	char *location =  NULL;

	location = getenv("PATH");
	return (location);
}

/**
 * split_path - splits path string gotten from get_path
 * Return: array of pointers to different paths
 */


char **split_path(void)
{
	char *tokens, **path_array, *token_copy, *path;
	int count, path_checks, j = 0, i = 0;

	path = get_path();
	count = word_count(path, ":");
	token_copy = strdup(path);
	path_array = (char **)malloc((count + 1) * sizeof(char *));
	if (path_array == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	tokens = split_token(token_copy, ":");
	while (tokens != NULL)
	{
		path_checks = path_check(tokens); /* checks if it a valid path */
		if (path_checks)
		{
			path_array[i] = malloc((_strlen(tokens) + 1) * sizeof(char));
			if (!path_array[i])
			{
				while (j < i)
				{
					free(path_array[j]);
					j++;
				}
				free(path_array[i]);
				free(path_array);
				break;
			}
			_strcpy(path_array[i], tokens);
			i++;
		}
		tokens = split_token(NULL, ":");
	}
	free(token_copy);
	path_array[i] = NULL;
	return (path_array);
}


/**
 * path_check - checks the existence of a path using stat
 * @path: path gotten from the use of split_token in split_path
 * Return: 1 on success, 0 on failure
 */

int path_check(char *path)
{
	int _value;
	struct stat buf;

	_value = stat(path, &buf);
	if (_value == 0)
		return (1);
	return (0);
}
