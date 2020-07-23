#pragma once

typedef struct {
    unsigned long _v[8];
} jmp_buf[1];

int _setjmp(jmp_buf env);
int setjmp(jmp_buf env);
void _longjmp(jmp_buf env, int val);
void longjmp(jmp_buf env, int val);
