#include "shell.h"

int ec(void **ptr)
{
	int i;

	for (i = 0; ptr[i] ; i++)
		;	

	return (i);
}
