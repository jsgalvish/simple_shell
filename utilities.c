#include "shell.h"
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
	char buffer[32];
	char *b = buffer;
	int bufsize = 32;

	_putstr("$");
	input = getline(&b,&bufsize,stdin);

	if (input)
	{
		_process_input(buffer);
		_get_input(input);
	}

	exit(98);
}

/**
*
**/

void _process_input(char *buffer)
{
	if(buffer[0] == '/')
	{
		if(access(buffer, X_OK))
		{
			pid_t pid;
			pid = fork();

			if (pid == 0)
			{
				char *nbuffer = strtok(buffer, "\n");
				char *argv[] = {nbuffer,NULL};
				char *envp[] = {NULL};

				if (execve(buffer, argv, envp) == -1)
					perror("Could not execve");
			}
		}
	}
}
