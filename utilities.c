#include "shell.h"

#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"
/**
 * _putstr - writes a string to stdout
 * @str: The string to print
 * Return: size of string or -1.
 */
int _putstr(char *str)
{
	int size = -1, len = 0;

	while (str[len] != '\0')
		len++;

	size = write(1, str, len);

	if (len == size)
		return (size);

	/*error*/
	return (size);
}

char **_tokenize(char *buffer, char *delimiter)
{
	int i = 0;
	char *token, cbuffer[98];
	char **store_tokens = NULL;

	_strcpy(cbuffer,buffer);

	store_tokens = malloc(sizeof(char *) * tc(buffer, delimiter) + 8);

	token = strtok(cbuffer, delimiter);
	store_tokens[i] = token;

	while ((token = strtok(NULL, delimiter)))
		store_tokens[++i] = token;

	store_tokens[++i] = NULL;

	return(store_tokens);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	if (*src == '\0')
		*dest = '\0';

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);

	if (*(src + i) == '\0')
		*(dest + i) = '\0';

	return (dest);
}

char *_strcat(char *dest, char *src)
{
	int i, j;
	char *str;

	str = dest;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		str[i] = src[j];

	str[i] = '\0';

	return (str);
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 * Return: i, length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	for (; s[i] != '\0'; i++)
		;
	return (i);

}
