#pragma once

#define __Malloc __attribute__((malloc))

#if defined(__cplusplus)
#define __Noreturn
#define __Restrict
#else
#define __Noreturn _Noreturn
#define __Restrict restrict
#endif
