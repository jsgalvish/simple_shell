#include "shell.h"

void _get_input(char *env[])
{
	char *buffer = NULL, *c_buffer = NULL;

	buffer = _prompt();

	c_buffer = _strcpy(buffer);

	if (strtok(c_buffer," \n\t\r"))
	{
		_execute(buffer,env);
		_get_input(env);
	}
	_get_input(env);
}

char *_prompt()
{
	int input;
	char *buffer = NULL;
	size_t bufsize = 0;

	if (!isatty(fileno(stdin)))
	{
		input = getline(&buffer, &bufsize, stdin);

		if(input == EOF)
			exit(EXIT_SUCCESS);
	}
	else
	{
		_putstr(GREEN "[._.] ");
		_putstr(YELLOW ">> " RESET);
		input = getline(&buffer, &bufsize, stdin);
	}

	return (buffer);
}

void _execute(char *buffer, char *env[])
{
	char **argv = NULL;
	argv =  _tokenizer(buffer, " \n\t\r");

	if (argv[0][0] == 47)
	{
		if (access(argv[0], X_OK) == 0)
			_process_input(argv,env);
	}
	else
	{
		if (check_path(argv,env))
			_process_input(argv,env);
	}
	//Error
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

int check_path(char *argv[], char *env[])
{
	char *path = _path(env), *check = NULL, *cpath = NULL;
	struct stat buf;
	int i = 0;
	char **routes = NULL;

	if (path != NULL)
	{
		cpath = _strcpy(path);
		routes = _tokenizer(cpath, ":");
		routes[0] = _strcpy(&routes[0][5]);

		while (routes[i])
		{
			check = _strcat(routes[i],argv[0]);

			if ( stat( check, &buf ) == 0)
			{
				argv[0] = check;
				free(check);
				return (1);
			}
			i++;
		}
	}
	free(routes);
	return (0);
}

char *_path(char **env)
{
	int i=0, j=0;
	char *path = "PATH=";

	while(env[i])
	{
		j = 0;
		while(j<5)
		{
			if (env[i][j] != path[j])
				break;
			j++;
		}
		if ( j == 5)
			break;
		i++;
	}

	return (env[i]);
}
