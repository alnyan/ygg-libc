#include <_libc/signal.h>
#include <sys/debug.h>
#include <unistd.h>
#include <stdlib.h>

void _sig_dfl(int signum) {
    ygg_debug_trace("\033[41mKilled by signal %d\033[0m\n", signum);
    exit((signum << 8) | signum);
}

void _sig_ign(int signum) {
    exit((signum << 8) | signum);
}
