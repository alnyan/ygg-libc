#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int open(const char *pathname, int flags, mode_t mode) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_OPEN, (long) pathname, flags, mode));
}
