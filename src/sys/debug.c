#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>

void ygg_msg_trace(const char *msg, size_t lim) {
    __syscall2(SYSCALL_NRX_TRACE, (long) msg, lim);
}

void ygg_debug_trace(const char *fmt, ...) {
    char buf[512];
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    if (len >= 0) {
        ygg_msg_trace(buf, len);
    }
}
