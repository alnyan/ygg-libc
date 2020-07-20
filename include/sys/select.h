#pragma once
#include <ygg/select.h>
#include <ygg/time.h>

int select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *xfds, struct timeval *tv);
