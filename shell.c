#include "shell.h"

int main(int argc, char **argv, char **environment)
{
	char *path;

	printf("%d\n", argc);
	puts(argv[0]);

	path = _path(environment);

	puts(path);
	_get_input(1, environment);

	return(0);
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
