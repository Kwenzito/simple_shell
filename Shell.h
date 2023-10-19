#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

extern char **environ;

void print(const char *mystr);

int _strlen(char *s);

bool _strcmp(char *string, char *cstring);

int _atoi(char *str);

int is_delimeter(char c, char *delimeter);

char **_strtok(char *str, char *delimeter, size_t *no_args);

void  deallocate(char **ptr, int ptrlength);

void *_memcpy(void *dest, void *src, int n);

char *_strcat(char *a, char *b, char *c);

char *getCommand(char *buffer, size_t buffer_size);

char *searchFile(char *filepath, struct stat *statusBuffer);

bool fileFound(char *filepath, struct stat *statusBuffer);

void handleExit(char **exit_args, size_t no_of_args);

char *_getenv(char *key);

void handleEnvironmentVariables(char **env_args, size_t no_of_args);

void _printenv(void);

bool handleBuiltIn(char **args, size_t no_of_args, char *buffer);

int execute(char **args, int no_args);

void executeProgram(char **args, size_t no_of_args);

bool isCommandLineInput(void);

bool running(bool input);



#endif /* SHELL_H */
