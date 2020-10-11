#include <ygg/syscall.h>
#include <_libc/syscalls.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

ssize_t readlinkat(int dfd, const char *restrict pathname, char *restrict buf, size_t count) {
    return SET_ERRNO(ssize_t, __syscall4(SYSCALL_NR_READLINKAT, dfd, (long) pathname, (long) buf, count));
}
