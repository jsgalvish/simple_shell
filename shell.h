#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int _putstr(char *str);
void _get_input(int input);
int _execute(char *buffer);
void _process_input( char *buffer);

#endif
