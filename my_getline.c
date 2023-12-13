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
	static char buffer[BUFFER_SIZE];
	static size_t bufferInd = 0;
	static size_t bytesRead = 0;

	ssize_t tBytesRead = 0;
	size_t lineInd = 0;

	while (lineInd < maxchar)
	{
		/*if buffer is empty, read more*/
		if (bufferInd == bytesRead)
		{
			bytesRead = read(fd, buffer, sizeof(buffer));
			/*Check for errors*/
			if (bytesRead == -1)
			{
				perror("Error reading from file");
				return (-1);
			}
			/*if no more data available, return total read*/
			if (bytesRead == 0)
			{
				return (tBytesRead);
			}
			bufferInd = 0; /*Reset buffer index*/
		}
		/*Copy data from buffer to output line*/
		line[lineInd++] = buffer[bufferInd++];
		/*Incase of a newline, remove it and terminate line*/
		if (line[lineInd - 1] == '\n')
		{
			line[lineInd - 1] = '\0';
			return (tBytesRead + lineInd);
		}
		tBytesRead++;
	}
	return (tBytesRead);
}
