#pragma once
#include <ygg/signum.h>
#include <ygg/types.h>

#define SIG_DFL         _sig_dfl
#define SIG_ERR         ((sighandler_t) -1)
#define SIG_HOLD        _sig_hold
#define SIG_IGN         _sig_ign

typedef void (*sighandler_t) (int);

extern void _sig_dfl(int signum);
extern void _sig_hold(int signum);
extern void _sig_ign(int signum);

sighandler_t signal(int signum, sighandler_t handler);
int sigaltstack(const stack_t *ss, stack_t *old_ss);

int kill(pid_t pid, int sig);
