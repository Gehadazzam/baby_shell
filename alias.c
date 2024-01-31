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
                if (token[0] == '\'' || token[0] == '\"')
                {
                        memmove(token, token + 1, strlen(token) - 2);
                        token[strlen(token) - 2] = '\0';
                }
                define_alias(temp, token);
        }
        else
        {
                print_alias(temp);
        }
}


char **check_aliases(char **argv)
{
        int j = 0;

        for (i = 0; i < aliases_counter; i++)
        {
                if (strcmp(argv[0], aliases[i].name) == 0)
                {
                        while (aliases[i].value[j] != NULL)
                        {
                                argv[j] = aliases[i].value[j];
                                j++;
                        }
                        argv[j] = NULL;
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
                        printf("%s='%s %s'\n", aliases[i].name, aliases[i].value[0], aliases[i].value[1]);
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
                        aliases[i].value = tokenize(value);
                        return;
                }
        }

        if (aliases_counter < MAX_ALIASES)
        {
                aliases[aliases_counter].name = strdup(name);
                aliases[aliases_counter].value = tokenize(value);
                aliases_counter++;
        }
        else
        {
                perror("Alias limit exceeded.");
        }
}

void print_stored_aliases()
{
        int j, count = 0;

        
        for (i = 0; i < aliases_counter; i++)
        {
                printf("%s=", aliases[i].name);
                while (aliases[i].value[j] != NULL)
                {
                        count++;
                        j++;
                }
                for (j = 0; j < count; j++)
                {
                        printf("%s ", aliases[i].value[j]);
                }
                printf("\n");
        }
}




                