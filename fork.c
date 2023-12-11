#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * forkExec - fork and command execution
 * @command: executable command
 * @argv: argument array
 */
void forkExec(char *command, char *argv[])
{
	pid_t pid = fork();
	char *path, *token, *exectblePath;
	int status;

	if (strcmp(command, "env") == 0)
	{	/*print the environment if command is "env"*/
		printEnv();
		return;
	}
	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{ /*Child process*/
		if (strchr(command, '/') != NULL)
		{ /*If command contains separator, execute without searching*/
			execv(command, argv);
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
		path = getenv("PATH");
		token = strtok(path, ":");
		while (token != NULL)
		{
			exectblePath = malloc(strlen(token) + strlen(command) + 2);
			sprintf(exectblePath, "%s/%s", token, command);
			if (access(exectblePath, X_OK) == 0)
			{
				execv(exectblePath, argv);
				perror("Execution error");
				free(exectblePath);
				exit(EXIT_FAILURE);
			}
			free(exectblePath), token = strtok(NULL, ":");
		} /*if loop completes, command not found*/
		write(STDERR_FILENO, "Error: ", 7);
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, " command not found\n", 19);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}
