#include "main.h"

/**
 * _printf - prints a string to stdout
 * @str: the string input
 * Return: void
 */
void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_array - function to deallocates memory for
 * an array of pointers
 * @array: the array of pointers
 * Return: void.
 */

void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}

/**
 * split - function that divides a given
 * string into multiple substrings
 * @d: input data structure
 * @delim: the string input
 * Return: void.
 */

void split(data *d, const char *delim)
{
	char *token;
	int ntoken = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	token = strtok(d->cmd, delim);
	while (token)
	{
		d->av = _realloc(d->av, (ntoken + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntoken] = _strdup(token);
		if (d->av[ntoken] == NULL)
			goto free;
		ntoken++;
		token = strtok(NULL, delim);
	}
	d->av[ntoken] = NULL;
	return;
free:
	free_array(d->av);
	free(d->cmd);
	perror(d->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * init_data - initilize the data
 * @d: inpute data structure
 * @shell_name: the string input
 * Return: void
 */

void init_data(data *d, const char *shell_name)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_name = shell_name;
}

/**
 * read_cmd - function that retrieves the command
 * from the prompt and organizes it into
 * a data structure.
 * @d: the data structure input
 * Return: void
 */

void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;

	nread = _getline(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_FAILURE);
	}

	d->cmd[nread - 1] = '\0';
	_trim(d->cmd);
}
