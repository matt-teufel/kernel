struct PML { 
    long long reserved1:3;
    long long PWT:1;
    long long PCD:1;
    long long reserved2:7;
    long long base_address:40;
    long long MBZ: 12;
};

struct PMLE {
    long long P:1;
    long long RW:1;
    long long US:1;
    long long PWT:1;
    long long PCD:1;
    long long A:1;
    long long IGN:1;
    long long MBZ:2;
    long long AVL:3;
    long long PDP_Pointer_Base:40;
    long long availbale:11;
    long long NX:1;
};

struct PML_Entries {
    struct PMLE entries[512];
};

struct PDPE { 
    long long P:1;
    long long RW:1;
    long long US:1;
    long long PWT:1;
    long long PCD:1;
    long long A:1;
    long long IGN:1;
    long long MBZ:2;
    long long AVL:3;
    long long PDP_Base:40;
    long long availbale:11;
    long long NX:1;
};

struct PDE {
    long long P:1;
    long long RW:1;
    long long US:1;
    long long PWT:1;
    long long PCD:1;
    long long A:1;
    long long IGN1:1;
    long long MBZ: 1;
    long long IGN2:1;
    long long AVL:3;
    long long Base_Address:40;
    long long available:11;
    long long NX:1;
};

struct PTE {
    long long P:1;
    long long RW:1;
    long long US:1;
    long long PWT:1;
    long long PCD:1;
    long long A:1;
    long long D:1;
    long long PAT:1;
    long long G:1;
    long long AVL:3;
    long long Base_Address:40;
    long long available:11;
    long long NX:1;
};



extern void *MMU_alloc_page();
extern void *MMU_alloc_pages(int num);
extern void MMU_free_page(void *);
extern void MMU_free_pages(void *, int num);
extern void * pt_init(struct Region * memory_region);

// struct VirtualAddress {
//     long long offset: 12;
//     long long L1: 9;
//     long long L2: 9;
//     long long L3: 9;
//     long long L4: 9;
//     long long avail: 16;
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