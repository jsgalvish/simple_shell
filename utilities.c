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
	char *token = NULL;
	char **store_tokens = NULL;
	char *copy = malloc(sizeof(char *) * _strlen(buffer));

	printf("[tokenizer] buffer: %s\n", buffer );
	printf("[tokenizer] delimiter: %s\n", delimiter );

	printf("[tokenizer] _strcpy: %s\n", _strcpy(buffer) );

	copy = _strcpy(buffer);

	store_tokens = malloc(sizeof(char *) * 8 );
	if (store_tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	printf("[tokenizer] copy: %s\n", copy );
	token = strtok(copy, delimiter);
	printf("[tokenizer] token: %s\n", delimiter );
	store_tokens[i++] = token;

	while ((token = strtok(0, delimiter)))
	{
		printf("[tokenizer] token: %s\n", token );
		store_tokens[i++] = token;
	}

	store_tokens[i] = NULL;

	printf("[tokenizer] buffer: %s\n", buffer );

	return(store_tokens);
}

char *_strcpy(char *original)
{
	int i = 0;
	char *copy = NULL;

	copy = malloc(sizeof(original) + 1);
	if (copy == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}

	while (original[i] != '\0')
	{
		copy[i] = original[i];
		i++;
	}

	copy[i] = '\0';

	printf("[strcpy] copy     size %li %s  \n", sizeof(copy), copy);
	printf("[strcpy] original %li %s  \n", sizeof(original), original);
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

int _strlen (char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return ++i;
}
