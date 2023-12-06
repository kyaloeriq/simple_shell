#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * main - UNIX command line interpreter
 * Return: 0
 */
int main(void)
{
	char *command = NULL, *cmd = NULL, *tkn = NULL, *argv[MAX_ARGS + 1];
	int i, a = 0;
	char *exectblePath = NULL;

	while (1)
	{
		prompt(&command);
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			break;
		}
		cmd = strdup(command);
		tkn = strtok(cmd, " ");
		/*Check if user specified a different command*/
		if (tkn != NULL)
			exectblePath = tkn;
		a = 0;
		while (tkn != NULL && a < MAX_ARGS)
		{
			argv[a++] = strdup(tkn);
			tkn = strtok(NULL, " ");
		} argv[a] = NULL;
		/*Check if the executable file is accessible*/
		if (access(exectblePath, X_OK) == -1)
		{
			fprintf(stderr, "Error:%s command not found\n", exectblePath);
			free(command), free(cmd);
			for (i = 0; i < a; ++i)
			{
				free(argv[i]);
				argv[i] = NULL;
			}
			continue;
		}
		forkExec(exectblePath, argv);
		/*free dynamically allocated memory*/
		free(command), free(cmd);
		for (i = 0; i < a; ++i)
			free(argv[i]), argv[i] = NULL;
	} return (0);
}
