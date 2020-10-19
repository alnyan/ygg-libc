#include <_libc/malloc.h>
#include <sys/mman.h>
#include <assert.h>

LIST_HEAD(small_zone_list);
LIST_HEAD(mid_zone_list);
LIST_HEAD(large_zone_list);

struct zone *zone_create(size_t size) {
    void *pages = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (pages == MAP_FAILED) {
        return NULL;
    }

    struct zone *zone = pages;
    struct block *head = pages + sizeof(struct zone);

    zone->size = size - sizeof(struct zone);
    list_head_init(&zone->list);

    head->size = size - sizeof(struct zone) - sizeof(struct block);
    head->flags = BLOCK_MAGIC;
    head->prev = NULL;
    head->next = NULL;

    return zone;
}

void zone_destroy(struct zone *zone) {
    assert(!((uintptr_t) zone & 0xFFF));
    munmap(zone, zone->size + sizeof(struct zone));
}

