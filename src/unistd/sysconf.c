#include <unistd.h>
#include <assert.h>

long sysconf(int name) {
    (void) name;
    assert(0 && "Not implemented");
}
