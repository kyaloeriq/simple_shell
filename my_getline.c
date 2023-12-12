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
	ssize_t bytesRead = 0;
	ssize_t tlBytsRead = 0;

	if (maxchar == 0 || line == NULL)
	{
		return (-1);
	}
	while (tlBytsRead < (ssize_t)maxchar - 1)
	{
		bytesRead = read(fd, line + tlBytsRead, 1);
		if (bytesRead > 0)
		{
			tlBytsRead += bytesRead;
			if (line[tlBytsRead - 1] == '\n')
			{
				line[tlBytsRead] = '\0';/*Remove newline character*/
				return (tlBytsRead);
			}
		}
		else if (bytesRead == 0 && tlBytsRead == 0)
		{
			return (0); /*Reached EOF without any bytes*/
		}
		else if (bytesRead == 0)
		{
			break;/*Reached EOF after reading some bytes*/
		}
		else if (bytesRead == -1 && errno != EINTR)
		{
			perror("Error reading from file");
			return (-1);/*Error reading from file*/
		}
		else if (bytesRead == -1 && errno == EINTR)
		{
			perror("Error reading from file");
			return (-1);
		}
	}
	if (tlBytsRead > 0)
	{
		line[tlBytsRead] = '\0';
		return (tlBytsRead);
	}
	return (-1);
}
