#include <stdio.h>
#include "main.h"
/**
 * printEnv - prints the current environment
 */
void printEnv(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
