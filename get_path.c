#include "shell.h"

char *get_path(char *command)
{
        char *path = getenv("PATH");
        char *pathcpy = strdup(path);
        char command_path[1024];
        char *directory = strtok(pathcpy, ":");

        while (directory != NULL)
        {
                strcpy(command_path, directory);

                if (command_path[strlen(command_path) - 1] != '/')
                {
                        strcat(command_path, "/");
                }

                strcat(command_path, command);

                if (access(command_path, F_OK) == 0 && access(command_path, X_OK) == 0)
                {
                        free(pathcpy);
                        return (strdup(command_path));
                }

                directory = strtok(NULL, ":");
        }
        free(pathcpy);
        return NULL;
}
