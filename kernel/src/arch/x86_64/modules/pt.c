#include "pfa.h"
#include "pt.h"
#include "string.h"
#include <stdint-gcc.h>
#include <stddef.h>
#include "std.h"




void * create_new_table(void * parent) {
    struct PTE * p = (struct PTE *)parent;
    void * new_page = MMU_pf_alloc();
    memset(new_page, 0, PAGE_SIZE);
    p->Base_Address = (uint64_t)new_page >> BASE_ADDRESS_SHIFT;
    p->P=1;
    p->AVL=1;
}

long long virtual_to_physical(long long vaddr, struct PML_Entries * pml_entries) {
    struct PMLE * pmle;
    struct PDPE * pdpe;
    struct PDE * pde;
    struct PTE * pte;
    void * new_page;

    long long l4_idx = (vaddr >>L4_SHIFT) & VMASK;
    pmle = &(pml_entries->entries[l4_idx]);
    if (pmle->P == 0) { 
        create_new_table(pmle);
    }

    long long l3_idx = (vaddr >> L3_SHIFT) & VMASK;
    pdpe = (struct PDPE*)((pmle->PDP_Pointer_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pdpe += l3_idx;
    if (pdpe->P == 0) {
       create_new_table(pdpe);
    }

    long long l2_idx = (vaddr >> L2_SHIFT) & VMASK;
    pde = (struct PDE*)((pdpe->PDP_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pde += l2_idx;

    if(pde->P == 0) {
        create_new_table(pde);
    }

    long long pt_idx = (vaddr >> L1_SHIFT) & VMASK;
    pte = (struct PTE*)((pde->Base_Address << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pte += pt_idx;

    if(pte->P == 0) {
        create_new_table(pte);
    }
    return (pte->Base_Address << BASE_ADDRESS_SHIFT);
}

void * pt_init(struct Region * memory_region) { 
    struct PML_Entries* entry = MMU_pf_alloc();
    memset(entry, 0, PAGE_SIZE);  
    while(memory_region != NULL) { 
        long long addr = (long long)memory_region->start;
        long long end = (long long)memory_region->end;
        while(addr < end) { 
            printk("initializing for %ll\n", addr);
            virtual_to_physical(addr, entry);
            addr += PAGE_SIZE;
        }
        memory_region = memory_region->next;
    }
}

void *MMU_alloc_page();
void *MMU_alloc_pages(int num);
void MMU_free_page(void *);
void MMU_free_pages(void *, int num);