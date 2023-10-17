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

void print(const char *mystr);

int _strlen(char *s);

bool _strcmp(char *string, char *cstring);

char *_strconcat(char *s1, char *s2);

int _atoi(char *str);

int is_delimeter(char c, char *delimeter);

char **_strtok(char *str, char *delimeter, size_t *no_args);


#endif /* SHELL_H */
