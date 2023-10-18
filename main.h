#ifndef MAIN_H
#define MAIN_H

/**
 * struct bin_status - checks the existence of a file
 * and returns a status
 *
 * @status: returns 1 if file is found r 0 if not
 * @cmd_path: the path for each found command
 */

typedef struct bin_status
{
	int status;
	char *cmd_path;
} retrn_node;

#define BUF_SIZE 1024
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

extern char **environ;
char **split_commands(char *string);
char **allocate_and_copy_tokens(char *new_tokens, int len);
char *get_commands(void);
char **check_tty(void);
char *_split_token(char *str, const char *delim);
void execute(char **argv, char **);
int env_count(char **envs);
char **new_env_array(int count);

void free_memory(char *lineptr, char **splits, size_t n);
char **split_path(void);
int path_check(char *path);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int count_array(char **);
char *remove_new_line(char *);
int check_command(char **args, char **);
int word_count(char *arg, char*);
void cleanup(char **argv);
void free_words_ptr(char **words_ptr, int count);

void my_env(void);

/** cd builtin */
void clean_dpointer(char **dpointer);
void free_splits(char **splits);
int change_dirs(char **);
int go_to_home(char **arg);
retrn_node *executable_check(char *path_ptr, char *);
int prev_dirs(void);
char *split_token(char *, char *);
#endif /* MAIN_H */
