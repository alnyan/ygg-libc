#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

ssize_t pread(int fd, void *buf, size_t count, off_t offset) {
    (void) fd;
    (void) buf;
    (void) offset;
    (void) count;
    assert(0 && "system call not yet implemented");
}
