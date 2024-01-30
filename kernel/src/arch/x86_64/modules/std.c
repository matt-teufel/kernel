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
                    print_uchar('%');
                    break;
                }
                case 'd': {
                    print_short(va_arg(args, int), 1);
                    break;
                }
                case 'u': { 
                    print_int(va_arg(args, int), 0);
                    break;
                }
                case 'x': {
                    print_long_hex(va_arg(args, int), 0);
                    break;
                }
                case 'c': {
                    print_char(va_arg(args, int));
                    break;
                }
                case 'p': {
                    print_long_hex((long)va_arg(args,void * ), 0);
                    break;
                }
                case 's': { 
                    print_str(va_arg(args, const char *));
                    break;
                }
                case 'h': { 
                    short s = va_arg(args, int);
                    print_short(s, 1);
                    break;
                }
                case 'l': {
                    long l = va_arg(args, long);
                    print_long_hex(l, 0);
                    break;
                }
                case 'q': {
                    print_long_hex(va_arg(args, long long), 1);
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
    if(c < 0) { 
        print_char('-');
    }
    print_uchar(c);
}

void print_str(const char * str) { 
    VGA_display_str(str);
}
void print_uchar(unsigned char c) {
    VGA_display_char(c);
}

void print_short(short s, char signed_flag) {
    char digit;
    char buff[MAX_SHORT] = {0};
    int i= 0;
    if(signed_flag && s < 0) { 
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

void print_int(int num, char signed_flag) {
    char digit;
    char buff[MAX_INT] = {0};
    int i= 0;
    if(signed_flag && num < 0) { 
        print_char('-');
        num = -num;
    }
    while (num > 0) { 
        digit = num % 10;
        buff[i++] = digit + ASCII_NUM_OFFSET;
        num /= 10;
    }
    int flag = 0;
    for (i = MAX_INT-1; i >= 0; i--){
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

void print_long_hex(long l, char ll_flag ) {
    char digit;
    int shift;
    int i;
    char character_count;
    if (ll_flag) { 
        character_count = LONG_HEX_CHAR_COUNT * 2;
    } else { 
        character_count = LONG_HEX_CHAR_COUNT;
    }
    print_str("0x");
    for (i = 0; i < character_count; i++) { 
        shift = (character_count - i -1) * HEX_CHAR_SIZE;
        digit = ((l >> shift) & HEX_MASK);
        if(digit < 10) { 
            print_char(digit + ASCII_NUM_OFFSET);
        } else {
            digit = digit - 10;
            print_char(digit + ASCII_LETTER_OFFSET);
        }
    }
}

