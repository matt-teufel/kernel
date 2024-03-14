#include "modules/vga.h"
#include "modules/std.h"
#include "modules/ps2.h"
#include "modules/interrupts.h"
#include "modules/string.h"
#include "modules/ser.h"
#include "modules/pfa.h"
#include "modules/pt.h"
#include "modules/kmalloc.h"

int kmain (uint32_t tag_addr) { 
    while(1) { 
        VGA_clear();
        int loop = 1;

        CLI();

        // printk("entering loop\n");
        // Force a trap (system call) with syscall number 60 (exit)
        // printk("tag address %l\n", tag_addr);
        // while(loop);
        struct Region * physical_regions = process_tag_entries(tag_addr);
        // test_full_allocation();
        // test_basic_alloc_and_free();
        pt_init(physical_regions);
        // printk("page table initialized, going to enable it\n");
        enable_paging();
                // asm volatile("int $0x0E");
        IRQ_init();

        ps2_init();
        SER_init(); 

        STI();
        printk("Matthew's kernel initializaiton complete\n");
        test_table();
        // test_page_fault();
        init_pools();
        test_kmalloc_simple();
        test_kmalloc_full();
        test_free_then_reallocate();
        test_very_large_allocation();
        // uint64_t * page1 = MMU_alloc_page();
        // uint64_t * page2 = MMU_alloc_page();
        // uint64_t * page3 = MMU_alloc_page();
        // printk("page1 is located at: %ll\n", (uint64_t)page1);
        // printk("page2 is located at: %ll\n", (uint64_t)page2);
        // printk("page3 is located at: %ll\n", (uint64_t)page3);


        // printk("printing a normal string\n");
        // char * str = "hello world\n";
        // printk("printing out a string %s\n", str);
        // long long var = 0x1000;
        // printk("printing long long %ll\n", var);
        // enable_kb();
        while(1) { 
            asm volatile("hlt");
        }
    }
}