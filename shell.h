#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

void _get_input(char *env[]);
int _putstr(char *str);
char *_strcpy(char *dest, char *src);
void _execute(char *buffer, char *env[]);
char **_tokenize(char *buffer, char *delimiter);
char *_strtok(char *str, char *delim);
void _process_input(char *argv[], char *env[]);
int check_path(char *argv[], char *env[]);
char *_path(char **env);
char *_strcat(char *a, char *b);
int charcmp(char c, char *cmp);
int tc(char *str, char *delim);
void *_memset(char *s, int c, size_t n);
void free_double(void **ptr, int i);
char *_next(void);
void show_prompt(void);
int _strlen(char *s);
void *expand(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
