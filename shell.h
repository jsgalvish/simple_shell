#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int _putstr(char *str);
void _get_input(int input);
void _process_input(char *buffer);
char *_strtok(char *str, char *delim);
int charcmp(char c, char *cmp);
int tc(char *str, char *delim);
int _execute(char *buffer);
void _process_input( char *buffer);
int _strcmp(char *s1, char *s2);

#endif
