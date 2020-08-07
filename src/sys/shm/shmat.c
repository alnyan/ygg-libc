#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/shm.h>
#include <stdint.h>
#include <errno.h>

void *shmat(int id, const void *hint, int flags) {
    intptr_t res = (intptr_t) __syscall3(SYSCALL_NR_SHMAT,
                                         id,
                                         (long) hint,
                                         flags);
    if (res < 0) {
        errno = (int) -res;
        return (void *) -1;
    } else {
        return (void *) res;
    }
}
