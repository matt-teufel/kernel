#include <stdint-gcc.h>
#include "std.h"
#include "pfa.h"
#include <stddef.h>
#include "string.h"

static struct Region rl[MAX_REGIONS]; // memory region list 
static struct Region * rlh = &rl[0]; // head
struct Region * cur_reg = NULL;
static uint16_t idx = 0;
static uint8_t all_regions_allocated = 0;

static struct Frame frame_list;

void printRegions() 
{ 
    struct Region * cr = rlh->next;
    printk("========Printing Regions==========\n");
    while (cr != NULL) {
        printk("memory region start: %ll and end: %ll\n", (uint64_t)cr->start, (uint64_t)cr->end);
        cr = cr->next;
    }
    printk("====================================\n");
}

void validateRegions() 
{
    struct Region * cr = rlh;
    while( cr->next != NULL) {
        uint64_t diff = ((uint64_t)(cr->next->end) - (uint64_t)(cr->next->start));
        if (diff < (20*PAGE_SIZE) || diff > MAX_64) {
            cr->next = cr->next->next;
        } else {
            cr = cr->next;
        }
    }
}

void initRegionList() 
{
    int i;
    for (i=0;i<MAX_REGIONS;i++) {
        rl[i].start = NULL;
        rl[i].end = NULL;
        rl[i].next = NULL;
        rl[i].current_address=0;
    }
}

void appendRegion(void * start, void *end)
{
    struct Region * current_region = rlh;
    while(current_region->next != NULL) {
        current_region = current_region->next;
    }
    idx++;
    current_region->next = &rl[idx];
    if(start == NULL) { 
        rl[idx].start = (uint64_t*)PAGE_TABLE_BASE;
        rl[idx].current_address = PAGE_TABLE_BASE;
    } else {
            rl[idx].start = start;
            rl[idx].current_address = (uint64_t)start;
    }
    rl[idx].end = end;
    // printk("memory region start: %ll and end: %ll\n", rl[idx].start, rl[idx].end);

}

void splitRegion(struct SectionHeader * section) {
    struct Region * current_region = rlh->next;
    struct Region * prev_region =rlh;
    uint64_t addr = section->address;
    uint64_t section_end_addr = addr + section->size;
    addr -= (addr % PAGE_SIZE);
    section_end_addr += (PAGE_SIZE- (section_end_addr%PAGE_SIZE));
    while ( current_region != NULL) { 
        if (addr >= (uint64_t)current_region->start && section_end_addr <= (uint64_t)current_region->end) { 
            if (((uint64_t)current_region->end - section_end_addr) > PAGE_SIZE) { 
                appendRegion((void*)section_end_addr, current_region->end);
            }
            current_region->end = (void*)addr;
        }
        if(((uint64_t)current_region->end - (uint64_t)current_region->start) < PAGE_SIZE) { 
            prev_region->next = current_region->next;
        } else {
            prev_region = current_region;
        }
        current_region = current_region->next;
    }
}

void initFrameList(void) {
    frame_list.next = NULL;
    frame_list.count = 0;
}

uint64_t add_bytes(uint64_t address, int bytes) {
    uint64_t new_address = address + bytes;
    return new_address;
}

struct Region * process_tag_entries(uint32_t tag_address) 
{
    uint32_t byte_offset;
    initRegionList();
    initFrameList();
    uint64_t base_address_int = tag_address & 0xFFFFFFFF;
    struct TagHeaderFixed * tag = (struct TagHeaderFixed *)base_address_int;
    uint64_t tag_header_int = add_bytes(base_address_int, sizeof(struct TagHeaderFixed));
    struct TagHeaderVar * tag_header = (struct TagHeaderVar*)tag_header_int;
    while (!(tag_header->type == 0 && tag_header->size ==8)) {
        switch(tag_header->type) {
            case 4: {
                // printk("Memory Info\n");
                break;
            }
            case 5: {
                // printk("Boot Device\n");
                break;
            }
            case 1: { 
                // printk("Boot CLI\n");
                break;
            }
            case 2: {
                // printk("Boot Loader\n");
                break;
            }
            case 6: {
                // printk("Memory Map\n");
                uint32_t offset = 0;
                struct MemoryMap * mm = (struct MemoryMap *)tag_header;
                struct MemoryMapInfo * mmi = (struct MemoryMapInfo *)(tag_header_int + sizeof(struct MemoryMap));
                // printk("memory info size %d\n", mm->tag_size);
                while (offset < mm->tag_size) { 
                    if (mmi->type  == 1) {
                        appendRegion((char*)(mmi->starting_address), (char *)(mmi->starting_address+mmi->length));
                    }
                    offset+=sizeof(struct MemoryMapInfo);
                    mmi++;
                }
                // printk("====Printing Regions at the end of MM=====\n");
                // printRegions();
                break;
            }
            case 9: {
                // printk("ELF Symbols\n");
                struct ELFSymbols * es = (struct ELFSymbols *)tag_header;
                struct SectionHeader * section = (struct SectionHeader *)(tag_header_int + sizeof(struct ELFSymbols));
                int i;
                for (i=0; i< es->entry_count;i++) { 
                    splitRegion(section);
                    section++;
                }
                break;
            }
            default : {
                // printk("type is something else: %d\n", tag_header->type);
                break;
            }
        }
        byte_offset = tag_header->size;
        if (byte_offset % 8) { 
            byte_offset += 8 - (byte_offset % 8);
        }
        // printk("byte offset %d", byte_offset);
        tag_header_int = add_bytes(tag_header_int, byte_offset);
        tag_header = (struct TagHeaderVar *)tag_header_int;
    }
    validateRegions();
    printRegions();
    cur_reg = rlh->next;
    return cur_reg;
    //tag type 0 and size 8 is termination of list 
}

