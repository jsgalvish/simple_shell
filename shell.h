#ifndef _shell_
#define _shell_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int _putstr(char *str);
void _get_input(int input);
void _process_input( char *buffer);

#endif
