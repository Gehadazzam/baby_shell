#include "shell.h"


int main(int argc, char **argv) {
        char *prom = "baby_shell>>", *input = NULL, **new_argv = NULL;
        size_t length = 0;
        ssize_t count = 0;
        int i;
        (void) argv;
        if (argc == 1)
        {        while (1) {
                        printf("%s", prom);
                        count = getline(&input, &length, stdin);
                        if (count == EOF) {
                                free(input);
                                return (-1);
                        }
                        
                        new_argv = tokenize(input);
                        execution(new_argv, input);

                        for (i = 0; new_argv[i] != NULL; i++) {
                                free(new_argv[i]);
                        }
                        free(new_argv);
                }

                free(input);}
        else
                file_mode(argv[1]);
        return (0);
}

char **tokenize(char *input)
{
        char *token = NULL, *copy = NULL, **new_argv = NULL;
        int token_num = 0, i;

        copy = strdup(input);
        token = strtok(input, " \n");
        while (token != NULL) {
                token_num++;
                token = strtok(NULL, " \n");
        }
        new_argv = malloc(sizeof(char *) * (token_num + 1));
        if (new_argv == NULL) {
                perror("malloc");
                free(input);
                free(copy);
                return (0);
        }
        token = strtok(copy, " \n");
        for (i = 0; token != NULL; i++) {
                new_argv[i] = strdup(token);
                token = strtok(NULL, " \n");
        }
        new_argv[i] = NULL;
        free(copy);

        return (new_argv);
}