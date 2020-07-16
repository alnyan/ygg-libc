#include <ygg/signum.h>
#include <string.h>

static const char *signal0[NSIG] = {
};

char *strsignal(int signum) {
    if (signum <= 0 || signum >= NSIG) {
        return "unknown signal";
    }
    return (char *) signal0[signum];
}
