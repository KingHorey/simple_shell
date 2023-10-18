#include "main.h"

/**
 * input_loop - handles the input loop for interactive and non-interactive modes
 * @env: array of pointers for environmental variables
 */
void input_loop(char **env) {
    char *lineptr = NULL, **splits;
    size_t n = 0, count = 0;
    size_t output_check = -1;

    for (;;) {
        if (isatty(STDIN_FILENO)) {
            printf("($) ");
        }

        count = getline(&lineptr, &n, stdin);
        if (count == output_check) {
            free(lineptr);
            if (isatty(STDIN_FILENO)) {
                printf("\n");
            }
            exit(0);
        }
        if (count == 1 && lineptr[0] == '\n')
        {
            free(lineptr);
            continue;
        }

        splits = split_commands(lineptr);
        free(lineptr);
        execute(splits, env);
    }
}

/**
 * main - main function that runs all other functions
 * @argc: number of command line arguments
 * @argv: array of pointers holding the commands passed to the terminal
 * @env: array of pointers for environmental variables
 * Return: 1 if successful
 */
int main(int argc, char **argv, char **env) {
    char current_dir[400];
    env = environ;
    (void)argc;
    (void)argv;
    setenv("OLDPWD", getcwd(current_dir, sizeof(current_dir)), 1);
    input_loop(env);

    return (0);
}
