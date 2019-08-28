#include "shell.h"

/**
 * _get_input - gets input from stdin.
 * @env: environment
 *
 * Return: void.
 */
void _get_input(char *env[])
{
	char *buffer = _next(), *cbuffer = NULL;

	cbuffer = malloc(sizeof(*cbuffer) * _strlen(buffer));
	_strcpy(cbuffer,buffer);

	if (strtok(cbuffer, " \n\t\r"))
	{
		_validate(buffer, env);
		free(buffer);
		_get_input(env);
	}
	_get_input(env);
}

/**
 * _next - gets input through getline and returns the associated buffer
 *
 * Return: void.
 */
char *_next(void)
{
	int input;
	char *buffer = NULL;
	size_t bufsize = 0;

	if (!isatty(fileno(stdin)))
	{
		input = getline(&buffer, &bufsize, stdin);
		if (input == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		show_prompt();
		input = getline(&buffer, &bufsize, stdin);
		if (input == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
	}

	return (buffer);
}

/**
 * show_prompt - shows the prompt.
 *
 * Return: void.
 */
void show_prompt(void)
{
	_putstr(GREEN "[._.] ");
	_putstr(YELLOW ">> " RESET);
}

/**
 * _validate - validates input from _next
 * @buffer: buffer containing the command
 * @env: environment
 *
 * Return: void.
 */
void _validate(char *buffer, char *env[])
{
	char **argv = NULL;

	argv = _tokenize(buffer, " \n\t\r");

	if (argv[0][0] == 47)
	{
		if (access(argv[0], X_OK) == 0)
			_execute(argv, env);
	}
	else
	{
		if (check_for_builtins(argv[0],env)==NULL)
		{
			if (check_path(argv, env))
				_execute(argv, env);
			else
			{
				_putstr(argv[0]);
				_putstr(": command not found\n");
			}
		}
	}
	free(argv);
	//free_double((void **) argv, ec((void **) argv));
}

/**
 * _execute - executes a command
 * @argv: arguments
 * @env: environment
 *
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
