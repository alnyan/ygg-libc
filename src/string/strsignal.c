#include <ygg/signum.h>
#include <string.h>

static const char *signal0[NSIG] = {
    [SIGHUP]    = "Hangup",
    [SIGINT]    = "Interrupt",
    [SIGQUIT]   = "Quit",
    [SIGILL]    = "Illegal instruction",
    [SIGTRAP]   = "Trace/breakpoint trap",
    [SIGABRT]   = "Abort",
    [SIGBUS]    = "Bus error",
    [SIGFPE]    = "Floating point exception",
    [SIGKILL]   = "Killed",
    [SIGUSR1]   = "User signal 1",
    [SIGSEGV]   = "Segmentation fault",
    [SIGUSR2]   = "User signal 2",
    [SIGPIPE]   = "Broken pipe",
    [SIGALRM]   = "Alarm clock",
    [SIGTERM]   = "Terminated",
    [SIGSYS]    = "Invalid system call",
    [SIGCHLD]   = "Child exited",
    [SIGCONT]   = "Continued",
    [SIGSTOP]   = "Stopped",
    [SIGTSTP]   = "Terminal stop",
    [SIGTTIN]   = "Stopped (tty input)",
    [SIGTTOU]   = "Stopped (tty output)",
    [SIGURG]    = "Urgent I/O condition",
    [SIGPWR]    = "Power fault",
    [SIGWINCH]  = "Window size changed"
};

char *strsignal(int signum) {
    if (signum <= 0 || signum >= NSIG) {
        return "unknown signal";
    }
    return (char *) signal0[signum];
}
