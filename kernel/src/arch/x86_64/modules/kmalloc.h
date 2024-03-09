#include <stddef.h>
extern void kfree(void *addr);
extern void *kmalloc(size_t size);

#define MAX_POOL_SIZE 2048
