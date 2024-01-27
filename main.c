#include "shell.h"

int main(int argc, char **argv)
{
        char *prom = "baby_shell>>", *input = NULL, *token = NULL, *copy = NULL;
        size_t length = 0;
        ssize_t count = 0;
        int token_num = 0, i;
        (void) argc;

        while (1)
        {
                printf("%s", prom);
                count = getline(&input, &length, stdin);
                if (count == EOF)
                {
                        free(input);
                        break;
                }
                copy = strdup(input);
                token = strtok(input, " \n");
                while (token != NULL)
                {
                        token_num++;
                        token = strtok(NULL, " \n");
                }
                argv = malloc(sizeof(char) * token_num + 1);
                if (argv == NULL)
                {
                        /*perror memorey allocate*/
                        free(input);
                        free(copy);
                        return (0);
                }
                token = strtok(copy, " \n");
                for (i = 0; token != NULL; i++)
                {
                        argv[i] = strdup(token);
                        token = strtok(NULL, " \n");
                }
                argv[i] = NULL;
                    execution(argv);

        }

        free (input);

        return (0);
}