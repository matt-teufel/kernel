#include "modules/vga.h"

int kmain () { 
    while(1) { 
        VGA_display_char('m');
        asm volatile("hlt");
    }
}