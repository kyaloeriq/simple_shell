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
	char *command = NULL;
	char *cmd = my_strdup(command);
	char *tkn = strtok(cmd, " ");
	char *argv[MAX_ARGS + 1];
	int i;
	int a = 0;
	char *exectble = "/usr/bin/ls";

	while (1)
	{
		prompt(&command);

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}

		/*Check if user specified a different command*/
		if (tkn != NULL && strcmp(tkn, "cp") == 0)
		{
			exectble = "/usr/bin/cp";
		}
		while (tkn != NULL && a < MAX_ARGS)
		{
			argv[a++] =strdup(tkn);
			tkn = strtok(NULL, " ");
		}
		argv[a] = NULL;
		/*Check if the executable file is accessible*/
		if (access(exectble, X_OK) == -1)
		{
			fprintf(stderr, "Error:%s command not found\n", exectble);
			free(command);
			free(cmd);
			for (i = 0; 1 < a; ++i)
			{
				free(argv[i]);
			}
			continue;
		}
		forkExec(exectble, argv);
		/*free dynamically allocated memory*/
		free(command);
		free(cmd);
		for (i = 0; i < a; ++i)
		{
			free(argv[i]);
		}
	}
	return (0);
}
