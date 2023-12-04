#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * main - UNIX cmd line interpreter
 * Return: 0
 */
int main(void)
{
	char *entry = NULL;
	size_t length = 0;
	ssize_t read;
	pid_t pid;

	while (1)
	{
		printf("Purposedriven#:");
		read = getline(&entry, &length, stdin);/*Read input from the user*/
		if (read == -1)
		{
			perror("Input error");
			exit(EXIT_SUCCESS);
		}
		/*Remove newline character at the end of entry*/
		entry[read - 1] = '\0';
		/*Check for the exit command*/
		if (strcmp(entry, "exit") == 0)
		{
			free(entry);
			exit(EXIT_SUCCESS);
		}
		/*Fork a new process*/
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execCmd(entry);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
	free(entry);/*Free memory allocated for entry*/
	return (0);
}
