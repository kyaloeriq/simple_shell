#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

void forkExec(char *exectble, char *argv[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if(execve(exectble, argv, environ) == -1)
		{
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
}
