#include "std.h"
#include <stdarg.h>
#include "vga.h"

int printk(const char * fmt, ...) { 
    va_list args;
    va_start(args, fmt);
    while(*fmt != '\0') {
        if(*fmt == '%') { 
            fmt++;
            switch (*fmt) { 
                case '%': {
                    print_char(*fmt);
                    break;
                }
                case 's': { 
                    print_str(va_arg(args, const char *));
                    break;
                }
                case 'h': { 
                    short s = va_arg(args, int);
                    print_short(s);
                    break;
                }
                case 'l': {
                    long l = va_arg(args, long);
                    print_long_hex(l);
                    break;
                }

            }
        } else { 
            VGA_display_char(*fmt);
        }
        fmt++;
     }
    return 0;
}

void print_char(char c) { 
    VGA_display_char(c);
}
void print_str(const char * str) { 
    VGA_display_str(str);
}
void print_uchar(unsigned char c) {
    VGA_display_char(c);
}

void print_short(short s) {
    char digit;
    char buff[MAX_SHORT] = {0};
    int i= 0;
    if(s < 0) { 
        print_char('-');
        s = -s;
    }
    while (s > 0) { 
        digit = s % 10;
        buff[i++] = digit + ASCII_NUM_OFFSET;
        s /= 10;
    }
    int flag = 0;
    for (i = MAX_SHORT-1; i >= 0; i--){
        if(buff[i] != 0) { 
            flag = 1;
        }
        if(flag) { 
            print_char(buff[i]);
        }
    }
    if(!flag) { 
        print_char('0');
    }
}
void print_long_hex(long l) {
    char digit;
    int shift;
    int i;
    print_str("0x");
    for (i = 0; i < LONG_HEX_CHAR_COUNT; i++) { 
        shift = (LONG_HEX_CHAR_COUNT - i -1) * HEX_CHAR_SIZE;
        digit = ((l >> shift) & HEX_MASK);
        if(digit < 10) { 
            print_char(digit + ASCII_NUM_OFFSET);
        } else {
            digit = digit - 10;
            print_char(digit + ASCII_LETTER_OFFSET);
        }
    }
}

