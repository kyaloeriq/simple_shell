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
void prompt(char **command)
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
	*command = strdup(entry);
	if (*command == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	free(entry);/*Free memory allocated by getline*/
}
