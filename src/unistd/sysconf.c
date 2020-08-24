#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

long sysconf(int name) {
    switch (name) {
    case _SC_OPEN_MAX:
        return 16;
    default:
        fprintf(stderr, "Unknown sysconf(): %d\n", name);
        abort();
    }
}
