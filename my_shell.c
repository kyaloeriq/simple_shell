#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * my_strdup - my strdup
 * @s: argument
 * Return: dup
 */
char *my_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		strcpy(dup, s);
	}
	return (dup);
}
/**
 * main - UNIX command line interpreter
 */
int main(void)
{
	while (1)
	{
		char *command = "ls";
		char *cmd = my_strdup(command);
		char *tkn = strtok(cmd, " ");
		char *argv[MAX_ARGS + 1];
		int i;
		int a = 0;
		char *exectble = "/usr/bin/ls";

		prompt();
		/*Check if user specified a different command*/
		if (tkn != NULL)
		{
			if (strcmp(tkn, "cp") == 0)
			{
				exectble = "/usr/bin/cp";
			}
		}
		while (tkn != NULL && a < MAX_ARGS)
		{
			argv[a++] = my_strdup(tkn);
			tkn = strtok(NULL, " ");
		}
		argv[a] = NULL;
		/*Check if the executable file is accessible*/
		if (access(exectble, X_OK) == -1)
		{
			fprintf(stderr, "Error:%s command not found\n", exectble);
			continue; 
		}
		forkExec(exectble, argv);
		/*free dynamically allocated memory*/
		free(cmd);
		for (i = 0; i < a; ++i)
		{
			free(argv[i]);
		}
	}
	return (0);
}
