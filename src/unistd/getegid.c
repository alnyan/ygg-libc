#include <unistd.h>

gid_t getegid(void) {
    // TODO: differentiate between gid and egid
    return getgid();
}
