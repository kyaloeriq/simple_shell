#include <stdio.h>
#include <stdlib.h>
/**
 * main - simple prompt
 * Return: 0
 */
int main(void)
{
	char *input = 0;
	size_t length = 0;
	ssize_t read;

	while (1)
	{
		printf("Purposedriven#:");
		read = getline(&input, &length, stdin);/*Read input from the user*/
		if (read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
	}
		/*Execute commands from the input*/
	}
	free(input);
	return (0);
}
