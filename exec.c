#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
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
 * execCmd - executes commands
 * @cmd: command
 */
void execCmd(char *command)
{
	char *cmd = my_strdup(command);
	char *tkn = strtok(cmd, " ");
	char *argv[10];
	int a = 0;

	while (tkn != NULL)
	{
		argv[a++] = tkn;
		tkn = strtok(NULL, " ");
	}
	argv[a] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Command execution error");
		exit(98);
	}
	free(cmd);
}
