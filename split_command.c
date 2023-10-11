#include "main.h"

/**
* split_commands - Splits the commands into tokens.
* @string: Pointer to the string to be split.
*
* Return: A pointer to an array of strings.
*/
char **split_commands(char *string)
{
	int len;
	char **words_ptr;
	char *new_tokens = remove_new_line(string);

	if (new_tokens == NULL)
		return (NULL);
	len = word_count(new_tokens, " \t\n");

	if (len <= 0)
	{
		free(new_tokens);
		return (NULL);
	}
	words_ptr = allocate_and_copy_tokens(new_tokens, len);

	if (words_ptr == NULL)
	{
		free(new_tokens);
		return (NULL);
	}
	free(new_tokens);
return (words_ptr);
}

/**
* allocate_and_copy_tokens - Allocates memory for tokens and copies them.
* @new_tokens: String with tokens to split.
* @len: Number of tokens.
*
* Return: A pointer to an array of strings.
*/
char **allocate_and_copy_tokens(char *new_tokens, int len)
{
	char **words_ptr = malloc((len + 1) * sizeof(char *));
	char *token;
	int i = 0;

	if (words_ptr == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	token = strtok(new_tokens, " \t\n");
	while (token != NULL)
	{
		words_ptr[i] = strdup(token);
		if (words_ptr[i] == NULL)
		{
			perror("malloc");
			free_words_ptr(words_ptr, i);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		i++;
	}
	words_ptr[i] = NULL;
	return (words_ptr);
}

/**
* free_words_ptr - Frees the memory allocated for words_ptr.
* @words_ptr: Array of strings.
* @count: Number of strings in the array.
*/
void free_words_ptr(char **words_ptr, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		free(words_ptr[i]);
	}
	free(words_ptr);
}
