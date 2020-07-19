#include <_libc/signal.h>

sighandler_t signal(int signum, sighandler_t s) {
    return __libc_signal(signum, s);
}
