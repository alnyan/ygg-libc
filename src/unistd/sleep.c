#include <unistd.h>

// TODO: time.h
struct timespec {
    uint64_t ts_sec;
    uint64_t ts_nsec;
};
extern int nanosleep(const struct timespec *ts, struct timespec *rem);

unsigned int sleep(unsigned int sec) {
    struct timespec ts;
    struct timespec rem;

    ts.ts_sec = sec;
    ts.ts_nsec = 0;

    if (nanosleep(&ts, &rem) != 0) {
        return rem.ts_sec;
    } else {
        return 0;
    }
}
