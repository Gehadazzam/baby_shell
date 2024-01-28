#include "shell.h"

int check_command(char **argv)
{
        if (strcmp(argv[0], "exit") == 0)
	{
		clean_and_exit(argv);
                return (1);
	}
        else if (strcmp(argv[0], "env") == 0)
        {
                print_environment();
                return (1);
        }
        return (0);
}

void clean_and_exit(char **argv)
{
        int i = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}

void print_environment()
{
        char **env = environ;

        while (*env != NULL) {
                printf("%s\n", *env);
                env++;
        }
}