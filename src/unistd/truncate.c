#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int truncate(const char *pathname, off_t size) {
    (void) pathname;
    (void) size;
    assert(0 && "system call not yet implemented");
}
