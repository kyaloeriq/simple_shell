#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * execCmd - executes commands
 * @cmd: command
 */
void execCmd(char cmd)
{
	char *tkn = strtok(cmd, "");
	char *cmd2 = tkn;
	char *argv[10];
	int a = 0;

	while (tkn != NULL)
	{
		argv[a++] = tkn;
		tkn = strtok(NULL, " ");
	}
	argv[a] = NULL;

	if (execve(cmd2, argv, NULL) == -1)
	{
		perror("Command execution error");
		exit(98);
	}
}
