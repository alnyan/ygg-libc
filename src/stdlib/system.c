#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int system_execute(char *const *argv) {
    int pid = fork();

    if (pid < 0) {
        return -1;
    }

    if (pid == 0) {
        _exit(execve(argv[0], argv, environ));
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

int system(const char *command) {
    char *s = strdup(command);
    size_t argc = 2;    // "sh" "-c"
    size_t argc_cap = 32;
    char *argv[32];
    argv[0] = "/bin/sh";
    argv[1] = "-c";
    char *token;
    char *saveptr = NULL;
    while (1) {
        token = strtok_r(s, " ", &saveptr);
        if (!token) {
            break;
        }
        if (argc == argc_cap) {
            // TODO: extend the buffer
            free(s);
            return -1;
        }
        argv[argc++] = token;
        s = NULL;
    }
    argv[argc] = NULL;

    int r = system_execute(argv);

    free(s);

    return r;
}
