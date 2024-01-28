#include "shell.h"

int check_command(char **argv, char *input)
{
        if (strcmp(argv[0], "exit") == 0)
	{
		clean_and_exit(argv, input);
                exit (0);
	}
        else if (strcmp(argv[0], "env") == 0)
        {
                print_environment();
                return (1);
        }
        else if (strcmp(argv[0], "cd") == 0)
        {
                chdir(argv[1]);
                return(1);
        }
        return (0);
}

void clean_and_exit(char **argv, char *input)
{
        int i = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
        free(input);
}

void print_environment()
{
        char **env = environ;

        while (*env != NULL) {
                printf("%s\n", *env);
                env++;
        }
}