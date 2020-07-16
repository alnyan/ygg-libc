// TODO: move to a proper place once I do abort()
#include <assert.h>
#include <string.h>
#include <unistd.h>

_Noreturn void _assert_fail(const char *func, const char *msg) {
    static const char msg0[] = "In function `";
    static const char msg1[] = "':\n";
    write(STDERR_FILENO, msg0, sizeof(msg0) - 1);
    write(STDERR_FILENO, func, strlen(func));
    write(STDERR_FILENO, msg1, sizeof(msg1) - 1);
    write(STDERR_FILENO, msg, strlen(msg));
    write(STDERR_FILENO, msg1 + 2, 1);

    _exit(-1);
}
