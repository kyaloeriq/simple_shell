#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * prompt - simple prompt
 * Return: 0
 */
int prompt(char **command)
{
	char *entry = NULL;
	size_t length = 0;
	ssize_t read;

	printf("Purposedriven#:");
	read = getline(&entry, &length, stdin);/*Read input from the user*/
	if (read == -1)
	{
		perror("Input error");
		exit(EXIT_FAILURE);
	}
	/*Remove newline character at the end of entry*/
	entry[read - 1] = '\0';
	/*Check for the exit command*/
	if (strcmp(entry, "exit") == 0)
	{
		free(entry);
		return (0);
	}
	*command = entry;
	return (1);/*Indicates program should continue*/
}
