#pragma once

typedef struct {
    unsigned long _v[8];
} jmp_buf[1];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);
