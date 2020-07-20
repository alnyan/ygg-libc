#pragma once
#include <ygg/types.h>
#include <ygg/time.h>

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

int nanosleep(const struct timespec *restrict ts, struct timespec *restrict rem);

struct tm *gmtime_r(const time_t *restrict timep, struct tm *restrict res);
size_t strftime(char *restrict buf, size_t lim, const char *restrict fmt, const struct tm *restrict tm);
