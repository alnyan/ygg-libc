#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/shm.h>
#include <errno.h>

int shmget(key_t key, size_t size, int flags) {
    (void) key;
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_SHMGET, size, flags));
}
