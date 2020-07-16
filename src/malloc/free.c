#include <_libc/malloc.h>
#include <sys/mman.h>
#include <assert.h>

void free(void *ptr) {
    if (!ptr) {
        return;
    }
    struct block *block = ptr - sizeof(struct block);

    if ((block->flags & BLOCK_MAGIC_MASK) != BLOCK_MAGIC) {
        while (1);
    }
    if (!(block->flags & BLOCK_ALLOC)) {
        while (1);
    }

    if (block->flags & BLOCK_MMAP) {
        void *base = (void *) ((uintptr_t) block & ~0xFFF);
        size_t len = block->size + 0x1000;
        munmap(base, len);
        return;
    }

    block->flags &= ~BLOCK_ALLOC;
    struct block *prev, *next;
    prev = block->prev;
    next = block->next;

    if (prev && !(prev->flags & BLOCK_ALLOC)) {
        block->flags = 0;
        prev->next = next;
        if (next) {
            next->prev = prev;
        }
        prev->size += block->size + sizeof(struct block);

        block = prev;
    }

    if (next && !(next->flags & BLOCK_ALLOC)) {
        next->flags = 0;

        if (next->next) {
            next->next->prev = block;
        }
        block->next = next->next;
        block->size += next->size + sizeof(struct block);
    }

    if (!block->prev && !block->next) {
        struct zone *zone = (void *) block - sizeof(struct zone);
        assert(!((uintptr_t) zone & 0xFFF));
        list_del(&zone->list);
        zone_destroy(zone);
    }
}

