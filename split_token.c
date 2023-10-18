#include "main.h"

/**
 * split_token - split a text just like strtok
 * however, this is a custom strtok-like function
 *
 * @token: the text to be split
 * @delim: the delimiter
 * Return: char or NULL
 */

char *split_token(char *token, char *delim)
{
	static int position;
	static char *new_token;
	char *tok, *first;

	if (token)
	new_token = token, tok = token;
	if (!delim)
		return (NULL);
	else if (position == 0 && new_token == NULL)
	{
		return (NULL);
	}
	else
	{
		tok = new_token;
	}
	if (!new_token)
		return (NULL);

	while (tok && (new_token = strpbrk(tok, delim)))
	{
		int num = (int)(new_token - tok);

		if (num == 0)
			tok++;
		else
		{
			tok[num] = '\0';
			first = tok;
			new_token++;
			return (first);
		}
	}

	if (!new_token && tok[0] != '\0')
	{
		position = 0;
		return (tok);
	}
	return (NULL);
}
