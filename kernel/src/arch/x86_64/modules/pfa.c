#include <stdint-gcc.h>
#include "std.h"
#include "pfa.h"
#include <stddef.h>
#include "string.h"

static struct Region rl[MAX_REGIONS]; // memory region list 
static struct Region * rlh = &rl[0]; // head
uint8_t current_region_index = 1;
static uint16_t idx = 0;
static uint8_t all_regions_allocated = 0;

static struct Frame frame_list;

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
    if (idx < (MAX_REGIONS-1)) {
        rl[idx].next = &rl[idx+1];
        idx++;
        rl[idx].start = start;
        rl[idx].end = end;
        rl[idx].current_address = start;
        printk("memory region start: %ll and end: %ll\n", rl[idx].start, rl[idx].end);
    } else {
        printk("============\n\n\nERRROR TOO MANY MEM REGIONS IN PFS\n\n\n\n========");
    }
}

void splitRegion(struct SectionHeader * section) {
    struct Region * current_region = rlh->next;
    uint64_t addr = section->address;
    uint64_t section_end_addr;
    while (current_region !=NULL) { 
        if ((addr > (uint64_t)(current_region->start)) && (addr < (uint64_t)(current_region->end))) {
            // printk("splitting region start %ll , end: %ll, split: %ll\n", (uint64_t)current_region->start, (uint64_t)current_region->end, addr);
            // section_end_addr = addr + section->size;
            // printk("Split addr: %ll\n", addr);
            section_end_addr = addr + PAGE_SIZE;
            // printk("section size%ll\n", section->size );
            // printk("section end addr: %ll\n", section_end_addr);
            appendRegion((char*)(section_end_addr), current_region->end);
            if((uint64_t)(current_region->end) > addr) {
                current_region->end = (char *)(addr);
                printk("changing the end of memory region: %ll and end: %ll\n", current_region->start, current_region->end);

            }
            return;
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

void process_tag_entries(uint32_t tag_address) 
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
                printk("Memory Info\n");
                break;
            }
            case 5: {
                printk("Boot Device\n");
                break;
            }
            case 1: { 
                printk("Boot CLI\n");
                break;
            }
            case 2: {
                printk("Boot Loader\n");
                break;
            }
            case 6: {
                printk("Memory Map\n");
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
                break;
            }
            case 9: {
                printk("ELF Symbols\n");
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
                printk("type is something else: %d\n", tag_header->type);
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
    //tag type 0 and size 8 is termination of list 
}

void * MMU_pf_alloc(void)
{ 
    void * return_addr;
    if (frame_list.count == 0 && all_regions_allocated) { 
        printk("I am screwed and out of memory\n");
        return (void *)NO_FRAMES_AVAILABLE;
    } else if (frame_list.count > 0) {
        printk("allocating from freed list\n");
        return_addr = frame_list.next;
        frame_list.next = frame_list.next->next;
        frame_list.count--;
    } else {
        struct Region * current_region = &(rl[current_region_index]);
        // printk("current region start: %ll, and end %ll\n", current_region->start, current_region->end);
        if ((current_region->current_address + PAGE_SIZE) < current_region->end) {
            return_addr = current_region->current_address;
            current_region->current_address = (void *)((uint64_t)current_region->current_address + PAGE_SIZE);
        } else {
            if(current_region->next == NULL) {
                printk("All regions have been allocated\n");
                all_regions_allocated = 1;
            } else {
                current_region_index++;
            }
            return MMU_pf_alloc();
        }
    }
    // printk("return addr: %ll\n", return_addr);
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


// struct TestingLL {
//     uint64_t address;
//     struct TestingLL * next;
// };
void test_full_allocation(void) {
    // struct TestingLL ll;
    // struct TestingLL * current_test_node = &ll;
    printk("Stress Test Full Allocation\n");
    uint8_t * f = MMU_pf_alloc();
    uint64_t addr = (uint64_t)f;
    while (addr != NO_FRAMES_AVAILABLE) { 
        int offset = 0;
        while (offset < PAGE_SIZE) { 
            memcpy(f+offset, &addr, 8);
            offset += 8;
        }
        f = MMU_pf_alloc();
        addr = (uint64_t)f;
        printk(" %ll ", addr);
    }
    printk("Completed writing all Page Frames with their address value\n");


}