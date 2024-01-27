#include "shell.h"


int main(int argc, char **argv) {
    char *prom = "baby_shell>>", *input = NULL, *token = NULL, *copy = NULL, **new_argv = NULL;
    size_t length = 0;
    ssize_t count = 0;
    int token_num = 0, i;
    (void) argc;

    while (1) {
        printf("%s", prom);
        count = getline(&input, &length, stdin);
        if (count == EOF) {
            free(input);
            free(copy);
            return (-1);
        }
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

        for (i = 0; new_argv[i] != NULL; i++) {
            free(argv[i]);
            argv[i] = strdup(new_argv[i]);
        }
        argv[i] = NULL;

        execution(new_argv);

        
        for (i = 0; new_argv[i] != NULL; i++) {
            free(new_argv[i]);
        }
        free(new_argv);


        free(copy);
    }

    free(input);
    return (0);
}
