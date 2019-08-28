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
 * _tokenize - tokenizes a string
 * @buffer: string
 * @delimiter: charset for the delimiter
 *
 * Return: double pointer with every token
 */
char **_tokenize(char *buffer, char *delimiter)
{
	int i = 0;
	char *token, *cbuffer;
	char **store_tokens = NULL;

	cbuffer = malloc(sizeof(*cbuffer) * _strlen(buffer) + 1);
	_strcpy(cbuffer, buffer);

	store_tokens = malloc(sizeof(char *) * tc(buffer, delimiter) + 8);

	token = strtok(cbuffer, delimiter);

	store_tokens[i] = malloc(sizeof(*token) * _strlen(token) + 1);
	_strcpy(store_tokens[i], token);

	while ((token = strtok(NULL, delimiter)))
	{
		store_tokens[++i] = malloc(sizeof(*token) * _strlen(token) + 1);
		_strcpy(store_tokens[i], token);
	}

	store_tokens[++i] = NULL;
	free(cbuffer);
	return (store_tokens);
}

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
