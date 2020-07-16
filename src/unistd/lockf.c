#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int lockf(int fd, int cmd, off_t len) {
    (void) fd;
    (void) cmd;
    (void) len;
    assert(0 && "system call not yet implemented");
}
