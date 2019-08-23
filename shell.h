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
void *_memset(char *s, int c, size_t n);
void free_double(void **ptr, int i);
int _execute(char *buffer);
void _process_input( char *buffer);
void print_env();

#endif
