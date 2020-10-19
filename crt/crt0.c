#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <_libc/stdio.h>
#include <_libc/signal.h>

// XXX: envp
extern int main(int argc, char **argv);

extern char **environ;
extern uintptr_t __libc_orig_argp_base;
extern size_t __libc_orig_argp_count;

extern uintptr_t __init_array_start;
extern uintptr_t __init_array_end;

static void call_constructors(void) {
    size_t init_array_size = ((void *) &__init_array_end - (void *) &__init_array_start) / sizeof(uintptr_t);
    for (size_t i = 0; i < init_array_size; ++i) {
        uintptr_t entry = (&__init_array_start)[i];
        ((void(*)(void)) entry)();
    }
}

void _start(void *_arg) {
    uintptr_t arg = (uintptr_t) _arg;
    // arg: argp page number << 24 | 12 bit page count << 12 | 12 bit argc
    char **argp = (char **) ((arg >> 12) & ~0xFFF);
    int argc = arg & 0xFFF;

    __libc_orig_argp_count = (arg >> 12) & 0xFFF;
    __libc_orig_argp_base = (uintptr_t) argp;

    environ = &argp[argc + 1];

    __libc_signal_init();

    extern void _init(void);
    _init();

    call_constructors();

    exit(main(argc, argp));
}
