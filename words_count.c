#include "main.h"

/**
 * word_count - counts the number of strings in a word
 * @word: word to be split
 * @delim: parameter for which the split is used to determine
 * the number of words
 * Return: The number of words read by using the delim as a
 * seperator
 */


int word_count(char *word, char *delim)
{
	char *token, *words;
	int count = 0;

	words = strdup(word);

	token = split_token(words, delim);
	while (token != NULL)
	{
		count++;
		token = split_token(NULL, delim);
	}
	free(words);
	return (count);
}
