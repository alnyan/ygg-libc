#include <unistd.h>

int getgroups(int size, gid_t list[]) {
    (void) size;
    (void) list;
    // TODO: supplementary groups
    return 0;
}
