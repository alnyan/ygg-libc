#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int ftruncate(int fd, off_t size) {
    (void) fd;
    (void) size;
    assert(0 && "system call not yet implemented");
}


