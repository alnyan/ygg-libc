#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int faccessat(int dfd, const char *pathname, int mode, int flags) {
    return SET_ERRNO(int, __syscall4(SYSCALL_NR_FACCESSAT, dfd, (long) pathname, mode, flags));
}
