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

void _get_input(int input)
{
	_putchar('$');

	input = getchar( );

	if (input)
		_get_input(input);

	exit(98);
}
