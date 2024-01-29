#include "string.h"

void * memset(void *dst, int c, size_t n) { 
    int i;
    unsigned char * d = (unsigned char *)dst;
    for (i=0; i<n; i++){
        d[i] = (unsigned char)c;
    }
    return dst;
}
void * memcpy(void *dest, const void *src, size_t n) {
    int i;
    unsigned char * d = (unsigned char *)dest;
    unsigned char * s = (unsigned char *)src;
    for (i = 0; i < n; i++){
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
    return dest;
}
size_t strlen(const char *s)  { 
    size_t c = 0;
    while(s[c++] != '\0');
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
