#include <stdlib.h>
#include <_libc/signal.h>

void _sig_dfl(int signum) {
    exit(signum << 8);
}
