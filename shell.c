#include "shell.h"

int main(int argc, char **argv, char **environment)
{
	printf("%d\n", argc);
	puts(argv[0]);

	_get_input(environment);

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
