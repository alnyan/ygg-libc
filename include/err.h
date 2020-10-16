#pragma once
#include <stdarg.h>

void err(int eval, const char *fmt, ...);
void errx(int eval, const char *fmt, ...);
void warn(const char *fmt, ...);
void vwarn(const char *fmt, va_list args);
