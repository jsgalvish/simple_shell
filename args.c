#include "shell.c"

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
	char **argv;
	argv =  _tokenizer(buffer, " \n\t\r");

	if (argv[0][0] == 47)
	{
		if (access(argv[0], X_OK) == 0)
			_process_input(argv,env);
	}
	else
	{
		if (check_path(argv))
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

int check_path(char *env[])
{
	char *path = _path(env);

	if (path != NULL)
	{
		char **routes;
		routes = _tokenizer(path, ":");

		int i = 0;
		while (routes[i])
			puts(routes[i++]);
	}

	return (0);
}
