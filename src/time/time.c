#include <sys/time.h>
#include <time.h>

time_t time(time_t *t) {
    struct timeval now;
    if (gettimeofday(&now, NULL) != 0) {
        return -1;
    }
    return t ? *t = (time_t) now.tv_sec : (time_t) now.tv_sec;
}
