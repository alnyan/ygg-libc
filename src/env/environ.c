#include <_libc/environ.h>

static char *dummy[] = { NULL };
char **environ = (char **) &dummy;
// argv/envp pages provided by the kernel
size_t __libc_orig_argp_count;
uintptr_t __libc_orig_argp_base;
