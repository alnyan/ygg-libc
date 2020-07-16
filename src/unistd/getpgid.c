#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

pid_t getpgid(pid_t pid) {
    return SET_ERRNO(pid_t, __syscall1(SYSCALL_NR_GETPGID, pid));
}
