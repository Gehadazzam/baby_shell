#include "shell.h"

struct alia aliases[MAX_ALIASES];
int aliases_counter = 0;

int i = 0;

void _alias(char **argv)
{
        char *token = NULL, *temp = NULL;

        if (argv[1] == NULL)
        {
                print_stored_aliases();
                return;
        }

        token = strtok(argv[1], "=");
        temp = token;
        token = strtok(NULL, "=");

        if (token != NULL)
        {
                define_alias(temp, token);
        }
        else
        {
                print_alias(temp);
        }
}

char **check_aliases(char **argv)
{
        for (i = 0; i < aliases_counter; i++)
        {
                if (strcmp(argv[0], aliases[i].name) == 0)
                {
                        argv[0] = aliases[i].value;
                        return (argv);
                }
        }
        
        return (argv);
}

void print_alias(char *name)
{
        for (i = 0; i < aliases_counter; i++)
        {
                if (strcmp(aliases[i].name, name) == 0)
                {
                        printf("%s='%s'\n", aliases[i].name, aliases[i].value);
                        return;
                }
        }
}

void define_alias(char *name, char *value)
{
        for (i = 0; i < aliases_counter; i++)
        {
                if (strcmp(aliases[i].name, name) == 0)
                {
                        free(aliases[i].value);
                        aliases[i].value = strdup(value);
                        return;
                }
        }

        if (aliases_counter < MAX_ALIASES)
        {
                aliases[aliases_counter].name = strdup(name);
                aliases[aliases_counter].value = strdup(value);
                aliases_counter++;
        }
        else
        {
                perror("Alias limit exceeded.");
        }
}

void print_stored_aliases()
{
        for (i = 0; i < aliases_counter; i++)
        {
                printf("%s=%s\n", aliases[i].name, aliases[i].value);
        }
}




                