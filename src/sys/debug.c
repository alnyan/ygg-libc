#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdarg.h>
#include <errno.h>

void ygg_debug_trace(const char *fmt, ...) {
    uintptr_t a0, a1, a2, a3, a4;
    va_list args;
    va_start(args, fmt);
    a0 = va_arg(args, uintptr_t);
    a1 = va_arg(args, uintptr_t);
    a2 = va_arg(args, uintptr_t);
    a3 = va_arg(args, uintptr_t);
    a4 = va_arg(args, uintptr_t);
    va_end(args);
    __syscall6(SYSCALL_NRX_TRACE, (long) fmt, a0, a1, a2, a3, a4);
}
