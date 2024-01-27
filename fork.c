#include "shell.h"

void execution(char **cmd)
{
    int status;
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
        execvp(*cmd, cmd);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
        waitpid(proc_id, &status, 0);
}
