#include <assert.h>
#include <unistd.h>

int execvp(const char *file, char *const argv[]) {
    (void) file;
    (void) argv;
    // TODO: PATH search impl.
    assert(0 && "function not implemented");
}

