#include "vga.h"
#include "string.h"
#include <stdint-gcc.h>
#include "interrupts.h"

static unsigned short *vgaBuff = (unsigned short *)VGA_BASE;
static int width = 80;
static int height = 25;
static int cursor = 0;
static unsigned char color = FG(VGA_LIGHT_GREY) | BG(VGA_BLACK);

void VGA_display_char(char c) 
{ 
    uint8_t enable_interrupts = 0;
    if (are_interrupts_enabled()){ 
        enable_interrupts = 1;
        CLI();
    }
    if (c == '\n') { 
        cursor = (LINE(cursor) + 1) * width;
        if(cursor >= width * height)
            scroll();
    } else if (c == '\r') { 
        cursor = LINE(cursor);
    } else if (c == '\b') {
        cursor --;
        vgaBuff[cursor] = (color << 8) | 0;
    }
      else { 
        vgaBuff[cursor] = (color << 8) | c;
        if ( (cursor % width) < (width -1))
            cursor++;
        else {
            VGA_display_char('\n');
        }
    }
    if(enable_interrupts == 1){
        STI();
    }
}

void VGA_clear() { 
    int i;
    for (i=0; i< (width* height); i++) {
        vgaBuff[i] = 0;
    }
    cursor = 0;
}

void VGA_display_str(const char * str) {
    int i;
    for (i=0; i < strlen(str); i++) { 
        VGA_display_char(str[i]);
    }
}

void scroll() { 
    int i;
    for (i=0; i<height-1;i++){
        memcpy(vgaBuff+ (i*width), vgaBuff+((i+1)*width), width * sizeof(unsigned short));
    }
    memset((vgaBuff + (height-1)*width),0, width* sizeof(unsigned short));
    cursor -= width;
}
