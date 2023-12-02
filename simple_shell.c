#include <stdio.h>
#include <stdlib.h>
/**
 * main - UNIX command line interpreter
 * Return: 0
 */
int main(void)
{
	char *entry = NULL;
	size_t length = 0;
	ssize_t read;

	while (1)
	{
		printf("Purposedriven#:");
		read = getline(&entry, &length, stdin);/*Read input from the user*/
		if (read == -1)
		{
			perror("Input error");
			exit(98);
		}
		/*Remove newline character at the end of entry*/
		entry[read - 1] = '\0';
		/*fork a new process*/
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Fork error");
			exit(98);
		}
		if (pid == 0)
		{
			execCmd(entry);
		}
		else
		{
			wait(NULL);
		}
	}
	free(entry);/*Free memory allocated for entry*/
	return (0);
}
