#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int link(const char *old, const char *new) {
    (void) old;
    (void) new;
    assert(0 && "system call not yet implemented");
}

