 #include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @ar: built for check
 * @en: current enviroment
 * @x: current status
 * Return: pointer to the function or NULL
 */

void (*check_for_builtins(char *ar[], char *en[], int *x))(char *en[], int *x)
{
	int i;

	builtins_t check[] = {
		{"exit", n_exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(ar[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
	{
		free_double((void **) ar, ec((void **) ar));
		check[i].f(en, x);
	}

	return (check[i].f);
}

/**
* n_exit - exit shell
* @env: current enviroment
* @x_status: current status
*/

void n_exit(char *env[] __attribute__((unused)),  int *x_status)
{
	exit(*x_status);
}

/**
* _env - prints enviroment
* @env: current enviroment
* @x_status: current status
*/

void _env(char *env[], int *x_status)
{
	int i = 0;

	while (env[i])
	{
		_putstr(env[i]);
		_putstr("\n");
		i++;
	}
	 *x_status = 0;
}
