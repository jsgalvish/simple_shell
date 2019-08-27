#include "shell.h"

int check_path(char *argv[], char *env[])
{
	char *path = _path(env), check[98], *cpath = NULL;
	struct stat buf;
	int i = 0;
	char **routes = NULL;

	if (path != NULL)
	{
		cpath = _strcpy(path);
		routes = _tokenize(cpath, ":");

		while (routes[i])
		{
			check = _strcpy(routes[i]);
			_strcat(check, "/");
			_strcat(check, argv[0]);
			printf("%s\n", check);

			if (stat( check, &buf ) == 0)
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
