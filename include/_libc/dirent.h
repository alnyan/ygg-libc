#pragma once
#include <ygg/dirent.h>

struct __DIR {
    int fd;
    union {
        struct dirent buf;
        char __data[512];
    };
};
