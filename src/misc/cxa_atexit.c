#include <sys/debug.h>

int __cxa_atexit(void (*func) (void *), void *ctx, void *dso) {
    // TODO: implement this
    (void) func;
    (void) ctx;
    (void) dso;
    ygg_debug_trace("__cxa_atexit: unimplemented\n");
    return 0;
}
