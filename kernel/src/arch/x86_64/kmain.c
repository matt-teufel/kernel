#include "modules/vga.h"
#include "modules/std.h"
#include "modules/ps2.h"
#include "modules/interrupts.h"


int kmain () { 
    while(1) { 
        VGA_clear();
        printk("Starting up Matthew's Kernel\n");
        int loop = 1;

        CLI();
        IRQ_init();

        ps2_init();
        // printk("entering loop\n");
        // while(loop);
        // Force a trap (system call) with syscall number 60 (exit)
        printk("interrupts are enabled\n");
        STI();
        // asm volatile("int $0x21");
        enable_kb();
        while(1) { 
            asm volatile("hlt");
        }


        char kb_input = '\0';
        while (1)  {
            kb_input = read_kb();
            // if (kb_input != '\0') { 
                printk("%c", read_kb());
            // }
        }
        printk("Exitting Matthew's Kernel\n");
        asm volatile("hlt");
    }
}