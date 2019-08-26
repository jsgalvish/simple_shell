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

char **_tokenizer(char *buffer, char *delimiter)
{
	int i = 0;
	char *token;
	char **store_tokens = NULL;

	store_tokens = malloc(sizeof(char *) * 64 );

	token = strtok(buffer, delimiter);
	store_tokens[i++] = token;

	while ((token = strtok(NULL, delimiter)))
		store_tokens[i++] = token;

	store_tokens[i] = NULL;

	return(store_tokens);
}

char *_strcpy(char *original)
{
	int i = 0;
	char *copy;

	copy = malloc(sizeof(original));

	while (original[i] != '\0')
	{
		copy[i] = original[i];
		i++;
	}

	copy[i] = '\0';

	return copy;
}

char *_strcat(char *a, char *b)
{
	char *news;
	size_t i,j;

	for (i = 0; a[i] != '\0'; i++)

	for (j = 0; b[j] != '\0'; j++)

	news = malloc((i+j) * sizeof(char) + 2);

	for (i = 0; a[i] != '\0'; i++)
		news[i] = a[i];
	news[i] = '/';

	for (j = 1; b[j-1] != '\0'; j++)
		news[i+j] = b[j-1];

	news[i+j] = '\0';
	return news;
}
