#ifndef MAIN_H
#define MAIN_H

/*Constant def */
#define SIZE 1024
#define DELIM " \t\n\r\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;
char *read_line();
void get_line(void);
void exec_line(char **);
char **split_line(char *);
char *path(void);
int _strlen(char *);
char **env(char **);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
void act(char **);
void start_fork(char **);
void _puts(char *str);
int _putchar(char c);
void create_child(char **);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);


#endif
