#include <ygg/syscall.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

int linkat(int olddfd, const char *old, int newdfd, const char *new, int flags) {
    (void) olddfd;
    (void) old;
    (void) newdfd;
    (void) new;
    (void) flags;
    assert(0 && "system call not yet implemented");
}

