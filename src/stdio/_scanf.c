#include <_libc/stdio.h>
#include <stdio.h>

int __libc_vscanf(const char *format,
                  void *ctx,
                  int (*in)(void *ctx),
                  va_list ap) {
    (void) format;
    (void) ctx;
    (void) in;
    (void) ap;
    return -1;
}
