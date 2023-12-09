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
	const char prompt_msg[] = "Purposedriven#: ";
	const char empty_msg[] = "Command empty, consider entering a valid one\n";

	if (write(STDOUT_FILENO, prompt_msg, sizeof(prompt_msg) - 1) == -1)
	{
		perror("Write error");
		exit(EXIT_FAILURE);
	}
	/*Use getline to read user input*/
	if (getline(command, &size, stdin) == -1)
	{
		perror("Input error");
		exit(EXIT_FAILURE);
	}
	/*Remove newline character at the end of *command*/
	(*command)[strcspn(*command, "\n")] = '\0';
	if ((*command)[0] == '\0')
	{
		if (write(STDOUT_FILENO, empty_msg, sizeof(empty_msg) - 1) == -1)
		{
			perror("Write error");
			exit(EXIT_FAILURE);
		}
		/*Recursive call for prompt to get a non_empty command*/
		prompt(command);
	}
}
