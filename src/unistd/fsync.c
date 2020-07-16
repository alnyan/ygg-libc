#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <unistd.h>
#include <errno.h>

int fsync(int fd) {
    (void) fd;
    // FS is synchronous lol
    return 0;
}

