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
char *_next(void);
void show_prompt(void);
void _execute(char *buffer, char *env[]);
void _process_input(char *argv[], char *env[]);

int tc(char *str, char *delim);
char **_tokenize(char *buffer, char *delimiter);
char *_strtok(char *str, char *delim);

int _putstr(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *a, char *b);
int _strlen(char *s);
int charcmp(char c, char *cmp);
int _strcmp(char *s1, char *s2);

char *_path(char **env);
int check_path(char *argv[], char *env[]);

int ec(void **ptr);

void *_memset(char *s, int c, size_t n);
void free_double(void **ptr, int i);
void *expand(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
