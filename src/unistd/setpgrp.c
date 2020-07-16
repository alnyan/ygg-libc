#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>

pid_t setpgrp(void) {
    pid_t pid = getpid();
    setpgid(0, 0);
    return pid;
}
