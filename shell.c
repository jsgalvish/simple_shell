#include "shell.h"

/**
 * main - start msh
 * @argc: argument count
 * @argv: argument variables
 * @environment: environment variables
 *
 * Return: zero..
 */
int main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **environment)
{
	int x_status = 0;

	_get_input(environment, &x_status);

	return (0);
}
