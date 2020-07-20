#include <time.h>

#define leap_days_to_1970           477

static inline int is_leap(int year) {
    return (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)));
}

static const int tab[] = {
    0, 3, 2, 5, 0, 3,
    5, 1, 4, 6, 2, 4
};

struct tm *gmtime_r(const time_t *restrict timep, struct tm *restrict tm) {
    if (!timep || !tm) {
        return NULL;
    }
    time_t t = *timep;

    time_t seconds_since_day = t % 86400;
    tm->tm_hour = seconds_since_day / 3600;
    tm->tm_min = (seconds_since_day / 60) % 60;
    tm->tm_sec = seconds_since_day % 60;

    // Number of days since 1970
    time_t z = t / 86400;

    // See http://howardhinnant.github.io/date_algorithms.html#civil_from_days
    z += 719468;
    int era = z / 146097;
    unsigned int doe = (unsigned int) (z - era * 146097);
    unsigned int yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
    int y = ((int) yoe) + era * 400;
    unsigned int doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    unsigned int mp = (5 * doy + 2) / 153;
    unsigned int d = doy - (153 * mp + 2) / 5 + 1;
    unsigned int m = mp + (mp < 10 ? 3 : -9);

    tm->tm_mday = d;
    tm->tm_mon = m;
    tm->tm_year = y + (m <= 2);
    tm->tm_yday = doy;
    tm->tm_wday = (y + y / 4 - y / 100 + y / 400 + tab[m - 1] + d - 1) % 7;

    return tm;
}
