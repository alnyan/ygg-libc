#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

ssize_t readlink(const char *restrict pathname, char *restrict buf, size_t count) {
    (void) pathname;
    (void) buf;
    (void) count;
    assert(0 && "system call not yet implemented");
}
