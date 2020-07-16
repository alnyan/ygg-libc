#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

gid_t getgid(void) {
    return __syscall0(SYSCALL_NR_GETGID);
}
