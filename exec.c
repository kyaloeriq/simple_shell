#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * execCmd - executes commands
 * @cmd: command
 */
void execCmd(char command)
{
	char *cmd = strdup(command);
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
