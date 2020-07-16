/*
 * Yggdrasil's signal implementation details
 */
#include <signal.h>
#include <stdlib.h>
#include <ygg/syscall.h>
#include <_libc/abort.h>
#include <_libc/signal.h>
#include <_libc/syscalls.h>

static sighandler_t signal_handlers[NSIG];

// _Noreturn because this function *must* end up
// calling sigreturn syscall
static _Noreturn void __libc_signal_handle(int signum) {
    if (signum <= 0 || signum >= NSIG) {
        // TODO: abort()
        exit(-1);
    }

    if (signal_handlers[signum]) {
        signal_handlers[signum](signum);
    } else {
        _sig_dfl(signum);
    }

    __syscall0(SYSCALL_NR_SIGRETURN);
    // To enforce _Noreturn
    while (1);
}

void __libc_signal_init(void) {
    stack_t ss;
    void *sig_stack;

    sig_stack = malloc(__LIBC_SIGNAL_STACK_SIZE);
    if (sig_stack == NULL) {
        __libc_abort_init("Failed to allocate signal stack");
    }

    // Tell kernel about signal stack
    ss.ss_sp = sig_stack;
    ss.ss_size = __LIBC_SIGNAL_STACK_SIZE;
    if (sigaltstack(&ss, NULL) != 0) {
        __libc_abort_init("Failed to set signal stack");
    }

    // Tell kernel about signal entry
    __syscall1(SYSCALL_NRX_SIGENTRY, (long) __libc_signal_handle);
}
