#include "ps2.h"
#include "std.h"
#include <stdint-gcc.h>

char left_shift = 0;
char right_shift = 0;

static inline void outb(uint16_t port, uint8_t val) { 
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port) { 
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                    : "=a"(ret)
                    : "Nd"(port) );
    return ret;
}

static char ps2_poll_read(void) {
    char status = inb(PS2_STATUS);
    while (!(status & PS2_STATUS_OUTPUT)) 
        status = inb(PS2_STATUS);
    return inb(PS2_DATA);
} 

void ps2_poll_out(void){ 
    char status;
    while((status = inb(PS2_STATUS) & PS2_STATUS_INPUT));
}


void ps2_init() { 
    char config;
    outb(PS2_CMD, DISABLE_P1);
    outb(PS2_CMD, DISABLE_P2);
    printk("about to poll read");
    config = inb(PS2_STATUS);
    printk("config before init: %l\n", config);
    config = (config | CFG_ENABLE_IRQ1 | CFG_DISABLE_C2)
               & ~CFG_DISABLE_C1 & ~CFG_ENABLE_IRQ2;
    printk("config after init: %l\n", config);
    ps2_poll_out();
    outb(PS2_CMD, config);

    //reset and enable keyboard 
    printk("initializing kb\n");
    outb(PS2_DATA, KB_RST);
    ps2_poll_out();
    printk("setting scan code\n");
    outb(PS2_DATA, SET_QWERTY);
    ps2_poll_out();
    outb(PS2_CMD, ENABLE_P1);
    printk("Finished kb init\n");
}

char read_kb(void)
{
    uint8_t scan_code = ps2_poll_read();
    // printk("scan code in func %l and shift vals: %u  %u\n", scan_code, left_shift, right_shift);
    switch (scan_code) { 
        case SCAN_A: return (left_shift || right_shift) ? 'A' : 'a';
        case SCAN_B: return (left_shift || right_shift) ? 'B' : 'b';
        case SCAN_C: return (left_shift || right_shift) ? 'C' : 'c';
        case SCAN_D: return (left_shift || right_shift) ? 'D' : 'd';
        case SCAN_E: return (left_shift || right_shift) ? 'E' : 'e';
        case SCAN_F: return (left_shift || right_shift) ? 'F' : 'f';
        case SCAN_G: return (left_shift || right_shift) ? 'G' : 'g';
        case SCAN_H: return (left_shift || right_shift) ? 'H' : 'h';
        case SCAN_I: return (left_shift || right_shift) ? 'I' : 'i';
        case SCAN_J: return (left_shift || right_shift) ? 'J' : 'j';
        case SCAN_K: return (left_shift || right_shift) ? 'K' : 'k';
        case SCAN_L: return (left_shift || right_shift) ? 'L' : 'l';
        case SCAN_M: return (left_shift || right_shift) ? 'M' : 'm';
        case SCAN_N: return (left_shift || right_shift) ? 'N' : 'n';
        case SCAN_O: return (left_shift || right_shift) ? 'O' : 'o';
        case SCAN_P: return (left_shift || right_shift) ? 'P' : 'p';
        case SCAN_Q: return (left_shift || right_shift) ? 'Q' : 'q';
        case SCAN_R: return (left_shift || right_shift) ? 'R' : 'r';
        case SCAN_S: return (left_shift || right_shift) ? 'S' : 's';
        case SCAN_T: return (left_shift || right_shift) ? 'T' : 't';
        case SCAN_U: return (left_shift || right_shift) ? 'U' : 'u';
        case SCAN_V: return (left_shift || right_shift) ? 'V' : 'v';
        case SCAN_W: return (left_shift || right_shift) ? 'W' : 'w';
        case SCAN_X: return (left_shift || right_shift) ? 'X' : 'x';
        case SCAN_Y: return (left_shift || right_shift) ? 'Y' : 'y';
        case SCAN_Z: return (left_shift || right_shift) ? 'Z' : 'z';
        case SCAN_1: return (left_shift || right_shift) ? '!' : '1';
        case SCAN_2: return (left_shift || right_shift) ? '@' : '2';
        case SCAN_3: return (left_shift || right_shift) ? '#' : '3';
        case SCAN_4: return (left_shift || right_shift) ? '$' : '4';
        case SCAN_5: return (left_shift || right_shift) ? '%' : '5';
        case SCAN_6: return (left_shift || right_shift) ? '^' : '6';
        case SCAN_7: return (left_shift || right_shift) ? '&' : '7';
        case SCAN_8: return (left_shift || right_shift) ? '*' : '8';
        case SCAN_9: return (left_shift || right_shift) ? '(' : '9';
        case SCAN_0: return (left_shift || right_shift) ? ')' : '0';
        case SCAN_MINUS: return (left_shift || right_shift) ? '_' : '-';
        case SCAN_EQUAL: return (left_shift || right_shift) ? '+' : '=';
        case SCAN_LEFT_BRACKET: return (left_shift || right_shift) ? '{' : '[';
        case SCAN_RIGHT_BRACKET: return (left_shift || right_shift) ? '}' : ']';
        case SCAN_SEMICOLON: return (left_shift || right_shift) ? ':' : ';';
        case SCAN_SINGLE_QUOTE: return (left_shift || right_shift) ? '"' : '\'';
        case SCAN_BACK_TICK: return (left_shift || right_shift) ? '~' : '`';
        case SCAN_COMMA: return (left_shift || right_shift) ? '<' : ',';
        case SCAN_PERIOD: return (left_shift || right_shift) ? '>' : '.';
        case SCAN_FORWARD_SLASH: return (left_shift || right_shift) ? '?' : '/';
        case SCAN_BACKSLASH: return (left_shift || right_shift) ? '|' : '\\';
        case SCAN_BACKSPACE: return '\b';
        case SCAN_LEFT_SHIFT: {
            left_shift = 1;
            break;
        }
        case SCAN_LEFT_SHIFT_RELEASE: {
            left_shift = 0;
            break;
        }
        case SCAN_RIGHT_SHIFT: {
            right_shift = 1;
            break;
        }
        case SCAN_RIGHT_SHIFT_RELEASE: {
            right_shift = 0;
            break;
        }
    }
    return '\0';
}

