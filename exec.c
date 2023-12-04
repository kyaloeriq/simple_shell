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
 * execCmd - executes commands with arguments
 * @command: command
 */
void execCmd(char *command)
{
	char *cmd = my_strdup(command);
	char *tkn = strtok(cmd, " ");
	char *argv[20];
	int a = 0;
	char *exectble = "/usr/bin/ls";

	/*Check if user specified a different command*/
	if (tkn != NULL)
	{
		if (strcmp(tkn, "cp") == 0)
		{
			exectble = "usr/bin/cp";
		}
	}
	while (tkn != NULL && a < 19)
	{
		argv[a++] = tkn;
		tkn = strtok(NULL, " ");
	}
	argv[a] = NULL;

	if (execve(exectble, argv, NULL) == -1)
	{
		perror("Command execution error");
		exit(EXIT_FAILURE);
	}
	free(cmd);
}