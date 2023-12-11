#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * exec - command execution
 * @command: executable command
 * @argv: argument array
 */
void exec(char *command, char *argv[])
{
	char *path, *token, *exectblePath;
	int a;

	for (a = 0; environ[a] != NULL; ++a)
	{
		if (strncmp(environ[a], "PATH=", 5) == 0)
		{
			path = environ[a] + 5;
			break;
		}
	}
	/*if PATH is not in environ, print an error*/
	if (path == NULL)
	{
		write(STDERR_FILENO, "Error: PATH variable not found\n", 42);
		exit(EXIT_FAILURE);
	}
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
			_exit(EXIT_FAILURE);
		}
		free(exectblePath);
		token = strtok(NULL, ":");
	} /*if loop completes, command not found*/
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, " command not found\n", 19);
	_exit(EXIT_FAILURE);
}
