#include <unistd.h>
#include <string.h>
#include <_libc/abort.h>

_Noreturn void __libc_abort_init(const char *reason) {
    static const char prefix[] = "libc abort: ";
    char ln = '\n';
    write(STDERR_FILENO, prefix, sizeof(prefix) - 1);
    write(STDERR_FILENO, reason, strlen(reason));
    write(STDERR_FILENO, &ln, 1);
    _exit(-1);
}
