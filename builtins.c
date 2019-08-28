#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @str: built for check
 * Return: pointer to the function or NULL
 */

void (*check_for_builtins(char* str, char *env[]))(char *env[])
{
	int i;

	builtins_t check[] = {
		{"exit", n_exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(str, check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
	{
		check[i].f(env);

	}
	return (check[i].f);
}

/**
* n_exit - exit shell
*/

void n_exit(char *env[])
{
	if (env)

	exit(0);
}

/**
* _env - prints enviroment
*/

void _env(char *env[])
{
	int i = 0;

	while(env[i])
	{
		_putstr(env[i]);
		_putstr("\n");
		i++;
	}
}
