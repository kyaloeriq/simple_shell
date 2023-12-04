#ifndef MAIN_H
#define MAIN_H

int prompt(void);
char *my_strdup(const char *s);
void forkExec(char *exectble, char *argv[]);

#define MAX_ARGS 20

#endif
