#include "shell.h"

void print_env()
{
	int i;
	extern char **environ;

	for (i = 0; environ[i]; i++)
	{
		_putstr(environ[i]);
		_putstr("\n");
	}
}

