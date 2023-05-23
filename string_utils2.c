#include "main.h"

/**
 * _strdup - function that returns a pointer to a
 * newly allocated memory space, which contains a duplicate
 * of the string provided as a parameter.
 * @str: the string input
 * Return: a pointer
 */

char *_strdup(const char *str)
{
	int i, len = 0;
	char *result;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	result = (char *)malloc((len + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		result[i] = str[i];

	return (result);
}
