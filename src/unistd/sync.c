#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

void sync(void) {
    __syscall0(SYSCALL_NR_SYNC);
}
