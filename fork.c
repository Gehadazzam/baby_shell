#include "shell.h"

void execution(char **cmd, char *input)
{
    int status;
    pid_t proc_id;

    if (check_command(cmd, input) == 1)
    {
            return;
    }
    proc_id = fork();
    /*if fork process failed*/
    if (proc_id == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    /*if fork process successful*/
    else if (proc_id == 0)
    {
        cmd = check_aliases(cmd);
        execvp(*cmd, cmd);
        clean_and_exit(cmd, input);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
        waitpid(proc_id, &status, 0);
}
