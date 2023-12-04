#ifndef MAIN_H
#define MAIN_H

void prompt(char **command);
char *my_strdup(const char *s);
void forkExec(char *exectble, char *argv[]);

#define MAX_ARGS 20
extern char **environ;

#endif
