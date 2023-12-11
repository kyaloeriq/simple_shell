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
 * Return: 0 on success, -1 on failure
 */
void execCmd(char *command, char *argv[])
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
		perror("Error: PATH variable not found\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		exectblePath = malloc(strlen(token) + strlen(command) + 2);
		sprintf(exectblePath, "%s/%s", token, command);
		if (access(exectblePath, X_OK) == 0)
		{
			if (execv(exectblePath, argv) == -1)
			{	
				perror("Execution error");
				free(exectblePath);
				exit(EXIT_FAILURE);
			}
		}
		free(exectblePath);
		token = strtok(NULL, ":");
	} /*if loop completes, command not found*/
	perror("Command not found");
	exit(EXIT_FAILURE);
}
