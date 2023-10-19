#ifndef MAIN_H
#define MAIN_H

/**
 * struct bin_status - returns the status of a file
 *
 * @status: 1 if file is found
 * @cmd_path: path of the bin found
 *
 */


typedef struct bin_status
{
	int status;
	char *cmd_path;
} retrn_node;


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
char *_strchr(char *s, char c);
char *_strdup(char *str);
int __strcmp(char *s1, char *s2);
char **allocate_and_copy_tokens(char *new_tokens, int len);
char *get_commands();
char **check_tty();
char *_strpbrk(char *s, char *accept);
void execute(char **argv, char **);
int env_count(char **envs);
char **new_env_array(int count);

char **split_path();
char *_strcat(char *dest, char *src);
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
char *split_token(char *token, char *delim);

retrn_node *path_checker(char **);
void show_errors(char **argv);
void clean_resources(char **argv, retrn_node *result);
#endif /* MAIN_H */
