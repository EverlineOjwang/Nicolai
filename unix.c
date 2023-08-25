#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 10

void execute_command(char *args[]) {
    pid_t pid = fork();
    
    if (pid == 0) {
        execvp(args[0], args);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        perror("Fork failed");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *token;
    char *args[MAX_ARGS + 1];
    int i = 0;
   
    while (1) {
        printf("#cisfun$ ");
	if (!fgets(input, sizeof(input), stdin)) {
            printf("\n");
            break;
	    
        }
	input[strcspn(input, "\n")] = '\0';
	 if (strlen(input) > 0) {
		 token = strtok(input, " ");

	while (token != NULL && i < MAX_ARGS)
	{
	args[i++] = token;
	token = strtok(NULL, " ");
	}
	args[i] = NULL;
	if (strcmp(args[0], "exit") == 0) {
		break;
	}
	else if (strcmp(args[0], "ls") == 0) {
		args[0] = "/bin/ls";
	}
        
        execute_command(args);
    }
    }    
    return 0;
}
