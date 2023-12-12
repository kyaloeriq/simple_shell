#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
/**
 * prompt - simple prompt
 * @command: buffer to store the user command
 * Return: 1 incase of a non-empty command, 0 otherwise
 */
int prompt(char *command)
{
	size_t size;
	const char prompt_msg[] = "Purposedriven#: ";
	const char empty_msg[] = "Command empty, consider entering a valid one\n";
	
	if (write(STDOUT_FILENO, prompt_msg, sizeof(prompt_msg) - 1) == -1)
	{
		perror("Write error");
		exit(EXIT_FAILURE);
	}
	/*Use getline to read user input*/
	if (my_getline(STDIN_FILENO, command, MAX_COMMAND_LENGTH) == -1)
	{
		perror("Input error");
		exit(EXIT_FAILURE);
	}
	/*Remove newline character at the end of *command*/
	size = strlen(command);
	if (size > 0 && command[size - 1] == '\n')
	{
		command[size - 1] = '\0';
	}
	if (command[0] == '\0')
	{
		if (write(STDOUT_FILENO, empty_msg, sizeof(empty_msg) - 1) == -1)
		{
			perror("Write error");
			exit(EXIT_FAILURE);
		}
		return (0);/*Indicates an empty command*/
	}
	return (1);/*Indicates an non-empty command*/
}
