#include "shell.h"

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

int check_path(char *argv[], char *env[])
{
	char *path = _path(env), *check = NULL;
	struct stat buf;
	int i = 0;
	char **routes = NULL;

	if (path != NULL)
	{
		routes = _tokenizer(path, ":");
		routes[0] = _strcpy(&routes[0][5]);

		while (routes[i])
		{
			check = _strcat(routes[i],argv[0]);
			printf("check %s\n", check);

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
