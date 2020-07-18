#include <assert.h>
#include <stdio.h>

int renameat(int olddfd, const char *old, int newdfd, const char *new) {
    (void) olddfd;
    (void) newdfd;
    (void) old;
    (void) new;
    assert(0 && "System call not yet implemented");
}
