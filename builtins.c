 #include "shell.h"
/**
 * check_for_builtins - checks if the command is a builtin
 * @a: arguments
 * @e: current enviroment
 * @x_s: current status
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(char *a[], char *e[], int *x_s))(char *e[], int *x_s)
{
	int i;

	builtins_t check[] = {
		{"exit", n_exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(a[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
	{
		free_double((void **) a, ec((void **) a));
		check[i].f(e, x_s);
	}

	return (check[i].f);
}

/**
* n_exit - exit shell
* @env: current enviroment
* @x_status: current status
*/
void n_exit(char *env[] __attribute__((unused)),
			int *x_status)
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
