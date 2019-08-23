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
	int i, j, k, l, len;
	static char **arr, *pos;
	static int n = 1;

	if ((!str && !arr) || !delim)
		return (NULL);
	if (pos != NULL)
	{
		pos = arr[n++];
		return (pos);
	}
	if (tc(str, delim) == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * tc(str, delim) + 8);
	if (arr == NULL)
		return (NULL);

	for (i = 0, len = 0, j = 0; str[i]; i++)
	{
		if (!charcmp(str[i], delim))
			len++;
		if (!charcmp(str[i], delim) && (charcmp(str[i + 1], delim) || !str[i + 1]))
		{
			arr[j] = malloc(sizeof(char) * len + 1);
			if (pos == NULL)
				pos = arr[j];
			if (arr[j] == NULL)
			{
				free_double((void *)arr, j);
				return (NULL);
			}
			_memset(arr[j], 0, len + 1);
			for (l = (i + 1) - len, k = 0; l <= i; l++, k++)
				arr[j][k] = str[l];
			len = 0;
			j++;
		}
	}
	arr[j] = NULL;
	return (pos);
}

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

/**
 * _memset - fills memory n times with a constant byte.
 * @s: pointer to the memory area
 * @c: specified byte
 * @n: amount of bytes to fill
 *
 * Return: pointer to the modified memory
 */
void *_memset(char *s, int c, size_t n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = c;
	return (s);
}

/**
 * free_double - frees a malloc'd double pointer from a specified position
 * @ptr: double pointer
 * @i: position
 *
 * Return: void.
 */
void free_double(void **ptr, int i)
{
	for (; i >= 0; i--)
		free(ptr[i]);
	free(ptr);
}


