
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

int check_command(char **argv);
void print_environment();
void clean_and_exit(char **argv);

void execution(char **cmd);

#endif
