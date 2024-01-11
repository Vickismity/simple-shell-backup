#include "shell.h"

extern char **environ;

int main(void)
{
        size_t buffsize = 0;
        char *buff = NULL;
        char *token;
        int i = 0;
        char **array;
        pid_t child_pid;
        int status;
        char *cmdPath = get_path(array[0]);

        while (1)
        {
                write(1, "#cisfun$ ", 10);
                getline(&buff, &buffsize, stdin);

                token = strtok(buff, " \t\n");
                array = malloc(sizeof(char *) * 1024);

                while (token)
                {
                        array[i] = token;
                        token = strtok(NULL, " \t\n");
                        i++;
                }
                array[i] = NULL;
                child_pid = fork();
                if (child_pid == -1)
		{
                        perror("Error:");
                        return (1);
                }

                if (child_pid == 0 && cmdPath != NULL)
                {
                        if (execve(cmdPath, array, environ) == -1)
                                perror("Error");

                }
                else
                        wait(&status);
                i = 0;
                free(array);

        }

        return (0);
}
