#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - a data structure that
 * holds the main data
 * @av: Token array to be passed as arguments
 * for the execve function
 * @cmd: command line
 * @shell_name: The name for the shell program.
 */
typedef struct data
{
	char **av;
	char *cmd;
	const char *shell_name;
} data;

/**
 * struct builtin - data structure that holds
 * the primary data
 * @cmd: integrated cmd
 * @f: function of integrated cmd
 */
typedef struct builtin
{
	const char *cmd;
	void (*f)(data *d);
} builtin;

/* builtin.c file */
int exec_builtin(data *d);
void builtin_exit(data *d);
void builtin_env(data *d);

/* helpers.c file */
void _printf(const char *str);
void free_array(char **array);
void split(data *d, const char *delim);
void init_data(data *d, const char *shell_name);
void read_cmd(data *d);

/* helpers2.c file */
void _perror(const char *str1, const char *str2);
void _trim(char *str);
void *_realloc(void *ptr, unsigned int new_size);

/* exec.c file */
void start_process(data *d);
void handler_sigint(int sig);
void _exec(data *d);

/* path.c file */
char *_getenv(char *name);
int _which(data *d);

/* string_utils.c file */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

/* string_utils2.c file */
char *_strdup(const char *str);

/* _getline.c file */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
