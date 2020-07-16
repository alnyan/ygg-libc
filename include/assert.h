#pragma once

#define _assert_stringify_line(x) #x
#define _assert_line(x) _assert_stringify_line(x)
#if !defined(NDEBUG)
#define assert(c) \
    if (!(c)) { _assert_fail(__func__, __FILE__ ":" _assert_line(__LINE__) ": Assertion `" #c "' failed." ); }
#else
#define assert(c)
#endif

_Noreturn void _assert_fail(const char *func, const char *msg);
