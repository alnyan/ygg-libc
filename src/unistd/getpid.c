#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

pid_t getpid(void) {
    return (pid_t) __syscall0(SYSCALL_NR_GETPID);
}
