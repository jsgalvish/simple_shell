#include "shell.h"


int main(int argc __attribute__((unused)), 
		char **argv __attribute__((unused)), char **environment)
{
	_get_input(environment);

	return(0);
}
