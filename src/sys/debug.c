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

int ygg_debug_instr(uint32_t cmd, void *arg0, void *arg1, void *arg2) {
    return SET_ERRNO(int, __syscall4(SYSCALL_NRX_INSTR, cmd, (long) arg0, (long) arg1, (long) arg2));
}
