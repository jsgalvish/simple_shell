#include "shell.h"

#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"
/**
 * _putstr - writes a string to stdout
 * @str: The string to print
 * Return: size of string or -1.
 */
int _putstr(char *str)
{
	int size = -1, len = 0;

	while (str[len] != '\0')
		len++;

	size = write(1, str, len);

	if (len == size)
		return (size);

	/*error*/
	return (size);
}

/**
* _get_input - manage input
**/

void _get_input(int input)
{
	char *b = NULL;
	size_t bufsize = 0;

	_putstr(GREEN "[._.] ");
	_putstr(YELLOW ">> " RESET);
	input = getline(&b, &bufsize, stdin);

	if (input)
		_get_input(_execute(b));

	exit(98);
}

/**
*
**/

int _execute(char *buffer)
{
	int status;

	if (buffer[0] == '/')
	{
		if (access(buffer, X_OK))
			_process_input(buffer);

		return (1);
	}

	return (0);
}

void _process_input(char *buffer)
{
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		char *nbuffer = strtok(buffer, "\n");
		char *argv[] = {nbuffer, NULL};
		char *envp[] = {NULL};

		if (execve(buffer, argv, envp) == -1)
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
