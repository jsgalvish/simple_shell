#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _get_input - manage input
**/

void _get_input(int characters)
{
	char buffer[32];
	char *b = buffer;
	int bufsize = 32;

	_putchar('$');
	characters = _getline(&b,&bufsize,stdin);

	if (characters)
		_get_input(characters);

	exit(98);
}
