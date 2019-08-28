#include "shell.h"

/**
 * check_path - checks if command is present in PATH.
 * @argv: arguments
 * @env: environment
 *
 * Return: if the command is found, the function will return 1. Else, the
 * function will return 0.
 */
int check_path(char *argv[], char *env[])
{
	char *path = _path(env), *check = NULL, *cpath = NULL;
	struct stat buf;
	int i = 0;
	char **routes = NULL;

	if (path != NULL)
	{
		cpath = malloc(sizeof(*cpath) * _strlen(path) + 1);
		_strcpy(cpath, path);
		routes = _tokenize(cpath, ":");

		check = expand(check, 0, (sizeof(*check) * _strlen(routes[i]))
				+ (sizeof(*check) * _strlen(argv[0]) + 2));

		while (routes[i])
		{
			_strcpy(check, routes[i]);
			_strcat(check, "/");
			_strcat(check, argv[0]);
			if (stat(check, &buf) == 0)
			{
				argv[0] = check;
				free_double((void **) routes, ec((void **) routes));
				return (1);
			}
			_memset(check, 0, _strlen(check));
			i++;
			if (routes[i])
				check = expand(check, sizeof(check), (sizeof(*check) * _strlen(routes[i]))
						+ (sizeof(*check) * _strlen(argv[0]) + 2));
		}
	}
	free_double((void **) routes, ec((void **) routes));
	return (0);
}

/**
 * _path - checks for the environment variable PATH.
 * @env: environment
 *
 * Return: pointer to the environment variable PATH, five steps forward.
 */
char *_path(char **env)
{
	int i = 0, j = 0;
	char *path = "PATH=";

	while (env[i])
	{
		j = 0;
		while (j < 5)
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
