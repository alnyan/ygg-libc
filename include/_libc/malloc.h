#pragma once
#include <_libc/list.h>
#include <stddef.h>
#include <stdint.h>

#define BLOCK_ALLOC                 1
#define BLOCK_MMAP                  2
#define BLOCK_MAGIC_MASK            0xFFFFFFC
#define BLOCK_MAGIC                 0xBAD8EA0

// Fits ~56 blocks of 256
#define SMALL_ZONE_ELEM             256
#define SMALL_ZONE_SIZE             (4 * 0x1000)
// Fits ~31 block of 2K
#define MID_ZONE_ELEM               2048
#define MID_ZONE_SIZE               (16 * 0x1000)
// Fits ~15 blocks of 8K
#define LARGE_ZONE_ELEM             8192
#define LARGE_ZONE_SIZE             (32 * 0x1000)
// Larger objects are allocated directly using mmap()

struct block {
    struct block *prev, *next;
    uint32_t flags, size;
};

struct zone {
    size_t size;
    struct list_head list;
};

extern struct list_head small_zone_list, mid_zone_list, large_zone_list;

struct zone *zone_create(size_t size);
void zone_destroy(struct zone *zone);
