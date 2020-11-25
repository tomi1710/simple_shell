#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;
char **_getinput(char *input, size_t size);
char *_strcpy(char *dest, const char *src);
char *_strcon(char *dest, char *src);
int _strcmp(char *src1, char *src2);
int _strlen(char *str);
char *checkexec(char *file);
void freetokens(char **tokens, int a);

#endif /* SHELL_H */
