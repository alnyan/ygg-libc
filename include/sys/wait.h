#pragma once
#include <ygg/types.h>
#include <ygg/wait.h>

pid_t waitpid(pid_t pid, int *status, int flags);
