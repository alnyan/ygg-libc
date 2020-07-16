#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int setpgid(pid_t pid, pid_t pgid) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_SETPGID, pid, pgid));
}
