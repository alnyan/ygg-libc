#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_EXECVE, (long) pathname, (long) argv, (long) envp));
}
