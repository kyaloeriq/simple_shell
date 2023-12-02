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
			perror("Input Error");
			exit(98);
		}
		/*Execute commands from the input*/
		free(entry);/*Free memory allocated for entry*/
		/*Reset entry and length for next iteration*/
		entry = NULL;
		length = 0;
	}
	return (0);
}
