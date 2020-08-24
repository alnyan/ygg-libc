#include <time.h>

char *ctime(const time_t *timep) {
    char buf[64];
    return ctime_r(timep, buf);
}
