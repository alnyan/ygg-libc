#pragma once
#include <stdint.h>
#include <stddef.h>

void ygg_debug_trace(const char *msg, ...);
void ygg_msg_trace(const char *data, size_t lim);
int ygg_debug_instr(uint32_t cmd, void *arg0, void *arg1, void *arg2);
