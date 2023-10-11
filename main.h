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
char **split_commands(char *);
char *get_commands();
char **check_tty();

int execute(char **argv, char **);
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

void my_env(void);
void add_alias(const char *name, const char *value);
void handle_unset_alias(char **args);
void handle_set_alias(char **args);
void handle_print_alias(char **args);
void display_aliases(void);
void free_aliases(void);
void add_to_history(const char *command);
void display_history(void);

void handle_exit(void);
void handle_cd(char **args);
void handle_echo(char **args);
void handle_help(void);
void close_fd(int fd);

/** memory allocation free handling */
void clean_dpointer(char **dpointer);
void free_splits(char **splits);

#endif /* MAIN_H */
