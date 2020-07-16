#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/mman.h>
#include <errno.h>

void *mmap(void *hint, size_t length, int prot, int flags, int fd, off_t offset) {
    intptr_t res = (intptr_t) __syscall6(SYSCALL_NR_MMAP,
                                         (long) hint,
                                         length,
                                         (long) prot,
                                         (long) flags,
                                         (long) fd,
                                         offset);
    if (res < 0) {
        errno = (int) -res;
        return (void *) -1;
    } else {
        return (void *) res;
    }
}

int munmap(void *ptr, size_t len) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_MUNMAP, (long) ptr, len));
}
