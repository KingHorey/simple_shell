#include "main.h"


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
