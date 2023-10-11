#include "main.h"

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
/**
* clean_dpointer - frees up a double pointer
*
* @dpointer: double pointer or array of pointers
*
* Return: NULL
*/

void clean_dpointer(char **dpointer)
{
	int i = 0;

	while (dpointer[i])
	{
		free(dpointer[i]);
		i++;
	}
	free(dpointer);
}
