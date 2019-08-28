#include "shell.h"

/**
 * ctrl_c - disables the process from getting terminated using SIGINT
 * @sig: signal
 *
 * Return: void.
 */
void ctrl_c(int sig __attribute__ ((unused)))
{
}

/**
 * _get_input - gets input from stdin.
 * @env: environment
 * @x_status: current status
 *
 * Return: void.
 */
void _get_input(char *env[], int *x_status)
{
	char *buffer = _next(x_status), *cbuffer = NULL;

	cbuffer = malloc(sizeof(*cbuffer) * _strlen(buffer) + 1);
	_strcpy(cbuffer, buffer);

	if (strtok(cbuffer, " \n\t\r"))
	{
		free(cbuffer);
		_validate(buffer, env, x_status);
		_get_input(env, x_status);
	}
	else
	{
		free(cbuffer);
		free(buffer);
		_get_input(env, x_status);
	}
}

/**
 * _next - gets input through getline and returns the associated buffer
 * @x_status: current status
 * Return: void.
 */
char *_next(int *x_status)
{
	int input;
	char *buffer = NULL;
	size_t bufsize = 0;

	show_prompt();
	signal(SIGINT, ctrl_c);
	input = getline(&buffer, &bufsize, stdin);
	if (input == EOF)
	{
		free(buffer);
		*x_status = 127;
	}

	return (buffer);
}

/**
 * _validate - validates input from _next
 * @buffer: buffer containing the command
 * @env: environment
 * @x_status: current status
 * Return: void.
 */
void _validate(char *buffer, char *env[], int *x_status)
{
	char **argv = NULL;

	argv = _tokenize(buffer, " \n\t\r");
	free(buffer);

	if (check_for_builtins(argv, env, x_status) == NULL)
	{
		if (check_path(argv, env))
		{
			*x_status = 0;
			_execute(argv, env);
		}
		else
		{
			if (access(argv[0], X_OK) == 0)
			{
				*x_status = 0;
				_execute(argv, env);
			}
			else
			{
				_putstr(argv[0]);
				_putstr(": command not found\n");
				*x_status = 127;
			}
		}
		free_double((void **) argv, ec((void **) argv));
	}
}

/**
 * _execute - executes a command
 * @argv: arguments
 * @env: environment
 * @x_status: current status
 * Return: void.
 */
void _execute(char *argv[], char *env[])
{
	int status;
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			perror("Could not execve");

		exit(0);
	}
	else if (pid < 0)
		perror("Could not execve");

	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
