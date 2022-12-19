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
char **env(char**);

#endif
