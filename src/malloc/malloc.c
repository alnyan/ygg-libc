#include <_libc/malloc.h>
#include <_libc/list.h>
#include <sys/mman.h>
#include <string.h>
#include <assert.h>

// Small zone allocation function
// XXX: This is absolute bullshit: meet my first fit allocator
static void *zone_alloc(struct zone *zone, size_t count) {
    struct block *begin = (struct block *) &zone[1];

    count = (count + 15) & ~15;

    for (struct block *block = begin; block; block = block->next) {
        if (block->flags & BLOCK_ALLOC) {
            continue;
        }

        if (count == block->size) {
            block->flags |= BLOCK_ALLOC;
            void *ptr = &block[1];
            memset(ptr, 0, count);
            return ptr;
        } else if (block->size >= count + sizeof(struct block)) {
            // Insert new block after this one
            struct block *cur_next = block->next;
            struct block *new_block = (struct block *) (((uintptr_t) block) + sizeof(struct block) + count);
            if (cur_next) {
                cur_next->prev = new_block;
            }
            new_block->next = cur_next;
            new_block->prev = block;
            new_block->size = block->size - sizeof(struct block) - count;
            new_block->flags = BLOCK_MAGIC;
            block->next = new_block;
            block->size = count;
            block->flags |= 1;
            void *ptr = &block[1];
            memset(ptr, 0, count);
            return ptr;
        }
    }

    return NULL;
}

///

static void *alloc_from(struct list_head *head, size_t zone_size, size_t size) {
    struct zone *zone;
    void *ptr;

try_again:
    list_for_each_entry(zone, head, list) {
        if ((ptr = zone_alloc(zone, size))) {
            return ptr;
        }
    }

    zone = zone_create(zone_size);
    if (!zone) {
        return NULL;
    }
    list_add(&zone->list, head);

    goto try_again;
}

void *malloc(size_t size) {
    if (size <= SMALL_ZONE_ELEM) {
        return alloc_from(&small_zone_list, SMALL_ZONE_SIZE, size);
    } else if (size <= MID_ZONE_ELEM) {
        return alloc_from(&mid_zone_list, MID_ZONE_SIZE, size);
    } else if (size <= LARGE_ZONE_ELEM) {
        return alloc_from(&large_zone_list, LARGE_ZONE_SIZE, size);
    } else {
        size_t pages_needed = (size + 0xFFF) & ~0xFFF;
        void *pages = mmap(NULL, pages_needed + 0x1000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (pages == MAP_FAILED) {
            return NULL;
        }

        struct block *block = pages + 0x1000 - sizeof(struct block);
        block->flags = BLOCK_MAGIC | BLOCK_ALLOC | BLOCK_MMAP;
        block->size = pages_needed;

        return pages + 0x1000;
    }
}

