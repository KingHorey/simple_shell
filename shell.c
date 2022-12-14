#include "main.h"
#define ERR STDERR_FILENO

int main(int __attribute__((unused)) argc, char __attribute((unused)) **argv)
{
	get_line();

	return (0);
}

void get_line()
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("~$ ");
		line = read_line();
		args = split_line(line);
		/* status = execute_line(args) */
		
		free(line);
		free(args);
	} while(1);
}

/**
 * read_lines- reads line provided by the user into a buffer
 * 
 * Return: buffer with provided string
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0, characters; /* setting bufsize to Zero and line to NULL, make getline allocate the buffer for us */

	characters = getline(&line, &bufsize, stdin);
	if(characters == -1)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	} else {
		printf("Failed to read");
		exit(EXIT_FAILURE);
	}

	return line;
}

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
			if(!token)
				fprintf(stderr, "Unable to reallocate memory\n");
			exit (EXIT_FAILURE);
		}
		store = strtok(NULL, DELIM);
	}
	token[position] = NULL;
	return (token);
}
		
