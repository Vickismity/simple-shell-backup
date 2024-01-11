#include "shell.h"

void builtin_cd(char *args)
{
	char *home = getenv("HOME");
	
	if (args == NULL)
	{
		if (home == NULL)
			perror("Error");
		else
		{
			if (chdir(home) != 0)
			{
				perror("Error: could not change directory");
			}
		}
	}
	else 
	{
		if (chdir(args) != 0)
			perror("Error: could not change directory");
	}
}

void builtin_exit(void)
{
	exit(0);
}
