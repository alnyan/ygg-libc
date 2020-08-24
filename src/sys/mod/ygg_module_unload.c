#include <_libc/syscalls.h>
#include <ygg/syscall.h>
#include <sys/mod.h>
#include <errno.h>

int ygg_module_unload(const char *name) {
    return SET_ERRNO(int, __syscall1(SYSCALL_NRX_MODULE_UNLOAD, (long) name));
}

