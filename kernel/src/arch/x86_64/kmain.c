#include "modules/vga.h"
#include "modules/std.h"
#include "modules/ps2.h"

int kmain () { 
    while(1) { 
        VGA_clear();
        printk("Starting up Matthew's Kernel\n");
        // asm volatile("cli");
        // asm volatile("sti");
        ps2_init();
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