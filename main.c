// main.c
#include "shell.h"

int main(int argc, char **argv)
{
        (void) argc, argv;
        char *prom = "baby_shell>>";
        size_t length = 0;
        ssize_t count = 0;


        while (1)
        {
                printf("%s", prom);
                count = getline(&input, &length, stdin);
                
        }


        return (0);
}
