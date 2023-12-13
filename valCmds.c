#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * valCmds - checks for validity of executables
 * @command: executables
 * Return: 1 for a valid command, 0 otherwise
 */
int valCmds(const char *command)
{
	if (access(command, X_OK) == 0)
	{
		return (1); /*valid command*/
	}
	else
	{
		perror("Executable not found");
		return (0); /*Invalid command*/
	}
}
