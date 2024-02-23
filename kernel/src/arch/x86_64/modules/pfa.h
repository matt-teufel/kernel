#include <stdint-gcc.h>

extern void * MMU_pf_alloc(void);
extern void MMU_pf_free(void *pf);
void process_tag_entries(uint32_t tag_address);

struct TagHeaderFixed { 
    uint32_t size;
    uint32_t reserved;
};

struct TagHeaderVar {
    uint32_t type;
    uint32_t size;
};
// 4
struct MemoryInfo { 
    uint32_t type;
    uint32_t size;
    uint32_t low_mem;
    uint32_t high_mem;
};

// 5
struct BootDevice { 
    uint32_t type;
    uint32_t size;
    uint32_t device;
    uint32_t partition;
    uint32_t subpartition;
};

// 1 
struct BootCLI {
    uint32_t type;
    uint32_t size;
    char * cli_string;
};

//2
struct BootLoader { 
    uint32_t type;
    uint32_t size;
    char * name;
};

struct MemoryMapInfo { 
    uint64_t starting_address;
    uint64_t length;
    uint32_t type;
    uint32_t reserved;
}__attribute__((packed));
// 6
struct MemoryMap { 
    uint32_t type;
    uint32_t tag_size;
    uint32_t memory_info_size;
    uint32_t version;
};

// in memory segmenet address and length are regioins containing our kernel 
struct SectionHeader { 
    uint32_t string_name_index;
    uint32_t type;
    uint64_t flags;
    uint64_t address; // address in used
    uint64_t offset;
    uint64_t size; //size it is using 
    uint32_t table_index_link;
    uint32_t extra_info;
    uint64_t alignment;
    uint64_t fixed_entry_size; //IFF section holds fixed entries 
};
// 9
struct ELFSymbols { 
    uint32_t type;
    uint32_t size;
    uint32_t entry_count;
    uint32_t entry_size;
    uint32_t string_table_index;
}__attribute__((packed));

struct Region { 
    void * start, *end;
    struct Region * next;
    void * current_address;
};

struct Frame { 
    struct Frame * next;
    uint64_t count;
};


#define MAX_REGIONS 256
#define PAGE_SIZE 4096
#define NO_FRAMES_AVAILABLE 0xFFFFFFFFFFFFFFFF

extern void test_basic_alloc_and_free(void);
extern void test_full_allocation(void);