#include <stdio.h>
#include "main.h"
/**
 * printEnv - prints the current environment
 */
void printEnv()
{
	extern char **environ;
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