void * MMU_pf_alloc(void)
{ 
    // printk("MMU_pf_alloc call\n");
    uint64_t * return_addr;
    if (frame_list.count == 0 && all_regions_allocated) { 
        printk("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\nI am screwed and out of memory\n\n\nvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
        return NULL;
    } else if (frame_list.count > 0) {
        // printk("allocating from freed list\n");
        return_addr = (uint64_t*)frame_list.next;
        frame_list.next = frame_list.next->next;
        frame_list.count--;
    } else {
        // printk("current region start: %ll, and end %ll, current addr: %ll\n", cur_reg->start, cur_reg->end, cur_reg->current_address);
        if ((cur_reg->current_address + PAGE_SIZE) <= (uint64_t)(cur_reg->end)) {
            return_addr = (uint64_t*)(cur_reg->current_address);
            cur_reg->current_address += PAGE_SIZE;
        } else {
            if(cur_reg->next == NULL) {
                // printk("All regions have been allocated\n");
                all_regions_allocated = 1;
                return NULL;
            } else {
                // printk("moving to the next region\n");
                cur_reg = cur_reg->next;
                return MMU_pf_alloc();
            }
        }
    }
    return return_addr;
}

void MMU_pf_free(void *pf) 
{
    struct Frame * f = (struct Frame *)pf;
    f->next = frame_list.next;
    frame_list.next = f;
    frame_list.count++;
}



void test_basic_alloc_and_free(void) { 
    printk("Testing basic frame allocation and freeing\n");
    struct Frame * f1 = MMU_pf_alloc();
    struct Frame * f2 = MMU_pf_alloc();
    struct Frame * f3 = MMU_pf_alloc();
    printk("First allocated frame %ll\n", f1);
    printk("Second allocated frame %ll\n", f2);
    printk("Third allocated frame %ll\n", f3);

    printk("Freeing frame 1\n");
    MMU_pf_free(f1);
    printk("Freeing frame 2\n");
    MMU_pf_free(f2);

    printk("Calling pf_alloc again should now give us frame 2 then frame 1\n");
    f1 = MMU_pf_alloc();
    f2 = MMU_pf_alloc();
    printk("Frame 1 should not be original frame 2: %ll\n", f1);
    printk("Frame 2 should not be original frame 1: %ll\n", f2);

    MMU_pf_free(f3);
    MMU_pf_free(f1);
    MMU_pf_free(f2);
}



void test_full_allocation(void) {
    printk("Stress Test Full Allocation\n");
    uint64_t * f= (uint64_t *)MMU_pf_alloc();
    uint64_t addr;
    int i;
    while (f != NULL) { 
        addr = (uint64_t)f;
        // printk("copying for addr: %ll and frame address: %ll\n", addr, (uint64_t)f);
        for (i=0;i<(PAGE_SIZE/sizeof(uint64_t));i++){
            *f++ = addr;
        }
        f = (uint64_t *)MMU_pf_alloc();
    }


    struct Region * cr = rlh->next;
    while(cr != NULL) { 
        printk("iterating through each block in region with start: %ll and end %ll\n", cr->start, cr->end);
        uint64_t * current_address = (uint64_t *)cr->start;
        uint64_t current_address_int = (uint64_t)cr->start;
        uint64_t end = (uint64_t)cr->end;
        end -= end % PAGE_SIZE;
        int i;
        while (current_address_int < end) { 
            for (i=0; i<(PAGE_SIZE/sizeof(uint64_t)); i++){
                if(*current_address++ != current_address_int) { 
                    printk("There is an error, the current address value is actually: %ll, but should be %ll, i: %d\n", *current_address, current_address_int, i);
                }
            }
            current_address_int = (uint64_t)current_address;
        }
        cr = cr->next;
    }
    printk("Page Frames stress test passed without error\n");
}