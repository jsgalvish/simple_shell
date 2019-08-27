#include "shell.h"

void _get_input(char *env[])
{
	char *buffer = NULL, *c_buffer = NULL;

	buffer = _next();

	c_buffer = _strcpy(buffer);

	if (strtok(c_buffer, " \n\t\r"))
	{
		_execute(buffer, env);
		_get_input(env);
	}
	_get_input(env);
}

char *_next(void)
{
	int input;
	char *buffer = NULL;
	size_t bufsize = 0;

	if (!isatty(fileno(stdin)))
	{
		input = getline(&buffer, &bufsize, stdin);
		if (input == -1)
			exit(EXIT_SUCCESS);
	}
	else
	{
		show_prompt();
		input = getline(&buffer, &bufsize, stdin);
		if (input == -1)
			exit(EXIT_SUCCESS);
	}

	return (buffer);
}

void show_prompt(void)
{
		_putstr(GREEN "[._.] ");
		_putstr(YELLOW ">> " RESET);
}

void _execute(char *buffer, char *env[])
{
	char **argv = NULL;

	argv = _tokenizer(buffer, " \n\t\r");

	if (argv[0][0] == 47)
	{
		if (access(argv[0], X_OK) == 0)
			_process_input(argv, env);
	}
	else
	{
		if (check_path(argv, env))
			_process_input(argv, env);
	}
}

void _process_input(char *argv[], char *env[])
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

