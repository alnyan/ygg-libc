#pragma once
#include <sys/types.h>
#include <ygg/time.h>

#define CLOCKS_PER_SEC          1000000

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

clock_t clock(void);
time_t time(time_t *t);
double difftime(time_t t1, time_t t0);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

struct tm *gmtime_r(const time_t *restrict timep, struct tm *restrict res);
struct tm *gmtime(const time_t *timep);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *restrict timep, struct tm *restrict res);
time_t mktime(struct tm *tm);
size_t strftime(char *restrict buf, size_t lim, const char *restrict fmt, const struct tm *restrict tm);
