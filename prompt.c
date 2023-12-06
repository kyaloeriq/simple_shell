#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * prompt - simple prompt
 * @command: executable commands
 * Return: 0
 */
void prompt(char **command)
{
	size_t size = 0;

	printf("Purposedriven#: ");
	if (getline(command, &size, stdin) == -1)
	{
		perror("Input error");
		exit(EXIT_FAILURE);
	}
	/*Remove newline character at the end of *command*/
	(*command)[strcspn(*command, "\n")] = '\0';
	if ((*command)[0] == '\0') {
		printf("Command empty, consider entering a valid one\n");
		prompt(command);
	}
}
