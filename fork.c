#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * fork - fork
 * @command: executable command
 * @argv: argument array
 */
void fork(char *command, char *argv[])
{
	pid_t pid = fork();
	int status;

	if (strcmp(command, "env") == 0)
	{
		/*print the environment if command is "env"*/
		printEnv();
		return;
	}
	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/
		if (strchr(command, '/') != NULL)
		{
			/*If command contains separator, execute without searching*/
			execv(command, argv);
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
		exec(command, argv);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
