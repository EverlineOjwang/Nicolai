#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void run_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	char *args[] = {"/bin/sh", "-c", command, NULL};
	execvp("/bin/sh", args);
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	else
	{
	int status;
	waitpid(pid, &status, 0);
	}
}
int main()
{
	char input[MAX_INPUT_LENGTH];
	
	while (1)
	{
        printf("$ ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{
            break;
        }
        input[strlen(input) - 1] = '\0';
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0)
	{
            break;
        }

        run_command(input);
    }

    return 0;
}
