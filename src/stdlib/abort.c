#include <signal.h>
#include <stdlib.h>

_Noreturn void abort(void) {
    kill(0, SIGABRT);
    // Still alive
    signal(SIGABRT, SIG_DFL);
    kill(0, SIGABRT);
    while (1);
}
