#include "main.h"

/**
 * main - initialize the data
 * @argc: input the size of @argv
 * @argv: @argv: array containing the command line
 * arguments provided as input
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	data d;

	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);

	return (0);
}
