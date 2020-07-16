#include <assert.h>
#include <unistd.h>

int execlp(const char *file, const char *arg, ...) {
    (void) file;
    (void) arg;
    // TODO: PATH search impl.
    assert(0 && "function not implemented");
}

