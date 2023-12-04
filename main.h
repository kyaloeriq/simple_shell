#ifndef MAIN_H
#define MAIN_H

void execCmd(char *command);
int prompt(void);
char *my_strdup(const char *s);
void forkExec(char *exectble, char *argv[]);

#endif
