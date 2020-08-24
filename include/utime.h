#pragma once
// TODO: #include <sys/types.h>!!!
#include <sys/time.h>

struct utimbuf {
    time_t actime;
    time_t modtime;
};

int utime(const char *filename, const struct utimbuf *times);
