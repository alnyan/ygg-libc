#include <unistd.h>
#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <errno.h>

int access(const char *pathname, int mode) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_ACCESS, (long) pathname, mode));
}
