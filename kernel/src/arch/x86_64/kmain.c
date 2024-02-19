#include "modules/vga.h"
#include "modules/std.h"
#include "modules/ps2.h"
#include "modules/interrupts.h"
#include "modules/string.h"
#include "modules/ser.h"


int kmain () { 
    while(1) { 
        VGA_clear();
        int loop = 1;

        CLI();
        IRQ_init();

        ps2_init();
        SER_init(); 
        // printk("entering loop\n");
        // Force a trap (system call) with syscall number 60 (exit)
        printk("Matthew's Kernel init complete\n");
        STI();
        const char * test1 = "This is the first test string\n";
        const char * test2 = "This is the second test string\n";
        printk("test printk serial with big strings \n%s%s", test1, test2);

        // asm volatile("int $0x24");

        enable_kb();
        while(1) { 
            asm volatile("hlt");
        }
    }
}