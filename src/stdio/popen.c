#include <errno.h>
#include <stdio.h>

FILE *popen(const char *command, const char *mode) {
    (void) command;
    (void) mode;
    errno = EINVAL;
    return NULL;
}
