#include "main.h"


/**
 * get_path - gets the environ PATH
 *
 * Return: Returns the path string
 */

char *get_path() /*expect funct to get input and return path*/
{
	char *location;

	location = getenv("PATH");/*getenv to get path env variable*/
	return (location);
}

/**
 * split_path - splits path string gotten from get_path
 * @path: path string gotten from get_path
 *
 * Return: array of pointers to different paths
 */


char **split_path(char *path)
{
	char *tokens, **path_array, *token_copy;
	int count, paths_check, j = 0, i = 0;

	count = word_count(path, ":");
	token_copy = strdup(path);
	path_array = (char **)malloc((count + 1) * sizeof(char *));
	if (path_array == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	tokens = strtok(token_copy, ":");
	while (tokens != NULL)
	{
		paths_check = path_check(tokens);
		if (paths_check)
		{
			path_array[i] = malloc((_strlen(tokens) + 1) * sizeof(char));
			if (!path_array[i])
			{
				while (j < i)
				{
					free(path_array[j]);
					j++;
				}
				free(path_array);
				break;
			}
			_strcpy(path_array[i], tokens);
			i++;
		}
		tokens = strtok(NULL, ":");
	}
	free(token_copy);
	path_array[i] = NULL;
	return (path_array);
}


/**
 * path_check - checks the existence of a path using stat
 * @path: path gotten from the use of strtok in split_path
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
