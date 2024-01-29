#include "vga.h"
#include "string.h"

static unsigned short *vgaBuff = (unsigned short *)VGA_BASE;
static int width = 80;
static int height = 25;
static int cursor = 0;
static unsigned char color = FG(VGA_LIGHT_GREY) | BG(VGA_BLACK);

void VGA_display_char(char c) 
{ 
    if (c == '\n') { 
        cursor = (LINE(cursor) + 1) * width;
        if(cursor >= width * height)
            scroll();
    } else if (c == '\r') { 
        cursor = LINE(cursor);
    } else { 
        vgaBuff[cursor] = (color << 8) | c;
        if ( (cursor % width) < (width -1))
            cursor++;
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
    memcpy(vgaBuff, (vgaBuff + width), (width * (height-1)));
}