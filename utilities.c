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

	if (strtok(b," \n\t\r"))
		_get_input(_execute(b));

	_get_input(input);
}

/**
*
**/

int _execute(char *buffer)
{
	int i = 0;
	char *token;
	char *store_tokens[1024];

	token = strtok(buffer, " \n\t\r");
	store_tokens[i++] = token;

	while ((token = strtok(NULL, " \n\t\r")))
		store_tokens[i++] = token;

	store_tokens[i] = NULL;

	if (store_tokens[0][0] == 47)
	{
		if (access(store_tokens[0], X_OK) == 0)
			_process_input(store_tokens);

		return (1);
	}

	return (0);
}

void _process_input(char *argv[])
{
	int status;
	char *envp[] = {NULL};

	pid_t pid;
	pid = fork();


	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
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
