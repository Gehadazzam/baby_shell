#include "shell.h"

void execution(char *cmd)
{
    char *argv[4];
    pid_t proc_id = fork();

    /*if fork process failed*/
    if (proc_id == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    /*if fork process successful*/
    else if (proc_id == 0)
    {
        argv[0] = "/bin/sh";
        argv[1] = "-c";
        argv[2] = cmd;
        argv[3] = NULL;
        execvp(argv[0], argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}
