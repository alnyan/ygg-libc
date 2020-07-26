#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/mman.h>
#include <errno.h>

int munmap(void *ptr, size_t len) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NR_MUNMAP, (long) ptr, len));
}
