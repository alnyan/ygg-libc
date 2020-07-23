#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int system(const char *command) {
    int pid = fork();

    if (pid < 0) {
        return -1;
    }

    if (pid == 0) {
        _exit(execl("/bin/sh", "sh", "-c", command, NULL));
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}
