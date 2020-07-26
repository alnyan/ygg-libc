#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int truncate(const char *pathname, off_t size) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_TRUNCATE, (long) pathname, size));
}
