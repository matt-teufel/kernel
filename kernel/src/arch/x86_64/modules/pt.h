#include <stdint-gcc.h>

struct PML { 
    uint64_t reserved1:3;
    uint64_t PWT:1;
    uint64_t PCD:1;
    uint64_t reserved2:7;
    uint64_t base_address:40;
    uint64_t MBZ: 12;
};

struct PMLE {
    uint64_t P:1;
    uint64_t RW:1;
    uint64_t US:1;
    uint64_t PWT:1;
    uint64_t PCD:1;
    uint64_t A:1;
    uint64_t IGN:1;
    uint64_t MBZ:2;
    uint64_t AVL:3;
    uint64_t PDP_Pointer_Base:40;
    uint64_t availbale:11;
    uint64_t NX:1;
};

struct PML_Entries {
    struct PMLE entries[512];
};

struct PDPE { 
    uint64_t P:1;
    uint64_t RW:1;
    uint64_t US:1;
    uint64_t PWT:1;
    uint64_t PCD:1;
    uint64_t A:1;
    uint64_t IGN:1;
    uint64_t MBZ:2;
    uint64_t AVL:3;
    uint64_t PDP_Base:40;
    uint64_t availbale:11;
    uint64_t NX:1;
};

struct PDE {
    uint64_t P:1;
    uint64_t RW:1;
    uint64_t US:1;
    uint64_t PWT:1;
    uint64_t PCD:1;
    uint64_t A:1;
    uint64_t IGN1:1;
    uint64_t MBZ: 1;
    uint64_t IGN2:1;
    uint64_t AVL:3;
    uint64_t Base_Address:40;
    uint64_t available:11;
    uint64_t NX:1;
};

struct PTE {
    uint64_t P:1;
    uint64_t RW:1;
    uint64_t US:1;
    uint64_t PWT:1;
    uint64_t PCD:1;
    uint64_t A:1;
    uint64_t D:1;
    uint64_t PAT:1;
    uint64_t G:1;
    uint64_t AVL:3;
    uint64_t Base_Address:40;
    uint64_t available:11;
    uint64_t NX:1;
};



extern void *MMU_alloc_page();
extern void *MMU_alloc_pages(int num);
extern void MMU_free_page(void *);
extern void MMU_free_pages(void *, int num);
extern void * pt_init(struct Region * memory_region);
extern void enable_paging();
extern void test_table();
void test_page_fault();

// struct VirtualAddress {
//     uint64_t offset: 12;
//     uint64_t L1: 9;
//     uint64_t L2: 9;
//     uint64_t L3: 9; 
//     uint64_t L4: 9;
//     uint64_t avail: 16;
// };

#define VMASK 0x1FF
#define OMASK 0xFFFF
#define L4_SHIFT 39
#define L3_SHIFT 30 
#define L2_SHIFT 21
#define L1_SHIFT 12

#define PHYSICAL_BASE 0x0000000000
#define PHYSICAL_END  0x1000000000
#define KHEAP_START   0x1000000000
#define KHEAP_END     0x2000000000
#define RESV_START    0x2000000000
#define RESV_END      0xEFFFFFFFFF
#define KSTACK_START  0xF000000000
#define KSTACK_END    0x10000000000
#define USER_START    0x10000000000

#define BASE_ADDRESS_SHIFT 12
#define BASE_ADDRESS_MASK 0x000FFFFFFFFFF000