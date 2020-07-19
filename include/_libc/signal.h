#pragma once
#include <signal.h>
#define __LIBC_SIGNAL_STACK_SIZE        4096

sighandler_t __libc_signal(int signum, sighandler_t h);
void __libc_signal_init(void);
