#pragma once
#include <sys/types.h>
#include <bits/attr.h>
#include <ygg/time.h>

#if defined(__cplusplus)
extern "C" {
#endif

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

int nanosleep(const struct timespec *__Restrict ts, struct timespec *__Restrict rem);

clock_t clock(void);
time_t time(time_t *t);
double difftime(time_t t1, time_t t0);

char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);

struct tm *gmtime_r(const time_t *__Restrict timep, struct tm *__Restrict res);
struct tm *gmtime(const time_t *timep);

struct tm *localtime(const time_t *timep);
struct tm *localtime_r(const time_t *__Restrict timep, struct tm *__Restrict res);
time_t mktime(struct tm *tm);
size_t strftime(char *__Restrict buf, size_t lim, const char *__Restrict fmt, const struct tm *__Restrict tm);

#if defined(__cplusplus)
}
#endif
