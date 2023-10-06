#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
char **split_commands(char *);
char *get_commands();
char **check_tty();

void execute(char **argv, char **);
char *get_path(void);
int path_check(char *);
char **split_path(char *path);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int count_array(char **);
char *remove_new_line(char *);
int check_command(char **args);
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
void free_splits(char **splits);
void handle_exit(void);
void handle_cd(char **args);
void handle_echo(char **args);
void handle_help(void);
void close_fd(int fd);

#endif /* MAIN_H */
