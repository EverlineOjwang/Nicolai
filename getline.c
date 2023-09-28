#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int get_input(char *input)
{
    if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
    {
        return 0;
    }
    input[strlen(input) - 1] = '\0';
    return 1;
}
