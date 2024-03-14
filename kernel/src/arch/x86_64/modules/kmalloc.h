#include <stddef.h>
extern void kfree(void *addr);
extern void *kmalloc(size_t size);
extern void test_kmalloc_simple();
extern void init_pools();
extern void test_kmalloc_full();
extern void test_free_then_reallocate();
extern void test_very_large_allocation();

#define MAX_POOL_SIZE 1024
