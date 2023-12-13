#ifndef MAIN_H
#define MAIN_H

int prompt(char *command);
char *my_strdup(const char *s);
int execCmd(char *command, char *argv[], int exitStat);
void forkExec(char *command, char *argv[]);
void printEnv(void);
ssize_t my_getline(int fd, char *line, size_t maxchar);
int valCmds(const char *command);

#define MAX_ARGS 20
#define MAX_COMMAND_LENGTH 1024
#define CONFIG_FILE "/usr/bin/ls"

extern char **environ;

#endif
