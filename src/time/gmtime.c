#include <time.h>

struct tm *gmtime(const time_t *timep) {
    static struct tm _buf;
    return gmtime_r(timep, &_buf);
}
