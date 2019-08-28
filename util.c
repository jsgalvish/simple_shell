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

void *expand(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == 0)
		return (ptr);

	new = malloc(new_size);
	if (new)
	{
		_memcpy(new, ptr, old_size);
		free(ptr);
	}
	else
	{
		free(new);
		return (NULL);
	}

	return (new);
}

/**
 * _memcpy - copies the n bytes of a memory area to a destination
 * @dest: pointer to the destination
 * @src: source
 * @n: amount of bytes to fill
 * Return: pointer to the modified memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	for (i = 0; i < (int)n; i++)
		dest[i] = src[i];

	return (dest);
}
