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
	size_t size = 0;
	ssize_t read;

	printf("Purposedriven#:");
	if (getline(command, &size, stdin) == -1)
	{
		perror("Input error");
		exit(EXIT_FAILURE);
	}
	/*Remove newline character at the end of *command*/
	(*command)[strcspn(*command, "\n")] = '\0';
}
