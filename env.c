#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * printEnv - prints the current environment
 */
void printEnv(void)
{
	char **env;
	size_t len = 0;

	for (env = environ; *env != NULL; env++)
	{
		while ((*env)[len] != '\0')
		len++;

		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
