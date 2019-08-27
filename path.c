#include "shell.h"

int check_path(char *argv[], char *env[])
{
	char *path = _path(env), check[98];
	struct stat buf;
	int i = 0;
	char **routes = NULL;

	if (path != NULL)
	{
		routes = _tokenize(path, ":");

		while (routes[i])
		{
			_strcpy(check,routes[i]);
			_strcat(check, "/");
			_strcat(check, argv[0]);

			if (stat( check, &buf ) == 0)
			{
				argv[0] = check;
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
	int i = 0, j = 0;
	char *path = "PATH=";

	while(env[i])
	{
		j = 0;
		while(j < 5)
		{
			if (env[i][j] != path[j])
				break;
			j++;
		}
		if (j == 5)
			break;
		i++;
	}

	return (&env[i][j]);
}
