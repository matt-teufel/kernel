#include "string.h"

void * memset(void *dst, int c, size_t n) { 
    int i;
    unsigned char * d = (unsigned char *)dst;
    for (i=0; i<n; i++){
        d[i] = (unsigned char)c;
    }
    return dst;
}
void *memcpy(void *dest, const void *src, size_t count) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    
    while (count-- > 0) {
        *d++ = *s++;
    }
    
    return dest;
}
size_t strlen(const char *s)  { 
    size_t c = 0;
    while(s[++c] != '\0');
    return c;
}
char * strcpy(char *dest, const char * src) { 
    return memcpy(dest, src, strlen(src));
}
int strcmp(const char *s1, const char * s2){ 
    while (*s1 && ((*s1) == (*s2))){
        s1++;
        s2++;
    }
    return (*s1) - (*s2);
}
const char * strchr(const char * s, int c) { 
    while (*s != '\0') {
        if(*s == c) {
            return (char *)s;
        }
        s++;
    }
    return s;
}

// printk tests 
// printk("testing printk of percent sign: %%\n");

// char * str = "<Argument String>";
// printk("testing printk with string arg: %s\n", str);

// short shorty = 32267;
// printk("testing prink with max short arg %h\n", shorty);
// short shorty2 = 1;
// printk("testing printk with short of 1: %h\n", shorty2);
// short shorty3 = 0;
// printk("testing printk with short of 0: %h\n", shorty3);
// short shorty4 = -123;
// printk("testing printk with a negative value -123: %h\n", shorty4);

// long l1 = 0xFFFFFFFF;
// printk("testing printk with max long: %l\n", l1);
// printk("testing printk with long 0: %l\n", 0x00000000);
// printk("testing printk with other long: %l\n", 0x12344321);

// printk("testing printk with normal char: %c\n", 'a');

// printk("testing print k with signed decimal %d\n", 65535);
// printk("testing printk with unsigned int %u\n", 65535);

// printk("testing printk with a pointer %p\n", &l1);

// printk("testing mixed types-- string - %s, then an unsigned int: %u, then a negative number %d \n", str, 20,-20 );