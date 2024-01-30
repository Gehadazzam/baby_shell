
#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
extern char **environ;

#define MAX_ALIASES 100

struct alia
{
    char *name;
    char *value;
};

extern struct alia aliases[MAX_ALIASES];
extern int aliases_counter;

int check_command(char **argv, char *);
void print_environment();
void clean_and_exit(char **argv, char *);
void cat_file(char **argv);
void execution(char **cmd, char *);
void file_mode(char *);

/*alias.c*/
void _alias(char **argv);
void print_alias(char *name);
void define_alias(char *name, char *value);
void print_stored_aliases();
char **check_aliases(char **argv);

#endif
