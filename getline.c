#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 128

/**
 * _getline - gets delimited string input from stdin
 * @lineptr: line pointer
 * @n: expected size of the line
 *
 * Return: size of the obtained input
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	int i = 0, c = 0;
	ssize_t size = SIZE;
	static char *buf;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (*n)
		buf = malloc(sizeof(*buf) * *n);
	else
		buf = malloc(sizeof(*buf) * SIZE);

	/*
	 * this part needs to be worked, since it will call to read()
	 * when iterating in every character of the buffer
	 */
	while ((read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n')
		{
			buf[i] = '\n';
			buf[i + 1] = 0;
			break;
		}
		if (i > size)
		{
			buf = realloc(buf, sizeof(*buf) * size << 1);
			size = size << 1;
		}
		buf[i] = c;
		i++;
	}

	printf("%s", buf);

	return (i);
}

