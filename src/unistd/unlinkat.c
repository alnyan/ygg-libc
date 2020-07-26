#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int unlinkat(int dfd, const char *pathname, int flags) {
    return SET_ERRNO(int, __syscall3(SYSCALL_NR_UNLINKAT, dfd, (long) pathname, flags));
}
