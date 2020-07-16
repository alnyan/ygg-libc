#include <unistd.h>

uid_t geteuid(void) {
    // TODO: differentiate between uid and euid
    return getuid();
}
