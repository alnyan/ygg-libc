#pragma once
#include <stddef.h>

typedef int key_t;

int shmget(key_t key, size_t size, int flags);
void *shmat(int id, const void *hint, int flags);
