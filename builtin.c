#include "main.h"

/**
 * exec_builtin - a function that verifies if a command is a
 * built-in command and executes it accordingly.
 * @d: input data structure
 * Return: 1 if the command is a built-in command, 0 if not.
 */
int exec_builtin(data *d)
{
	builtin builtin[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; builtin[i].cmd; i++)
	{
		if (_strcmp(d->av[0], builtin[i].cmd) == 0)
		{
			builtin[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * builtin_exit - exit the shell
 * @d: input data structure
 * Return: void
 */
void builtin_exit(data *d)
{
	int status = 0;

	if (d->av[1])
		status = atoi(d->av[1]);
	free_array(d->av);
	free(d->cmd);
	exit(status);
}

/**
 * builtin_env - function that prints the
 * current environment
 * @d: input data structure
 * Return: void
 */
void builtin_env(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}
