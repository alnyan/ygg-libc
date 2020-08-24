#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/mod.h>
#include <errno.h>

int ygg_module_load(const char *filename, const char *arg) {
    return SET_ERRNO(int, __syscall2(SYSCALL_NRX_MODULE_LOAD, (long) filename, (long) arg));
}
