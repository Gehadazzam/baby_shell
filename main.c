
#include "shell.h"

int main(int argc, char **argv)
{
        
        char *prom = "baby_shell>>", *input = NULL, *token = NULL;
        size_t length = 0;
        ssize_t count = 0;
        (void) (argc), (void) (argv);

        while (1)
        {
                printf("%s", prom);
                count = getline(&input, &length, stdin);
                if (count == EOF)
                {
                        free(input);
                        break;
                }
                
                token = strtok(input, " \n");
                while (token != NULL)
                {
                        printf ("%s\n", token);
                        token = strtok(NULL, " \n");
                }
        }


        return (0);
}