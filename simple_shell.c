#include <stdio.h>
#include <stdlib.h>
/**
 * main - simple prompt
 * Return: 0
 */
int main(void)
{
	char *entry = 0;
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
	}
	free(entry);
	return (0);
}
