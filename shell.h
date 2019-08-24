#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void _get_input(char *env[]);
char *_prompt();
int _putstr(char *str);
void _execute(char *buffer, char *env[]);
char **_tokenizer(char *buffer, char *delimiter);
char *_strtok(char *str, char *delim);
void _process_input(char *argv[], char *env[]);
char *_path(char **env);
int charcmp(char c, char *cmp);
int tc(char *str, char *delim);
void *_memset(char *s, int c, size_t n);
void free_double(void **ptr, int i);


#endif
