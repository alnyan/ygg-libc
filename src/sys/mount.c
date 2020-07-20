#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/mount.h>
#include <errno.h>

int mount(const char *src, const char *dst, const char *fs, unsigned long flags, void *data) {
    return SET_ERRNO(int, __syscall5(SYSCALL_NR_MOUNT,
                                     (long) src,
                                     (long) dst,
                                     (long) fs,
                                     flags,
                                     (long) data));
}
