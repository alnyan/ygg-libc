#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence) {
    return SET_ERRNO(off_t, __syscall3(SYSCALL_NR_LSEEK, fd, offset, whence));
}

