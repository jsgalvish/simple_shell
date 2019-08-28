#include "shell.h"

/**
 * _strtok - returns the next token of a string, delimited with a
 * provided set of characters
 * @str: provided string
 * @delim: character set for delimiters
 *
 * Return: pointer to the next token (word), if there are no tokens left, the
 * function will return a null pointer.
 */
char *_strtok(char *str, char *delim)
{
	int i, len;
	static char *token;
	static char *cpy;
	static int pos;

	if (!str && !cpy)
		return (NULL);

	if (str && cpy)
		pos = 0;

	if (!cpy || !token)
	{
		cpy = str;
		pos = 0;
	}

	for (i = pos, len = 0; cpy[i]; i++)
	{
		if (!charcmp(cpy[i], delim))
			len++;
		if (!charcmp(cpy[i], delim) && (charcmp(cpy[i + 1], delim) || !cpy[i + 1]))
		{
			token = &cpy[(i + 1) - len];
			token[len] = 0;
			pos = i + 2;
			return (token);
		}
	}
	token = NULL;
	return (token);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: zero, if the strings are equal. A positive or negative integer if
 * respectively the first string is alphabetically greater than the second
 * integer or viceversa.
 */

int _strcmp(char *s1, char *s2)
{
	for (; *s1 != '\0' && *s2 != '\0' && *s2 == *s1; s1++, s2++)
		;
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
