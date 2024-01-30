#include "modules/vga.h"
#include "modules/std.h"

int kmain () { 
    while(1) { 
        VGA_clear();
        printk("testing printk of percent sign: %%\n");

        char * str = "<Argument String>";
        printk("testing printk with string arg: %s\n", str);

        short shorty = 32267;
        printk("testing prink with max short arg %h\n", shorty);
        short shorty2 = 1;
        printk("testing printk with short of 1: %h\n", shorty2);
        short shorty3 = 0;
        printk("testing printk with short of 0: %h\n", shorty3);
        short shorty4 = -123;
        printk("testing printk with a negative value -123: %h\n", shorty4);

        long l1 = 0xFFFFFFFF;
        printk("testing printk with max long: %l\n", l1);
        printk("testing printk with long 0: %l\n", 0x00000000);
        printk("testing printk with other long: %l\n", 0x12344321);

        printk("testing printk with normal char: %c\n", 'a');
        
        printk("testing print k with signed decimal %d\n", 65535);
        printk("testing printk with unsigned int %u\n", 65535);
        
        printk("testing printk with a pointer %p\n", &l1);
        asm volatile("hlt");
    }
}