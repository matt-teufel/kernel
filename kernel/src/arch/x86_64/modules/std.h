#define MAX_SHORT 10
#define HEX_MASK 0xF
#define LONG_HEX_CHAR_COUNT 8
#define HEX_CHAR_SIZE 4

#define ASCII_NUM_OFFSET 48
#define ASCII_LETTER_OFFSET 65

extern int printk(const char * fmt, ...) __attribute__ ((format (printf, 1, 2)));
extern void print_char(char);
extern void print_str(const char *);
extern void print_uchar(unsigned char);
extern void print_short(short);
extern void print_long_hex(long);
