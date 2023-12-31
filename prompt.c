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
	ssize_t bytesRead;

	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, prompt_msg, sizeof(prompt_msg) - 1) == -1)
		{
			perror("Write error");
			exit(EXIT_FAILURE); }}
	bytesRead = my_getline(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
	if (bytesRead == -1)
	{
		perror("Input error");
		return (-1); }
	else if (bytesRead == 0)
	{
		return (0);/*Handle EOF*/ }
	/*Remove newline character at the end of command*/
	size = 0;
	while (command[size] != '\0' && command[size] != '\n')
	{
		size++; }
	if (size > 0)/*Check for non_empty command*/
	{
		if (command[size - 1] == '\n')
		{
			command[size - 1] = '\0'; }}
	else
	{
		if (isatty(STDIN_FILENO))
		{
			if (write(STDOUT_FILENO, empty_msg, sizeof(empty_msg) - 1) == -1)
			{
				perror("Input error");
				exit(EXIT_FAILURE); }}
		return (0);/*Return 0 for an empty command*/ }
	return (1);/*Indicates a valid non-empty command*/
}
