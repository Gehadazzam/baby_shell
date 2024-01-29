#include "shell.h"
void file_mode(char *filename)
{
    size_t length;
    char cmd[100];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("open");
        return;
    }
    /*reading everyline from the file*/
    while (fgets(cmd, 100, file) != NULL)
    {   
        length = strlen(cmd);
        if (length > 0 && cmd[length - 1] == '\n') 
        {
            cmd[length - 1] = '\0';
        }
    /*use system fuction to execute the command*/
  system(cmd);
 }
 fclose(file);
}
