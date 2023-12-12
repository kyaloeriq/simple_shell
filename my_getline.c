#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * my_getline - my personal getline
 * @fd: File descriptor
 * @line: Buffer for storing the line
 * @maxchar: Maximum number of characters to read
 * Return: bytes read, -1 incase of error
 */
ssize_t my_getline(int fd, char *line, size_t maxchar)
{
	ssize_t bytesRead = read(fd, line, maxchar);

	if (bytesRead == -1)
	{
		perror("Error reading from file");
		return (-1);
	}
	if (bytesRead > 0 && line[bytesRead - 1] == '\n')
	{
		line[bytesRead - 1] = '\0';/*Remove newline character*/
		return (bytesRead);
	}
	return (bytesRead);
}
