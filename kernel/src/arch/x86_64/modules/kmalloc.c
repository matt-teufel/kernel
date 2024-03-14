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
        // printk("using pool 32\n");
        return &pool32;
    } else if (size <= 64) { 
        // printk("using pool 64\n");
        return &pool64;
    } else if (size <= 128) {
        // printk("using pool 128\n");
        return &pool128;
    } else if (size <= 256) { 
        // printk("using pool 256\n");
        return &pool256;
    } else if (size<=512) { 
        // printk("using pool 512\n");
        return &pool512;
    } else {
        // printk("using pool 1024\n");
        return &pool1024;
    }
}

void *kmalloc(size_t size) {
    int adjusted_size = size + sizeof(struct KmallocExtra);
    void * return_addr;
    struct KmallocExtra * extra;
    if (adjusted_size > MAX_POOL_SIZE) { 
        printk("size: %d is too large for a pool, allocating raw pages\n", adjusted_size);
        extra = MMU_alloc_pages((adjusted_size / PAGE_SIZE) + 1);
        extra->pool = NULL;
        extra->size = size;
        extra++;
        return_addr = extra;
    } else { 
        struct KmallocPool *pool = find_best_pool(adjusted_size);
        if (pool->avail > 0) { 
            extra = (struct KmallocExtra *)pool->head;
            pool->head = pool->head->next;
            pool->avail--;

            extra->pool = pool;
            extra->size = size;
            extra++;
            return_addr = extra;
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
    struct KmallocExtra * extra = (struct KmallocExtra *)addr;
    extra--;
    if (extra->pool == NULL) { 
        MMU_free_pages(extra, extra->size/PAGE_SIZE );
    } else {
        struct FreeList * current_head = extra->pool->head;
        struct FreeList * l = (struct FreeList *)extra;
        extra->pool->head = l;
        extra->pool->avail++;
        l->next = current_head;
    }
}


void test_kmalloc_simple() {
    printk("kmalloc single byte\n");
    kmalloc(1);
    printk("kmalloc 31 byte\n");
    kmalloc(31);

    printk("kmalloc 63 byte\n");
    kmalloc(63);

    printk("kmalloc 127 byte\n");
    kmalloc(127);

    printk("kmalloc 255 byte\n");
    kmalloc(255);

    printk("kmalloc 511 byte\n");
    kmalloc(511);

    printk("kmalloc 1023 byte\n");
    kmalloc(1023);

    printk("kmalloc 2047 byte\n");
    kmalloc(2047);

    printk("kmalloc 4095 byte\n");
    kmalloc(4095);
}

void test_kmalloc_full() { 
    printk("testing large volume of kmalloc for all pools\n");
    int size = 16;
    uint8_t ** pointers = MMU_alloc_pages(12); // allocate room for 6000 pointers
    uint8_t * ptr;
    int i, j,k;
    for (i = 0; i < 6; i++) {
        printk("kmallocing 1000 pages of %d size\n", size);
        for (j=0;j<1000;j++) {
            ptr = kmalloc(size);
            pointers[i*1000 + j] = ptr;
            int value = i+1;
            for (k=0; k < size; k++) { 
                ptr[k] = value;
            }
        }
        size *= 2;
    }
    printk("completed full allocations for all sizes\n");
    printk("begginning verfication of values in all pointers\n");
    size=16;
    for (i=0; i < 6; i++) { 
        for (j=0; j<1000;j++) {
            ptr = pointers[i*1000 + j];
            int value = i+1;
            for (k=0; k<size;k++) { 
                if(ptr[k] != value) { 
                    printk("ERROR DURING VALIDATION for pointer: %ll and size\n %d\n", ptr, size);
                }
            }
        }
        size *=2;
    }
    printk("verification complete without error\n");
}

void test_free_then_reallocate() { 
    printk("testing free then reallocate\n");
    uint8_t * ptr = kmalloc(16);
    printk("resulting pointer before free: %ll\n", ptr);
    kfree(ptr);
    ptr = kmalloc(16);
    printk("resulting pointer after free: %ll\n",ptr);
}

void test_very_large_allocation() { 
    printk("testing very large allocation of size 40960\n");
    uint8_t * ptr = kmalloc(40960);
    int i;
    for (i=0;i<40960;i++){
        ptr[i] = 0xF;
    }
    for(i=0;i<40960;i++){
        if(ptr[i] != 0xF){
            printk("ERROR IN LARGE ALLOCATION\n");
        }
    }
    printk("no page faults form large allocation\n");
}