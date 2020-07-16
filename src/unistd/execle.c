#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>

int execle(const char *pathname, const char *arg, ...) {
    va_list args;
    char *const *envp;
    size_t argc;
    int res;

    if (!arg) {
        va_start(args, arg);
        char *const *envp = va_arg(args, char *const *);
        va_end(args);

        return execve(pathname, (char *const *) &arg, envp);
    }

    // 1. collect arg count
    va_start(args, arg);
    while (va_arg(args, const char *)) {
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
    va_start(args, arg);
    for (size_t i = 0; i < argc; ++i) {
        argv[i] = va_arg(args, char *);
    }
    envp = va_arg(args, char *const *);
    va_end(args);
    argv[argc] = NULL;

    res = execve(pathname, argv, envp);

    // Won't return normally, so free()
    free(argv);

    return res;
}
