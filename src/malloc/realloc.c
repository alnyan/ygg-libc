#include <_libc/malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void *realloc(void *old, size_t size) {
    // TODO: maybe optimize this
    void *ptr = malloc(size);
    if (!ptr) {
        return NULL;
    }

    if (old) {
        struct block *old_block = old - sizeof(struct block);
        size_t less_size = size;
        if (less_size > old_block->size) {
            less_size = old_block->size;
        }
        assert((old_block->flags & BLOCK_MAGIC_MASK) == BLOCK_MAGIC);
        memcpy(ptr, old, less_size);
        free(old);
    }

    return ptr;
}

