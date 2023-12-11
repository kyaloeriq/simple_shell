#ifndef MAIN_H
#define MAIN_H

int prompt(char **command);
char *my_strdup(const char *s);
int execCmd(char *command, char *argv[]);
void forkExec(char *command, char *argv[]);
void printEnv();

#define MAX_ARGS 20
extern char **environ;

#endif
