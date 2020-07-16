#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

uid_t getuid(void) {
    return __syscall0(SYSCALL_NR_GETUID);
}
