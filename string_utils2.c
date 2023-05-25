#include "main.h"
/**
 * _strdup - returns a pointer to a newly
 * allocated block in memory,
 * containing a duplicate of the
 * string given by as a parameter
 *
 * @str: the string input
 *
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


/**
 * _isnumber - check for a string is a number
 * @status: the string that is being checked
 * Return: void
 */
int _isnumber(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}


/**
 * _isdigit - check if character is number or not
 * @c: the character
 * Return: 1 if the character is a digit
 * 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


