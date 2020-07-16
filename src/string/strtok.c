#include <string.h>

char *strtok_r(char *str, const char *delim, char **saveptr) {
    char *token;

    if (!str) {
        str = *saveptr;
    }

    // Skip leading delimiter
    str += strspn(str, delim);
    if (!*str) {
        *saveptr = str;
        // No next token - NULL
        return NULL;
    }

    token = str;
    str = strpbrk(str, delim);
    if (str) {
        // Have a delimiter
        *str = 0;
        *saveptr = str + 1;
    } else {
        // Point to end
        *saveptr = token + strlen(token);
    }
    return token;
}

// TODO: throw an error "programmer" for using this
char *strtok(char *str, const char *delim) {
    static char *saveptr;
    if (str) {
        saveptr = NULL;
    }
    return strtok_r(str, delim, &saveptr);
}
