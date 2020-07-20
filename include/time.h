#pragma once
#include <ygg/time.h>

int nanosleep(const struct timespec *restrict ts, struct timespec *restrict rem);
