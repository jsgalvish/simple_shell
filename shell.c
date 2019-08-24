#include "shell.h"

int main(int argc, char **argv, char **environment)
{
	printf("%d\n", argc);
	puts(argv[0]);

	_get_input(environment);

	return(0);
}
