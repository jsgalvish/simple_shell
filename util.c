#include "shell.h"

/**
 * tc - Returns the token count of a string, each one separated by a
 * specified delimiter.
 * @str: provided string
 * @delim: charset for delimiters
 *
 * Return: token count of the string.
 */
int tc(char *str, char *delim)
{
	int i, c;

	for (i = 0, c = 0; str[i]; i++)
		if (!charcmp(str[i], delim) && (charcmp(str[i + 1], delim) || !str[i + 1]))
			c++;

	return (c);
}

/**
 * charcmp - compares a provided character with each one provided in a charset.
 * @c: provided character
 * @cmp: charset for comparison
 *
 * Return: if the character matches with the charset, the function will
 * return 1. Else, the function will return 0.
 */
int charcmp(char c, char *cmp)
{
	int i;

	for (i = 0; cmp[i]; i++)
		if (c == cmp[i])
			return (1);
	return (0);
}


