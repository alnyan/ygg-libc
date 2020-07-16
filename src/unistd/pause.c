#include <unistd.h>

// TODO: time.h
struct timespec {
    uint64_t ts_sec;
    uint64_t ts_nsec;
};
extern int nanosleep(const struct timespec *ts, struct timespec *rem);

int pause(void) {
    struct timespec ts;
    while (1) {
        ts.ts_sec = 1000000;
        ts.ts_nsec = 0;

        if (nanosleep(&ts, NULL) != 0) {
            return 0;
        }
    }
}
