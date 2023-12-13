#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * valCmds - checks for executables
 */
int valCmds(const char *command)
{
	FILE *config_file = fopen(CONFIG_FILE, "r");
	char line[256];
	int valid = 0;
	ssize_t bytesRead;
	size_t len;

	if (config_file == NULL)
	{
		perror("Error opening configuration file");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		bytesRead = my_getline(fileno(config_file), line, sizeof(line));
		if (bytesRead == -1)
		{
			perror("Error reading configuration file");
			exit(EXIT_FAILURE);
		}
		else if (bytesRead == 0)
		{
			break; /*EOF*/
		}
		/*Remove newline character*/
		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		/*Compare user entered command with those in the config file*/
		if (strcmp(command, line) == 0)
		{
			valid = 1;
			break;
		}
	}
	fclose(config_file);
	return (valid);
}
