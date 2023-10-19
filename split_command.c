#include "main.h"

/**
 * split_commands - splits the commands into tokens
 *
 * @string: pointer to string to be split
 *
 * Return: a pointer to an array of strings
 */

char **split_commands(char *string)
{
	int len;
	char **words_ptr, *tokens, *delim, *new_tokens;
	int i = 0, j = 0, data;

	delim = " \t\n";
	new_tokens = remove_new_line(string);
	len = word_count(new_tokens, delim);
	words_ptr = malloc((len + 1) * sizeof(char *));
	tokens = strtok(new_tokens, delim);
	while (tokens != NULL)
	{
		data = _strlen(tokens) + 1;
		words_ptr[i] = malloc(data);
		if (words_ptr[i] == NULL)
		{
			perror("malloc");
			while (j < i)
			{
				free(words_ptr[j]);
				j++;
			}
			free(words_ptr);
		}
		strcpy(words_ptr[i], tokens); /* invalid write size of 1 */
		tokens = strtok(NULL, delim);
		i++;
	}
	words_ptr[i] = NULL;
	free(new_tokens);
	free(tokens);
	return (words_ptr);
}

/**
 * remove_new_line - removes the newline character that is added
 * automatically when getline is used t read data
 * @word: word read by getline
 * Return: Stripped down word
 */

char *remove_new_line(char *word)
{
	int i = 0;
	char *word_copy;

	word_copy = strdup(word);

	for (i = 0; i <= _strlen(word_copy); i++)
	{
		if (word_copy[i] == '\n')
			word_copy[i] = '\0';
		word_copy[i] = word[i];
	}
	return (word_copy);
}
