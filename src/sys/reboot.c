#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/reboot.h>
#include <errno.h>

int reboot(int magic, int magic2, unsigned int cmd, void *arg) {
    return SET_ERRNO(int, __syscall4(SYSCALL_NR_REBOOT, magic, magic2, cmd, (long) arg));
}
