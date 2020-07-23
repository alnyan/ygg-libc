#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>

int execl(const char *pathname, const char *arg, ...) {
    va_list args;
    size_t argc = 1;
    int res;

    if (!arg) {
        // execv pathname without arguments
        return execv(pathname, (char *const *) &arg);
    }

    // 1. collect arg count
    va_start(args, arg);
    while (va_arg(args, const char *) != NULL) {
        ++argc;
    }
    va_end(args);

    // 2. allocate space for args
    char **argv = malloc(sizeof(char *) * (argc + 1));
    if (!argv) {
        errno = ENOMEM;
        return -1;
    }

    // 3. copy args
    argv[0] = (char *) arg;
    va_start(args, arg);
    for (size_t i = 0; i < argc; ++i) {
        argv[i + 1] = va_arg(args, char *);
    }
    va_end(args);
    argv[argc] = NULL;

    res = execv(pathname, argv);

    // Won't return normally, so free()
    free(argv);

    return res;
}
