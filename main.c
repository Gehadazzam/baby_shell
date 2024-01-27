// main.c
#include "shell.h"

int main(int argc, char **argv)
{
        (void) argc, argv;
        char *prom = "baby_shell>>", *input = NULL, *token = NULL;
        size_t length = 0;
        ssize_t count = 0;


        while (1)
        {
                printf("%s", prom);
                count = getline(&input, &length, stdin);
                if (count == EOF)
                {
                        free(input);
                        break;
                }
                
                token = _strtok(input, ' \n');
                while (token != NULL)
                {
                        printf ("%s\n", token);
                        token = _strtok(NULL, ' \n');
                }
        }


        return (0);
}