#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * forkExec - fork and command execution
 * @command: executable command
 * @argv: arguments
 */
void forkExec(char *command, char *argv[])
{
	pid_t pid = fork();
	char *path, *token, *exectblePath;
	int status;

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		path = getenv("PATH");
		token = strtok(path, ":");
		while (token != NULL)
		{
			exectblePath = malloc(strlen(token) + strlen(command) + 2);
			sprintf(exectblePath, "%s/%s", token, command);
			if (access(exectblePath, X_OK) == 0)
			{
				argv[0] = strdup(exectblePath);
				execv(exectblePath, argv);
				perror("Execution error");
				exit(EXIT_FAILURE);
			}
		free(exectblePath), token = strtok(NULL, ":");
		}
		/*if loop completes, command not found*/
		fprintf(stderr, "Error: %s command not found\n", command);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}
