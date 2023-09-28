#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "prompt.c"
#include "strfun.c"
#include "getline.c"
#include "strtok.c"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execute_command(char **tokens)
{
	pid_t pid = fork();
	int status;

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execvp(tokens[0], tokens);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

void start_shell()
{
    char input[MAX_INPUT_LENGTH];
    char *tokens[MAX_TOKENS];
    int token_count;

    while (1) {
        display_prompt();

        if (!get_input(input))
	{
            break;
        }

        trim_whitespace(input);
        token_count = tokenize_input(input, tokens);

        if (token_count > 0)
	{
            execute_command(tokens);
        }
    }
}
