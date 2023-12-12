#include <stdio.h>
#include <stdlib.h>
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
			if (line[tlBytsRead] == '\n')
			{
				line[tlBytsRead] = '\0';/*Remove newline character*/
				return (tlBytsRead);
			}
			tlBytsRead += bytesRead;
		}
		else if (bytesRead == 0)
		{
			break; /*Reached EOF*/
		}
		else
		{
			return (-1);/*Error reading from file*/
		}
	}
	return (tlBytsRead);
}
