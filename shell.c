#include "main.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int __attribute__((unused)) argc, char __attribute((unused)) * argv[])
{
	get_line();

	return (0);
}

/**
* get_line - runs other neccesary functions
* Description: This function runs all other functions that
* is needed to leep the shell running
*/
void get_line(void)
{
	char *line;
	char **args;

	do {
		printf("msh-$: ");
		line = read_line();
		if (*line == '\n')
		{
			continue;
		}
		args = split_line(line);
		exec_line(args);
		free(line);
		free(args);
	} while (1); /* infinite loop */
}

/**
 * read_line- reads line provided by the user into a buffer
 * Return: buffer with provided string
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0, characters, num = -1; /** setting bufsize to Zero and line
						    *to NULL makes getline allocate
						    * the buffer for us
						    */
	characters = getline(&line, &bufsize, stdin);
	if (characters == num)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		} else
		{
			fprintf(stderr, "Failed to read");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 * split_line - This function splits the text stored in
 * the line memory allocation (using strtok)
 * @word: memory allocated from read_line function that contains
 * text passed in
 *
 * Return: token - has all the seprated text as different pointers
 */

char **split_line(char *word)
{
	int position = 0, counter = SIZE;
	char *store; /* stores the token when strtok is called */

	char **token = malloc(sizeof(char *) * SIZE);

	if (!token)
		fprintf(stderr, "Unable to allocate memory\n");

	store = strtok(word, DELIM);
	while (store) /* runs the loop till word is NULL, 0 */
	{
		token[position++] = store;
		if (position >= SIZE)
		{
			counter += SIZE;
			token = realloc(token, sizeof(char *) * counter);
			if (!token)
				fprintf(stderr, "Unable to reallocate memory\n");
			exit(EXIT_FAILURE);
		}
		store = strtok(NULL, DELIM);
	}
	token[position] = NULL;
	return (token);
}
