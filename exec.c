#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * execCmd - command execution
 * @command: executable command
 * @argv: argument array
 * Return: 0 on success, -1 on failure
 */
int execCmd(char *command, char *argv[])
{
	char *path, *token, *exectblePath;
	int a;

	if (strchr(command, '/') != NULL)
	{
		/*Likely an absolute path*/
		execv(command, argv);
		perror("Execution error");
		exit(EXIT_FAILURE);
	}
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
			execv(exectblePath, argv);
			perror("Execution error");
			free(exectblePath);
		}
		free(exectblePath);
		token = strtok(NULL, ":");
	} /*if loop completes, command not found*/
	perror("Command not found");
	exit(EXIT_FAILURE);
}
