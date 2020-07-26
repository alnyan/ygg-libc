#pragma once
#include <ygg/reboot.h>

int reboot(int magic, int magic2, unsigned int cmd, void *arg);
