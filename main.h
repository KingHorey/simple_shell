#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>



extern char **environ;
char **split_commands(char *string);
char **allocate_and_copy_tokens(char *new_tokens, int len);
char *get_commands();
char **check_tty();

void execute(char **argv, char **);
int env_count(char **envs);
char **new_env_array(int count);

char **split_path();
int path_check(char *path);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int count_array(char **);
char *remove_new_line(char *);
int check_command(char **args, char **env);
int word_count(char *arg, char*);
void cleanup(char **argv);
void free_words_ptr(char **words_ptr, int count);

void my_env(void);

/** memory allocation free handling */
void clean_dpointer(char **dpointer);
void free_splits(char **splits);
#endif /* MAIN_H */
