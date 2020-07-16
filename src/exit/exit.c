#include <stdlib.h>

void exit(int status) {
    // TODO: call atexit()s here
    _Exit(status);
}
