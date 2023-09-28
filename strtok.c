#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 64
#define TOKEN_DELIMITERS " \t\r\n\a"

int tokenize_input(char *input, char **tokens)
{
    int token_count = 0;
    char *token = strtok(input, TOKEN_DELIMITERS);

    while (token != NULL)
    {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, TOKEN_DELIMITERS);
    }

    tokens[token_count] = NULL;
    return token_count;
}
