#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <signal.h>
#include <errno.h>

int kill(pid_t pid, int signum) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_KILL, pid, signum));
}
