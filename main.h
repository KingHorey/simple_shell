#ifndef MAIN_H
#define MAIN_H

/*Constant def */
#define SIZE 1024
#define DELIM " \t\n\r\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line();
void get_line();
int execute_line(char **);
char **split_line(char *);

#endif
