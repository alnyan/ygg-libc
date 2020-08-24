#include <assert.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, ...) {
    return 0;
    (void) fd;
    (void) cmd;
    assert(0 && "Not implemented yet");
}
