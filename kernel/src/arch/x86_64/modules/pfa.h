#include <stdint-gcc.h>

extern void * MMU_pf_alloc(void);
extern void MMU_pf_free(void *pf);

struct Tag_Header { 
    uint32_t size;
    uint32_t reserved;
}__attribute__((packed));

// 4
struct Memory_Info { 
    uint32_t type;
    uint32_t size;
    uint32_t low_mem;
    uint32_t high_mem;
};

// 5
struct Boot_Device { 
    uint32_t type;
    uint32_t size;
    uint32_t device;
    uint32_t partition;
    uint32_t subpartition;
};

// 1 
struct Boot_CLI {
    uint32_t type;
    uint32_t size;
    char * cli_string;
};

//2
struct Boot_Loader { 
    uint32_t type;
    uint32_t size;
    char * name;
};

struct Memory_Info { 
    uint64_t starting_address;
    uint64_t length;
    uint32_t type;
    uint32_t reserved;
}
// 6
struct Memory_Map { 
    uint32_t type;
    uint32_t tag_size;
    uint32_t memory_info_size;
    uint32_t version;
    struct Memory_Info * entries;
}

// in memory segmenet address and length are regioins containing our kernel 
struct Section_Header { 
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
}

struct ELF_Symbols { 
    uint32_t type;
    uint32_t size;
    uint32_t entry_count;
    uint32_t entry_size;
    uint32_t string_table_index;
    struct Section_Header * entries;
}