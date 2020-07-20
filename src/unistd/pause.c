#include <unistd.h>
#include <time.h>

int pause(void) {
    struct timespec ts;
    while (1) {
        ts.tv_sec = 1000000;
        ts.tv_nsec = 0;

        if (nanosleep(&ts, NULL) != 0) {
            return 0;
        }
    }
}
