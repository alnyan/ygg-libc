#include <sys/stat.h>
#include <assert.h>

mode_t umask(mode_t cmask) {
    (void) cmask;
    assert(0 && "Not implemented yet");
}
