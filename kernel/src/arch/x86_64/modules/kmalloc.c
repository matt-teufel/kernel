#include "kmalloc.h"
#include "pfa.h"
#include "pt.h"
#include <stddef.h>
#include "std.h"
struct KmallocPool { 
    int max_size;
    int avail;
    struct FreeList *head;
};

struct FreeList {
    struct FreeList *next;
};

struct KmallocExtra {
    struct KmallocPool * pool;
    size_t size;
};

struct KmallocPool pool32;
struct KmallocPool pool64;
struct KmallocPool pool128;
struct KmallocPool pool256;
struct KmallocPool pool512;
struct KmallocPool pool1024;

void init_pools() {
    pool32.max_size = 32;
    pool32.avail = 0;
    pool32.head = NULL;

    pool64.max_size = 64;
    pool64.avail = 0;
    pool64.head = NULL;

    pool128.max_size = 128;
    pool128.avail = 0;
    pool128.head = NULL;

    pool256.max_size = 256;
    pool256.avail = 0;
    pool256.head = NULL;

    pool512.max_size = 512;
    pool512.avail = 0;
    pool512.head = NULL;

    pool1024.max_size = 1024;
    pool1024.avail = 0;
    pool1024.head = NULL;
}

struct KmallocPool * find_best_pool(size_t size) { 
    if (size <= 32) { 
        printk("using pool 32\n");
        return &pool32;
    } else if (size <= 64) { 
        printk("using pool 32\n");
        return &pool64;
    } else if (size <= 128) {
        printk("using pool 32\n");
        return &pool128;
    } else if (size <= 256) { 
        printk("using pool 32\n");
        return &pool256;
    } else if (size<=512) { 
        printk("using pool 32\n");
        return &pool512;
    } else {
        printk("using pool 32\n");
        return &pool1024;
    }
}

void *kmalloc(size_t size) {
    int adjusted_size = size + sizeof(struct KmallocExtra);
    void * return_addr;
    struct KmallocExtra * extra;
    if (adjusted_size > MAX_POOL_SIZE) { 
        extra = MMU_alloc_pages(size / PAGE_SIZE);
        extra->pool = NULL;
        extra->size = adjusted_size;
        extra++;
        return_addr = extra;
    } else { 
        struct KmallocPool *pool = find_best_pool(adjusted_size);
        if (pool->avail > 0) { 
            extra = (struct KmallocExtra *)pool->head;
            extra->pool = pool;
            extra->size = size;
            extra++;
            return_addr = extra;

            pool->head = pool->head->next;
            pool->avail--;
        } else { 
            int i;
            uint8_t * frame = MMU_alloc_page();

            extra = (struct KmallocExtra *)frame;
            extra->pool = pool;
            extra->size = size;
            extra++;
            return_addr = extra;

            frame += pool->max_size;
            pool->head = (struct FreeList *)frame;
            pool->avail = (PAGE_SIZE / pool->max_size) - 1;
            struct FreeList * curr = (struct FreeList *)frame;
            for (i = 1; i < pool->avail; i++) { 
                frame += pool->max_size;
                curr->next = (struct FreeList *)frame;
                curr = curr->next;
            }
        }
    }
    return return_addr;
}
// add the header and write the fre func
void kfree(void * addr) { 
    struct KmallocExtra * extra = (struct KmallocExtra *)((uint8_t *)addr - sizeof(struct KmallocExtra));
    if (extra->pool = NULL) { 
        MMU_free_pages(extra, extra->size/PAGE_SIZE );
    } else {
        struct FreeList * l = (struct FreeList *)extra;
        l->next = extra->pool->head;
        extra->pool->head = l;
        extra->pool->avail++;
    }
}


void test_kmalloc() {

}