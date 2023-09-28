#include <string.h>
#include <ctype.h>
#include "shell.h"

void trim_whitespace(char *str) {
    int len = strlen(str);
    int start = 0, end = len - 1;

    while (isspace(str[start])) {
        start++;
    }
    while ((end >= start) && isspace(str[end])) {
        end--;
    }

    for (int i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[end - start + 1] = '\0';
}
