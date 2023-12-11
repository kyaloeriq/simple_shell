#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * forkExec - fork
 * @command: executable command
 * @argv: arguments array
 */
void forkExec(char *command, char *argv[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Child process*/
		if (strcmp(command, "env") == 0)
		{
                /*print the environment if command is "env"*/
		printEnv();
		exit(EXIT_SUCCESS);
		}
		if (strchr(command, '/') != NULL)
		{
			/*If command contains separator, execute without searching*/
			execv(command, argv);
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
		if (execCmd(command, argv) != 0)
		{
			fprintf(stderr, "Error executing command: %s\n", command);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	else
	{ /*Parent process*/
		waitpid(pid, &status, 0);
	}
}
