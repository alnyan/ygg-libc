#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int sec) {
    struct timespec ts;
    struct timespec rem;

    ts.tv_sec = sec;
    ts.tv_nsec = 0;

    if (nanosleep(&ts, &rem) != 0) {
        return rem.tv_sec;
    } else {
        return 0;
    }
}
