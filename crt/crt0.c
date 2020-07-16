#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <_libc/stdio.h>
#include <_libc/signal.h>

// XXX: envp
extern int main(int argc, char **argv);

extern char **environ;

void _start(void *_arg) {
    uintptr_t arg = (uintptr_t) _arg;
    // arg: argp page number << 24 | 12 bit page count << 12 | 12 bit argc
    char **argp = (char **) ((arg >> 12) & ~0xFFF);
    int argc = arg & 0xFFF;
    //__libc_vecp_pages = (arg >> 12) & 0xFFF;

    // TODO: better handling for this
    environ = &argp[argc + 1];

    __libc_signal_init();

    fwrite("Test\n", 1, 5, stdout);

    exit(main(argc, argp));
}
