#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/wait.h>
#include <errno.h>

pid_t waitpid(pid_t pid, int *status, int opt) {
    return SET_ERRNO(pid_t, __syscall3(SYSCALL_NRX_WAITPID, pid, (long) status, opt));
}
