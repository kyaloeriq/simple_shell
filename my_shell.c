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
			argv[0] = strdup(tkn);
		a = 1;/*Start from 1 to keep argv[0] for the command*/
		while (tkn != NULL && a < MAX_ARGS)
		{
			tkn = strtok(NULL, " ");
			argv[a++] = tkn ? strdup(tkn) : NULL;
		}
		argv[a] = NULL;
		forkExec(argv[0], argv);
		/*free dynamically allocated memory*/
		free(command);
		free(cmd);
		for (i = 0; i < a; ++i)
		{
			free(argv[i]);
			argv[i] = NULL;
		}
	}
	return (0);
}
