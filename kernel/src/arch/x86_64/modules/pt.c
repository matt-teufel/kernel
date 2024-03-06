#include "pfa.h"
#include "pt.h"
#include "string.h"
#include <stdint-gcc.h>
#include <stddef.h>
#include "std.h"

uint64_t heap_vaddr = KHEAP_START;
struct PML_Entries * ktable;


void * create_new_table(void * parent) {
    struct PTE * p = (struct PTE *)parent;
    void * new_page = MMU_pf_alloc();
    memset(new_page, 0, PAGE_SIZE);
    p->Base_Address = (uint64_t)new_page >> BASE_ADDRESS_SHIFT;
    p->P=1;
    p->AVL=1;
}

uint64_t virtual_to_physical(uint64_t vaddr, struct PML_Entries * pml_entries) { 
        
    struct PMLE * pmle;
    struct PDPE * pdpe;
    struct PDE * pde;
    struct PTE * pte;
    void * new_page;

    uint64_t l4_idx = (vaddr >>L4_SHIFT) & VMASK;
    pmle = &(pml_entries->entries[l4_idx]);
    if (pmle->P == 0) { 
        return 0;
    }

    uint64_t l3_idx = (vaddr >> L3_SHIFT) & VMASK;
    pdpe = (struct PDPE*)((pmle->PDP_Pointer_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pdpe += l3_idx;
    if (pdpe->P == 0) {
       return 0;
    }

    uint64_t l2_idx = (vaddr >> L2_SHIFT) & VMASK;
    pde = (struct PDE*)((pdpe->PDP_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pde += l2_idx;

    if(pde->P == 0) {
        return 0;
    }

    uint64_t pt_idx = (vaddr >> L1_SHIFT) & VMASK;
    pte = (struct PTE*)((pde->Base_Address << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pte += pt_idx;
    if (pte->P == 0) {
        return 0;
    }
    return pte->Base_Address << BASE_ADDRESS_SHIFT;
}

void put_vaddr(uint64_t vaddr, struct PML_Entries * pml_entries) {
    // set the page table entry to be present with the physical address. this is needed
    // to prevent our page fault allocater from sending incorrect page faults when allocating pages 
    struct PMLE * pmle;
    struct PDPE * pdpe;
    struct PDE * pde;
    struct PTE * pte;
    void * new_page;

    uint64_t l4_idx = (vaddr >>L4_SHIFT) & VMASK;
    pmle = &(pml_entries->entries[l4_idx]);
    if (pmle->P == 0) { 
        printk("id map creating new l3 table\n");
        create_new_table(pmle);
    }

    uint64_t l3_idx = (vaddr >> L3_SHIFT) & VMASK;
    pdpe = (struct PDPE*)((pmle->PDP_Pointer_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pdpe += l3_idx;
    if (pdpe->P == 0) {
        printk("id map creating new l2 table\n");
        create_new_table(pdpe);
    }

    uint64_t l2_idx = (vaddr >> L2_SHIFT) & VMASK;
    pde = (struct PDE*)((pdpe->PDP_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pde += l2_idx;

    if(pde->P == 0) {
        printk("id map creating new l1 table for addr: %ll\n", vaddr);
        create_new_table(pde);
    }

    uint64_t pt_idx = (vaddr >> L1_SHIFT) & VMASK;
    pte = (struct PTE*)((pde->Base_Address << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pte += pt_idx;
    pte->P = 1;
    pte->AVL = 1;
    pte->Base_Address = vaddr >> BASE_ADDRESS_SHIFT;
}

void validate_id_map(struct Region * memory_region, struct PML_Entries * pml)
{
    while(memory_region != NULL) { 
        uint64_t addr = (uint64_t)memory_region->start;
        uint64_t end = (uint64_t)memory_region->end;
        while(addr < end) { 
            // printk("initializing for %ll\n", addr);
            if(virtual_to_physical(addr, pml) != addr) {
                printk("ERROR: physical addr :%ll does not have an entry in pml table\n", addr);
            }
            addr += PAGE_SIZE;
        }
        memory_region = memory_region->next;
    }
}

void * pt_init(struct Region * memory_region) { 
    struct PML_Entries* pml_entries = MMU_pf_alloc();
    memset(pml_entries, 0, PAGE_SIZE); 
    ktable = pml_entries;
    // struct Region * head = memory_region; 
    put_vaddr(0x0, pml_entries);
    while(memory_region != NULL) { 
        uint64_t addr = (uint64_t)memory_region->start;
        uint64_t end = (uint64_t)memory_region->end;
        while(addr <= end) { 
            // printk("initializing for %ll\n", addr);
            put_vaddr(addr, pml_entries);
            addr += PAGE_SIZE;
        }
        memory_region = memory_region->next;
    }
    // validate_id_map(head, pml_entries);
}

void enable_paging() { 
    asm volatile ("mov %0, %%cr3" : : "r" ((uint64_t)ktable));
}

void *MMU_alloc_page() { 
    // printk("allocating a new page at kernel addr: %ll\n", heap_vaddr);
    struct PML_Entries * pml_entries = ktable;
    struct PMLE * pmle;
    uint64_t vaddr = heap_vaddr;
    struct PDPE * pdpe;
    struct PDE * pde;
    struct PTE * pte;
    void * new_page;

    uint64_t l4_idx = (vaddr >>L4_SHIFT) & VMASK;
    pmle = &(pml_entries->entries[l4_idx]);
    if (pmle->P == 0) { 
        // printk("mmu alloc creating new l3 table\n");
        create_new_table(pmle);
    }

    uint64_t l3_idx = (vaddr >> L3_SHIFT) & VMASK;
    pdpe = (struct PDPE*)((pmle->PDP_Pointer_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pdpe += l3_idx;
    if (pdpe->P == 0) {
        // printk("mmu alloc creatign new l2 table\n");
       create_new_table(pdpe);
    }

    uint64_t l2_idx = (vaddr >> L2_SHIFT) & VMASK;
    pde = (struct PDE*)((pdpe->PDP_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pde += l2_idx;

    if(pde->P == 0) {
        // printk("mmu alloc creating new l1 table\n");
        create_new_table(pde);
    }

    uint64_t pt_idx = (vaddr >> L1_SHIFT) & VMASK;
    pte = (struct PTE*)((pde->Base_Address << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pte += pt_idx;
    if(pte->P == 0) { 
        // printk("allocating a new page in the page table\n");
        create_new_table(pte);
    }
    heap_vaddr += sizeof(PAGE_SIZE);
    return (void *)vaddr;
}
void *MMU_alloc_pages(int num)
{
    int i; 
    //optomize this later to just fully populate page table 
    void * return_value = MMU_alloc_page();
    for (i = 1; i < num; i++) {
        MMU_alloc_page();
    }
    return return_value;
}
void MMU_free_page(void * vaddr) { 
    printk("Freeing page with vaddr: %ll\n", (uint64_t)vaddr);
    struct PML_Entries * pml_entries = ktable;
    struct PMLE * pmle;
    struct PDPE * pdpe;
    struct PDE * pde;
    struct PTE * pte;
    void * new_page;
    uint64_t vaddr_int = (uint64_t)vaddr;

    uint64_t l4_idx = (vaddr_int >>L4_SHIFT) & VMASK;
    pmle = &(pml_entries->entries[l4_idx]);
    if (pmle->P == 0) { 
        printk("no l4 entry\n");
        return;
    }

    uint64_t l3_idx = (vaddr_int >> L3_SHIFT) & VMASK;
    pdpe = (struct PDPE*)((pmle->PDP_Pointer_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pdpe += l3_idx;
    if (pdpe->P == 0) {
        printk("no l3 entry\n");

       return;
    }

    uint64_t l2_idx = (vaddr_int >> L2_SHIFT) & VMASK;
    pde = (struct PDE*)((pdpe->PDP_Base << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pde += l2_idx;

    if(pde->P == 0) {
        printk("no l2 entry\n");

        return;
    }

    uint64_t pt_idx = (vaddr_int >> L1_SHIFT) & VMASK;
    pte = (struct PTE*)((pde->Base_Address << BASE_ADDRESS_SHIFT) & BASE_ADDRESS_MASK);
    pte += pt_idx;
    if (pte->P == 0) {
        printk("no l1 entry\n");    
        return;
    }
    pte->P = 0;
    uint64_t addr = pte->Base_Address;
    addr = addr << BASE_ADDRESS_SHIFT;
    printk("freeing address\n");
    MMU_free_page((void*)addr);
}
void MMU_free_pages(void *vaddr, int num) {
    int i;
    for (i=0;i < num;i++) { 
        MMU_free_page(vaddr + (PAGE_SIZE * i));
    }
}


void test_table() {
    printk("testing the table simple\n");
    uint64_t * page1 = MMU_alloc_page();
    uint64_t * page2 = MMU_alloc_page();
    printk("page 1");
}