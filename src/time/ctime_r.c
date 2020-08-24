#include <time.h>

char *ctime_r(const time_t *timep, char *buf) {
    if (!timep) {
        return NULL;
    }
    struct tm tm;
    if (gmtime_r(timep, &tm) != 0) {
        return NULL;
    }
    strftime(buf, 64, "%c", &tm);
    return buf;
}
