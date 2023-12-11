#ifndef MAIN_H
#define MAIN_H

void prompt(char **command);
char *my_strdup(const char *s);
void exec(char *command, char *argv[]);
void fork(char *command, char *argv[]);
void printEnv();

#define MAX_ARGS 20
extern char **environ;

#endif
