#pragma once
#include <ygg/types.h>
#include <ygg/wait.h>

#define WIFEXITED(w)	(((w) & 0xff) == 0)
#define WIFSIGNALED(w)	(((w) & 0x7f) > 0 && (((w) & 0x7F) < 0x7F))
#define WIFSTOPPED(w)	(((w) & 0xff) == 0x7F)
#define WEXITSTATUS(w)	(((w) >> 8) & 0xFF)
#define WTERMSIG(w)	    ((w) & 0x7F)
#define WSTOPSIG	    WEXITSTATUS

pid_t waitpid(pid_t pid, int *status, int flags);
